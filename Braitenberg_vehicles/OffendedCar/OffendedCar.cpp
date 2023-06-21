#include "Print.h"
#include "OffendedCar.h"
#include "Motor.h"

 int OffendedCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int OffendedCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

OffendedCar::OffendedCar( int stopDistance, int slowDownDistance , int spinTime)
  {
    this->spinTime = spinTime;
    this->state = MOVE;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void OffendedCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
    int speed = rightMotorSpeed;

    //no dobla
    switch(this->state){
      case MOVE:
       //checkeo choque
        if (distance > stopDistance && speed > 10){
          //slow down
          if (distance < slowDownDistance){
            Serial.println("Slow down!");
            leftMotorSpeed /= 4;
            rightMotorSpeed /= 4;
            return;
          }
          //speed up
          speed = constrain(speed * 2, 50 , 255);
          rightMotorSpeed= leftMotorSpeed = speed; 
          return;
        }
        //tengo que frenar y cambio de estado
        Serial.println("too close!");
        leftMotorSpeed = -100;
        rightMotorSpeed = 100;

        //change state
        this->state = OFFENDED;
        this->lastSpinTime = millis();
      case OFFENDED:
        unsigned long currentTime = millis();
        if(this-> lastSpinTime + this->spinTime < currentTime){
          leftMotorSpeed = 0;
          rightMotorSpeed = 0;
        }
        return;
      default: 
        return;
    }
    
   

    



}
