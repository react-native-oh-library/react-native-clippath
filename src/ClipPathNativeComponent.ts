// @flow strict-local

import type { ViewProps } from "react-native/Libraries/Components/View/ViewPropTypes";
import type { HostComponent } from "react-native";
import codegenNativeComponent from "react-native/Libraries/Utilities/codegenNativeComponent";
import { Int32, WithDefault, Float } from "react-native/Libraries/Types/CodegenTypes"

export interface NativeProps extends ViewProps {
    color?: string;
    openClip?: WithDefault<boolean, true>;
    fill?: WithDefault<string, ''>;
    stroke?: WithDefault<string, ''>;
    showProperty?: WithDefault<boolean, false>;
  
    svgKey?: string;
    d?: string;
    viewBox?: Array<Int32>;
    align?: WithDefault<string, 'xMidYMid'>;
    aspect?: WithDefault<string, 'meet'>;
    fillRule?: WithDefault<string, 'nonzero'>;
    strokeWidth?: WithDefault<Int32, 1>;
    strokeCap?: WithDefault<string, 'butt'>;
    strokeJoin?: WithDefault<string, 'miter'>;
    strokeMiter?: WithDefault<Int32, 4>;
    strokeStart?: WithDefault<Int32, 0>;
    strokeEnd?: WithDefault<Int32, 1>;
    // children?: React.ReactElement;
    translateZ?: WithDefault<Int32, 0>;
    transX?: WithDefault<Int32, 0>;
    transY?: WithDefault<Int32, 0>;
    transPercentageValue?: WithDefault<boolean, false>;
    rot?: WithDefault<Int32, 0>;
    rotO?: WithDefault<Int32, 0>;
    rotOx?: WithDefault<Int32, 0>;
    rotOy?: WithDefault<Int32, 0>;
    rotPercentageValue?: WithDefault<boolean, false>;
    sc?: WithDefault<Float, 1>;
    scX?: WithDefault<Float, 1>;
    scY?: WithDefault<Float, 1>;
    scO?: WithDefault<Int32, 0>;
    scOx?: WithDefault<Int32, 0>;
    scOy?: WithDefault<Int32, 0>;
    scPercentageValue?: WithDefault<boolean, false>;
  }

export default codegenNativeComponent<NativeProps>(
  "ClipPath"
) as HostComponent<NativeProps>;