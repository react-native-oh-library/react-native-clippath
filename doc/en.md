> Template version：v0.2.2

<p align="center">
  <h1 align="center"> <code>react-native-clippathview</code> </h1>
</p>
<p align="center">
        <a href="https://github.com/Only-IceSoul/react-native-clippath/blob/main">
        <img src="https://img.shields.io/badge/platforms-android%20|%20ios%20|%20harmony%20-lightgrey.svg" alt="Supported platforms" />
    </a>
    <a href="https://github.com/Only-IceSoul/react-native-clippath/blob/main/LICENSE">
        <img src="https://img.shields.io/badge/license-MIT-green.svg" alt="License" />
    </a>
</p>



> [!TIP] [Github address](https://github.com/react-native-oh-library/react-native-clippath)

## Installation and Usage

Find the matching version information in the release address of a third-party library：[@react-native-oh-tpl/react-native-clippathview Releases](https://github.com/react-native-oh-library/react-native-clippath/releases).For older versions that are not published to npm, please refer to the [installation guide](/en/tgz-usage-en.md) to install the tgz package.

Go to the project directory and execute the following instruction:


<!-- tabs:start -->

#### **npm**

```bash
npm install @react-native-oh-tpl/react-native-clippathview
```

#### **yarn**

```bash
yarn add @react-native-oh-tpl/react-native-clippathview
```

<!-- tabs:end -->

The following code shows the basic use scenario of the repository:

```jsx
import { View, Text, ScrollView } from "react-native";
import React from "react";
import { ClipPathView } from "react-native-clippathview";

export default function index() {
  const viewBox = [0, 0, 400, 400];
  const path = "M 0 0 L 400 0 L 0 400 L 400 400 Z";

  return (
    <ScrollView style={{ width: "100%", height: "100%" }}>
      <ClipPathView d={path} style={{ backgroundColor: "#ff0" }}>
        <Text style={{ height: 800, fontSize: 26 }}>
          MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM
        </Text>
      </ClipPathView>
    </ScrollView>
  );
}
```

## Constraints

### Compatibility

To use this repository, you need to use the correct React-Native and RNOH versions. In addition, you need to use DevEco Studio and the ROM on your phone.

Check the release version information in the release address of the third-party library:[@react-native-oh-tpl/react-native-clippathview Releases](https://github.com/react-native-oh-library/react-native-clippath/releases)

## Use Codegen

If this repository has been adapted to `Codegen`, generate the bridge code of the third-party library by using the `Codegen`. For details, see [Codegen Usage Guide](/en/codegen.md).

## Link

Currently, HarmonyOS does not support AutoLink. Therefore, you need to manually configure the linking.

Open the `harmony` directory of the HarmonyOS project in DevEco Studio.

### 1. Adding the overrides Field to oh-package.json5 File in the Root Directory of the Project

```json
{
  ...
  "overrides": {
    "@rnoh/react-native-openharmony" : "./react_native_openharmony"
  }
}
```

### 2.Introducing Native Code

Currently, two methods are available:

1. (Recommended) Use the HAR file.
2. Directly link to the source code.

Method 1 (recommended): Use the HAR file.

> [!TIP] The HAR file is stored in the harmony directory in the installation path of the third-party library.

Open entry/oh-package.json5 file and add the following dependencies:

```json
"dependencies": {
    "rnoh": "file:../rnoh",
    "@react-native-oh-library/react-native-clippathview": "file:../../node_modules/@react-native-oh-tpl/react-native-clippathview/harmony/clip_path.har",
}
```

Click the sync button in the upper right corner.

Alternatively, run the following instruction on the terminal:

```bash
cd entry
ohpm install
```

Method 2: Directly link to the source code.

> [!TIP] For details, see[Directly Linking Source Code](/en/link-source-code.md)

### 3.Introducing ClipPath component to Arkts

Find * * function buildCustoms Component () * *, usually located in ` entry/src/main/ets/pages/index. ets ` or ` entry/src/main/ets/rn/LoadBundle. ets `, and add the following code:

```diff
...
+ import { ClipPath } from '@react-native-oh-library/react-native-clippathview';

@Builder
function buildCustomComponent(ctx: ComponentBuilderContext) {
  if (ctx.componentName === SAMPLE_VIEW_TYPE) {
    SampleView({
      ctx: ctx.rnComponentContext,
      tag: ctx.tag,
      buildCustomComponent: buildCustomComponent
    })
  }
+ else if (ctx.componentName === ClipPath.NAME) {
+   ClipPath({
+     ctx: ctx.rnComponentContext,
+     tag: ctx.tag,
+   })
+ }
 ...
}
...
```

### 4. Introducing  ClipPathPackage to ArkTS

Open the  `entry/src/main/ets/RNPackagesFactory.ts` file and add the following code:

```diff
import type {RNPackageContext, RNPackage} from 'rnoh/ts';
import {SamplePackage} from 'rnoh-sample-package/ts';
+ import { ClipPathPackage } from '@react-native-oh-library/react-native-clippathview/ts'

export function createRNPackages(ctx: RNPackageContext): RNPackage[] {
  return [
    new SamplePackage(ctx),
+   new ClipPathPackage(ctx)
  ];
}
```

### 5.Running

Click the `sync` button in the upper right corner.

Alternatively, run the following instruction on the terminal:

```bash
cd entry
ohpm install
```

Then build and run the code.

## Properties

> [!TIP] The **Platform** column indicates the platform where the properties are supported in the original third-party library.

> [!TIP] If the value of **HarmonyOS Support** is **yes**, it means that the HarmonyOS platform supports this property; **no** means the opposite; **partially** means some capabilities of this property are supported. The usage method is the same on different platforms and the effect is the same as that of iOS or Android.

| Name                 | Description                                                  | Type              | Required | Platform    | HarmonyOS Support |
| -------------------- | ------------------------------------------------------------ | ----------------- | -------- | ----------- | ----------------- |
| svgKey               | Unique key.                                                     | string            | No       | iOS/Android | Yes               |
| d                    | Path shape defined by a series of commands (SVG path data).                       | string            | No       | iOS/Android | Yes               |
| viewBox              | Defines the position and dimensions in user space.                                  | Array<Number>(4)  | No       | iOS/Android | Yes               |
| align                | **align** of the **preserveAspectRatio**                            | string            | No       | iOS/Android | No                |
| aspect               | **meetOrSlice** of the **preserveAspectRatio**                       | meet/slice/none   | No       | iOS/Android | No                |
| fillRule             | Path fill rule.                                             | nonzero/evenodd   | No       | iOS/Android | No                |
| strokeWidth          | Path stroke width.                                                 | number            | No       | iOS/Android | Yes               |
| strokeCap            | Shape of the ends of open paths.                                           | butt/round/square | No       | iOS/Android | Yes               |
| strokeJoin           | Shape used at corners of paths.                                         | bevel/miter/round | No       | iOS/Android | Yes               |
| strokeMiter          | Miter length when **strokeJoin** is **miter**.                           | number            | No       | iOS/Android | Yes               |
| strokeStart          | Percentage of the starting point of the **CAShapeLayer** stroke to the total path on iOS. The default value is **0**. | number            | No       | iOS/Android | No                |
| strokeEnd            | Percentage of the ending point of the **CAShapeLayer** stroke to the total path on iOS. The default value is **1**. If the value is less than or equal to that of **strokeStart**, no content is drawn. | number            | No       | iOS/Android | No                |
| translateZ           | Sets the positioning layer depth (similar to index).  index                                   | number            | No       | iOS/Android | Yes               |
| transX               | Horizontal translation in a 2D plane.                                   | number            | No       | iOS/Android | Yes               |
| transY               | Vertical translation in a 2D plane.                                  | number            | No       | iOS/Android | Yes               |
| transPercentageValue | Whether **transX** and **transY** use percentage values.                                     | boolean           | No       | iOS/Android | Yes               |
| rot                  | Rotation of an element around a specific point.                                          | number            | No       | iOS/Android | Yes               |
| rotOx                | Horizontal position of the rotation origin.                                            | number            | No       | iOS/Android | Yes               |
| rotOy                | Vertical position of the rotation origin.                                           | number            | No       | iOS/Android | Yes               |
| rotPercentageValue   |  Whether **rotOx** and **rotOy** use percentage values.                                       | boolean           | No       | iOS/Android | Yes               |
| sc                   | Uniform scaling of an element.                                               | number            | No       | iOS/Android | Yes               |
| scX                  | 水平缩放                                                     | number            | No       | iOS/Android | Yes               |
| scY                  | X-axis scaling.                                                     | number            | No       | iOS/Android | Yes               |
| scO                  | Scaling origin point.                                                | number            | No       | iOS/Android | Yes               |
| scOx                 | Horizontal position of the scaling origin.                                           | number            | No       | iOS/Android | Yes               |
| scOy                 | Vertical position of the scaling origin.                                           | number            | No       | iOS/Android | Yes               |
| scPercentageValue    | Whether **scO**, **scOx**, and **scOy** use percentage values.                                   | boolean           | No       | iOS/Android | Yes               |

## Known Issues

- [ ] Some attributes are currently not supported in the current version. Please refer to the 'HarmonyOS' column in the attribute table for details: [issue # 15](https://github.com/react-native-oh-library/react-native-clippath/issues/15)

## Others

## License

This project is licensed under [The MIT License (MIT)](https://github.com/Only-IceSoul/react-native-clippath/blob/main/LICENSE) .

---
