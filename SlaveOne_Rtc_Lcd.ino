// I2C 통신을 위한 라이브러리를 불러온다.
#include <Wire.h>

// DS1302 라이브러리를 불러온다
#include <DS1302.h>

// LCD 모듈 라이브러리를 불러온다
#include <LiquidCrystal.h>

char ch;

// DS1302 핀 설정
const int CEPin = 10;
const int IOPin = 9;
const int CLKPin = 8;

//LCD 설정
// LiquidCrystal(rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // LCD값 초기화

// DS1302 모듈을 rtc 오브젝트로 설정
DS1302 rtc(CEPin, IOPin, CLKPin);

// DS1302에서 읽어낸 데이터 중 day 값으로 요일을 설정한다
String dayAsString(const Time::Day day)
{
  switch(day)
  {
    case Time::kSunday: return "Sun";
    case Time::kMonday: return "Mon";
    case Time::kTuesday: return "Tue";
    case Time::kWednesday: return "Wed";
    case Time::kThursday: return "Thu";
    case Time::kFriday: return "Fri";
    case Time::kSaturday: return "Sat";
  }
  return "(nuknown day)";
}

void setup()
{
  Wire.begin(1);                  // Slave 주소
  Wire.onReceive(result);         // I2C 통신이 호출되면 괄호 안의 함수를 실행해주는 함수
  
 // 16×2 LCD 설정
  lcd.begin(16, 2);
  
  // rtc에 쓰기방지 OFF, 정지기능 OFF
  rtc.writeProtect(false);
  rtc.halt(false);

  // 입력하고자 하는 시간을 적는다
  // 2021년 4월 30일 0시 0분 0초 금요일 로 설정한다
  Time t(2021, 4, 30, 00, 00, 00, Time::kFriday);

  // 현재의 시간을 DS1302에 입력한다
  rtc.time(t);

  Serial.begin(9600);
}

void loop()
{
  FirstGameLcd(); //*첫줄: 현재 요일, 날짜 *둘째줄: Game Start
}

void FirstGameLcd()
{
  // DS1302로 부터 현재 시간을 읽어온다
  Time t = rtc.time();

  //day 데이터를 요일로 변경한다
  const String day = dayAsString(t.day);
  lcd.clear();

  // 현재 요일 날짜 시간 순서대로 시리얼 통신으로 출력한다
  lcd.setCursor(0,0);
  lcd.print(day.c_str());
  lcd.print(" ");
  lcd.print(t.yr);
  lcd.print("-");
  lcd.print(t.mon);
  lcd.print("-");
  lcd.print(t.date);
    
  lcd.setCursor(0,1); //두 번째줄 첫 번째 칸으로 커서 이동
  lcd.println("LED Game");
  
  delay(1000);
}

void result() //전송 데이터 읽기
{ 
  while (Wire.available()) 
  { 
    ch = Wire.read();        
  } 

  if( ch == 'T')          // Master에서 입력받은 값이 'T'이면 
  {
    Serial.println("LED Random Flash");
    lcd.clear();
    lcd.setCursor(0,0); //두 번째줄 첫 번째 칸으로 커서 이동 
    lcd.print("LED Random Flash");
    delay(630000);
  }
  else                   // Master에서 입력받은 값이 'T'가 아닌 다른 값이면 
  {
    Serial.print(ch);
    Serial.println(" LED Flashing");
    lcd.clear();
    lcd.setCursor(0,0); 
    lcd.print(ch);
    lcd.setCursor(2,0); 
    lcd.print("LED Flashing");
    delay(20000); 
  }
}
