#include <Arduino.h>
#include "Car.h"

ParanoidLCar behavior(10, 30);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
