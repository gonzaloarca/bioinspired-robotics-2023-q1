#include "Print.h"
#include "ParanoidLCar.h"
#include "Motor.h"

 int ParanoidLCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int ParanoidLCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

ParanoidLCar::ParanoidLCar( int stopDistance, int slowDownDistance)
  {
    // this->spinTime = spinTime;
    // this->state = SPIN;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void ParanoidLCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
    

    if(distance < 30){
      leftMotorSpeed = constrain( leftMotorSpeed * 2 , 25, 255);
      rightMotorSpeed = constrain( rightMotorSpeed * 2 , 25, 255);
      return;
    }

    rightMotorSpeed = -100;
    leftMotorSpeed = 100;
    
}
