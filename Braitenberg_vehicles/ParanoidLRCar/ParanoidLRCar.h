#ifndef PARANOIDLRCAR_H
#define PARANOIDLRCAR_H
#include "CarBehavior.h"
#include <Arduino.h>


enum State{
  SEARCH_L,
  SEARCH_R,
  MOVE,
  STOP
};

class ParanoidLRCar : public CarBehavior {
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;;
  State state;
  int leftMotorSpeed;
  int rightMotorSpeed;
  bool ready;
public:
    ParanoidLRCar(int stopDistance, int slowDownDistance, int minPhotoresistorValue , int maxPhotoresistorValue);
    virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
    virtual int getLeftMotorSpeed();
    virtual int getRightMotorSpeed();
};

#endif