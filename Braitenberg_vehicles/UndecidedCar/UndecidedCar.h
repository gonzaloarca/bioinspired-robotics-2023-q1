#ifndef UNDECIDEDCAR_H
#define UNDECIDEDCAR_H
#include "CarBehavior.h"
#include <Arduino.h>


enum State{
  MOVE,
  RETREAT
};

class UndecidedCar : public CarBehavior {
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;
  State state;
  int leftMotorSpeed;
  int rightMotorSpeed;
public:
    UndecidedCar(int stopDistance, int slowDownDistance);
    virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
    virtual int getLeftMotorSpeed();
    virtual int getRightMotorSpeed();
};

#endif