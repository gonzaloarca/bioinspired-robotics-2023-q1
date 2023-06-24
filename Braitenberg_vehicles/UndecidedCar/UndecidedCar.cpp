#include "Print.h"
#include "UndecidedCar.h"
#include "Motor.h"

int UndecidedCar::getLeftMotorSpeed()
{
  return rightMotorSpeed;
}

int UndecidedCar::getRightMotorSpeed()
{
  return leftMotorSpeed;
}

UndecidedCar::UndecidedCar(int stopDistance, int slowDownDistance)
{

  this->state = MOVE;
  this->stopDistance = stopDistance;
  this->slowDownDistance = slowDownDistance;
  leftMotorSpeed = 0;
  rightMotorSpeed = 0;
}

void UndecidedCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
{
  int speed = rightMotorSpeed;

  // no dobla
  switch (this->state)
  {
  case RETREAT:
    Serial.println("retreat");
    if (distance > slowDownDistance)
    {
      this->state = MOVE;

      rightMotorSpeed = 150;
      leftMotorSpeed = 200;
    }
    leftMotorSpeed = 150 - 255;
    rightMotorSpeed = 150 - 255;
    return;

  case MOVE:
    // checkeo choque
    if (distance < stopDistance)
    {
      // tengo que frenar y cambio de estado
      Serial.println("too close!");
      leftMotorSpeed = 0;
      rightMotorSpeed = 0;
      // change state
      this->state = RETREAT;
      return;
    }

    if (distance < slowDownDistance)
    {
      Serial.println("Slow down!");
      leftMotorSpeed = 100;
      rightMotorSpeed = 100;
      return;
    }
    Serial.println("Forward");
    speed = 200;
    leftMotorSpeed = 200;
    rightMotorSpeed = 180;
    return;

  default:
    return;
  }
}
