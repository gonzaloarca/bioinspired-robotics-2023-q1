#ifndef SEARCHCAR_H
#define SEARCHCAR_H
#include "CarBehavior.h"
#include <Arduino.h>

enum State
{
  SEARCH_L,
  SEARCH_R,
  MOVE,
  STOP
};

class SearchCar : public CarBehavior
{
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;
  unsigned long spinTime;
  unsigned long lastSpinTime;
  State state;
  int leftMotorSpeed;
  int rightMotorSpeed;
  bool ready;

public:
  SearchCar(int stopDistance, int slowDownDistance, unsigned long spinTime);
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();
};

#endif