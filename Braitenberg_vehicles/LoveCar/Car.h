#ifndef CAR_H
#define CAR_H

#include "LoveCar.h"
#include "CarBehavior.h"
#include "Motor.h"
#include "Led.h"
#include "Photoresistor.h"
#include "DistanceSensor.h"
#include <Arduino.h>

class Car
{
  DistanceSensor distanceSensor;
  Motor leftMotor;
  Motor rightMotor;
  Photoresistor leftLdr;
  Photoresistor rightLdr;
  Led leftLed;
  Led rightLed;
  LoveCar behavior;

public:
  Car(const LoveCar& behavior);
  void update();
};

#endif // CAR_H
