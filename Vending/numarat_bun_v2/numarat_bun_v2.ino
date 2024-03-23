
#include <LiquidCrystal.h>
#include<Servo.h>
const int rs = 8, en = 9, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pinIr10p = 10;
const int pinIr50p = 2;
int IRvalue10p = 0;
int IRvalue50p = 0;
int buton1=0;
const float costProdus=250;
Servo servo50p;
Servo servo10p;
const int pinIrStart =10;
int pinMotor = 3;
int IRvalueStart = 0;

int coinCount = 0;
float MoneyWorth = 0;
int flag1;
int flag2;
int Rest=0;
int pos=0;
int nrRest50=0;
int nrRest10=0;
int copie;
#include "SPI.h"
/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
/* Create somewhere to store the message*/
String message = "BEEF";
/* Create an instance of the library */




void setup()
{
//  servo10p.attach(A2);
  servo50p.attach(A3);
  servo10p.attach(A2);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(3,INPUT);
  Serial.begin(9600);
  pinMode(pinIr10p,INPUT);
  pinMode(pinIrStart,INPUT);
  pinMode(pinMotor,OUTPUT);
   lcd.begin(16, 2);
  
 servo50p.write(180); 
 servo10p.write(80);
  
  //Welcome message
  byte Loopcounter;
  byte Position;

}

void loop()
{
  IRvalue10p = digitalRead(pinIr10p);
  IRvalue50p = digitalRead(pinIr50p);
  IRvalueStart = digitalRead(pinIrStart);
  char serialinput=Serial.read();
  digitalWrite(12,HIGH);
  digitalWrite(11,HIGH);
  if(digitalRead(13)==HIGH && digitalRead(3)==LOW)
  {
    if(MoneyWorth>250)
    {
      MoneyWorth=MoneyWorth-250;
      copie=MoneyWorth;
      nrRest50=copie/50;
      MoneyWorth=MoneyWorth-50*nrRest50;
      copie=MoneyWorth;
      servofunc50(nrRest50);
      nrRest10=copie/10;
      MoneyWorth=MoneyWorth-10*nrRest10;
      servofunc10(nrRest10); 
      Serial.write("1");
      displayAmountSerial();
     
    }
  }

  if(digitalRead(3)==HIGH && digitalRead(13)==LOW)
  {
    if(MoneyWorth>400)
    {
      MoneyWorth=MoneyWorth-400;
      copie=MoneyWorth;
      nrRest50=copie/50;
      MoneyWorth=MoneyWorth-50*nrRest50;
      copie=MoneyWorth;
      servofunc50(nrRest50);
      nrRest10=copie/10;
      MoneyWorth=MoneyWorth-10*nrRest10;
      servofunc10(nrRest10);
      Serial.write("2");
      displayAmountSerial();
    }
  }

  if ((IRvalue10p == 0) && (flag1 == 0)) {
    MoneyWorth = MoneyWorth + 10;
    displayAmountSerial();
    flag1=1;
    delay(200);
   }

  if (( IRvalue10p == 1) && (flag1 == 1)) {
    flag1=0;
   }

  if ((IRvalue50p == 0) && (flag2 == 0)) {
    MoneyWorth = MoneyWorth + 50;
    displayAmountSerial();
    flag2=1;
    delay(200);
   }

   if (( IRvalue50p == 1) && (flag2 == 1)) {
    flag2=0;
   }
 if(serialinput=='4'){
    MoneyWorth = MoneyWorth + 100;
    displayAmountSerial();
    Serial.write("3");
    delay(200);
  }
 if(serialinput=='5'){
    MoneyWorth = MoneyWorth + 500;
    displayAmountSerial();
    Serial.write("3");
    delay(200);
  }
}
void displayAmountSerial(){
  
    lcd.clear();
    /*
    Serial.print("Sunt ");
    Serial.print(coinCount);
    Serial.print(" banuti iar suma totala este : ");
    Serial.print(MoneyWorth/100);
    Serial.println("bani");
    Serial.println();
    */
    lcd.print("Credit: ");
    lcd.print(MoneyWorth/100);
    lcd.print(" RON");
}
void servofunc50(int count){
  for(int i=0;i<count;i++)
  {
   for (pos = 180; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo50p.write(pos);              // tell servo to go to position in variable 'pos'
   delay(3);                       // waits 15ms for the servo to reach the position
  } 
  for (pos = 80; pos <= 180; pos++) { 
    servo50p.write(pos);              
    delay(3);         
  }
  }
}
void servofunc10(int count){
  for(int i=0;i<count;i++)
  {
  for (pos = 80; pos <= 180; pos++) { 
    servo10p.write(pos);              
    delay(3);         
  }
  for (pos = 180; pos >= 80; pos -= 1) { // goes from 180 degrees to 0 degrees
    servo10p.write(pos);              // tell servo to go to position in variable 'pos'
   delay(3);                       // waits 15ms for the servo to reach the position
  } 
  }
}
