import { RNComponentContext, RNViewBase, DescriptorWrapper, RNComponentFactory, Tag } from '@rnoh/react-native-openharmony';
import {CustomComponentBuilder} from '@rnoh/react-native-openharmony/src/main/ets/RNOH'
// import codegen 生成的内容
import { RNC } from "@rnoh/react-native-openharmony/generated";


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

@Component
export struct ClipPath {
  public static readonly NAME = RNC.ClipPath.NAME
  public ctx!: RNComponentContext
  public tag: number = 0
  @State private descriptorWrapper: RNC.ClipPath.DescriptorWrapper = {} as RNC.ClipPath.DescriptorWrapper
  private eventEmitter: RNC.ClipPath.EventEmitter | undefined = undefined
  private cleanUpCallbacks: (() => void)[] = []
  @BuilderParam childrenBuilder: TChildrenBuilder = this.defaultChildrenBuilder

  @BuilderParam public buildCustomComponent: CustomComponentBuilder
  @State private childrenTags: Tag[] = []
  @State propertyArr: Array<string> = [];

  aboutToAppear() {
    this.eventEmitter = new RNC.ClipPath.EventEmitter(this.ctx.rnInstance, this.tag)
    this.onDescriptorWrapperChange(this.ctx.descriptorRegistry.findDescriptorWrapperByTag<RNC.ClipPath.DescriptorWrapper>(this.tag)!)
    this.cleanUpCallbacks.push(this.ctx.descriptorRegistry.subscribeToDescriptorChanges(this.tag,
      (_descriptor, newDescriptorWrapper) => {
        this.onDescriptorWrapperChange(newDescriptorWrapper! as RNC.ClipPath.DescriptorWrapper)
      }
    ))

    const props = this.descriptorWrapper.props
    console.log(`FG 1.1 ${JSON.stringify(props)}`)
    this.propertyArr = Object.entries(props).map((item: Array<string>) => `${item[0]}: ${item[1]}`)
    console.log(`FG 2 ${this.propertyArr}`)
    console.log(`FG 3 ${JSON.stringify(this.descriptorWrapper)}`)
  }
  
  private onDescriptorWrapperChange(descriptorWrapper: RNC.ClipPath.DescriptorWrapper) {
    this.descriptorWrapper = descriptorWrapper
    this.childrenTags = descriptorWrapper.childrenTags
  }

  aboutToDisappear() {
    this.cleanUpCallbacks.forEach(cb => cb())
  }


  computedShapeWidth(): string {
    const viewBox = this.descriptorWrapper.props.viewBox;
    const width = viewBox && viewBox[2] ? viewBox[2] : 0;
    if (width) {
      return `${width}px`
    }
    return ''
  }

  computedShapeHeight(): string {
    const viewBox = this.descriptorWrapper.props.viewBox;
    const height = viewBox && viewBox[3] ? viewBox[3] : 0;
    if (height) {
      return `${height}px`
    }
    return ''
  }

  computedClipParams(): PathAttribute | boolean {
    const openClip = this.descriptorWrapper.props.openClip
    const d = this.descriptorWrapper.props.d
    // const viewBox = this.computedViewBoxParam()
    return openClip ? new Path({ commands: d }) : false
  }

  computedViewBoxParam(): IViewPort {
    const viewBox = this.descriptorWrapper.props.viewBox
    if (viewBox?.length !== 4) return {}
    return {
      x: viewBox[0] + 'px',
      y: viewBox[1] + 'px',
      width: viewBox[2] + 'px',
      height: viewBox[3] + 'px'
    }
  }

  computedKey(): string {
    let key = this.descriptorWrapper.props.svgKey || String(Date.now())
    return key
  }

  computedFill(): ResourceColor {
    let fill = this.descriptorWrapper.props.fill || Color.Transparent
    return fill
  }

  computedStroke(): ResourceColor {
    let stroke = this.descriptorWrapper.props.stroke || Color.Transparent
    return stroke
  }

  computedStrokeWidth(): number {
    let strokeWidth = this.descriptorWrapper.props.strokeWidth || 0
    return strokeWidth
  }

  computedStrokeMiter(): number {
    let strokeMiter = this.descriptorWrapper.props.strokeMiter || 4
    return strokeMiter
  }

  computedStrokeCap(): LineCapStyle {
    let strokeCap = this.descriptorWrapper.props.strokeCap || 'butt'
    if(String(strokeCap).toLowerCase() === "butt") return LineCapStyle.Butt
    if(String(strokeCap).toLowerCase() === "round") return LineCapStyle.Round
    if(String(strokeCap).toLowerCase() === "square") return LineCapStyle.Square
    return LineCapStyle.Butt
  }

  computedStrokeJoin(): LineJoinStyle {
    let strokeJoin = this.descriptorWrapper.props.strokeJoin || 'miter'
    // bevel/miter/round
    if(String(strokeJoin).toLowerCase() === "miter") return LineJoinStyle.Miter
    if(String(strokeJoin).toLowerCase() === "round") return LineJoinStyle.Round
    if(String(strokeJoin).toLowerCase() === "bevel") return LineJoinStyle.Bevel
    return LineJoinStyle.Miter
  }

  computedTranslateZ(): number {
    let translateZ = this.descriptorWrapper.props.translateZ || 1
    return translateZ
  }

  computedTranslateValue() {
    const transX = this.descriptorWrapper.props.transX || 0
    const transY = this.descriptorWrapper.props.transY || 0
    const transPercentageValue = this.descriptorWrapper.props.transPercentageValue || false

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
    const rot = this.descriptorWrapper.props.rot || 0
    const rotO = this.descriptorWrapper.props.rotO || 0
    const rotOx = this.descriptorWrapper.props.rotOx || 0
    const rotOy = this.descriptorWrapper.props.rotOy || 0
    const rotPercentageValue = this.descriptorWrapper.props.rotPercentageValue || false
    let val = {
      angle: rot,
      centerX: rotO,
      centerY: rotO
    } as RotateOptions

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
    const sc = this.descriptorWrapper.props.sc || 1
    const scX = this.descriptorWrapper.props.scX || 1
    const scY = this.descriptorWrapper.props.scY || 1
    const scO = this.descriptorWrapper.props.scO || 0
    const scOx = this.descriptorWrapper.props.scOx || 0
    const scOy = this.descriptorWrapper.props.scOy || 0
    const scPercentageValue = this.descriptorWrapper.props.scPercentageValue || false
    let val = {
      x: sc,
      y: sc,
      z: 1,
      centerX: `${scO}px`,
      centerY: `${scO}px`
    } as RotateOptions

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

  build() {
    Column() {
      RNViewBase({ ctx: this.ctx, tag: this.tag }) {
        if (this.descriptorWrapper.props.showProperty) {
          ListPanel({
            arr: this.propertyArr
          })
        }
        Shape() {
          Path({
            commands: this.descriptorWrapper.props.d
          })
          Column() {
            this.childrenBuilder()
            if (this.ctx instanceof RNComponentContext) {
              LazyForEach(this.ctx.createComponentDataSource({ tag: this.tag }),
                (descriptorWrapper: DescriptorWrapper) => {
                  (this.ctx as RNComponentContext).wrappedRNComponentBuilder.builder((this.ctx as RNComponentContext), descriptorWrapper.tag)
                },
                (descriptorWrapper: DescriptorWrapper) => descriptorWrapper.tag.toString() + "@" + descriptorWrapper.renderKey
              )
            } else {
              ForEach(this.childrenTags, (childrenTag: Tag) => {
                RNComponentFactory({ ctx: this.ctx, tag: childrenTag, buildCustomComponent: this.buildCustomComponent })
              }, (childrenTag: Tag) => childrenTag.toString())
            }
          }
          .alignItems(HorizontalAlign.Start)
        }
        .width(this.computedShapeWidth())
        .height(this.computedShapeHeight())
        .key(this.computedKey())
        .viewPort(this.computedViewBoxParam())
        .fill(this.computedFill())
        .stroke(this.computedStroke())
        .strokeWidth(this.computedStrokeWidth())
        .strokeMiterLimit(this.computedStrokeMiter())
        .strokeLineCap(this.computedStrokeCap())
        .strokeLineJoin(this.computedStrokeJoin())
        .translate(this.computedTranslateValue())
        .scale(this.computedScaleValue())
        .rotate(this.computedRotateValue())
        .clip(this.computedClipParams())
      }
    }
    .zIndex(this.computedTranslateZ())
  }
}
