#include "Print.h"
#include "FearCar.h"
#include "Motor.h"

int FearCar::getLeftMotorSpeed()
{
  return rightMotorSpeed;
}

int FearCar::getRightMotorSpeed()
{
  return leftMotorSpeed;
}

FearCar::FearCar(int stopDistance, int slowDownDistance)
{
  this->stopDistance = stopDistance;
  this->slowDownDistance = slowDownDistance;
  leftMotorSpeed = 0;
  rightMotorSpeed = 0;
}

void FearCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
{
  Serial.print("[DEBUG]= leftPrV: ");
  Serial.print(leftPhotoresistorValue);
  Serial.print(" rightPrv: ");
  Serial.println(rightPhotoresistorValue);

  if (distance < stopDistance)
  {
    Serial.println("too close!");
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
    return;
  }
  if (distance < slowDownDistance)
  {
    Serial.println("Slow down!");
    leftMotorSpeed /= 4;
    rightMotorSpeed /= 4;
    // int speed = map(distance, stopDistance, slowDownDistance, 50, Motor::MAX_SPEED_INPUT);
    // leftMotorSpeed = speed;
    // rightMotorSpeed = speed;
    return;
  }

  Serial.println("Im  fearful");
  rightMotorSpeed = map(rightPhotoresistorValue, 0, 1023, 0, 255);

  leftMotorSpeed = map(leftPhotoresistorValue, 0, 1023, 0, 255);

  leftMotorSpeed = constrain(leftMotorSpeed * 1.25, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed * 1.25, 0, 255);
}
