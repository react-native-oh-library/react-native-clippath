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

#ifndef HARMONY_SVGPATHPARSER_H
#define HARMONY_SVGPATHPARSER_H
#include <native_drawing/drawing_types.h>
#include <string>

namespace rnoh {
class SVGPathParser {
public:
    static float mScale;
    static OH_Drawing_Path *parse(const std::string d);

private:
    static int i;
    static int l;
    static std::string s;
    static float mPenX;
    static float mPenY;
    static float mPivotX;
    static float mPivotY;
    static float mPenDownX;
    static float mPenDownY;
    static bool mPenDown;
    static void move(float x, float y, OH_Drawing_Path *cPath_);
    static void moveTo(float x, float y, OH_Drawing_Path *cPath_);
    static void line(float x, float y, OH_Drawing_Path *cPath_);
    static void lineTo(float x, float y, OH_Drawing_Path *cPath_);
    static void curve(float c1x, float c1y, float c2x, float c2y, float ex, float ey, OH_Drawing_Path *cPath_);
    static void curveTo(float c1x, float c1y, float c2x, float c2y, float ex, float ey, OH_Drawing_Path *cPath_);
    static void cubicTo(float c1x, float c1y, float c2x, float c2y, float ex, float ey, OH_Drawing_Path *cPath_);
    static void smoothCurve(float c1x, float c1y, float ex, float ey, OH_Drawing_Path *cPath_);
    static void smoothCurveTo(float c1x, float c1y, float ex, float ey, OH_Drawing_Path *cPath_);
    static void quadraticBezierCurve(float c1x, float c1y, float c2x, float c2y, OH_Drawing_Path *cPath_);
    static void quadraticBezierCurveTo(float c1x, float c1y, float c2x, float c2y, OH_Drawing_Path *cPath_);
    static void smoothQuadraticBezierCurve(float c1x, float c1y, OH_Drawing_Path *cPath_);
    static void smoothQuadraticBezierCurveTo(float c1x, float c1y, OH_Drawing_Path *cPath_);
    static void arc(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y,
                    OH_Drawing_Path *cPath_);
    static void arcTo(float rx, float ry, float rotation, bool outer, bool clockwise, float x, float y,
                      OH_Drawing_Path *cPath_);
    static void close(OH_Drawing_Path *cPath_);
    static void arcToBezier(float cx, float cy, float rx, float ry, float sa, float ea, bool clockwise, float rad,
                            OH_Drawing_Path *cPath_);
    static void setPenDown();
    static double _round(double val);
    static void skip_spaces();
    static bool is_cmd(char c);
    static bool is_number_start(char c);
    static bool is_absolute(char c);
    static bool parse_flag();
    static float parse_list_number();
    static float parse_number();
    static void parse_list_separator();
    static void skip_digits();
};
} // namespace rnoh
#endif // HARMONY_SVGPATHPARSER_H