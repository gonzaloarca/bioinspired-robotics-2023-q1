#include <Arduino.h>
#include "Car.h"

ShyCar shyCar(500,500,7,15);
Car car(shyCar);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
