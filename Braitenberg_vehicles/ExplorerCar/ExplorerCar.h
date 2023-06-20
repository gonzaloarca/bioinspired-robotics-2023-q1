#ifndef EXPLORERCAR_H
#define EXPLORERCAR_H
#include "CarBehavior.h"
#include <Arduino.h>
class ExplorerCar : public CarBehavior {
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;

  int leftMotorSpeed;
  int rightMotorSpeed;
public:
    ExplorerCar(int stopDistance, int slowDownDistance);
    virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
    virtual int getLeftMotorSpeed();
    virtual int getRightMotorSpeed();
    
};

#endif