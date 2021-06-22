
#include <Servo.h>

char blueToothVal;           //value sent over via bluetooth
char lastValue;              //stores last state of device (on/off)
const int motorPin3  = 6; // Pin  7 of L293
const int motorPin4  = 5;  // Pin  2 of L293
int servoPin = 10;
Servo motor;
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  motor.attach(10);
  motor.write(90);
}


void loop()
{
  if (Serial.available())
  { //if there is data being recieved
    blueToothVal = Serial.read(); //read it
  }
  if (blueToothVal == 'c')
  { //if value from bluetooth serial is n
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);          //switch on LED
    if (lastValue != 'c')
      Serial.println(F("clockwise")); //print LED is on
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'a')
  { //if value from bluetooth serial is n
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);           //turn off LED
    if (lastValue != 'a')
      Serial.println(F("anti-clockwise")); //print LED is on
    lastValue = blueToothVal;
  }
    else if (blueToothVal == 's')
  { //if value from bluetooth serial is n
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);           //turn off LED
    if (lastValue != 's')
      Serial.println(F("stopped")); //print LED is on
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'm')
  { //if value from bluetooth serial is n
    motor.write(120);           //turn off LED
    if (lastValue != 'm')
      Serial.println(F("small motor r")); //print LED is on
    lastValue = blueToothVal;
  }
    else if (blueToothVal == 'r')
  { //if value from bluetooth serial is n
    motor.write(60);           //turn off LED
    if (lastValue != 'r')
      Serial.println(F("small motor l")); //print LED is on
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'l')
  { //if value from bluetooth serial is n
    motor.write(90);           //turn off LED
    if (lastValue != 'l')
      Serial.println(F("small motor s")); //print LED is on
    lastValue = blueToothVal;
  }
  delay(1000);
}
