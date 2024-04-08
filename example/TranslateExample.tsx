import { View, Text, ScrollView } from 'react-native'
import React from 'react'
import ClipPath from '@react-native-oh-tpl/clip-path'
import { myPath2,myPath3,myPath10, myPath11, myPath12 } from './paths'

export default function index() {
  const viewBox = [0, 0, 400, 400]
  const path = myPath12

  return (
    <ScrollView style={{ width: '100%', height: '100%'}}>
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