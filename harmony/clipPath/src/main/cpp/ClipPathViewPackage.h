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

#ifndef HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWPACKAGE_H
#define HARMONY_CLIP_PATH_VIEW_SRC_MAIN_CPP_CLIPPATHVIEWPACKAGE_H

#include "RNCClipPathTurboModule.h"
#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "ClipPathViewNoneJSIBinder.h"
#include "ClipPathViewNoneNapiBinder.h"
#include "ClipPathViewJSIBinder.h"
#include "ClipPathViewNapiBinder.h"
#include "ClipPathViewNoneComponentInstance.h"
#include "ClipPathViewComponentInstance.h"

namespace rnoh {
    class ClipPathViewPackageComponentInstanceFactoryDelegate : public ComponentInstanceFactoryDelegate {
    public:
        using ComponentInstanceFactoryDelegate::ComponentInstanceFactoryDelegate;

        ComponentInstance::Shared create(ComponentInstance::Context ctx) override {
            if (ctx.componentName == "RNCClipPathView") {
                return std::make_shared<ClipPathViewComponentInstance>(std::move(ctx));
            } else if (ctx.componentName == "RNCClipPathViewNone") {
                return std::make_shared<ClipPathViewNoneComponentInstance>(std::move(ctx));
            }
            return nullptr;
        }
    };

    class RNCClipPathFactoryDelegate : public TurboModuleFactoryDelegate {
    public:
        SharedTurboModule createTurboModule(Context ctx, const std::string &name) const override {
            if (name == "RNCClipPathContext") {
                return std::make_shared<RNCClipPathTurboModule>(ctx, name);
            }
            return nullptr;
        };
    };

    class ClipPathViewPackage : public Package {
    public:
        ClipPathViewPackage(Package::Context ctx) : Package(ctx) {}

        ComponentInstanceFactoryDelegate::Shared createComponentInstanceFactoryDelegate() override {
            return std::make_shared<ClipPathViewPackageComponentInstanceFactoryDelegate>();
        }

        std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
            return {facebook::react::concreteComponentDescriptorProvider<
                facebook::react::RNCClipPathViewNoneComponentDescriptor>()};
        }

        std::unique_ptr<TurboModuleFactoryDelegate> createTurboModuleFactoryDelegate() override {
            return std::make_unique<RNCClipPathFactoryDelegate>();
        }
        ComponentJSIBinderByString createComponentJSIBinderByName() override {
            return {
                {"RNCClipPathViewNone", std::make_shared<ClipPathViewNoneJSIBinder>()},
                {"RNCClipPathView", std::make_shared<ClipPathViewJSIBinder>()},
            };
        }

        ComponentNapiBinderByString createComponentNapiBinderByName() override {
            return {
                {"RNCClipPathViewNone", std::make_shared<ClipPathViewNoneNapiBinder>()},
                {"RNCClipPathView", std::make_shared<ClipPathViewNapiBinder>()},
            };
        }
    };
} // namespace rnoh
#endif