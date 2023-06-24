#ifndef SHYCAR_H
#define SHYCAR_H
#include "CarBehavior.h"
#include <Arduino.h>
class ShyCar : public CarBehavior
{
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;

  int leftMotorSpeed;
  int rightMotorSpeed;

public:
  ShyCar(int minPhotoresistorValue, int maxPhotoresistorValue, int stopDistance, int slowDownDistance);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif