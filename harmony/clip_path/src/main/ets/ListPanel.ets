@Component
export default struct  ListPanel {
  @Prop arr: Array<string|number> =  [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  private scrollerForScroll: Scroller = new Scroller()
  private scrollerForList: Scroller = new Scroller()
  build() {
    List({ space: 6, scroller: this.scrollerForList }) {
      ForEach(this.arr, (item: string | number) => {
        ListItem() {
          Text(String(item))
            .width("100%").height("100%").borderRadius(15)
            .fontSize(16).textAlign(TextAlign.Start).backgroundColor(Color.White)
        }.width("100%").padding(6)
      }, (item: string) => item)
    }
    .width("100%")
    .height('100%')
    .edgeEffect(EdgeEffect.None)
    .onReachStart(() => {
    })
    .onReachEnd(() => {
    })
  }
}