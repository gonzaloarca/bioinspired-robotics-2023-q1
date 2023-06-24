#include "Print.h"
#include "ShyCar.h"
#include "Motor.h"

int ShyCar::getLeftMotorSpeed()
{
  return leftMotorSpeed;
}

int ShyCar::getRightMotorSpeed()
{
  return rightMotorSpeed;
}

ShyCar::ShyCar(int minPhotoresistorValue, int maxPhotoresistorValue, int stopDistance, int slowDownDistance)
{
  this->minPhotoresistorValue = minPhotoresistorValue;
  this->maxPhotoresistorValue = maxPhotoresistorValue;
  this->stopDistance = stopDistance;
  this->slowDownDistance = slowDownDistance;
  leftMotorSpeed = 0;
  rightMotorSpeed = 0;
}

void ShyCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
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

  // si no ve nada incrementar speed
  if (leftPhotoresistorValue < minPhotoresistorValue && rightPhotoresistorValue < minPhotoresistorValue)
  {
    Serial.println("speed up!!");

    leftMotorSpeed = constrain(leftMotorSpeed * 2, 50, Motor::MAX_SPEED_INPUT);
    rightMotorSpeed = constrain(rightMotorSpeed * 2, 50, Motor::MAX_SPEED_INPUT);
    return;
  }

  Serial.println("Im shy!!");
  // si detecta slowdown
  leftMotorSpeed /= 4;
  rightMotorSpeed /= 4;

  // if (leftPhotoresistorValue > minPhotoresistorValue || rightPhotoresistorValue > minPhotoresistorValue)
  // { // Both sensors see something, slow down
  //   leftSpeed /= 2;
  //   rightSpeed /= 2;
  //   return;
  // }

  // if (leftPhotoresistorValue > minPhotoresistorValue) {
  //   // Left sensor sees something, turn right
  //   leftSpeed = 255;
  //   rightSpeed = 0;
  // }
  // else if (rightPhotoresistorValue > minPhotoresistorValue) {
  //   // Right sensor sees something, turn left
  //   leftSpeed = 0;
  //   rightSpeed = 255;
  // }
}
