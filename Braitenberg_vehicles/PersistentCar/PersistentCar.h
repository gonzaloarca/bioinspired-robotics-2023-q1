#ifndef PERSISTENTCAR_H
#define PERSISTENTCAR_H
#include "CarBehavior.h"
#include <Arduino.h>

enum State
{
  MOVE = 1,
  RETREAT = 2
};

class PersistentCar : public CarBehavior
{
private:
  unsigned long backUpTime;
  unsigned long lastDetectTime;
  int stopDistance;
  int slowDownDistance;
  State state;
  int leftMotorSpeed;
  int rightMotorSpeed;

public:
  PersistentCar(int stopDistance, int slowDownDistance, unsigned long backUpTime);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif