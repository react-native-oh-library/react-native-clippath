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

#ifndef HARMONY_SVGVIEWBOX_H
#define HARMONY_SVGVIEWBOX_H

#include <native_drawing/drawing_types.h>
#include <string>

namespace rnoh {
class SVGViewBox {
public:
    static const int MOS_MEET = 0;
    static const int MOS_SLICE = 1;
    static const int MOS_NONE = 2;
    static void transform(OH_Drawing_Rect *vbRect, OH_Drawing_Rect *eRect, std::string align, int meetOrSlice,
                          float density, OH_Drawing_Matrix *result);
};
};     // namespace rnoh
#endif // HARMONY_SVGVIEWBOX_H