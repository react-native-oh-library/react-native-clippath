import { Descriptor, ComponentBuilderContext, ViewBaseProps, Tag } from 'rnoh';
import { RNComponentFactory, RNOHContext, RNViewBase } from 'rnoh'
import { TViewBox, IViewPort, TChildrenBuilder } from './types'
import ListPanel from './ListPanel'

export const CLIP_PATH_TYPE: string = "ClipPath"

export interface ClipPathProps extends ViewBaseProps {
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

export type ClipPathDescriptor = Descriptor<"ClipPath", ClipPathProps>

@Component
export struct ClipPath {
  ctx!: RNOHContext
  tag: number = 0
  @State descriptor: ClipPathDescriptor = {} as ClipPathDescriptor
  @BuilderParam buildCustomComponent: (componentBuilderContext: ComponentBuilderContext) => void
  @BuilderParam childrenBuilder: TChildrenBuilder = this.defaultChildrenBuilder
  private unregisterDescriptorChangesListener?: () => void = undefined
  @State propertyArr: Array<string> = [];

  aboutToAppear() {
    this.descriptor = this.ctx.descriptorRegistry.getDescriptor<ClipPathDescriptor>(this.tag)
    this.unregisterDescriptorChangesListener = this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (newDescriptor) => {
        this.descriptor = (newDescriptor as ClipPathDescriptor)
      }
    )
    console.log(`FG ${JSON.stringify(this.descriptor.props)}`)
    this.propertyArr = Object.entries(this.descriptor.props).map((item: Array<string>) => `${item[0]}: ${item[1]}`)
    console.log(`FG ${this.propertyArr}`)
    console.log(`FG ${JSON.stringify(this.descriptor)}`)
  }

  aboutToDisappear() {
    this.unregisterDescriptorChangesListener?.()
  }

  computedShapeWidth(): string {
    const viewBox = this.computedViewBoxParam()
    return String(viewBox.width) || 'auto'
  }

  computedShapeHeight(): string {
    const viewBox = this.computedViewBoxParam()
    return String(viewBox.height) || 'auto'
  }

  computedClipParams(): PathAttribute | boolean {
    const openClip = this.descriptor.props.openClip
    const d = this.descriptor.props.d
    // const viewBox = this.computedViewBoxParam()
    return openClip ? new Path({ commands: d }) : false
  }
  computedViewBoxParam(): IViewPort {
    const viewBox = this.descriptor.props.viewBox
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
    let key = this.descriptor.props.svgKey || String(Date.now())
    return key
  }

  computedFill(): ResourceColor {
    let fill = this.descriptor.props.fill || '#f00'
    return fill
  }

  computedStroke(): ResourceColor {
    let stroke = this.descriptor.props.stroke || '#0ff'
    return stroke
  }

  computedStrokeWidth(): number {
    let strokeWidth = this.descriptor.props.strokeWidth || 0
    return strokeWidth
  }

  computedStrokeMiter(): number {
    let strokeMiter = this.descriptor.props.strokeMiter || 4
    return strokeMiter
  }

  computedStrokeCap(): LineCapStyle {
    let strokeCap = this.descriptor.props.strokeCap || 'butt'
    if(String(strokeCap).toLowerCase() === "butt") return LineCapStyle.Butt
    if(String(strokeCap).toLowerCase() === "round") return LineCapStyle.Round
    if(String(strokeCap).toLowerCase() === "square") return LineCapStyle.Square
    return LineCapStyle.Butt
  }

  computedStrokeJoin(): LineJoinStyle {
    let strokeJoin = this.descriptor.props.strokeJoin || 'miter'
    // bevel/miter/round
    if(String(strokeJoin).toLowerCase() === "miter") return LineJoinStyle.Miter
    if(String(strokeJoin).toLowerCase() === "round") return LineJoinStyle.Round
    if(String(strokeJoin).toLowerCase() === "bevel") return LineJoinStyle.Bevel
    return LineJoinStyle.Miter
  }

  computedTranslateZ(): number {
    let translateZ = this.descriptor.props.translateZ || 1
    return translateZ
  }

  computedTranslateValue() {
    const transX = this.descriptor.props.transX || 0
    const transY = this.descriptor.props.transY || 0
    const transPercentageValue = this.descriptor.props.transPercentageValue || false
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
    const rot = this.descriptor.props.rot || 0
    const rotO = this.descriptor.props.rotO || 0
    const rotOx = this.descriptor.props.rotOx || 0
    const rotOy = this.descriptor.props.rotOy || 0
    const rotPercentageValue = this.descriptor.props.rotPercentageValue || false
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
    console.log(`FG rotate ${JSON.stringify(val)}`)
    return val
  }

  computedScaleValue(): RotateOptions {
    const sc = this.descriptor.props.sc || 1
    const scX = this.descriptor.props.scX || 1
    const scY = this.descriptor.props.scY || 1
    const scO = this.descriptor.props.scO || 0
    const scOx = this.descriptor.props.scOx || 0
    const scOy = this.descriptor.props.scOy || 0
    const scPercentageValue = this.descriptor.props.scPercentageValue || false
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

    console.log(`FG scale ${JSON.stringify(val)}`)
    return val
  }

  @Builder
  defaultChildrenBuilder() {
  };

  // build() {
  //   Column() {
  //     if (this.descriptor.props.showProperty) {
  //       ListPanel({
  //         arr: this.propertyArr
  //       })
  //     }
  //     Shape() {
  //       Path({
  //         commands: this.descriptor.props.d
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
    Column() {
      RNViewBase({ ctx: this.ctx, tag: this.tag }) {
        if (this.descriptor.props.showProperty) {
          ListPanel({
            arr: this.propertyArr
          })
        }
        Shape() {
          Path({
            commands: this.descriptor.props.d
          })
          Column() {
            this.childrenBuilder()
            ForEach(this.descriptor.childrenTags, (tag: Tag) => {
              Column() {
                RNComponentFactory({ ctx: this.ctx, tag: tag, buildCustomComponent: this.buildCustomComponent })
              }
            }, (tag: Tag) => tag.toString())
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
        // .zIndex(this.computedTranslateZ())
        .translate(this.computedTranslateValue())
        .scale(this.computedScaleValue())
        .rotate(this.computedRotateValue())
        .clip(this.computedClipParams())
      }
    }
    .zIndex(this.computedTranslateZ())
  }
}
