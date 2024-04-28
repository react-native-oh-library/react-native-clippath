import { RNPackage } from '@rnoh/react-native-openharmony/ts';
import type {
  DescriptorWrapperFactoryByDescriptorTypeCtx,
  DescriptorWrapperFactoryByDescriptorType
} from '@rnoh/react-native-openharmony/ts';
import { RNC } from "@rnoh/react-native-openharmony/generated/ts"

export class ClipPathPackage extends RNPackage {
  createDescriptorWrapperFactoryByDescriptorType(ctx: DescriptorWrapperFactoryByDescriptorTypeCtx): DescriptorWrapperFactoryByDescriptorType {
    return {
      [RNC.ClipPath.NAME]: (ctx) => new RNC.ClipPath.DescriptorWrapper(ctx.descriptor)
    }
  }
}


// 根 ts.ts
export * from "./src/main/ets/ClipPathPackage";

// 根 index.ts
export * from "./ts";
export * from './src/main/ets/ClipPath'

