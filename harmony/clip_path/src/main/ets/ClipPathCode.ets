
import { TViewBox, IViewPort, TChildrenBuilder } from './types'
import ListPanel from './ListPanel'

export const CLIP_PATH_TYPE: string = "ClipPath"

export interface ClipPathProps {
  color?: string;
  openClip?: boolean;
  fill?: string;
  stroke?: string;
  showProperty?: boolean;
  svgKey?: string;
  d?: string;
  viewBox?: TViewBox;
  strokeWidth?: number;
  strokeCap?: LineCapStyle;
  strokeJoin?: LineJoinStyle;
  strokeMiter?: number;
  strokeStart?: number;
  strokeEnd?: number;
  translateZ?: number;
  transX?: number;
  transY?: number;
  transPercentageValue?: boolean;
  rot?: number;
  rotO?: number;
  rotOx?: number;
  rotOy?: number;
  rotPercentageValue?: boolean;
  sc?: number;
  scX?: number;
  scY?: number;
  scO?: number;
  scOx?: number;
  scOy?: number;
  scPercentageValue?: boolean;
}

// export type ClipPathDescriptor = Descriptor<"ClipPath", ClipPathProps>

@Component
export struct ClipPathCode {
  @Prop color: ResourceColor = '';
  @Prop openClip: boolean = true;
  @Prop fill: ResourceColor = '';
  @Prop stroke: ResourceColor = '';
  @Prop showProperty: boolean = false;
  @Prop svgKey: string = '';
  @Prop d: string = '';
  @Prop viewBox: TViewBox = [0, 0, 0, 0];
  @Prop strokeWidth: number = 1;
  @Prop strokeCap: LineCapStyle = LineCapStyle.Butt;
  @Prop strokeJoin: LineJoinStyle = LineJoinStyle.Miter;
  @Prop strokeMiter: number = 4;
  @Prop strokeStart: number = 0;
  @Prop strokeEnd: number = 0;
  @Prop translateZ: number = 0;
  @Prop transX: number = 0;
  @Prop transY: number = 0;
  @Prop transPercentageValue: boolean = false;
  @Prop rot: number = 0;
  @Prop rotO: number = 0;
  @Prop rotOx: number = 0;
  @Prop rotOy: number = 0;
  @Prop rotPercentageValue: boolean = false;
  @Prop sc: number = 1;
  @Prop scX: number = 1;
  @Prop scY: number = 1;
  @Prop scO: number = 0;
  @Prop scOx: number = 0;
  @Prop scOy: number = 0;
  @Prop scPercentageValue: boolean = false;


  // ctx!: RNOHContext
  // tag: number = 0
  // @State descriptor: ClipPathDescriptor = {} as ClipPathDescriptor
  // @BuilderParam buildCustomComponent: (componentBuilderContext: ComponentBuilderContext) => void
  @BuilderParam childrenBuilder: TChildrenBuilder = this.defaultChildrenBuilder
  // private unregisterDescriptorChangesListener?: () => void = undefined
  @State propertyArr: Array<string> = [];

  // aboutToAppear() {
  //   this.descriptor = this.ctx.descriptorRegistry.getDescriptor<ClipPathDescriptor>(this.tag)
  //   this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
  //     (newDescriptor) => {
  //       this.descriptor = (newDescriptor as ClipPathDescriptor)
  //     }
  //   )
  //   this.propertyArr = Object.entries(this).map((item: Array<string>) => `${item[0]}: ${item[1]}`)
  // }

  // aboutToDisappear() {
  //   this.unregisterDescriptorChangesListener?.()
  // }

  computedShapeWidth(): string {
    const viewBox = this.computedViewBoxParam()
    return String(viewBox.width) || 'auto'
  }

  computedShapeHeight(): string {
    const viewBox = this.computedViewBoxParam()
    return String(viewBox.height) || 'auto'
  }

  computedClipParams(): PathAttribute | boolean {
    const openClip = this.openClip
    const d = this.d
    // const viewBox = this.computedViewBoxParam()
    return openClip ? new Path({ commands: d }) : false
  }
  computedViewBoxParam(): IViewPort {
    const viewBox = this.viewBox
    if (viewBox?.length !== 4) return {}
    // return {
    //   x: viewBox[0],
    //   y: viewBox[1],
    //   width: viewBox[2],
    //   height: viewBox[3]
    // }
    return {
      x: viewBox[0] + 'px',
      y: viewBox[1] + 'px',
      width: viewBox[2] + 'px',
      height: viewBox[3] + 'px'
    }
  }

  computedKey(): string {
    let key = this.svgKey || String(Date.now())
    return key
  }

  computedFill(): ResourceColor {
    let fill = this.fill || '#f00'
    return fill
  }

  computedStroke(): ResourceColor {
    let stroke = this.stroke || '#0ff'
    return stroke
  }

  computedStrokeWidth(): number {
    let strokeWidth = this.strokeWidth || 0
    return strokeWidth
  }

  computedStrokeMiter(): number {
    let strokeMiter = this.strokeMiter || 4
    return strokeMiter
  }

  computedStrokeCap(): LineCapStyle {
    let strokeCap = this.strokeCap || 'butt'
    if(String(strokeCap).toLowerCase() === "butt") return LineCapStyle.Butt
    if(String(strokeCap).toLowerCase() === "round") return LineCapStyle.Round
    if(String(strokeCap).toLowerCase() === "square") return LineCapStyle.Square
    return LineCapStyle.Butt
  }

  computedStrokeJoin(): LineJoinStyle {
    let strokeJoin = this.strokeJoin || 'miter'
    // bevel/miter/round
    if(String(strokeJoin).toLowerCase() === "miter") return LineJoinStyle.Miter
    if(String(strokeJoin).toLowerCase() === "round") return LineJoinStyle.Round
    if(String(strokeJoin).toLowerCase() === "bevel") return LineJoinStyle.Bevel
    return LineJoinStyle.Miter
  }

  computedTranslateZ(): number {
    let translateZ = this.translateZ || 1
    return translateZ
  }

  computedTranslateValue() {
    const transX = this.transX || 0
    const transY = this.transY || 0
    const transPercentageValue = this.transPercentageValue || false
    // let val: TranslateOptions = {
    //   x: transX || 0,
    //   y: transY || 0,
    //   z: 0
    // }
    let val: TranslateOptions = {
      x: `${transX}px`,
      y: `${transY}px`,
      z: 0
    }
    if (transPercentageValue) {
      val.x = `${transX}%`
      val.y = `${transY}%`
    }
    return val
  }

  computedRotateValue(): RotateOptions {
    const rot = this.rot || 0
    const rotO = this.rotO || 0
    const rotOx = this.rotOx || 0
    const rotOy = this.rotOy || 0
    const rotPercentageValue = this.rotPercentageValue || false
    let val = {
      angle: rot,
      centerX: rotO,
      centerY: rotO
    } as RotateOptions

    // if(rotOx || (rotOx === 0)){
    //   val.centerX = rotOx || 0
    // }
    // if(rotOy || (rotOy === 0)){
    //   val.centerY = rotOy || 0
    // }

    if (rotOx) {
      val.centerX = `${rotOx}px`
    }
    if (rotOy) {
      val.centerY = `${rotOy}px`
    }

    if (rotPercentageValue) {
      val.centerX = `${rotO}%`
      val.centerY = `${rotO}%`

      if (rotOx) {
        val.centerX = `${rotOx}%`
      }
      if (rotOy) {
        val.centerY = `${rotOy}%`
      }
    }

    const scaleConfig = this.computedScaleValue();
    if (rotO === 0 && rotOx === 0) {
      val.centerX = scaleConfig.centerX;
    }
    if (rotO === 0 && rotOy === 0) {
      val.centerY = scaleConfig.centerY;
    }
    return val
  }

  computedScaleValue(): RotateOptions {
    const sc = this.sc || 1
    const scX = this.scX || 1
    const scY = this.scY || 1
    const scO = this.scO || 0
    const scOx = this.scOx || 0
    const scOy = this.scOy || 0
    const scPercentageValue = this.scPercentageValue || false
    let val = {
      x: sc,
      y: sc,
      z: 1,
      centerX: `${scO}px`,
      centerY: `${scO}px`
    } as RotateOptions

    // if(scOx || (scOx === 0)){
    //   val.centerX = scOx || 0
    // }
    // if(scOy || (scOy === 0)){
    //   val.centerY = scOy || 0
    // }

    if (scX !== 1) {
      val.x = scX
    }
    if (scY !== 1) {
      val.y = scY
    }
    if (scOx) {
      val.centerX = `${scOx}px`
    }
    if (scOy) {
      val.centerY = `${scOy}px`
    }

    if (scPercentageValue) {
      val.centerX = `${scO}%`
      val.centerY = `${scO}%`
      if (scOx) {
        val.centerX = `${scOx}%`
      }
      if (scOy) {
        val.centerY = `${scOy}%`
      }
    }

    return val
  }

  @Builder
  defaultChildrenBuilder() {
  };

  // build() {
  //   Column() {
  //     if (this.showProperty) {
  //       ListPanel({
  //         arr: this.propertyArr
  //       })
  //     }
  //     Shape() {
  //       Path({
  //         commands: this.d
  //       })
  //       Column() {
  //         this.childrenBuilder()
  //         ForEach(this.descriptor.childrenTags, (tag: Tag) => {
  //           Column() {
  //             RNComponentFactory({ ctx: this.ctx, tag: tag, buildCustomComponent: this.buildCustomComponent })
  //           }
  //         }, (tag: Tag) => tag.toString())
  //       }
  //       .alignItems(HorizontalAlign.Start)
  //     }
  //     .key(this.computedKey())
  //     .viewPort(this.computedViewBoxParam())
  //     .fill(this.computedFill())
  //     .stroke(this.computedStroke())
  //     .strokeWidth(this.computedStrokeWidth())
  //     .strokeMiterLimit(this.computedStrokeMiter())
  //     .strokeLineCap(this.computedStrokeCap())
  //     .strokeLineJoin(this.computedStrokeJoin())
  //     .zIndex(this.computedTranslateZ())
  //     .translate(this.computedTranslateValue())
  //     .scale(this.computedScaleValue())
  //     .rotate(this.computedRotateValue())
  //     .clip(this.computedClipParams())
  //   }
  // }

  build() {
    // RNViewBase({ ctx: this.ctx, tag: this.tag }) {
    Column() {
      if (this.showProperty) {
        ListPanel({
          arr: this.propertyArr
        })
      }
      Shape() {
        Path({
          commands: this.d
        })
        Column() {
          this.childrenBuilder()
          // ForEach(this.descriptor.childrenTags, (tag: Tag) => {
          //   Column() {
          //     RNComponentFactory({ ctx: this.ctx, tag: tag, buildCustomComponent: this.buildCustomComponent })
          //   }
          // }, (tag: Tag) => tag.toString())
        }
        .alignItems(HorizontalAlign.Start)
        // .width('100%')
        // .height('100%')
        // .clip(true)
      }
      .width(this.computedShapeWidth())
      .height(this.computedShapeHeight())
      // .backgroundColor(Color.Pink)
      .key(this.computedKey())
      .viewPort(this.computedViewBoxParam())
      .fill(this.computedFill())
      .stroke(this.computedStroke())
      .strokeWidth(this.computedStrokeWidth())
      .strokeMiterLimit(this.computedStrokeMiter())
      .strokeLineCap(this.computedStrokeCap())
      .strokeLineJoin(this.computedStrokeJoin())
      .zIndex(this.computedTranslateZ())
      .translate(this.computedTranslateValue())
      .scale(this.computedScaleValue())
      .rotate(this.computedRotateValue())
      .clip(this.computedClipParams())
    }
  }
}
