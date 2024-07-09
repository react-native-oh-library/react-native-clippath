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

#include "Props.h"
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

namespace facebook {
namespace react {

RNCClipPathViewProps::RNCClipPathViewProps(const PropsParserContext &context, const RNCClipPathViewProps &sourceProps,
                                           const RawProps &rawProps)
    : ViewProps(context, sourceProps, rawProps), 
      d(convertRawProp(context, rawProps, "d", sourceProps.d, "/0")),
      aspect(convertRawProp(context, rawProps, "aspect", sourceProps.aspect, "meet")),
      fillRule(convertRawProp(context, rawProps, "fillRule", sourceProps.fillRule, "/0")),
      translateZ(convertRawProp(context, rawProps, "translateZ", sourceProps.strokeStart, {0.0})),
      strokeWidth(convertRawProp(context, rawProps, "strokeWidth", sourceProps.strokeWidth, {1.0})),
      strokeCap(convertRawProp(context, rawProps, "strokeCap", sourceProps.strokeCap, {"none"})),
      strokeJoin(convertRawProp(context, rawProps, "strokeJoin", sourceProps.strokeJoin, {"none"})),
      strokeMiter(convertRawProp(context, rawProps, "strokeMiter", sourceProps.strokeMiter, {4.0})),
      strokeStart(convertRawProp(context, rawProps, "strokeStart", sourceProps.strokeStart, {0.0})),
      strokeEnd(convertRawProp(context, rawProps, "strokeEnd", sourceProps.strokeEnd, {1.0})),
      transX(convertRawProp(context, rawProps, "transX", sourceProps.transX, {0.0})),
      transY(convertRawProp(context, rawProps, "transY", sourceProps.transY, {0.0})),
      transPercentageValue(
          convertRawProp(context, rawProps, "transPercentageValue", sourceProps.transPercentageValue, {false})),
      rot(convertRawProp(context, rawProps, "rot", sourceProps.rot, {0.0})),
      rotO(convertRawProp(context, rawProps, "rotO", sourceProps.rotO, {0.0})),
      rotOx(convertRawProp(context, rawProps, "rotOx", sourceProps.rotOx, {0.0})),
      rotOy(convertRawProp(context, rawProps, "rotOy", sourceProps.rotOy, {0.0})),
      rotPercentageValue(
          convertRawProp(context, rawProps, "rotPercentageValue", sourceProps.rotPercentageValue, {false})),
      sc(convertRawProp(context, rawProps, "sc", sourceProps.sc, {1.0})),

      scX(convertRawProp(context, rawProps, "scX", sourceProps.scX, {1.0})),
      scY(convertRawProp(context, rawProps, "scY", sourceProps.scY, {1.0})),
      scO(convertRawProp(context, rawProps, "scO", sourceProps.scO, {0.0})),
      scOx(convertRawProp(context, rawProps, "scOX", sourceProps.scOx, {0.0})),
      scOy(convertRawProp(context, rawProps, "scOY", sourceProps.scOy, {0.0})),
      scPercentageValue(convertRawProp(context, rawProps, "scPercentageValue", sourceProps.scPercentageValue, {false})),

      align(convertRawProp(context, rawProps, "align", sourceProps.align, {"xMidYMid"})),
      viewBox(convertRawProp(context, rawProps, "viewBox", sourceProps.viewBox, {})) {}


RNCClipPathViewNoneProps::RNCClipPathViewNoneProps(const PropsParserContext &context,
                                                   const RNCClipPathViewNoneProps &sourceProps,
                                                   const RawProps &rawProps)
    : ViewProps(context, sourceProps, rawProps), 
      d(convertRawProp(context, rawProps, "d", sourceProps.d, "/0")),
      aspect(convertRawProp(context, rawProps, "aspect", sourceProps.aspect, "meet")),
      fillRule(convertRawProp(context, rawProps, "fillRule", sourceProps.fillRule, "/0")),
      translateZ(convertRawProp(context, rawProps, "translateZ", sourceProps.strokeStart, {0.0})),
      strokeWidth(convertRawProp(context, rawProps, "strokeWidth", sourceProps.strokeWidth, {1.0})),
      strokeCap(convertRawProp(context, rawProps, "strokeCap", sourceProps.strokeCap, {"none"})),
      strokeJoin(convertRawProp(context, rawProps, "strokeJoin", sourceProps.strokeJoin, {"none"})),
      strokeMiter(convertRawProp(context, rawProps, "strokeMiter", sourceProps.strokeMiter, {4.0})),
      strokeStart(convertRawProp(context, rawProps, "strokeStart", sourceProps.strokeStart, {0.0})),
      strokeEnd(convertRawProp(context, rawProps, "strokeEnd", sourceProps.strokeEnd, {1.0})),
      transX(convertRawProp(context, rawProps, "transX", sourceProps.transX, {0.0})),
      transY(convertRawProp(context, rawProps, "transY", sourceProps.transY, {0.0})),
      transPercentageValue(
          convertRawProp(context, rawProps, "transPercentageValue", sourceProps.transPercentageValue, {false})),
      rot(convertRawProp(context, rawProps, "rot", sourceProps.rot, {0.0})),
      rotO(convertRawProp(context, rawProps, "rotO", sourceProps.rotO, {0.0})),
      rotOx(convertRawProp(context, rawProps, "rotOx", sourceProps.rotOx, {0.0})),
      rotOy(convertRawProp(context, rawProps, "rotOy", sourceProps.rotOy, {0.0})),
      rotPercentageValue(
          convertRawProp(context, rawProps, "rotPercentageValue", sourceProps.rotPercentageValue, {false})),

      sc(convertRawProp(context, rawProps, "sc", sourceProps.sc, {1.0})),
      scX(convertRawProp(context, rawProps, "scX", sourceProps.scX, {1.0})),
      scY(convertRawProp(context, rawProps, "scY", sourceProps.scY, {1.0})),
      scO(convertRawProp(context, rawProps, "scO", sourceProps.scO, {0.0})),
      scOx(convertRawProp(context, rawProps, "scOX", sourceProps.scOx, {0.0})),
      scOy(convertRawProp(context, rawProps, "scOY", sourceProps.scOy, {0.0})),
      scPercentageValue(convertRawProp(context, rawProps, "scPercentageValue", sourceProps.scPercentageValue, {false})),

      align(convertRawProp(context, rawProps, "align", sourceProps.align, {"xMidYMid"})),
      viewBox(convertRawProp(context, rawProps, "viewBox", sourceProps.viewBox, {})) {}
} // namespace react
} // namespace facebook