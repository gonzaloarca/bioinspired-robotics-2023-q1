#include "Car.h"

// LED
#define LEFT_LED_PIN 13
#define RIGHT_LED_PIN 10
#define LED_ON_TIME 500
#define LED_OFF_TIME 500

// DISTANCE SENSOR MACROS
#define DISTANCE_SENSOR_UPDATE_INTERVAL 100
#define ECHO_PIN 11
#define TRIGGER_PING 12

// LEFT MOTOR
#define LEFT_MOTOR_SPEED_PIN 9
#define LEFT_MOTOR_DIR_PIN1 8
#define LEFT_MOTOR_DIR_PIN2 7
#define LEFT_MOTOR_MAX_SPEED 115
// RIGHT MOTOR
#define RIGHT_MOTOR_SPEED_PIN 3
#define RIGHT_MOTOR_DIR_PIN1 5
#define RIGHT_MOTOR_DIR_PIN2 4
#define RIGHT_MOTOR_MAX_SPEED 130

Car::Car(const ShyCar &b)
    : distanceSensor(TRIGGER_PING, ECHO_PIN, DISTANCE_SENSOR_UPDATE_INTERVAL),
      //  Motor(int speedControlPin, int dirControlPin1, int dirControlPin2, int MaxSpeed);
      leftMotor(LEFT_MOTOR_SPEED_PIN, LEFT_MOTOR_DIR_PIN1, LEFT_MOTOR_DIR_PIN2, LEFT_MOTOR_MAX_SPEED),
      rightMotor(RIGHT_MOTOR_SPEED_PIN, RIGHT_MOTOR_DIR_PIN1, RIGHT_MOTOR_DIR_PIN2, RIGHT_MOTOR_MAX_SPEED),
      leftLdr(A1),
      rightLdr(A0),
      leftLed(LEFT_LED_PIN, LED_ON_TIME, LED_OFF_TIME),
      rightLed(RIGHT_LED_PIN, LED_ON_TIME, LED_OFF_TIME),
      behavior(b){};

void Car::update()
{
    distanceSensor.update();

    Serial.println("");
    Serial.print("Light left ");
    Serial.println(leftLdr.read());
    Serial.print("Light right  ");
    Serial.println(rightLdr.read());
    Serial.print("Distance ");
    Serial.println(distanceSensor.read());

    behavior.update(leftLdr.read(), rightLdr.read(), distanceSensor.read());
    Serial.print("Speed left ");
    Serial.println(behavior.getLeftMotorSpeed());
    Serial.print("Speed right ");
    Serial.println(behavior.getRightMotorSpeed());

    leftMotor.setSpeed(behavior.getLeftMotorSpeed());
    rightMotor.setSpeed(behavior.getRightMotorSpeed());

    //    delay(1000);
};
