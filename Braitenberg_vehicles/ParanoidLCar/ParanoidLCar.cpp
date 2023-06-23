#include "Print.h"
#include "ParanoidLCar.h"
#include "Motor.h"

 int ParanoidLCar::getLeftMotorSpeed() 
{
  return rightMotorSpeed;
}

 int ParanoidLCar::getRightMotorSpeed() 
{
  return leftMotorSpeed;
}

ParanoidLCar::ParanoidLCar( int stopDistance, int slowDownDistance)
  {
    // this->spinTime = spinTime;
    this->state = SPIN;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void ParanoidLCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){

    unsigned long currentTime;
   switch(this->state){
     
     
      case CHASE:
        Serial.println("FORWARD");
        leftMotorSpeed = constrain( leftMotorSpeed * 2 , 25, 255);
        rightMotorSpeed = constrain( rightMotorSpeed * 2 , 25, 255);
   
        if(distance > slowDownDistance ){
          this->state = SPIN;
        leftMotorSpeed =  - ( 255 - 150 );
        rightMotorSpeed = 150;
        }
        break;
      case SPIN:
        Serial.println("spin");
        leftMotorSpeed =  - ( 255 - 80 );
        rightMotorSpeed = 80;
        if(distance < slowDownDistance ){
          this->lastSpinTime = millis();
          this->state = CHASE;
          rightMotorSpeed =  0;
          leftMotorSpeed = 0;
        }
        break;
     
      default:
        Serial.println("NONE");
        break;
      }  

      Serial.println("end of switch");
}
