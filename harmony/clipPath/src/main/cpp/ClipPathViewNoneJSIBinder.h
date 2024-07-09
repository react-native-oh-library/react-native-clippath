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


#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWNONEJSIBINDER_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWNONEJSIBINDER_H

#include "RNOHCorePackage/ComponentBinders/ViewComponentJSIBinder.h"

namespace rnoh {
class ClipPathViewNoneJSIBinder : public ViewComponentJSIBinder {
    facebook::jsi::Object createNativeProps(facebook::jsi::Runtime &rt) override {
        auto object = ViewComponentJSIBinder::createNativeProps(rt);
        object.setProperty(rt, "d", "string");
        object.setProperty(rt, "viewBox", "array");
        object.setProperty(rt, "aspect", "string");
        object.setProperty(rt, "align", "string");
        object.setProperty(rt, "translateZ", "float");
        object.setProperty(rt, "fillRule", "string");
        object.setProperty(rt, "strokeWidth", "float");
        object.setProperty(rt, "strokeCap", "string");
        object.setProperty(rt, "strokeJoin", "string");
        object.setProperty(rt, "strokeMiter", "float");
        object.setProperty(rt, "strokeStart", "float");
        object.setProperty(rt, "strokeEnd", "float");

        object.setProperty(rt, "sc", "float");
        object.setProperty(rt, "scX", "float");
        object.setProperty(rt, "scY", "float");
        object.setProperty(rt, "scO", "float");
        object.setProperty(rt, "scOx", "float");
        object.setProperty(rt, "scOy", "float");
        object.setProperty(rt, "scPercentageValue", "float");

        object.setProperty(rt, "rot", "float");
        object.setProperty(rt, "rotO", "float");
        object.setProperty(rt, "rotOx", "float");
        object.setProperty(rt, "rotOy", "float");
        object.setProperty(rt, "rotPercentageValue", "bool");

        object.setProperty(rt, "transX", "float");
        object.setProperty(rt, "transY", "float");
        object.setProperty(rt, "transPercentageValue", "bool");

        return object;
    }
};
} // namespace  rnoh
#endif