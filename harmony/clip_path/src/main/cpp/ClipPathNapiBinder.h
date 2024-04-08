#include "RNOHCorePackage/ComponentBinders/ViewComponentNapiBinder.h"
#include "Props.h"

namespace rnoh {

    class ClipPathNapiBinder : public ViewComponentNapiBinder {
    public:
        napi_value createProps(napi_env env, facebook::react::ShadowView const shadowView) override {
            napi_value napiViewProps = ViewComponentNapiBinder::createProps(env, shadowView);
            if (auto props = std::dynamic_pointer_cast<const facebook::react::ClipPathProps>(shadowView.props)) {
                auto propsObjBuilder = ArkJS(env).getObjectBuilder(napiViewProps);

                auto viewBox = std::vector<napi_value>();
                auto viewBoxRaw = props->viewBox;
                for (auto viewBoxItem : viewBoxRaw) {
                    //                     auto viewBoxItemObjBuilder = ArkJS(env).createObjectBuilder();
                    //                     viewBoxItemObjBuilder.addProperty("viewBoxItem",viewBoxItem);
                    //                     viewBox.push_back(viewBoxItemObjBuilder.build());
                    auto viewBoxItemInt = ArkJS(env).createInt(viewBoxItem);
                    viewBox.push_back(viewBoxItemInt);
                }
                auto viewBoxArray = ArkJS(env).createArray(viewBox);


                propsObjBuilder.addProperty("color", props->color);
                propsObjBuilder.addProperty("openClip", props->openClip);
                propsObjBuilder.addProperty("fill", props->fill);
                propsObjBuilder.addProperty("stroke", props->stroke);
                propsObjBuilder.addProperty("showProperty", props->showProperty);

                propsObjBuilder.addProperty("svgKey", props->svgKey);
                propsObjBuilder.addProperty("d", props->d);
                propsObjBuilder.addProperty("viewBox", viewBoxArray);
                propsObjBuilder.addProperty("align", props->align);
                propsObjBuilder.addProperty("aspect", props->aspect);
                propsObjBuilder.addProperty("fillRule", props->fillRule);
                propsObjBuilder.addProperty("strokeWidth", props->strokeWidth);
                propsObjBuilder.addProperty("strokeCap", props->strokeCap);
                propsObjBuilder.addProperty("strokeJoin", props->strokeJoin);
                propsObjBuilder.addProperty("strokeMiter", props->strokeMiter);
                propsObjBuilder.addProperty("strokeStart", props->strokeStart);
                propsObjBuilder.addProperty("strokeEnd", props->strokeEnd);
                propsObjBuilder.addProperty("translateZ", props->translateZ);
                propsObjBuilder.addProperty("transX", props->transX);
                propsObjBuilder.addProperty("transY", props->transY);
                propsObjBuilder.addProperty("transPercentageValue", props->transPercentageValue);
                propsObjBuilder.addProperty("rot", props->rot);
                propsObjBuilder.addProperty("rotO", props->rotO);
                propsObjBuilder.addProperty("rotOx", props->rotOx);
                propsObjBuilder.addProperty("rotOy", props->rotOy);
                propsObjBuilder.addProperty("rotPercentageValue", props->rotPercentageValue);
                propsObjBuilder.addProperty("sc", props->sc);
                propsObjBuilder.addProperty("scX", props->scX);
                propsObjBuilder.addProperty("scY", props->scY);
                propsObjBuilder.addProperty("scO", props->scO);
                propsObjBuilder.addProperty("scOx", props->scOx);
                propsObjBuilder.addProperty("scOy", props->scOy);
                propsObjBuilder.addProperty("scPercentageValue", props->scPercentageValue);

                return propsObjBuilder.build();
                //                 return ArkJS(env)
                //                     .getObjectBuilder(napiViewProps)
                //                     .addProperty("color", props->color)
                //                     .addProperty("d", props->d)
                //                     .build();
            }
            return napiViewProps;
        };
    };

} // namespace rnoh