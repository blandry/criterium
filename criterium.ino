#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
//Adafruit_DCMotor *dcmotor = AFMS.getMotor(3);
Adafruit_StepperMotor *steppermotor = AFMS.getStepper(200, 1);

volatile byte rpmcount;
//unsigned int rpm;
//unsigned long timeold;
//unsigned int motorSpeed;

void setup() {
  attachInterrupt(0, ping, RISING);
  attachInterrupt(1, ping, RISING);
  rpmcount = 0;
//  rpm = 0;
//  timeold = 0;
  AFMS.begin();
//  dcmotor->setSpeed(0);
//  dcmotor->run(FORWARD);
  steppermotor->setSpeed(10);
//  Serial.begin(9600);
}

void loop() {
  //delay(10);
  detachInterrupt(0);
  detachInterrupt(1);
  steppermotor->setSpeed(rpmcount*100);

  steppermotor->step(rpmcount*10,FORWARD,MICROSTEP);
  //rpm = 30*100/(millis() - timeold)*rpmcount*0.1;
  //timeold = millis();
  rpmcount = 0;
  //motorSpeed = 255;
  //dcmotor->setSpeed(motorSpeed);
  //dcmotor->run(FORWARD);
  attachInterrupt(0, ping, RISING);
  attachInterrupt(1, ping, RISING);
  //Serial.print(rpm);
  //Serial.print("\n");
}

void ping()
{
  rpmcount++;
}
