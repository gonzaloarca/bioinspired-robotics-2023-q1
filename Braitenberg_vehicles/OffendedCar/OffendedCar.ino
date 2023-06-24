#include <Arduino.h>
#include "Car.h"

OffendedCar behavior(15, 35, 250);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
  Serial.println("HELLOO!");
}

void loop()
{
  car.update();
}
