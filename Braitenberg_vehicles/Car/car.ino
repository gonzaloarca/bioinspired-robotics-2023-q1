#include <Arduino.h>
#include "Behaviors/ShyCar/ShyCar.h"
#include "Behaviors/CarBehavior/CarBehavior.h"
#include "Peripherals/Motor/Motor.h"
#include "Peripherals/Led/Led.h"
#include "Peripherals/Photoresistor/Photoresistor.h"
#include "Peripherals/DistanceSensor/DistanceSensor.h"

#define LEFT_LED_PIN A1
#define RIGHT_LED_PIN A0
#define LED_ON_TIME 500
#define LED_OFF_TIME 500

class Car
{
  DistanceSensor distanceSensor;
  Motor leftMotor;
  Motor rightMotor;
  Photoresistor leftLdr;
  Photoresistor rightLdr;
  Led leftLed;
  Led rightLed;
  CarBehaviour CarBehaviour;

public:
  Car()
      : distanceSensor(12, 11, 100),
        leftMotor(9, 8, 7, 255),
        rightMotor(3, 5, 4, 255),
        leftLdr(A1),
        rightLdr(A0),
        leftLed(LEFT_LED_PIN, 500, 500),
        rightLed(RIGHT_LED_PIN, 500, 500) {}
  ShyCar()
};

Car car();

void setup()
{
  Serial.begin(9600);
}

void loop()
{
}
