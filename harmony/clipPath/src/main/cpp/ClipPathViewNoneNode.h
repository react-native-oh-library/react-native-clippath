//
// Created on 2024/6/25.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".
#pragma once

#include "RNOH/arkui/ArkUINode.h"
#include <native_drawing/drawing_matrix.h>
#include <native_drawing/drawing_pen.h>
#include <native_drawing/drawing_rect.h>
#include <native_drawing/drawing_types.h>
#include "ClipPathProps.h"
#include "SVGViewBox.h"
namespace rnoh {

    struct CanvasCallback {
        std::function<void(ArkUI_NodeCustomEvent *event)> callback;
    };

    class ClipPathViewNoneNode : public ArkUINode {
    public:
        ClipPathViewNoneNode();
        ~ClipPathViewNoneNode() override;
        void insertChild(ArkUINode &child, std::size_t index);
        void removeChild(ArkUINode &child);
        void setD(const std::string d);
        void setStrokeWidth(float const width);
        void setStrokeCap(std::string const cap);
        void setStrokeJoin(std::string const join);
        void setStrokeMiter(float const miter);
        void setStrokeStart(float const start);
        void setStrokeEnd(float const end);
        void setViewBox(std::vector<float> viewBox);
        void setAlign(std::string v);
        void setAspect(std::string v);
        void setFillRule(std::string v);
        // transFrom
        void setTransX(float v);
        void setTransY(float v);
        void setTransPercentageValue(bool v);
        void setRot(float v);
        void setRotO(float v);
        void setRotOx(float v);
        void setRotOy(float v);
        void setRotPercentageValue(bool v);
        void setSc(float v);
        void setScX(float v);
        void setScY(float v);
        void setScO(float v);
        void setScOx(float v);
        void setScOy(float v);
        void setTranslateZ(float z);
        void setScPercentageValue(bool v);
 private:
        void (*eventReceiver)(ArkUI_NodeCustomEvent *event);
        void OnDraw(ArkUI_NodeCustomEvent *event);
        void setupPath(OH_Drawing_Canvas *canvas);
        void viewBoxTransform();
        bool validateViewBox();
        void setRect(OH_Drawing_Rect *target, OH_Drawing_Rect *src);
        void setRectF(OH_Drawing_Rect *target, float left, float top, float right, float bottom);
        void setPaintStrokeProps();
        float toDip(float value);
        void canvasTransform();
        void drawPath(OH_Drawing_Canvas *canvas);
        void setPanStyleMode(OH_Drawing_Canvas *canvas,int type);    
    
    private:
        std::string mD{""};
        std::string mAlign{"xMinYMin"};
        CanvasCallback *canvasCallback_{nullptr};
        int mAspect{SVGViewBox::MOS_MEET};
        ClipPathProps *mProps{new ClipPathProps()};
        OH_Drawing_Rect *mRectVb{OH_Drawing_RectCreate(0.0f, 0.0f, -1.0f, -1.0f)};
        OH_Drawing_Rect *mRectVbDensity{OH_Drawing_RectCreate(0.0f, 0.0f, -1.0f, -1.0f)};
        OH_Drawing_Rect *mRectPath{OH_Drawing_RectCreate(0.0f, 0.0f, 0.0f, 0.0f)};
        OH_Drawing_Rect *mBounds{OH_Drawing_RectCreate(0.0f, 0.0f, 0.0f, 0.0f)};
        OH_Drawing_Matrix *mMatrix{OH_Drawing_MatrixCreate()};
        OH_Drawing_Path *mPath{};
        OH_Drawing_Path *mPath2{OH_Drawing_PathCreate()};
        OH_Drawing_Pen *mPaint{OH_Drawing_PenCreate()};
        OH_Drawing_Pen *mPaintStroke{OH_Drawing_PenCreate()};
        float mTranslationX{0.0f};
        float mTranslationY{0.0f};
        bool mTranslationIsPercent{false};
        float mRotation{0.0f};
        float mRotationOx{0.0f};
        float mRotationOy{0.0f};
        bool mRotationIsPercent{false};
        float mScaleX{1.0f};
        float mScaleY{1.0f};
        float mScaleOriginX{0.0f};
        float mScaleOriginY{0.0f};
        bool mScaleIsPercent{false};
    };
} // namespace rnoh