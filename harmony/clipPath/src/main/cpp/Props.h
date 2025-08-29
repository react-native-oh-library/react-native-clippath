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

#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_PROPS_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_PROPS_H

#include <jsi/jsi.h>
#include <react/renderer/components/view/ViewProps.h>
#include <react/renderer/core/PropsParserContext.h>
#include <react/renderer/core/propsConversions.h>

#include <vector>
namespace facebook {
namespace react {


class JSI_EXPORT RNCClipPathViewProps final : public ViewProps {
public:
    RNCClipPathViewProps() = default;
    RNCClipPathViewProps(const PropsParserContext &context, const RNCClipPathViewProps &sourceProps,
                         const RawProps &rawProps);

#pragma mark - Props
    std::string d;
    std::string aspect;
    std::string align{"xMidYMid"};
    std::string fillRule{"evenodd"};
    float strokeWidth{1.0};
    std::string strokeCap{"round"};
    std::string strokeJoin{"miter"};
    float strokeMiter{4.0};
    float strokeStart{0.0};
    float strokeEnd{1.0};

    float translateZ{0.0f};
    float transX = 0.f;
    float transY = 0.f;
    bool transPercentageValue = false;

    float rot = 0.f;
    float rotO = 0.f;
    float rotOx = 0.f;
    float rotOy = 0.f;
    bool rotPercentageValue = false;

    float sc = 1.f;
    float scX = 1.f;
    float scY = 1.f;
    float scO = 0.f;
    float scOx = 0.f;
    float scOy = 0.f;
    bool scPercentageValue = false;
    std::vector<float> viewBox{};
};

class JSI_EXPORT RNCClipPathViewNoneProps final : public ViewProps {
public:
    RNCClipPathViewNoneProps() = default;
    RNCClipPathViewNoneProps(const PropsParserContext &context, const RNCClipPathViewNoneProps &sourceProps,
                             const RawProps &rawProps);
#pragma mark - Props
    std::string d;
    std::string aspect;
    std::string align{"xMidYMid"};
    std::string fillRule{"evenodd"};
    float strokeWidth{1.0};
    std::string strokeCap{"round"};
    std::string strokeJoin{"miter"};
    float strokeMiter{4.0};
    float strokeStart{0.0};
    float strokeEnd{1.0};

    float translateZ{0.0f};
    float transX = 0.f;
    float transY = 0.f;
    bool transPercentageValue = false;

    float rot = 0.f;
    float rotO = 0.f;
    float rotOx = 0.f;
    float rotOy = 0.f;
    bool rotPercentageValue = false;

    float sc = 1.f;
    float scX = 1.f;
    float scY = 1.f;
    float scO = 0.f;
    float scOx = 0.f;
    float scOy = 0.f;
    bool scPercentageValue = false;
    std::vector<float> viewBox{};
};

} // namespace react
} // namespace facebook
#endif