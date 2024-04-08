export type TViewBox = [(number | string)?, (number | string)?, (number | string)?, (number | string)?]


export interface IViewPort {
  x?: number | string;
  y?: number | string;
  width?: number | string;
  height?: number | string;
}

export type TChildrenBuilder = () => void