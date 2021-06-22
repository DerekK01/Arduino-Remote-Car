
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
  { 
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);          
    if (lastValue != 'c')
      Serial.println(F("clockwise")); 
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'a')
  { 
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);           
    if (lastValue != 'a')
      Serial.println(F("anti-clockwise")); 
    lastValue = blueToothVal;
  }
    else if (blueToothVal == 's')
  { 
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);           
    if (lastValue != 's')
      Serial.println(F("stopped")); 
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'm')
  { 
    motor.write(120);           
    if (lastValue != 'm')
      Serial.println(F("small motor r")); 
    lastValue = blueToothVal;
  }
    else if (blueToothVal == 'r')
  { 
    motor.write(60);           
    if (lastValue != 'r')
      Serial.println(F("small motor l")); 
    lastValue = blueToothVal;
  }
  else if (blueToothVal == 'l')
  { 
    motor.write(90);           
    if (lastValue != 'l')
      Serial.println(F("small motor s")); 
    lastValue = blueToothVal;
  }
  delay(1000);
}
