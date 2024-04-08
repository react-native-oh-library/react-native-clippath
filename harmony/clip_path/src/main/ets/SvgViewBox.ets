export interface IRect {
  left: number;
  top: number;
  right?: number;
  bottom?: number;
  width: number;
  height: number;
}

const MOS_MEET = 'meet';
const MOS_SLICE = 'slice';
const MOS_NONE = 'none';


const SVGViewBox = (vbRect: IRect, eRect: IRect, align: string, meetOrSlice: string) => {
  // based on https://svgwg.org/svg2-draft/coords.html#ComputingAViewportsTransform

  // Let vb-x, vb-y, vb-width, vb-height be the min-x, min-y, width and height values of the viewBox attribute respectively.
  const vbX = vbRect.left;
  const vbY = vbRect.top;
  // const vbX2 = vbRect.right;
  // const vbY2 = vbRect.bottom;
  // const vbWidth = vbX2 - vbX;
  // const vbHeight = vbY2 - vbY;
  const vbWidth = vbRect.width;
  const vbHeight = vbRect.height;

  // Let e-x, e-y, e-width, e-height be the position and size of the element respectively.
  const eX = eRect.left;
  const eY = eRect.top;
  // const eWidth = eRect.right - eRect.left;
  // const eHeight = eRect.bottom - eRect.top;
  const eWidth = eRect.width;
  const eHeight = eRect.height;


  // Initialize scale-x to e-width/vb-width.
  let scaleX = eWidth / vbWidth;

  // Initialize scale-y to e-height/vb-height.
  let scaleY = eHeight / vbHeight;

  // Initialize translate-x to e-x - (vb-x * scale-x).
  // Initialize translate-y to e-y - (vb-y * scale-y).
  let translateX = eX - (vbX * scaleX);
  let translateY = eY - (vbY * scaleY);


  //If align is 'none'
  if (meetOrSlice == MOS_NONE) {
    // Let scale be set the smaller value of scale-x and scale-y.
    // Assign scale-x and scale-y to scale.
    scaleX = scaleY = Math.min(scaleX, scaleY);
    translateX += (eWidth - vbWidth * scaleX) / 2.0;
    translateY += (eHeight - vbHeight * scaleY) / 2.0;


  } else {
    // If align is not 'none' and meetOrSlice is 'meet', set the larger of scale-x and scale-y to the smaller.
    // Otherwise, if align is not 'none' and meetOrSlice is 'slice', set the smaller of scale-x and scale-y to the larger.

    if (!(align === "none") && meetOrSlice == MOS_MEET) {
      scaleX = scaleY = Math.min(scaleX, scaleY);
    } else if (!(align === "none") && meetOrSlice == MOS_SLICE) {
      scaleX = scaleY = Math.max(scaleX, scaleY);
    }

    // If align contains 'xMid', add (e-width - vb-width * scale-x) / 2 to translate-x.
    if (align.includes("xMid")) {
      translateX += (eWidth - vbWidth * scaleX) / 2.0;
    }

    // If align contains 'xMax', add (e-width - vb-width * scale-x) to translate-x.
    if (align.includes("xMax")) {
      translateX += (eWidth - vbWidth * scaleX);
    }

    // If align contains 'yMid', add (e-height - vb-height * scale-y) / 2 to translate-y.
    if (align.includes("YMid")) {
      translateY += (eHeight - vbHeight * scaleY) / 2.0;
    }

    // If align contains 'yMax', add (e-height - vb-height * scale-y) to translate-y.
    if (align.includes("YMax")) {
      translateY += (eHeight - vbHeight * scaleY);
    }
  }


  // The transform applied to content contained by the element is given by
  // translate(translate-x, translate-y) scale(scale-x, scale-y).
  const result = [0, 0, 0, 0]
  result[0] = scaleX;
  result[1] = scaleY;
  result[2] = translateX;
  result[3] = translateY;

  return result;

}

export { SVGViewBox };
