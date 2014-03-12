#include <Stepper.h>
#include <Servo.h> 

Servo myservo1;
Servo myservo2;
int pos = 55; 
int direction = 1;

const int stepsPerRevolution = 200;
Stepper myStepper(stepsPerRevolution, 3, 4, 5, 6);
int stepperSpeed = 10; // rpm
int steps = 1;

const int pingPin = 2;
long distance;

void setup() {
  myStepper.setSpeed(stepperSpeed);
  myservo1.attach(8); 
  myservo2.attach(9);  
}

void loop()
{
  for(pos = 55; pos <= 125; pos += 1) 
  {                                 
    myservo1.write(pos);
    myservo2.write(pos);
    distance = readDistance();
    myStepper.setSpeed(distance);
    myStepper.step(1);    
  } 
  for(pos = 125; pos>=55; pos-=1) 
  {                                
    myservo1.write(pos);
    myservo2.write(pos); 
    distance = readDistance();
    myStepper.setSpeed(distance);
    myStepper.step(1);
  } 
}

long readDistance()
{ 
  long duration, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  return cm;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

