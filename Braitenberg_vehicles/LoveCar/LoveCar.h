#ifndef LOVECAR_H
#define LOVECAR_H
#include "CarBehavior.h"
#include <Arduino.h>
class LoveCar : public CarBehavior {
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;

  int leftMotorSpeed;
  int rightMotorSpeed;
public:
    LoveCar(int stopDistance, int slowDownDistance);
    virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
    virtual int getLeftMotorSpeed();
    virtual int getRightMotorSpeed();
    
};

#endif