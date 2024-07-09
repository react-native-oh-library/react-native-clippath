/*
 * Copyright (C) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ModUtil.h"
#include <native_drawing/drawing_rect.h>
namespace rnoh {
float ModUtil::mScreenDensity = 2.5f;

float ModUtil::clamp(float v) { return v > 1 ? 1 : (v < 0 ? 0 : v); }

float ModUtil::uClamp(float v) { return v < 0 ? 0 : v; }

float ModUtil::uClamp(float v, float optional) { return v < 0 ? optional : v; }

float ModUtil::viewBoxEvaluator(float value, float start, float end) { return (value - start) / (end - start); }

float ModUtil::viewBoxToWidth(float value, OH_Drawing_Rect *rectF, float w) {
    return viewBoxEvaluator(value, OH_Drawing_RectGetLeft(rectF), OH_Drawing_RectGetRight(rectF)) * w;
}

float ModUtil::viewBoxToHeight(float value, OH_Drawing_Rect *rectF, float h) {
    return viewBoxEvaluator(value, OH_Drawing_RectGetTop(rectF), OH_Drawing_RectGetBottom(rectF)) * h;
}

float ModUtil::viewBoxToMax(float value, OH_Drawing_Rect *rectF, float w, float h) {
    float size = OH_Drawing_RectGetWidth(rectF) > OH_Drawing_RectGetHeight(rectF) ? OH_Drawing_RectGetWidth(rectF)
                                                                                  : OH_Drawing_RectGetHeight(rectF);
    float maxVb = w > h ? OH_Drawing_RectGetWidth(rectF) : OH_Drawing_RectGetHeight(rectF);
    return (value / maxVb) * size;
}
void ModUtil::setDensity(float density) { mScreenDensity = density; }

float ModUtil::getDensity() { return mScreenDensity; }

} // namespace rnoh