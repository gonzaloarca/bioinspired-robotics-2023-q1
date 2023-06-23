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
    this->ready = false;
  }

 void OffendedCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){ 

   if(!this-> ready)
  {
    if(distance <= 0 ) return ;
     this->ready = true;
   }
    int speed = rightMotorSpeed;

    //no dobla
    switch(this->state){
      case MOVE:
        Serial.println("moving -- ");
        Serial.print("Distance: ");
        Serial.println(distance);
       //checkeo choque
        if(distance > slowDownDistance){
          //speed up
          Serial.println("speed up");
          rightMotorSpeed= leftMotorSpeed = constrain(rightMotorSpeed * 2 , 50 ,255); 
          return;
        }else{
          if(distance < stopDistance ){
            Serial.println("Stop!");
            leftMotorSpeed = 0;
            rightMotorSpeed = 0;
            
          }else{
            Serial.println("Slow down!");
            leftMotorSpeed /= 4 ;
            rightMotorSpeed /= 4;
            rightMotorSpeed = leftMotorSpeed = constrain(leftMotorSpeed , 75 , 255);
          }
        }

        speed = rightMotorSpeed;
        Serial.print("speed: ");
        Serial.println(speed);
        if(speed <= 0 ){
          //tengo que rotar y cambio de estado
          Serial.println("too close!");
          this->state = OFFENDED;
          this->lastSpinTime = millis();
          leftMotorSpeed = 0;
          rightMotorSpeed = 0;
          //change state
           
        }
        
        break;
      case OFFENDED:
          Serial.println("ofendido -.- ");
          this->state = OFFENDED;

        unsigned long currentTime = millis();
        if(this-> lastSpinTime + (this->spinTime * 3) < currentTime){
          leftMotorSpeed = 0;
          rightMotorSpeed = 0;
        }else if (this-> lastSpinTime + (this->spinTime * 2) < currentTime){
          leftMotorSpeed = 70;
          rightMotorSpeed = -70;
        }
        return;
      default: 
        return;
    }
    
   

    



}
