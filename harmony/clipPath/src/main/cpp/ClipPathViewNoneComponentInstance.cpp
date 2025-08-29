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

#include "ClipPathViewNoneComponentInstance.h"
#include "ModUtil.h"
#include <glog/logging.h>
namespace rnoh {
ClipPathViewNoneComponentInstance::ClipPathViewNoneComponentInstance(Context context)
    : CppComponentInstance(std::move(context)) {
    auto rnInstancePtr = this->m_deps->rnInstance.lock();
    if (rnInstancePtr != nullptr) {
        auto turboModule = rnInstancePtr->getTurboModule("RNCClipPathContext");
        auto arkTsTurboModule = std::dynamic_pointer_cast<rnoh::ArkTSTurboModule>(turboModule);
        folly::dynamic result = arkTsTurboModule->callSync("getDensity", {});
        ModUtil::setDensity(static_cast<float>(result.asDouble()));
    }
}
void ClipPathViewNoneComponentInstance::onChildInserted(ComponentInstance::Shared const &childComponentInstance,
                                                        std::size_t index) {
    CppComponentInstance::onChildInserted(childComponentInstance, index);
    mClipPathNode.insertChild(childComponentInstance->getLocalRootArkUINode(), index);
}

void ClipPathViewNoneComponentInstance::onChildRemoved(ComponentInstance::Shared const &childComponentInstance) {
    CppComponentInstance::onChildRemoved(childComponentInstance);
    mClipPathNode.removeChild(childComponentInstance->getLocalRootArkUINode());
};

ClipPathViewNoneNode &ClipPathViewNoneComponentInstance::getLocalRootArkUINode() { return mClipPathNode; }

void ClipPathViewNoneComponentInstance::onPropsChanged(SharedConcreteProps const &props) {
    CppComponentInstance::onPropsChanged(props);
    if (auto p = std::dynamic_pointer_cast<const facebook::react::RNCClipPathViewNoneProps>(props)) {
        mClipPathNode.setD(p->d);
        mClipPathNode.setViewBox(p->viewBox);
        if (p->translateZ != 0) {
            mClipPathNode.setTranslateZ(p->translateZ);
        }
        mClipPathNode.setAlign(p->align);
        mClipPathNode.setAspect(p->aspect);

        mClipPathNode.setStrokeCap(p->strokeCap);
        mClipPathNode.setStrokeJoin(p->strokeJoin);
        mClipPathNode.setStrokeWidth(p->strokeWidth);
        mClipPathNode.setStrokeMiter(p->strokeMiter);
        mClipPathNode.setStrokeStart(p->strokeStart);
        mClipPathNode.setStrokeEnd(p->strokeEnd);
        mClipPathNode.setFillRule(p->fillRule);

        if (p->rot != 0.0f) {
            mClipPathNode.setRot(p->rot);
        }
        if (p->rotO != 0.0f) {
            mClipPathNode.setRotO(p->rotO);
        }
        if (p->rotOx != 0.0f) {
            mClipPathNode.setRotOx(p->rotOx);
        }
        if (p->rotOy != 0.0f) {
            mClipPathNode.setRotOy(p->rotOy);
        }

        mClipPathNode.setRotPercentageValue(p->rotPercentageValue);
        if (p->sc != 1.0f) {
            mClipPathNode.setSc(p->sc);
        }
        if (p->scX != 1.0f) {
            mClipPathNode.setScX(p->scX);
        }
        if (p->scY != 1.0f) {
            mClipPathNode.setScY(p->scY);
        }

        if (p->scO != 0.0f) {
            mClipPathNode.setScO(p->scO);
        }
        if (p->scOx != 0.0f) {
            mClipPathNode.setScOx(p->scOx);
        }
        if (p->scOy != 0.0f) {
            mClipPathNode.setScOy(p->scOy);
        }
        mClipPathNode.setScPercentageValue(p->scPercentageValue);

        mClipPathNode.setTransX(p->transX);
        mClipPathNode.setTransY(p->transY);
        mClipPathNode.setTransPercentageValue(p->transPercentageValue);
    }
}
} // namespace rnoh