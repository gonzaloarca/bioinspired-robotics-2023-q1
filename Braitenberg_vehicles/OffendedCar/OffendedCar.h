#ifndef OFFENDEDCAR_H
#define OFFENDEDCAR_H
#include "CarBehavior.h"
#include <Arduino.h>

enum State
{
  MOVE,
  OFFENDED
};

class OffendedCar : public CarBehavior
{
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;
  bool ready;
  State state;
  int leftMotorSpeed;
  int rightMotorSpeed;
  unsigned long spinTime;
  unsigned long lastSpinTime;

public:
  OffendedCar(int stopDistance, int slowDownDistance, int spinTime);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif