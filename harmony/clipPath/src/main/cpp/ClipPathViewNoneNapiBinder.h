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

#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWNONENAPIBINDER_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWNONENAPIBINDER_H
#include "RNOHCorePackage/ComponentBinders/ViewComponentNapiBinder.h"
#include "Props.h"

namespace rnoh {

    class ClipPathViewNoneNapiBinder : public ViewComponentNapiBinder {
    public:
        napi_value createProps(napi_env env, facebook::react::ShadowView const shadowView) override {
            napi_value napiViewProps = ViewComponentNapiBinder::createProps(env, shadowView);
            auto propsObjBuilder = ArkJS(env).getObjectBuilder(napiViewProps);

            if (auto props = std::dynamic_pointer_cast<const facebook::react::RNCClipPathViewNoneProps>(shadowView.props)) {
                propsObjBuilder.addProperty("d", props->d);
                propsObjBuilder.addProperty("aspect", props->aspect);
                propsObjBuilder.addProperty("align", props->align);
                propsObjBuilder.addProperty("translateZ", props->translateZ);
            
                propsObjBuilder.addProperty("fillRule", props->fillRule);
                propsObjBuilder.addProperty("strokeWidth", props->strokeWidth);
                propsObjBuilder.addProperty("strokeCap", props->strokeCap);
                propsObjBuilder.addProperty("strokeJoin", props->strokeJoin);
                propsObjBuilder.addProperty("strokeMiter", props->strokeMiter);
                propsObjBuilder.addProperty("strokeStart", props->strokeStart);
                propsObjBuilder.addProperty("strokeEnd", props->strokeEnd);
    
                propsObjBuilder.addProperty("sc", props->sc);
                propsObjBuilder.addProperty("scX", props->scX);
                propsObjBuilder.addProperty("scY", props->scY);
                propsObjBuilder.addProperty("scO", props->scO);
                propsObjBuilder.addProperty("scOx", props->scOx);
                propsObjBuilder.addProperty("scOy", props->scOy);
                propsObjBuilder.addProperty("scPercentageValue", props->scPercentageValue);
            
                propsObjBuilder.addProperty("rot", props->rot);
                propsObjBuilder.addProperty("rotO", props->rotO);
                propsObjBuilder.addProperty("rotOx", props->rotOx);
                propsObjBuilder.addProperty("rotOy", props->rotOy);
                   propsObjBuilder.addProperty("rotPercentageValue", props->rotPercentageValue);
            
              
                propsObjBuilder.addProperty("transX", props->transX);
                propsObjBuilder.addProperty("transY", props->transY);
                propsObjBuilder.addProperty("transPercentageValue", props->transPercentageValue);
                auto boxArray = std::vector<napi_value>();
                auto boxArrayRaw = props->viewBox;

                for (auto item : boxArrayRaw) {
                    auto itemObjBuilder = ArkJS(env).createDouble(item);
                    boxArray.push_back(itemObjBuilder);
                }

                auto boxArrayArray = ArkJS(env).createArray(boxArray);

                propsObjBuilder.addProperty("viewBox", boxArrayArray);

                return propsObjBuilder.build();
            }
            return napiViewProps;
        };
    };

} // namespace rnoh
#endif