// main index.js
// import ClipPath from 'react-native-clippathview/src/ClipPath'
// import ClipPathH from 'react-native-clippathview/src/ClipPathH'
// export const ClipPathViewH = ClipPathH
// export const ClipPathView = ClipPath

import React from 'react';
import ClipPathNativeComponent from './src/ClipPathNativeComponent';

const ClipPath = React.forwardRef((props, ref) => {
    const { style, ...otherProps } = props;
    const { backgroundColor, ...otherStyle } = style;
    let newProps = { ...otherProps, style: otherStyle };
    if (backgroundColor) {
        newProps.fill = backgroundColor;
    }
    return (
        <ClipPathNativeComponent ref={ref} {...newProps}></ClipPathNativeComponent>
    )
})
export {
    ClipPath as ClipPathView
}
export default ClipPath
