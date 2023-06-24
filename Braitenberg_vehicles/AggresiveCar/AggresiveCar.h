#ifndef AGGRESIVECAR_H
#define AGGRESIVECAR_H
#include "CarBehavior.h"
#include <Arduino.h>
class AggresiveCar : public CarBehavior
{
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;

  int leftMotorSpeed;
  int rightMotorSpeed;

public:
  AggresiveCar(int stopDistance, int slowDownDistance);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif