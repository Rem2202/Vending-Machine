#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
char serialinput  = ' ';
int pos = 0;    // variable to store the servo position

void setup() {
 myservo.attach(A3);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
}

void loop() {
 
   if(Serial.available())
   {
      /*char serialinput = Serial.read();
      if (serialinput =='1') 
      { servofunc(); }
      Serial.println(serialinput);
      */
     
   } 
   servofunc();
}
void servofunc(){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // waits 15ms for the servo to reach the position
  }
}
