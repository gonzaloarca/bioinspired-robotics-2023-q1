#include <Arduino.h>
#include "Car.h"

LoveCar behavior(15, 25);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
