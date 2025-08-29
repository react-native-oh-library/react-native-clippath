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

#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_SHADOWNODES_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_SHADOWNODES_H

#pragma once

#include <react/renderer/components/view/ConcreteViewShadowNode.h>
#include <react/renderer/components/view/ViewShadowNode.h>
#include <jsi/jsi.h>
#include "Props.h"

namespace facebook {
namespace react {

JSI_EXPORT extern const char RNCClipPathViewComponentName[];
JSI_EXPORT extern const char RNCClipPathViewNoneComponentName[];

/*
 * `ShadowNode` for <RTNCenteredText> component.
 */
using RNCClipPathViewShadowNode =
    ConcreteViewShadowNode<RNCClipPathViewComponentName, RNCClipPathViewProps, ViewEventEmitter>;
using RNCClipPathViewNoneShadowNode =
    ConcreteViewShadowNode<RNCClipPathViewNoneComponentName, RNCClipPathViewNoneProps, ViewEventEmitter>;
} // namespace react
} // namespace facebook
#endif