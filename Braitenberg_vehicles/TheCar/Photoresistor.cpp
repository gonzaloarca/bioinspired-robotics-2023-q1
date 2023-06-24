#include "Photoresistor.h"
#include <Arduino.h>

Photoresistor::Photoresistor(int pin)
{
  this->ldrPin = pin;
  pinMode(ldrPin, INPUT);
}

int Photoresistor::read()
{
  int r = analogRead(ldrPin);
  // Serial.print("Light: ");
  // Serial.print(r);
  // Serial.println();

  return r;
}