// I2C 통신을 위한 라이브러리를 불러온다.
#include <Wire.h>

const int RandPin = 10;  // 랜덤하게 Led를 점등시킬 버튼

// 열의 수를 설정
const int numRows = 4;
// 행의 수를 설정
const int numCols = 4;

// 열과 행에 대하여 문자를 할당
char keys[numRows][numCols] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', 'A', 'B', 'C'},
  {'D', '0', '#', '*'},
};

// 열에 연결된 핀 번호
int rowPins[] = {2, 3, 4, 5};

// 행에 연결된 핀 번호
int colPins[] = {6, 7, 8, 9};

// 키패드에서 입력받은 값을 저장할 변수
char key;     

void setup() 
{   
  Wire.begin();       // Master임을 의미

  // 스위치 입력을 위하여 각 핀을 입력으로 설정하고 풀업.
  pinMode(RandPin, INPUT_PULLUP);

  //열을 입력 풀업 모드로 설정한다
  for(int i = 0; i < numRows; i++)
  {
    pinMode(rowPins[i], INPUT_PULLUP);
  }
  
  // 행을 출력 모드로 설정한다. 초기값을 HIGH로 설정
  for(int i = 0; i < numCols; i++)
  {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
  }
  Serial.begin(9600);
}

void loop()
{
  // 랜덤 푸쉬 버튼
  int RanStart = digitalRead(RandPin);
  if(RanStart == LOW)
  {
    delay(10); // 바운싱 방지를 위해 10ms 대기

    Serial.println("Random LED 점등");
        
    // 키를 놓을 때까지 기다린다
    while(digitalRead(RanStart) == LOW);       

    Wire.beginTransmission(2);                
    Wire.write('T');            
    Wire.endTransmission();
    delay(500);

    Wire.beginTransmission(1);                
    Wire.write('T');            
    Wire.endTransmission();
    delay(500);
  }
  
  key = keypadRead();    // keyPad에서 입력한 값을 key에 저장
  if(key)               // key의 값이 존재한다면
  {
    Serial.print(key);
    Serial.println("번 LED 점등");
  }

  // key의 값에 따라 다른 값을 I2C 통신을 통해 각 UNO에게 전달
   if( key == '1')
   {
     Wire.beginTransmission(2);                 
     Wire.write('1');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('1');
     Wire.endTransmission();
     delay(500);     
   }
   
   if( key == '2')
   {
     Wire.beginTransmission(2);                 
     Wire.write('2');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('2');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '3')
   {
     Wire.beginTransmission(2);                 
     Wire.write('3');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('3');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '4')
   {
     Wire.beginTransmission(2);                 
     Wire.write('4');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('4');
     Wire.endTransmission();
     delay(500);    
   } 
   if( key == '5')
   {
     Wire.beginTransmission(2);                 
     Wire.write('5');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('5');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '6')
   {
     Wire.beginTransmission(2);                 
     Wire.write('6');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('6');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '7')
   {
     Wire.beginTransmission(2);                 
     Wire.write('7');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('7');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '8')
   {
     Wire.beginTransmission(2);                 
     Wire.write('8');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('8');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '9')
   {
     Wire.beginTransmission(2);                 
     Wire.write('9');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('9');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == 'A')
   {
     Wire.beginTransmission(2);                 
     Wire.write('A');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('A');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == 'B')
   {
     Wire.beginTransmission(2);                 
     Wire.write('B');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('B');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == 'C')
   {
     Wire.beginTransmission(2);                 
     Wire.write('C');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('C');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == 'D')
   {
     Wire.beginTransmission(2);                 
     Wire.write('D');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('D');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '0')
   {
     Wire.beginTransmission(2);                 
     Wire.write('0');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('0');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '#')
   {
     Wire.beginTransmission(2);                 
     Wire.write('#');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('#');
     Wire.endTransmission();
     delay(500);    
   }
   if( key == '*')
   {
     Wire.beginTransmission(2);                 
     Wire.write('*');
     Wire.endTransmission();
     delay(500);

     Wire.beginTransmission(1);                 
     Wire.write('*');
     Wire.endTransmission();
     delay(500);    
   }                        
  
}

// 4x4키패드 입력 기본함수 
char keypadRead()
{ 
  char key = 0;

  for(int i = 0; i < numCols; i++)
  {
    // 행 중에 하나를 LOW로 설정
    digitalWrite(colPins[i], LOW);
    
    // 열을 하나씩 바꿔가면서 값을 Read
    for(int j = 0; j < numRows; j++)
    {
      // 열의 입력이 LOW일 때 키 입력이 발생
      if(digitalRead(rowPins[j]) == LOW)
      {
        delay(10); // 바운싱 방지를 위해 10ms 대기
        
        //키를 놓을 때까지 기다린다
        while(digitalRead(rowPins[j]) == LOW);
        
        //keys 상수에서 위치에 맞는 값을 대입
        key = keys[j][i];
      }
    }
    //LOW로 설정했던 행을 다시 HIGH로 설정
    digitalWrite(colPins[i], HIGH);
  }
  return key;
}
