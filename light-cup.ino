//* Light Cup

#include <LiquidCrystal.h>
#include <Servo.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int ledPinA = 9;
int switchPinA = 8;
int switchStateA = 0;
int ledPinB = 6;
int switchPinB = 7;
int switchStateB = 0;
int brightness   = 0;
Servo myservo;
int pos = 0;

void setup() 
{
  pinMode(ledPinA, OUTPUT); 
  pinMode(ledPinB, OUTPUT);  
  pinMode(switchPinA, INPUT); 
  pinMode(switchPinB, INPUT);
  myservo.attach(10);
  
  lcd.begin(16, 2);
  lcd.cursor();
}

void loop() 
{
  switchStateA = digitalRead(switchPinA);
  if (switchStateA == HIGH && brightness != 255)
  { 
   brightness ++;
   lcd.rightToLeft();   
   lcd.write(">> >> >> ");
   pos = 0;
   myservo.write(pos); 
  } 
  switchStateB = digitalRead(switchPinB);
  if (switchStateB == HIGH && brightness != 0)
  { 
   brightness --;   
   lcd.leftToRight();
   lcd.write("<< << << ");
   pos = 180;
   myservo.write(pos);
   
  } 
  analogWrite(ledPinA, brightness);
  analogWrite(ledPinB, 255 - brightness);
  delay(20);
}
