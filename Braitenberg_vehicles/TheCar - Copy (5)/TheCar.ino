#include <Arduino.h>
#include "Car.h"

ShyCar shyCar(600,600,15
,25);
Car car(shyCar);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
