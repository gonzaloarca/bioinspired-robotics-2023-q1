#include "DistanceSensor.h"
#include <Arduino.h>

DistanceSensor::DistanceSensor(int triggerPin, int echoPin, long updateInterval)
{
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->updateInterval = updateInterval;

    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(triggerPin, LOW); // Initialize pin with 0

    previousTime = 0;
    senseTime = 0;
    isReading = false;
}

int DistanceSensor::read()
{
    return latestDistance;
}

void DistanceSensor::beginRead()
{
    if (isReading)
        return;

    Serial.println("Begin read");

    digitalWrite(triggerPin, HIGH);
    isReading = true;
    senseTime = millis();
}

void DistanceSensor::finishRead()
{
    digitalWrite(triggerPin, LOW);
    long t = pulseIn(echoPin, HIGH); // get pulse width
    latestDistance = t / 59;         // scale time to distance in cm
    isReading = false;               // disable reading mode

    Serial.print("Distance: ");
    Serial.print(latestDistance); // Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
}

void DistanceSensor::update()
{
    unsigned long currentTime = millis();

    // begin sense interval, finish update interval
    if (!isReading && currentTime - previousTime > updateInterval)
    {
        beginRead();
    }

    // begin update interval, finish sense interval
    if (isReading && currentTime - senseTime > SENSE_INTERVAL)
    {
        finishRead();
        previousTime = millis();
    }
}
