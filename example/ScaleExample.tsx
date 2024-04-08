import { View, Text, Image, ScrollView } from 'react-native'
import React from 'react'
import ClipPath from '@react-native-oh-tpl/clip-path'
import { myPath2,myPath3, myPath10, myPath11, myPath12 } from './paths'

export default function index() {
  const viewBox = [0, 0, 400, 400]
  const path = myPath12

  return (
    <ScrollView style={{ width: '100%', height: '100%'}}>
      <Text>sc: 1</Text>
      <ClipPath sc={1} viewBox={viewBox} d={myPath10} style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>sc: 0.5</Text>
      <ClipPath sc={0.5} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>sc: 2</Text>
      <ClipPath sc={2} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text></Text><Text></Text><Text></Text><Text></Text><Text></Text><Text></Text>
      <Text>--------------------------------------------</Text>
      <Text>sc: 0.5, scO: 200</Text>
      <ClipPath sc={0.5} scO={200} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>sc: 0.5, scO: 50, scPercentageValue: true</Text>
      <ClipPath sc={0.5} scO={50} scPercentageValue={true} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>scX: 0.5</Text>
      <ClipPath scX={0.5} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
      <Text>--------------------------------------------</Text>
      <Text>scY: 0.5</Text>
      <ClipPath scY={0.5} viewBox={viewBox} d={myPath10}  style={{ width: 200, height: 100, backgroundColor: '#ff0' }}>
        <Text>11111111111111111111111111111111111111111</Text>
        <Text>22222222222222222222222222222222222222222</Text>
      </ClipPath>
    </ScrollView>
  )
}