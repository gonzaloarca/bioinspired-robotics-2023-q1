#ifndef FEARCAR_H
#define FEARCAR_H
#include "CarBehavior.h"
#include <Arduino.h>
class FearCar : public CarBehavior
{
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;

  int leftMotorSpeed;
  int rightMotorSpeed;

public:
  FearCar(int stopDistance, int slowDownDistance);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif