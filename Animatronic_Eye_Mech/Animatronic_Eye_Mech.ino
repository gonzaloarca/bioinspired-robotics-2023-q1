// include library for servo
#include <Servo.h>

// define name of the servo motors
Servo upDownServo;
Servo rightLeftServo;

// define position name and value
#define left 90
#define right 160
#define middle 120
#define closed 20
#define halfOpen 40
#define fullOpen 70

#define waitTime 750

void setup()
{
    // define pin numbers of the servo motors
    upDownServo.attach(6);
    rightLeftServo.attach(5);

    // starting position of the servo motors
    delay(10);
    upDownServo.write(closed);
    rightLeftServo.write(middle);
}

void loop()
{

    delay(1000);
    upDownServo.write(halfOpen);
    delay(waitTime);
    rightLeftServo.write(right);
    delay(waitTime);
    rightLeftServo.write(left);
    delay(waitTime);
    rightLeftServo.write(middle);

    delay(1000);
    upDownServo.write(closed);
    delay(waitTime);
    upDownServo.write(fullOpen);
    delay(waitTime);
    upDownServo.write(closed);
    delay(waitTime);
    upDownServo.write(fullOpen);
    delay(waitTime);
    rightLeftServo.write(right);
    delay(waitTime);
    rightLeftServo.write(left);
    delay(waitTime);
    rightLeftServo.write(middle);
    upDownServo.write(halfOpen);
    delay(waitTime);
    rightLeftServo.write(right);
    delay(waitTime);
    rightLeftServo.write(left);
    delay(waitTime);
    rightLeftServo.write(middle);
    delay(waitTime);
    upDownServo.write(fullOpen);
    delay(waitTime);
    upDownServo.write(halfOpen);
    delay(waitTime);
    upDownServo.write(fullOpen);
    delay(waitTime);
    rightLeftServo.write(right);
    delay(waitTime);
    rightLeftServo.write(left);
    delay(waitTime);
    rightLeftServo.write(middle);
}
