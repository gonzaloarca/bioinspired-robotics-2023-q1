#include <Arduino.h>
#include "Car.h"

ParanoidLRCar behavior(20, 40, 600, 900);
Car car(behavior);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
