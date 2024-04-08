#include "RNOH/Package.h"
#include "ComponentDescriptors.h"
#include "ClipPathJSIBinder.h"
#include "ClipPathNapiBinder.h"

namespace rnoh {

    class ClipPathPackage : public Package {
    public:
        ClipPathPackage(Package::Context ctx) : Package(ctx) {}

        std::vector<facebook::react::ComponentDescriptorProvider> createComponentDescriptorProviders() override {
            return {facebook::react::concreteComponentDescriptorProvider<
                facebook::react::ClipPathComponentDescriptor>()};
        }

        ComponentNapiBinderByString createComponentNapiBinderByName() override {
            return {{"ClipPath", std::make_shared<ClipPathNapiBinder>()}};
        }

        ComponentJSIBinderByString createComponentJSIBinderByName() override {
            return {{"ClipPath", std::make_shared<ClipPathJSIBinder>()}};
        }
    };
} // namespace rnoh
