#include <Arduino.h>
#include "Car.h"

PersistentCar behavior(20, 40, 1000);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
