#include "Print.h"
#include "UndecidedCar.h"
#include "Motor.h"

 int UndecidedCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int UndecidedCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

UndecidedCar::UndecidedCar( int stopDistance, int slowDownDistance)
  {

    this->state = MOVE;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void UndecidedCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
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
        leftMotorSpeed = 0;
        rightMotorSpeed = 0;
        //change state
        this->state = RETREAT;
      
      case RETREAT:
        if(distance > slowDownDistance ){
          this->state = MOVE;
        }

        if(speed > 20 ){
          //slow down
          rightMotorSpeed= leftMotorSpeed= speed;
          leftMotorSpeed /= 4;
          rightMotorSpeed /= 4;
        }else{
          speed = constrain(speed * 2, -50 , -255);
        }
        return;
      default: 
        return;
    }
    
   

    



}
