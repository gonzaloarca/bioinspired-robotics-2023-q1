#ifndef CAR_H
#define CAR_H

#include "ShyCar.h"
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
  ShyCar behavior;

public:
  Car(const ShyCar& behavior);
  void update();
};

#endif // CAR_H
