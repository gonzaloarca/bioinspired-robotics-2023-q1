#include "Print.h"
#include "SearchCar.h"
#include "Motor.h"

 int SearchCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int SearchCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

SearchCar::SearchCar( int stopDistance, int slowDownDistance , unsigned long spinTime )
  {

    this->state = SEARCH_L;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    this->lastSpinTime = 0;
    this->spinTime = spinTime;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
    this->ready = false;
  }

 void SearchCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
    int speed = rightMotorSpeed;
    unsigned long currentTime;
    if(!this->ready && distance > 0) {
      this->ready =true;
    }
    if(!this->ready){
      return;
    }
    //no dobla
    switch(this->state){
      case SEARCH_L:
        Serial.println("spinL");
        rightMotorSpeed =  - ( 255 - 80 );
        leftMotorSpeed = 80;
        if(distance < slowDownDistance ){
          //this->lastSpinTime = millis();
          this->state = MOVE;
          rightMotorSpeed =  0;
          leftMotorSpeed = 0;
          return;
        }
        currentTime = millis();
        if(this->lastSpinTime + this->spinTime < currentTime){
          this->state = SEARCH_R;
          this->lastSpinTime = currentTime;
        }
        return;
      case SEARCH_R:
          Serial.println("spinR");
          leftMotorSpeed =  - ( 255 - 100 );
          rightMotorSpeed = 80;
          if(distance < slowDownDistance ){
            //this->lastSpinTime = millis();
            this->state = MOVE;
            rightMotorSpeed =  0;
            leftMotorSpeed = 0;
            return;
          }
          
          currentTime = millis();
          if(this->lastSpinTime + this->spinTime < currentTime){
            this->state = SEARCH_L;
            this->lastSpinTime = currentTime;
            return;
          }
          return;

      case STOP:
        leftMotorSpeed = 0;
        rightMotorSpeed = 0;
        return;

      case MOVE:
       //checkeo choque
       if(distance < stopDistance ){
          //tengo que frenar y cambio de estado
        Serial.println("too close!");
        leftMotorSpeed = 0;
        rightMotorSpeed = 0;
        //change state
        this->state = STOP;
        return;         
      }
      
      if (distance < slowDownDistance){
        Serial.println("Slow down!");
        leftMotorSpeed = 100;
        rightMotorSpeed = 100;
        return;
      }

      Serial.println("Forward");
      speed = 200;
      rightMotorSpeed= 200;
      leftMotorSpeed = 180; 
      return;
    
      default: 
        return;
    }
    
}
