import { View, Text, ScrollView } from 'react-native'
import React from 'react'
import ClipPath from '@react-native-oh-tpl/clip-path'
import { myPath2,myPath3,myPath10, myPath11, myPath12 } from './paths'

export default function index() {
  const viewBox = [0, 0, 400, 400]
  const path = myPath12

  return (
    <ScrollView style={{ width: '100%', height: '100%'}}>
      <Text>默认 translateZ</Text>
      <ClipPath viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 150,  }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <ClipPath viewBox={viewBox} d={myPath10} fill="#0f0" style={{ width: 200, height: 150,  position: 'absolute', top: 30, left: 20 }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>

      <View>   
      <Text>红色 translateZ: 2, 绿色 translateZ: 1</Text>
      <ClipPath  translateZ={2} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 150,  }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <ClipPath translateZ={1} viewBox={viewBox} d={myPath10} fill="#0f0" style={{ width: 200, height: 150,  position: 'absolute', top: 30, left: 20 }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      </View> 

      <Text>--------------------------------------------</Text>
      <Text>transX:0, transY: 0</Text>
      <ClipPath transX={0} transY={0} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>transX:200</Text>
      <ClipPath transX={200} transY={0} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>transX:50, transPercentageValue: true</Text>
      <ClipPath transX={50} transPercentageValue={true} transY={0} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>transY: 200</Text>
      <ClipPath transY={200} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text></Text><Text></Text><Text></Text><Text></Text><Text></Text>
      <Text>--------------------------------------------</Text>
      <Text>transY: 50, transPercentageValue: true</Text>
      <ClipPath transY={50} transPercentageValue={true} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text></Text><Text></Text><Text></Text><Text></Text><Text></Text>
      <Text>--------------------------------------------</Text>
      <Text>transX: 200, transY: 200</Text>
      <ClipPath transX={200} transY={200} viewBox={viewBox} d={myPath10} fill="#f00" style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM</Text>
      </ClipPath>
      <Text></Text><Text></Text><Text></Text><Text></Text><Text></Text>
    </ScrollView>
  )
}