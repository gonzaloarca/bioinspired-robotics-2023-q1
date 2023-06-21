#include <Arduino.h>
#include "Car.h"

OffendedCar behavior(15,25,100);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
