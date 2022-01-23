# LED_Game  ![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
# 아두이노 UNO - I2C 통신

#### Project nickname : LED_Game
#### Project execution period : 2021.04.02 ~ 2020.04.30
-----------------------
## Description
아두이노 UNO 3개를 사용하여 각 부품을 연결한 후 I2C 통신을 이용하여 각 아두이노 UNO에 값을 전달하여 동작을 수행

## 1. 소스코드 세부 내용
|소스코드|기능|
|------|---|
|Master_UNO_KeyPad_Switch|랜덤하게 LED 점등시키는 스위치와 각 버튼과 대응되는 LED를 점등시킬 키패드를 설정하는 프로그램이다. 키패드나 스위치를 입력했을 때 I2C 통신을 통해 Slave UNO에 특정한 문자를 전달|
|SlaveOne_Rtc_Lcd|LCD 설정 프로그램이며, RTC 모듈을 통해 날짜를 입력받고 출력한다. 또 Master UNO에서 I2C 통신으로 문자를 받고, 받으면 ‘Wire.onReceive(result)’ 가 실행되며, 괄호 안에 있는 함수를 실행하고 값에 따라 해당하는 문자열을 LCD에 출력|
|SlaveTwo_74595Chip_LED|LED 설정 프로그램이다. Master UNO에서 값을 받고 ‘Wire.onReceive(result)’에서 함수를 받아서 그 함수를 실행하고 값에 따라 LED를 랜덤하게 키거나 특정 LED를 점등|

## 2. Flowchart




## Environment

> Arduino Sketches (Window)
> 
> Arduino UNO x 3
>
> Switch
>
> 4x4 KeyPad
>
> 74HC595
>
> LED x 16
>
> LCD 1602
>
> RTC Module


## Prerequisite
> Download source code
> 
> Connect the parts
>
> Run from Arduino Sketches
