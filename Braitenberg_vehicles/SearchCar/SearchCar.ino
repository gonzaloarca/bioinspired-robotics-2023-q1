#include <Arduino.h>
#include "Car.h"

SearchCar behavior(20, 40, 500);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
