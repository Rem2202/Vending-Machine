const int motor1_enable = 3;
const int motor1_dir = 5;

const int motor2_enable = 6;
const int motor2_dir = 9;

#include <NewPing.h>
const int trigPin = 31;
const int echoPin = 30;

int sensor1_pin = A15;
int sensor2_pin = A14;
int sensor3_pin = A13;
int sensor4_pin = A12;

int sensor_threshold = 500; // ajustați această valoare în funcție de condițiile de iluminare
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

void setup() {
  pinMode(motor1_enable, OUTPUT);
  pinMode(motor1_dir, OUTPUT);
  pinMode(motor2_enable, OUTPUT);
  pinMode(motor2_dir, OUTPUT);

  pinMode(sensor1_pin, INPUT);
  pinMode(sensor2_pin, INPUT);
  pinMode(sensor3_pin, INPUT);
  pinMode(sensor4_pin, INPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  analogWrite(motor1_enable, 255);
  analogWrite(motor2_enable, 255);
  Serial.begin(9600);
}

void fata(int viteza_motor1,int viteza_motor2)
{
    analogWrite(motor1_enable, viteza_motor1);
    analogWrite(motor2_enable, viteza_motor2);
    digitalWrite(motor1_dir, LOW);
    digitalWrite(motor2_dir, LOW);
}

void spate(int viteza_motor1,int viteza_motor2)
{
    analogWrite(motor1_enable, viteza_motor1);
    analogWrite(motor2_enable, viteza_motor2);
    digitalWrite(motor1_dir, HIGH);
    digitalWrite(motor2_dir, HIGH);
}

void opreste()
{
  
    analogWrite(motor1_enable, 0);
    analogWrite(motor2_enable, 0);

}


void dreapta()
{
    analogWrite(motor1_enable, 200);
    analogWrite(motor2_enable, 10);
    digitalWrite(motor1_dir, LOW);
    digitalWrite(motor2_dir, HIGH);
}


void stanga()
{
    analogWrite(motor1_enable, 10);
    analogWrite(motor2_enable, 200);
    digitalWrite(motor1_dir, HIGH);
    digitalWrite(motor2_dir, LOW);
}



void loop() {
  int sensor1_value = analogRead(sensor1_pin);
  int sensor2_value = analogRead(sensor2_pin);
  int sensor3_value = analogRead(sensor3_pin);
  int sensor4_value = analogRead(sensor4_pin);

Serial.print("Sensor1(dreapta): ");
Serial.print(sensor1_value);
Serial.print(" Sensor2: ");
Serial.print(sensor2_value);
Serial.print(" Sensor3: ");
Serial.print(sensor3_value);
Serial.print(" Sensor4: ");
Serial.print(sensor4_value);
Serial.print("\n");

delay(1000);
int distance = sonar.ping_cm();
  if (distance < 10) {
    Serial.println("Object detected!");
    opreste();
    
  }

    delay(100);
  }
  
