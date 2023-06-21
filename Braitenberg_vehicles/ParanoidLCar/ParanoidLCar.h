#ifndef PARANOIDLCAR_H
#define PARANOIDLCAR_H
#include "CarBehavior.h"
#include <Arduino.h>


// enum State{
//   SPIN,
//   CHASE
// };

class ParanoidLCar : public CarBehavior {
private:
  int minPhotoresistorValue;
  int maxPhotoresistorValue;
  int stopDistance;
  int slowDownDistance;
  //State state;
  int leftMotorSpeed;
  int rightMotorSpeed;
  //unsigned long spinTime;
  unsigned long lastSpinTime;
public:
    ParanoidLCar(int stopDistance, int slowDownDistance);
    virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
    virtual int getLeftMotorSpeed();
    virtual int getRightMotorSpeed();
};

#endif