#include <Arduino.h>
#include "Car.h"

UndecidedCar behavior(20,40);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
