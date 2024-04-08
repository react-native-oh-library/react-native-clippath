#include "RNOHCorePackage/ComponentBinders/ViewComponentJSIBinder.h"

namespace rnoh {

    class ClipPathJSIBinder : public ViewComponentJSIBinder {
        facebook::jsi::Object createNativeProps(facebook::jsi::Runtime &rt) override {
            auto object = ViewComponentJSIBinder::createNativeProps(rt);
            object.setProperty(rt, "color", "string");
            object.setProperty(rt, "openClip", "boolean");
            object.setProperty(rt, "fill", "string");
            object.setProperty(rt, "stroke", "string");
            object.setProperty(rt, "showProperty", "boolean");
        
            object.setProperty(rt, "svgKey", "string");
            object.setProperty(rt, "d", "string");
            object.setProperty(rt, "viewBox", "array");
            object.setProperty(rt, "align", "string");
            object.setProperty(rt, "aspect", "string");
            object.setProperty(rt, "fillRule", "string");
            object.setProperty(rt, "strokeWidth", "int");
            object.setProperty(rt, "strokeCap", "string");
            object.setProperty(rt, "strokeJoin", "string");
            object.setProperty(rt, "strokeMiter", "int");
            object.setProperty(rt, "strokeStart", "int");
            object.setProperty(rt, "strokeEnd", "int");

            object.setProperty(rt, "translateZ", "int");
            object.setProperty(rt, "transX", "int");
            object.setProperty(rt, "transY", "int");
            object.setProperty(rt, "transPercentageValue", "boolean");
            object.setProperty(rt, "rot", "int");
            object.setProperty(rt, "rotO", "int");
            object.setProperty(rt, "rotOx", "int");
            object.setProperty(rt, "rotOy", "int");
            object.setProperty(rt, "rotPercentageValue", "boolean");
            object.setProperty(rt, "sc", "float");
            object.setProperty(rt, "scX", "float");
            object.setProperty(rt, "scY", "float");
            object.setProperty(rt, "scO", "int");
            object.setProperty(rt, "scOx", "int");
            object.setProperty(rt, "scOy", "int");
            object.setProperty(rt, "scPercentageValue", "boolean");


            return object;
        }
    };

} // namespace rnoh
