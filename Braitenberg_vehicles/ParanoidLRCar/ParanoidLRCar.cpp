#include "Print.h"
#include "ParanoidLRCar.h"
#include "Motor.h"

 int ParanoidLRCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int ParanoidLRCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

ParanoidLRCar::ParanoidLRCar( int stopDistance, int slowDownDistance , int minPhotoresistorValue , int maxPhotoresistorValue)
  {

    this->state = SEARCH_L;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    this->minPhotoresistorValue = minPhotoresistorValue;
    this->maxPhotoresistorValue = maxPhotoresistorValue;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
    this->ready = false;
  }

 void ParanoidLRCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
    //no dobla
    switch(this->state){
      case SEARCH_L:
        Serial.println("spinL");
        rightMotorSpeed =  - ( 255 - 80 );
        leftMotorSpeed = 80;
        //if both detect a lot of light go ahead
        if(leftPhotoresistorValue > maxPhotoresistorValue && rightPhotoresistorValue > maxPhotoresistorValue ){
          //this->lastSpinTime = millis();
          this->state = MOVE;
          rightMotorSpeed =  0;
          leftMotorSpeed = 0;
          return;
        }
        //si el valor derecho es mayor del izquierdo pero no tengo que ir para adelante giro para ese lado
        
        if(rightPhotoresistorValue > minPhotoresistorValue && rightPhotoresistorValue > leftPhotoresistorValue){
          this->state = SEARCH_R;
          return;
        }
        return;
      case SEARCH_R:
          Serial.println("spinR");
          leftMotorSpeed =  - ( 255 - 100 );
          rightMotorSpeed = 80;
           if(leftPhotoresistorValue > minPhotoresistorValue && rightPhotoresistorValue > maxPhotoresistorValue ){
          //this->lastSpinTime = millis();
          this->state = MOVE;
          rightMotorSpeed =  0;
          leftMotorSpeed = 0;
          return;
        }
        //si el valor izquierdo es mayor del derecho pero no tengo que ir para adelante giro para ese lado
        if(leftPhotoresistorValue > minPhotoresistorValue && rightPhotoresistorValue < leftPhotoresistorValue){
          this->state = SEARCH_L;
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
       // this->state = STOP;
        return;         
      }
      
      if (distance < slowDownDistance){
        Serial.println("Slow down!");
        leftMotorSpeed = 100;
        rightMotorSpeed = 100;
        return;
      }

      if(rightPhotoresistorValue < minPhotoresistorValue ){
        this->state = SEARCH_L;
        return;
      }

      
      if(leftPhotoresistorValue < minPhotoresistorValue ){
        this->state = SEARCH_R;
        return;
      }

      Serial.println("Forward");
      rightMotorSpeed= 200;
      leftMotorSpeed = 180; 
      return;
    
      default: 
        return;
    }
    
}
