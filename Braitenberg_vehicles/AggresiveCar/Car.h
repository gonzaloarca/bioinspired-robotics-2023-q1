#ifndef CAR_H
#define CAR_H

#include "AggresiveCar.h"
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
  AggresiveCar behavior;

public:
  Car(const AggresiveCar &behavior);
  void update();
};

#endif // CAR_H
