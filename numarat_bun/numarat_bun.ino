

#include <LiquidCrystal.h>
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int pinIr10p = 10;
const int pinIr50p = 2;
int IRvalue10p = 0;
int IRvalue50p = 0;



const int pinIrStart =10;
int pinMotor = 3;
int IRvalueStart = 0;

int coinCount = 0;
int MoneyWorth = 0;
int flag1;
int flag2;

#include "SPI.h"
/* Set the LOAD (CS) digital pin number*/
#define LOAD 10
/* Create somewhere to store the message*/
String message = "BEEF";
/* Create an instance of the library */




void setup()
{
  Serial.begin(9600);
  pinMode(pinIr10p,INPUT);
  pinMode(pinIrStart,INPUT);
  pinMode(pinMotor,OUTPUT);
   lcd.begin(16, 2);

   lcd.print("hello, world!");
  
  //Welcome message
  byte Loopcounter;
  byte Position;

}

void loop()
{
  IRvalue10p = digitalRead(pinIr10p);
  IRvalue50p = digitalRead(pinIr50p);
  IRvalueStart = digitalRead(pinIrStart);
  


 //  if (IRvalueStart == 0) {
 //   Serial.println("Coin detected. Starting motor...");
 //   digitalWrite(pinMotor, HIGH);
 //   delay(200);
 //  }
   


   if ((IRvalue10p == 0) && (flag1 == 0)) {
    Serial.println("10 bani:)  ");
    coinDetected();
    MoneyWorth = MoneyWorth + 10;
    displayAmountSerial();
    flag1=1;
    delay(200);
   }

        if (( IRvalue10p == 1) && (flag1 == 1)) {
      flag1=0;
}

   if ((IRvalue50p == 0) && (flag2 == 0)) {
    Serial.println("50 bani:)  ");
    coinDetected();
    MoneyWorth = MoneyWorth + 50;
    displayAmountSerial();
    flag2=1;
    delay(200);
   }

        if (( IRvalue50p == 1) && (flag2 == 1)) {
      flag2=0;
}

}
void displayAmountSerial(){
  
  Serial.print("Sunt ");
    Serial.print(coinCount);
    Serial.print(" banuti iar suma totala este : ");
    Serial.print(MoneyWorth);
    Serial.println("bani");
    Serial.println();
}

void coinDetected() {
    coinCount ++;
    digitalWrite(pinMotor, LOW);
}
