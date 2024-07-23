//
// Created on 2024/6/27.
//
// Node APIs are not fully supported. To solve the compilation error of the interface cannot be found,
// please include "napi/native_api.h".

#pragma once
#include "ModUtil.h"
#include <native_drawing/drawing_path.h>
#include <native_drawing/drawing_pen.h>
#include <string>
namespace rnoh {
class ClipPathProps {
public:
    float mOpacity{1.0f};
    bool mOpacityStatus{false};
    std::string mMask{""};
    std::string mOldMask{""};
    bool mFillColorStatus{false};
    float mFillOpacity{1.0f};
    bool mFillOpacityStatus{false};
    std::string mFillRule{"none"};
    bool mFillRuleStatus{false};
    bool mStrokeColorStatus{false};
    float mStrokeOpacity{1.0f};
    bool mStrokeOpacityStatus{false};
    float mStrokeWidth{1.0f};
    bool mStrokeWidthStatus{false};
    std::string mStrokeCap{"none"};
    std::string mStrokeJoin{"none"};
    float mStrokeMiter{4.0f};
    bool mStrokeMiterStatus{false};
    float mStrokeStart{0.0f};
    bool mStrokeStartStatus{false};
    float mStrokeEnd{1.0f};
    bool mStrokeEndStatus{false};
    bool mShadowColorStatus{false};
    float mShadowOpacity{0.0f};
    bool mShadowOpacityStatus{false};
    float mShadowRadius{2.0f};
    bool mShadowRadiusStatus{false};
    float mShadowOffsetX{2.0f};
    float mShadowOffsetY{2.0f};
    bool mShadowOffsetIsPercent{false};
    bool mShadowOffsetStatus{false};

public:
    float getOpacity() { return ModUtil::clamp(mOpacity); }

    std::string getMask() { return mMask; }

    float getFillOpacity() { return ModUtil::clamp(mFillOpacity); }

    OH_Drawing_PathFillType getFillRule() {
        return mFillRule.compare("evenodd") == 0 ? OH_Drawing_PathFillType::PATH_FILL_TYPE_EVEN_ODD
                                                 : OH_Drawing_PathFillType::PATH_FILL_TYPE_WINDING;
    }


    float getStrokeOpacity() { return ModUtil::clamp(mStrokeOpacity); }

    float getStrokeWidth() { return ModUtil::uClamp(mStrokeWidth, 1.0f); }

    OH_Drawing_PenLineCapStyle getStrokeCap() {
        return mStrokeCap.compare("round") == 0
                   ? OH_Drawing_PenLineCapStyle::LINE_ROUND_CAP
                   : (mStrokeCap.compare("square") == 0 ? OH_Drawing_PenLineCapStyle::LINE_SQUARE_CAP
                                                        : OH_Drawing_PenLineCapStyle::LINE_FLAT_CAP);
    }
    OH_Drawing_PenLineJoinStyle getStrokeJoin() {
        return mStrokeJoin.compare("round") == 0
                   ? OH_Drawing_PenLineJoinStyle::LINE_ROUND_JOIN
                   : (mStrokeJoin.compare("bevel") == 0 ? OH_Drawing_PenLineJoinStyle::LINE_BEVEL_JOIN
                                                        : OH_Drawing_PenLineJoinStyle::LINE_MITER_JOIN);
    }

    float getStrokeMiter() { return mStrokeMiter; }

    float getStrokeStart() { return ModUtil::clamp(mStrokeStart); }

    float getStrokeEnd() { return ModUtil::clamp(mStrokeEnd); }


    float getShadowOpacity() { return ModUtil::clamp(mShadowOpacity); }

    float getShadowRadius() { return ModUtil::uClamp(mShadowRadius); }

    float getShadowOffsetX() { return mShadowOffsetX; }

    float getShadowOffsetY() { return mShadowOffsetY; }

    bool getShadowOffsetIsPercent() { return mShadowOffsetIsPercent; }

    void set(ClipPathProps props) {

        if (!mOpacityStatus)
            mOpacity = props.mOpacity;
        if (!mFillOpacityStatus)
            mFillOpacity = props.mFillOpacity;
        if (!mFillRuleStatus)
            mFillRule = props.mFillRule;
        if (!mStrokeOpacityStatus)
            mStrokeOpacity = props.mStrokeOpacity;
        if (!mStrokeWidthStatus)
            mStrokeWidth = props.mStrokeWidth;
        if (mStrokeCap == "none")
            mStrokeCap = props.mStrokeCap;
        if (mStrokeJoin == "none")
            mStrokeJoin = props.mStrokeJoin;
        if (!mStrokeMiterStatus)
            mStrokeMiter = props.mStrokeMiter;
        if (!mStrokeStartStatus)
            mStrokeStart = props.mStrokeStart;
        if (!mStrokeEndStatus)
            mStrokeEnd = props.mStrokeEnd;
        if (!mShadowOpacityStatus)
            mShadowOpacity = props.mShadowOpacity;
        if (!mShadowRadiusStatus)
            mShadowRadius = props.mShadowRadius;
        if (!mShadowOffsetStatus) {
            mShadowOffsetX = props.mShadowOffsetX;
            mShadowOffsetY = props.mShadowOffsetY;
            mShadowOffsetIsPercent = props.mShadowOffsetIsPercent;
        }
    }
};
} // namespace rnoh