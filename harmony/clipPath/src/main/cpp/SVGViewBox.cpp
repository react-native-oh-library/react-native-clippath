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

#include "SVGViewBox.h"
#include <math.h>
#include <native_drawing/drawing_matrix.h>
#include <native_drawing/drawing_rect.h>
#include <native_drawing/drawing_types.h>
#include "string"
#include "vector"
#include <glog/logging.h>

void rnoh::SVGViewBox::transform(OH_Drawing_Rect *vbRect, OH_Drawing_Rect *eRect, std::string align, int meetOrSlice,
                                 float density, OH_Drawing_Matrix *result) {

    double vbX = OH_Drawing_RectGetLeft(vbRect) * density;
    double vbY = OH_Drawing_RectGetTop(vbRect) * density;
    double vbX2 = OH_Drawing_RectGetRight(vbRect) * density;
    double vbY2 = OH_Drawing_RectGetBottom(vbRect) * density;
    double vbWidth = vbX2 - vbX;
    double vbHeight = vbY2 - vbY;

    // Let e-x, e-y, e-width, e-height be the position and size of the element respectively.
    double eX = OH_Drawing_RectGetLeft(eRect);
    double eY = OH_Drawing_RectGetTop(eRect);
    double eWidth = OH_Drawing_RectGetWidth(eRect);
    double eHeight = OH_Drawing_RectGetHeight(eRect);


    // Initialize scale-x to e-width/vb-width.
    double scaleX = eWidth / vbWidth;

    // Initialize scale-y to e-height/vb-height.
    double scaleY = eHeight / vbHeight;

    // Initialize translate-x to e-x - (vb-x * scale-x).
    // Initialize translate-y to e-y - (vb-y * scale-y).
    double translateX = eX - (vbX * scaleX);
    double translateY = eY - (vbY * scaleY);

    // If align is 'none'
    if (meetOrSlice == MOS_NONE) {
        // Let scale be set the smaller value of scale-x and scale-y.
        // Assign scale-x and scale-y to scale.
        double scale = scaleX = scaleY = fmin(scaleX, scaleY);

        translateX += (eWidth - vbWidth * scaleX) / 2.0;
        translateY += (eHeight - vbHeight * scaleY) / 2.0;

    } else {
        // If align is not 'none' and meetOrSlice is 'meet', set the larger of scale-x and scale-y to the smaller.
        // Otherwise, if align is not 'none' and meetOrSlice is 'slice', set the smaller of scale-x and scale-y to the
        // larger.
        if (align.compare("none") != 0 && meetOrSlice == MOS_MEET) {
            scaleX = scaleY = fmin(scaleX, scaleY);
        } else if (align.compare("none") != 0 && meetOrSlice == MOS_SLICE) {
            scaleX = scaleY = fmax(scaleX, scaleY);
        }

        // If align contains 'xMid', add (e-width - vb-width * scale-x) / 2 to translate-x.
        if (align.find("xMid") != std::string::npos) {
            translateX += (eWidth - vbWidth * scaleX) / 2.0;
        }
        // If align contains 'xMax', add (e-width - vb-width * scale-x) to translate-x.
        if (align.find("xMax") != std::string::npos) {
            translateX += (eWidth - vbWidth * scaleX);
        }

        // If align contains 'yMid', add (e-height - vb-height * scale-y) / 2 to translate-y.
        if (align.find("YMid") != std::string::npos) {
            translateY += (eHeight - vbHeight * scaleY) / 2.0;
        }

        // If align contains 'yMax', add (e-height - vb-height * scale-y) to translate-y.
        if (align.find("YMax") != std::string::npos) {
            translateY += (eHeight - vbHeight * scaleY);
        }
    }
    OH_Drawing_MatrixReset(result);
    OH_Drawing_MatrixPostScale(result, (float)scaleX, (float)scaleY, 0.0f, 0.0f);
    OH_Drawing_MatrixPostTranslate(result, (float)translateX, (float)translateY);
}