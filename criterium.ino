#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *steppermotor = AFMS.getStepper(200, 2);

volatile byte rpmcount;
int hallEffectSensorPin1 = 0;
int hallEffectSensorPin2 = 1;
int lightPin = 7;

void setup() {
  attachInterrupt(hallEffectSensorPin1, ping, RISING);
  attachInterrupt(hallEffectSensorPin2, ping, RISING);
  pinMode(lightPin, OUTPUT);
  AFMS.begin();
  rpmcount = 0;
  steppermotor->setSpeed(1);
}

void loop() {
  if (rpmcount>0) {
    digitalWrite(lightPin, HIGH);
  } else {
    digitalWrite(lightPin, LOW);
  }
  detachInterrupt(hallEffectSensorPin1);
  detachInterrupt(hallEffectSensorPin2);
  steppermotor->setSpeed(rpmcount);
  steppermotor->step(rpmcount,FORWARD,MICROSTEP);
  rpmcount = 0;
  attachInterrupt(hallEffectSensorPin1, ping, RISING);
  attachInterrupt(hallEffectSensorPin2, ping, RISING);
}

void ping()
{
  rpmcount++;
}
