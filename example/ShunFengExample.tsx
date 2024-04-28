import React, { useRef, useState, useEffect, forwardRef } from 'react';
import { View, Text, StyleSheet, Image, Animated, Easing } from 'react-native';
import { ClipPathView, ClipPathViewH } from 'react-native-clippathview';
// import ClipPathView from '../lib/clippath.web'
import {
  myPath1,
  myPath2,
  myPath3,
  myPath4,
  myPath5,
  myPath6,
  myPath10,
  myPath11,
} from './paths';

const CustomView = React.forwardRef((props, ref) => {
  // some additional logic
  // console.log(StyleSheet.flatten(props.style))
  return (
    <View ref={ref} {...props}>
      <Text>custom view {props.d}</Text>

      <ClipPathViewH
        style={{
          zIndex: 1,
          backgroundColor: '#f00',
          width: 375,
          height: 300,
        }}
        d={props.d}></ClipPathViewH>
    </View>
  );
});

const WClipPathView = React.forwardRef((props, ref) => {
  const { style, ...otherProps } = props;
  // console.log('WClipPathView', style[0])
  console.log('WClipPathView', otherProps.d);
  useEffect(() => {
    console.log('ref', ref);
  }, [ref]);
  return (
    <ClipPathViewH ref={ref} style={style[0]} d={otherProps.d}></ClipPathViewH>
  );
});

const AniClipPathView = Animated.createAnimatedComponent(CustomView);

function Demo() {
  const [path, setPath] = useState('?');
  const offset = useRef(new Animated.Value(-400)).current;
  const headerViewHeight = 200;
  const screenWidth = 375;
  const ScreenConstant = {
    height: 400,
  };

  offset.addListener((value) => {
    console.log(`value: ${JSON.stringify(value)}`);
  });

  const generatePath = (arcDepth: number) => {
    return `M 0 0
      L 0 ${headerViewHeight + arcDepth}
      Q ${screenWidth / 2} ${headerViewHeight - arcDepth - 1}
        ${screenWidth} ${headerViewHeight + arcDepth}
      L ${screenWidth} 0
      L 0 0
      Z`;
  };

  const d = offset.interpolate({
    inputRange: [-headerViewHeight, -26, 0],
    outputRange: [generatePath(-26), generatePath(-26), generatePath(0)],
  });

  const translateY =
    offset.interpolate({
      inputRange: [
        -ScreenConstant.height,
        -headerViewHeight,
        0,
        ScreenConstant.height,
      ],
      outputRange: [headerViewHeight - ScreenConstant.height, 0, 0, 0],
    }) ?? 0;

  // const d = offset.interpolate({
  //   inputRange: [0, 1],
  //   outputRange: [1, 2],
  // });

  console.log(d);
  useEffect(() => {
    Animated.loop(
      Animated.timing(offset, {
        toValue: 1,
        duration: 5000,
        easing: Easing.linear,
        useNativeDriver: true,
      }),
      {
        iterations: -1,
      }
    ).start();
  }, [offset]);

  // const g1 = generatePath(-26);
  // console.log(g1);
  // const g2 = generatePath(0);
  // console.log(g2);

  return (
    <View>
      <Text>{JSON.stringify(d)}</Text>
      <AniClipPathView
        svgKey="1"
        style={{
          zIndex: 1,
          backgroundColor: '#ff0',
          width: 375,
          height: 600,
          // position: 'absolute',
          // flexDirection: 'column-reverse',
          transform: [
            {
              translateY: translateY,
            },
          ],
        }}
        d={d}></AniClipPathView>
      <ClipPathView
        svgKey="2"
        style={{
          zIndex: 1,
          backgroundColor: '#201E1E',
          width: 375,
          height: 60,
          // position: 'absolute',
          // flexDirection: 'column-reverse',
        }}
        d="M 0 0 L 0 14 Q 187.5 65 375 14 L 375 0 L 0 0 Z">
        <Image
          // style={styles.tinyLogo}
          style={{ width: '100%', height: '100%' }}
          source={{
            uri: 'https://www.sf-express.com/uploads/4047_1461_61d9908db1.jpg',
          }}
        />
      </ClipPathView>
    </View>
  );

  // return (
  //   <AnimatedClipPathView
  //       style={{
  //         zIndex: 1,
  //         backgroundColor: "#201E1E",
  //         width: 375,
  //         height: 60,
  //         position: "absolute",
  //         flexDirection: "column-reverse",
  //         transform: [
  //           {
  //             translateY:
  //               this.props.offset?.interpolate({
  //                 inputRange: [
  //                   -ScreenConstant.height,
  //                   -headerViewHeight,
  //                   0,
  //                   ScreenConstant.height
  //                 ],
  //                 outputRange: [
  //                   headerViewHeight - ScreenConstant.height,
  //                   0,
  //                   0,
  //                   0
  //                 ]
  //               }) ?? 0
  //           }
  //         ]
  //       }}
  //       d={offset?.interpolate({
  //         inputRange: [-headerViewHeight, -26, 0],
  //         outputRange: [generatePath(-26), generatePath(-26), generatePath(0)]
  //       })}
  // >

  // )
}

export default Demo;
