#ifndef CAR_H
#define CAR_H

#include "OffendedCar.h"
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
  OffendedCar behavior;

public:
  Car(const OffendedCar& behavior);
  void update();
};

#endif // CAR_H
