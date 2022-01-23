// I2C 통신을 위한 라이브러리를 불러온다.
#include <Wire.h>

int latch = 2;                  // 74595의 latch Pin
int clock = 3;                  // 74595의 clock Pin
int data = 4;                   // 74595의 data Pin

// 74595에 연결되지 않은 LED들의 Pin 정의
int led5 = 5;                   
int led6 = 6;
int led7 = 7;
int led8 = 8;

int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;

int i = 0;                      // 반복문 변수

int QuArr[4] = {0, 0, 0, 0};     // 랜덤하게 나온 led 순서 저장 배열
int keyPadLedInt = 0;            // Master UNO에서 받은 Char 값을 Int로 저장하기 위한 변수

char ch;                        // I2C 통신을 통해 받은 값을 저장할 변수
  
void setup() 
{
  Wire.begin(2);    // Slave 주소
  Wire.onReceive(LedRutin);  // I2C 통신이 호출되면 괄호 안의 함수를 실행해주는 함수

  // 74595 모듈을 위한 핀 입력 설정
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);

  // 나머지 LED를 위한 핀 입력 설정 
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);

  Serial.begin(9600);
}

void loop() 
{
      
}

void light(int n)  // 74595에 연결되지 않는 LED를 켜기 위한 루틴
{  
  digitalWrite(n, HIGH);
  delay(100000);  
  digitalWrite(n, LOW);
  delay(100000);
}

void chipLedLight(int n)  // 74595에 연결된 LED를 켜기 위한 루틴
{
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, 1<<n);
  digitalWrite(latch, HIGH);
  
  delay(100000);
  
  digitalWrite(latch, LOW);
  shiftOut(data, clock, MSBFIRST, 0);
  digitalWrite(latch, HIGH);

  delay(100000);
}

void LedRutin()        // LED를 켜기 위한 함수
{
  Serial.print("KeyPad Number : "); 
  while (Wire.available()) 
  {
    ch = Wire.read();
    Serial.println(ch);
  }
  
  // led를 무작위로 켜는 루틴
  if(ch == 'T')
  {
    Serial.print("Random Number : ");
    for( i = 0; i < 4; i++)
    {     
      QuArr[i] = random(16) + 1;
      Serial.print(QuArr[i]);
      Serial.print(" ");
      
      if(QuArr[i] == 5 || QuArr[i] == 6 || QuArr[i] == 7 || QuArr[i] == 8)
      {
        light(QuArr[i]);
      }
    
      if(QuArr[i] == 9 || QuArr[i] == 10 || QuArr[i] == 11 || QuArr[i] == 12)
      {
        light(QuArr[i]);
      }  
  
      if(QuArr[i] == 1 || QuArr[i] == 2 || QuArr[i] == 3 || QuArr[i] == 4)  
      {
        chipLedLight(QuArr[i]-1);
      }
  
      if(QuArr[i] == 13 || QuArr[i] == 14 || QuArr[i] == 15 || QuArr[i] == 16)  
      {
        chipLedLight(QuArr[i]-9);
      }
    }
    Serial.println();
  }
  else      // Master UNO에서 넘겨받은 값은 Char 형이므로 Int 값으로 새로 설정하기 위한 루틴
  {
    switch(ch)
      {
        case '1':
                  keyPadLedInt = 1;
                  break;
  
        case '2':
                  keyPadLedInt = 2;
                  break;
          
        case '3':
                  keyPadLedInt = 3;
                  break;
  
        case '4':
                  keyPadLedInt = 4;
                  break;
          
        case '5':
                  keyPadLedInt = 13;
                  break;
          
        case '6':
                  keyPadLedInt = 14;
                  break;
  
        case '7':
                  keyPadLedInt = 15;
                  break;
  
        case '8':
                  keyPadLedInt = 16;
                  break;
          
        case '9':
                  keyPadLedInt = 5;
                  break;
  
        case 'A':
                  keyPadLedInt = 6;
                  break;
  
        case 'B':
                  keyPadLedInt = 7;
                  break;
  
        case 'C':
                  keyPadLedInt = 8;
                  break;
  
        case 'D':
                  keyPadLedInt = 9;
                  break;
  
        case '0':
                  keyPadLedInt = 10;
                  break;
  
        case '#':
                  keyPadLedInt = 11;
                  break;
  
        case '*':
                  keyPadLedInt = 12;
                  break;
      }

      // Int에 맞게 바꾼 다음 번호에 맞는 LED를 켜기
      if(keyPadLedInt == 5 || keyPadLedInt == 6 || keyPadLedInt == 7 || keyPadLedInt == 8)
      {
        light(keyPadLedInt);
      }
    
      if(keyPadLedInt == 9 || keyPadLedInt == 10 || keyPadLedInt == 11 || keyPadLedInt == 12)
      {
        light(keyPadLedInt);
      }  
  
      if(keyPadLedInt == 1 || keyPadLedInt == 2 || keyPadLedInt == 3 ||keyPadLedInt == 4)  
      {
        chipLedLight(keyPadLedInt - 1);
      }
  
      if(keyPadLedInt == 13 || keyPadLedInt == 14 || keyPadLedInt == 15 ||keyPadLedInt == 16)  
      {
        chipLedLight(keyPadLedInt - 9);
      }
  }
}
