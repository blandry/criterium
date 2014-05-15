#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *steppermotor = AFMS.getStepper(200, 2);

volatile byte rpmcount;
//int hallEffectSensor1 = 0;
int hallEffectSensor2 = 1;
int lightPin = 7;

void setup() {
//  attachInterrupt(hallEffectSensor1, ping, FALLING);
  attachInterrupt(hallEffectSensor2, ping, FALLING);
  pinMode(lightPin, OUTPUT);
  AFMS.begin();
  rpmcount = 0;
  steppermotor->setSpeed(1);
}

void loop() {
  if (rpmcount>0) {
//    detachInterrupt(hallEffectSensor1);
    detachInterrupt(hallEffectSensor2);    
    digitalWrite(lightPin, HIGH);
    steppermotor->step(5,FORWARD,MICROSTEP);
    rpmcount = 0;
//    attachInterrupt(hallEffectSensor1, ping, FALLING);
    attachInterrupt(hallEffectSensor2, ping, FALLING);
  } else {
    digitalWrite(lightPin, LOW);
  }
}

void ping()
{
  rpmcount++;
}
