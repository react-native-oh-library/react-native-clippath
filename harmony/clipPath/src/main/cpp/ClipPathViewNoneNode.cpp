//
// Created on 2024/6/25.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#include "ModUtil.h"
#include "RNOH/arkui/NativeNodeApi.h"
#include "ClipPathViewNoneNode.h"
#include "SVGPathParser.h"
#include "SVGViewBox.h"
#include "pen_style_node.h"
#include <native_drawing/drawing_brush.h>
#include <native_drawing/drawing_canvas.h>
#include <native_drawing/drawing_color.h>
#include <native_drawing/drawing_path.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_point.h>
#include <native_drawing/drawing_rect.h>
#include <native_drawing/drawing_shader_effect.h>
#include <native_drawing/drawing_types.h>

namespace rnoh {
ClipPathViewNoneNode::ClipPathViewNoneNode()
    : ArkUINode(NativeNodeApi::getInstance()->createNode(ArkUI_NodeType::ARKUI_NODE_CUSTOM)) {
    canvasCallback_ = new CanvasCallback();
    canvasCallback_->callback = [this](ArkUI_NodeCustomEvent *event) {
        auto type = OH_ArkUI_NodeCustomEvent_GetEventType(event);
        switch (type) {
        case ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW:
            OnDraw(event);
            break;
        case ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE: {
            int32_t width = getSavedWidth();
            int32_t height = getSavedHeight();
            maybeThrow(NativeNodeApi::getInstance()->setMeasuredSize(m_nodeHandle, width, height));
            setRectF(mBounds, 0, 0, width, height);
        } break;
        default:
            break;
        }
    };
    eventReceiver = [](ArkUI_NodeCustomEvent *event) {
        int32_t targetId = OH_ArkUI_NodeCustomEvent_GetEventTargetId(event);
        if (targetId == 10001 || targetId == 10002) {
            auto *userData = reinterpret_cast<CanvasCallback *>(OH_ArkUI_NodeCustomEvent_GetUserData(event));
            if (userData != nullptr && userData->callback != nullptr) {
                userData->callback(event);
            }
        }
    };
    maybeThrow(NativeNodeApi::getInstance()->addNodeCustomEventReceiver(m_nodeHandle, eventReceiver));
    maybeThrow(NativeNodeApi::getInstance()->registerNodeCustomEvent(
        m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW, 10001, canvasCallback_));
    maybeThrow(NativeNodeApi::getInstance()->registerNodeCustomEvent(m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE,
                                                                     10002, canvasCallback_));
    OH_Drawing_PenIsAntiAlias(mPaint);
    OH_Drawing_PenIsAntiAlias(mPaintStroke);
    OH_Drawing_PenSetColor(mPaint, 0xffffffff);
    OH_Drawing_PenSetColor(mPaintStroke, 0xffffffff);
}

ClipPathViewNoneNode::~ClipPathViewNoneNode() {
    NativeNodeApi::getInstance()->removeNodeCustomEventReceiver(m_nodeHandle, eventReceiver);
    NativeNodeApi::getInstance()->unregisterNodeCustomEvent(m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_FOREGROUND_DRAW);
    NativeNodeApi::getInstance()->unregisterNodeCustomEvent(m_nodeHandle, ARKUI_NODE_CUSTOM_EVENT_ON_MEASURE);
    OH_Drawing_RectDestroy(mRectVb);
    OH_Drawing_RectDestroy(mRectVbDensity);
    OH_Drawing_RectDestroy(mBounds);
    OH_Drawing_RectDestroy(mRectPath);
    OH_Drawing_PathDestroy(mPath);
    OH_Drawing_PathDestroy(mPath2);
    OH_Drawing_MatrixDestroy(mMatrix);
    OH_Drawing_PenDestroy(mPaint);
    OH_Drawing_PenDestroy(mPaintStroke);
    delete canvasCallback_;
    delete mProps;
    canvasCallback_ = nullptr;
    mProps = nullptr;
    canvas =nullptr;
}

void ClipPathViewNoneNode::insertChild(ArkUINode &child, std::size_t index) {
    maybeThrow(NativeNodeApi::getInstance()->insertChildAt(m_nodeHandle, child.getArkUINodeHandle(), index));
}

void ClipPathViewNoneNode::removeChild(ArkUINode &child) {
    maybeThrow(NativeNodeApi::getInstance()->removeChild(m_nodeHandle, child.getArkUINodeHandle()));
}

void ClipPathViewNoneNode::setPanStyleMode(OH_Drawing_Canvas *canvas, int type) {

    auto cBrush = OH_Drawing_BrushCreate();
    switch (type) {
    case CLIP_PEN_STYLE_FILL:
        OH_Drawing_BrushSetColor(cBrush, OH_Drawing_ColorSetArgb(0xff, 0xff, 0xff, 0xff));
        break;
    case CLIP_PEN_STYLE_STROKE:
        OH_Drawing_BrushSetColor(cBrush, OH_Drawing_ColorSetArgb(0x00, 0x00, 0x00, 0x00));
        break;
    default:
        break;
    }
    OH_Drawing_CanvasAttachBrush(canvas, cBrush);
    OH_Drawing_BrushDestroy(cBrush);
}

void ClipPathViewNoneNode::OnDraw(ArkUI_NodeCustomEvent *event) {
    auto *drawContext = OH_ArkUI_NodeCustomEvent_GetDrawContextInDraw(event);
    canvas = reinterpret_cast<OH_Drawing_Canvas *>(OH_ArkUI_DrawContext_GetCanvas(drawContext));
    auto width_ = OH_Drawing_CanvasGetWidth(canvas);
    auto height_ = OH_Drawing_CanvasGetHeight(canvas);

    auto canvasRect = OH_Drawing_RectCreate(0.0f, 0.0f, width_, height_);
    OH_Drawing_CanvasSaveLayer(canvas, canvasRect, nullptr);
    OH_Drawing_Brush *cBrush_back = OH_Drawing_BrushCreate();
    OH_Drawing_BrushSetColor(cBrush_back, OH_Drawing_ColorSetArgb(0xff, 0xff, 0xff, 0xff));
    OH_Drawing_CanvasDrawBackground(canvas, cBrush_back);

    OH_Drawing_Brush *cBrush_ = OH_Drawing_BrushCreate();
    OH_Drawing_BrushSetBlendMode(cBrush_, BLEND_MODE_DST_OUT);
    OH_Drawing_CanvasSaveLayer(canvas, canvasRect, cBrush_);

    drawPath(canvas);
    OH_Drawing_RectDestroy(canvasRect);
    OH_Drawing_BrushDestroy(cBrush_back);
    OH_Drawing_BrushDestroy(cBrush_);
}

void ClipPathViewNoneNode::drawPath(OH_Drawing_Canvas *canvas) {
    setupPath(canvas);
    viewBoxTransform();
    setPaintStrokeProps();
    canvasTransform();
    OH_Drawing_CanvasSave(canvas);
    OH_Drawing_CanvasConcatMatrix(canvas, mMatrix);

    uint32_t count = OH_Drawing_CanvasGetSaveCount(canvas);
    OH_Drawing_CanvasAttachPen(canvas, mPaint);
    setPanStyleMode(canvas, CLIP_PEN_STYLE_FILL);
    OH_Drawing_CanvasDrawPath(canvas, mPath);
    OH_Drawing_CanvasDetachPen(canvas);

    OH_Drawing_CanvasAttachPen(canvas, mPaintStroke);
    setPanStyleMode(canvas, CLIP_PEN_STYLE_STROKE);
    OH_Drawing_CanvasDrawPath(canvas, mPath2);
    OH_Drawing_CanvasDetachPen(canvas);

    OH_Drawing_CanvasRestoreToCount(canvas, count);
    OH_Drawing_CanvasRestore(canvas);
    OH_Drawing_CanvasRestore(canvas);
}

void ClipPathViewNoneNode::setupPath(OH_Drawing_Canvas *canvas) {
    if (!canvas || mD.empty()) {
        return;
    }
    if (mPath) {
        OH_Drawing_PathReset(mPath);
    }
    SVGPathParser::mScale = ModUtil::getDensity();
    mPath = SVGPathParser::parse(mD);
}
void ClipPathViewNoneNode::setD(const std::string d) {
    mD = d;
    markDirty();
}
void ClipPathViewNoneNode::setStrokeWidth(float const width) { mProps->mStrokeWidth = width; }
void ClipPathViewNoneNode::setStrokeCap(std::string const cap) { mProps->mStrokeCap = cap; }
void ClipPathViewNoneNode::setStrokeJoin(std::string const join) { mProps->mStrokeJoin = join; }
void ClipPathViewNoneNode::setStrokeMiter(float const miter) { mProps->mStrokeMiter = miter; }
void ClipPathViewNoneNode::setStrokeStart(float const start) { mProps->mStrokeStart = start; }
void ClipPathViewNoneNode::setStrokeEnd(float const end) { mProps->mStrokeEnd = end; }
float ClipPathViewNoneNode::toDip(float value) { return value * ModUtil::getDensity(); }
void ClipPathViewNoneNode::setFillRule(std::string v) { mProps->mFillRule = v.empty() ? "none" : v; }
void ClipPathViewNoneNode::setAlign(std::string v) { mAlign = v.empty() ? "xMidYMid" : v; }
void ClipPathViewNoneNode::setAspect(std::string v) {
    mAspect = v.empty()
                  ? SVGViewBox::MOS_MEET
                  : (v.compare("slice") == 0 ? SVGViewBox::MOS_SLICE
                                             : (v.compare("none") == 0 ? SVGViewBox::MOS_NONE : SVGViewBox::MOS_MEET));
}
void ClipPathViewNoneNode::setRect(OH_Drawing_Rect *target, OH_Drawing_Rect *src) {
    OH_Drawing_RectSetLeft(target, OH_Drawing_RectGetLeft(src));
    OH_Drawing_RectSetTop(target, OH_Drawing_RectGetTop(src));
    OH_Drawing_RectSetRight(target, OH_Drawing_RectGetRight(src));
    OH_Drawing_RectSetBottom(target, OH_Drawing_RectGetBottom(src));
}

void ClipPathViewNoneNode::setRectF(OH_Drawing_Rect *target, float left, float top, float right, float bottom) {
    setRect(target, OH_Drawing_RectCreate(left, top, right, bottom));
}

void ClipPathViewNoneNode::setTranslateZ(float z) {
    ArkUI_NumberValue translateValue[] = {{.f32 = z}};
    ArkUI_AttributeItem translateItem = {translateValue, sizeof(translateValue) / sizeof(ArkUI_NumberValue)};
    uint32_t code = NativeNodeApi::getInstance()->setAttribute(m_nodeHandle, NODE_Z_INDEX, &translateItem);
}
void ClipPathViewNoneNode::setTransX(float v) {
    if (mTranslationX != v) {
        mTranslationX = v;
    }
}
void ClipPathViewNoneNode::setTransY(float v) {
    if (mTranslationY != v) {
        mTranslationY = v;
    }
}
void ClipPathViewNoneNode::setTransPercentageValue(bool v) {
    if (mTranslationIsPercent != v) {
        mTranslationIsPercent = v;
    }
}

void ClipPathViewNoneNode::setRot(float v) {
    if (mRotation != v) {
        mRotation = v;
    }
}
void ClipPathViewNoneNode::setRotO(float v) {
    if (mRotationOx != v || mRotationOy != v) {
        mRotationOx = v;
        mRotationOy = v;
    }
}
void ClipPathViewNoneNode::setRotOx(float v) {
    if (mRotationOx != v) {
        mRotationOx = v;
    }
}
void ClipPathViewNoneNode::setRotOy(float v) {
    if (mRotationOy != v) {
        mRotationOy = v;
    }
}
void ClipPathViewNoneNode::setRotPercentageValue(bool v) {
    if (mRotationIsPercent != v) {
        mRotationIsPercent = v;
    }
}
void ClipPathViewNoneNode::setSc(float v) {
    if (mScaleX != v || mScaleY != v) {
        mScaleX = v;
        mScaleY = v;
    }
}
void ClipPathViewNoneNode::setScX(float v) {
    if (mScaleX != v) {
        mScaleX = v;
    }
}

void ClipPathViewNoneNode::setScY(float v) {
    if (mScaleY != v) {
        mScaleY = v;
    }
}

void ClipPathViewNoneNode::setScO(float v) {
    if (mScaleOriginX != v || mScaleOriginY != v) {
        mScaleOriginX = v;
        mScaleOriginY = v;
    }
}
void ClipPathViewNoneNode::setScOx(float v) {
    if (mScaleOriginX != v) {
        mScaleOriginX = v;
    }
}
void ClipPathViewNoneNode::setScOy(float v) {
    if (mScaleOriginY != v) {
        mScaleOriginY = v;
    }
}
void ClipPathViewNoneNode::setScPercentageValue(bool v) {
    if (mScaleIsPercent != v) {
        mScaleIsPercent = v;
    }
}

void ClipPathViewNoneNode::setViewBox(std::vector<float> viewBox) {
    if (viewBox.empty()) {
        return;
    }
    float density = ModUtil::getDensity();
    setRectF(mRectVb, viewBox[0], viewBox[1], (viewBox[0] + viewBox[2]), (viewBox[1] + viewBox[3]));
    setRectF(mRectVbDensity, viewBox[0] * density, viewBox[1] * density, (viewBox[0] + viewBox[2]) * density,
             (viewBox[1] + viewBox[3]) * density);
}

void ClipPathViewNoneNode::viewBoxTransform() {
    float density = ModUtil::getDensity();
    if (validateViewBox()) {
        setRect(mRectPath, mRectVbDensity);
        SVGViewBox::transform(mRectVb, mBounds, mAlign, mAspect, density, mMatrix);
        OH_Drawing_PathTransform(mPath, mMatrix);
        OH_Drawing_MatrixMapRect(mMatrix, mRectPath, mRectPath);

    } else {
        setRect(mRectPath, mBounds);
    }
}
bool ClipPathViewNoneNode::validateViewBox() {
    return OH_Drawing_RectGetWidth(mRectVb) >= 0.0f && OH_Drawing_RectGetHeight(mRectVb) >= 0.0f;
}

void ClipPathViewNoneNode::setPaintStrokeProps() {
    OH_Drawing_PathSetFillType(mPath, mProps->getFillRule());
    float sw = validateViewBox()
                   ? ModUtil::viewBoxToMax(mProps->getStrokeWidth(), mRectVb, OH_Drawing_RectGetWidth(mRectPath),
                                           OH_Drawing_RectGetHeight(mRectPath))
                   : toDip(mProps->getStrokeWidth());
    OH_Drawing_PenSetWidth(mPaintStroke, sw);
    OH_Drawing_PenSetCap(mPaintStroke, mProps->getStrokeCap());
    OH_Drawing_PenSetJoin(mPaintStroke, mProps->getStrokeJoin());
    OH_Drawing_PenSetMiterLimit(mPaintStroke, mProps->getStrokeMiter());
    OH_Drawing_PathReset(mPath2);
    mPath2 = OH_Drawing_PathCopy(mPath);
    if (mProps->getStrokeStart() != 0.0f || mProps->getStrokeEnd() != 1.0f) {
        OH_Drawing_PathMoveTo(mPath2, OH_Drawing_PathGetLength(mPath2, false) * mProps->getStrokeStart(),
                              OH_Drawing_PathGetLength(mPath2, false) * mProps->getStrokeEnd());
        OH_Drawing_PathLineTo(mPath2, 0.0f, 0.0f);
    }
}

void ClipPathViewNoneNode::canvasTransform() {
    OH_Drawing_MatrixReset(mMatrix);
    if (mRotation != 0.0f) {
        float rotX;
        float rotY;
        if (mRotationIsPercent) {
            rotX = (mRotationOx * getSavedWidth());
            rotY = (mRotationOy * getSavedHeight());
        } else if (validateViewBox()) {
            rotX = OH_Drawing_RectGetLeft(mRectPath) +
                   ModUtil::viewBoxToWidth(mRotationOx, mRectVb, OH_Drawing_RectGetWidth(mRectPath));
            rotY = OH_Drawing_RectGetTop(mRectPath) +
                   ModUtil::viewBoxToHeight(mRotationOy, mRectVb, OH_Drawing_RectGetHeight(mRectPath));
        } else {
            rotX = toDip(mRotationOx);
            rotY = toDip(mRotationOy);
        }
        OH_Drawing_MatrixPostRotate(mMatrix, mRotation, rotX, rotY);
    }

    if (mScaleX != 1.0f || mScaleY != 1.0f) {
        float oX;
        float oY;
        if (mScaleIsPercent) {
            oX = (mScaleOriginX * getSavedWidth());
            oY = (mScaleOriginY * getSavedHeight());
        } else if (validateViewBox()) {
            oX = OH_Drawing_RectGetLeft(mRectPath) +
                 ModUtil::viewBoxToWidth(mScaleOriginX, mRectVb, OH_Drawing_RectGetWidth(mRectPath));
            oY = OH_Drawing_RectGetTop(mRectPath) +
                 ModUtil::viewBoxToHeight(mScaleOriginY, mRectVb, OH_Drawing_RectGetHeight(mRectPath));
        } else {
            oX = toDip(mScaleOriginX);
            oY = toDip(mScaleOriginY);
        }
        OH_Drawing_MatrixPostScale(mMatrix, mScaleX, mScaleY, oX, oY);
    }

    if (mTranslationX != 0.0f || mTranslationY != 0.0f) {
        float transX;
        float transY;
        if (mTranslationIsPercent) {
            transX = (mTranslationX * getSavedWidth());
            transY = (mTranslationY * getSavedHeight());
        } else if (validateViewBox()) {
            transX = (mTranslationX / OH_Drawing_RectGetWidth(mRectVb)) * OH_Drawing_RectGetWidth(mRectPath);
            transY = (mTranslationY / OH_Drawing_RectGetHeight(mRectVb)) * OH_Drawing_RectGetHeight(mRectPath);
        } else {
            transX = toDip(mTranslationX);
            transY = toDip(mTranslationY);
        }
        OH_Drawing_MatrixPostTranslate(mMatrix, transX, transY);
    }
}

} // namespace rnoh