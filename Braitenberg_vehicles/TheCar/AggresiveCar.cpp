#include "Print.h"
#include "AggresiveCar.h"
#include "Motor.h"

int AggresiveCar::getLeftMotorSpeed()
{
  return leftMotorSpeed;
}

int AggresiveCar::getRightMotorSpeed()
{
  return rightMotorSpeed;
}

AggresiveCar::AggresiveCar(int stopDistance, int slowDownDistance)
{
  this->stopDistance = stopDistance;
  this->slowDownDistance = slowDownDistance;
  leftMotorSpeed = 0;
  rightMotorSpeed = 0;
}

void AggresiveCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
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
  leftMotorSpeed = map(rightPhotoresistorValue, 300, 1023, 0, 255);
  rightMotorSpeed = map(leftPhotoresistorValue, 300, 1023, 0, 255);
}
