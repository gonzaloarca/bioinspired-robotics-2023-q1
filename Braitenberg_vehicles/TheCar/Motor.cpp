#include "Motor.h"
#include <Arduino.h>

void Motor::setDirection(Direction dir)
{
  switch (dir)
  {
  case FORWARD:
    digitalWrite(directionControlPin1, HIGH);
    digitalWrite(directionControlPin2, LOW);
  case BACKWARD:
    digitalWrite(directionControlPin1, LOW);
    digitalWrite(directionControlPin2, HIGH);
  case STOPPED:
  default:
    digitalWrite(directionControlPin1, LOW);
    digitalWrite(directionControlPin2, LOW);
  }
}

Motor::Motor(int speedControlPin, int dirControlPin1, int dirControlPin2, int maxSpeed)
{
  this->speedControlPin = speedControlPin;
  this->directionControlPin1 = dirControlPin1;
  this->directionControlPin2 = dirControlPin2;
  this->maxSpeed = maxSpeed;
  pinMode(speedControlPin, OUTPUT);
  pinMode(directionControlPin1, OUTPUT);
  pinMode(directionControlPin2, OUTPUT);
}

void Motor::setSpeed(int speed)
{
  if (speed > 0)
  {
    setDirection(FORWARD);
  }
  else if (speed < 0)
  {
    setDirection(BACKWARD);
  }
  else
  {
    setDirection(STOPPED);
  }

  analogWrite(speedControlPin, map(speed, 0, 255, 0, maxSpeed));
}
