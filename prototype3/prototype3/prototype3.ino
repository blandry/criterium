#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *dcmotor = AFMS.getMotor(1);

volatile byte rpmcount;
unsigned int rpm;
unsigned long timeold;

void setup() {
  attachInterrupt(0, ping, RISING);
  rpmcount = 0;
  rpm = 0;
  timeold = 0;
  AFMS.begin();
  dcmotor->setSpeed(0);
  dcmotor->run(FORWARD);  
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  detachInterrupt(0);
  // .5 is because there are 2 sensors
  rpm = 30*1000/(millis() - timeold)*rpmcount*0.5;
  timeold = millis();
  rpmcount = 0;
  dcmotor->setSpeed(rpm);
  dcmotor->run(FORWARD);
  attachInterrupt(0, ping, RISING);
  Serial.print(rpm);
  Serial.print("\n");
}

void ping()
{
  rpmcount++;
}
