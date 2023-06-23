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
    this->state = SPIN;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void ParanoidLCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
   Serial.println("");
   Serial.println("PARANOID UPDATE");
   Serial.print("distance: ");
   Serial.println(distance);
   Serial.print("State: ");
   Serial.println(this->state);
    unsigned long currentTime;
   switch(this->state){
     
      // case STOP:
      //   Serial.println("STOP");
      //   leftMotorSpeed = 0;
      //   rightMotorSpeed = 0;
      //   if(distance > slowDownDistance){
      //     this->state = SPIN;
      //     return;
      //   }

      //   if(distance > stopDistance){
      //     this->state = CHASE;
      //   }
      //   break;
     
      case CHASE:
        Serial.println("FORWARD");
        leftMotorSpeed = constrain( leftMotorSpeed * 2 , 25, 255);
        rightMotorSpeed = constrain( rightMotorSpeed * 2 , 25, 255);
        //currentTime = millis();
        // if(distance < stopDistance && currentTime > this->lastSpinTime + 200){
        //   this->state = STOP;
        // }
        if(distance > slowDownDistance ){
          this->state = SPIN;
        rightMotorSpeed =  - ( 255 - 150 );
        leftMotorSpeed = 150;
        }
        break;
      case SPIN:
        Serial.println("spin");
        rightMotorSpeed =  - ( 255 - 80 );
        leftMotorSpeed = 80;
        if(distance < slowDownDistance ){
          this->lastSpinTime = millis();
          this->state = CHASE;
          rightMotorSpeed =  0;
          leftMotorSpeed = 0;
        }
        break;
      // case CORRECT:
      //   Serial.println("correct");
      //   rightMotorSpeed = 70;
      //   leftMotorSpeed =  70 - 255; 
      //  currentTime = millis();
      //   if(this->lastSpinTime + 100 < currentTime ){
      //     this->state = CHASE;
      //     this->lastSpinTime = millis();
      //   }
      //   break;
      default:
        Serial.println("NONE");
        break;
      }  

      Serial.println("end of switch");
}
