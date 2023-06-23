#include <Arduino.h>
#include "Car.h"

FearCar fearCar(15,25 );
Car car(fearCar);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  car.update();
}
