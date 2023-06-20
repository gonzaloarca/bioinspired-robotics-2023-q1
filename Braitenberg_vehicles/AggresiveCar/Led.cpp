#include "Led.h"
#include <Arduino.h>

Led::Led(int pin, long on, long off)
{
  this->ledPin = pin;
  pinMode(ledPin, OUTPUT);

  this->onTime = on;
  this->offTime = off;

  ledState = LOW;
  previousMillis = 0;
}

void Led::Update()
{

  // check to see if it's time to change the state of the LED
  unsigned long currentMillis = millis();

  if ((ledState == HIGH) && (currentMillis - previousMillis >= onTime))
  {
    ledState = LOW;                 // Turn it off
    previousMillis = currentMillis; // Remember the time
    digitalWrite(ledPin, ledState); // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= offTime))
  {
    ledState = HIGH;                // turn it on
    previousMillis = currentMillis; // Remember the time
    digitalWrite(ledPin, ledState); // Update the actual LED
  }
}
