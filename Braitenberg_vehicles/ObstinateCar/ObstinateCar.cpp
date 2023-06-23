#include "Print.h"
#include "ObstinateCar.h"
#include "Motor.h"

 int ObstinateCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int ObstinateCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

ObstinateCar::ObstinateCar( int stopDistance, int slowDownDistance, unsigned long backUpTime)
  {
    this->backUpTime = backUpTime;
    this->state = MOVE;
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    this->lastDetectTime = 0;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void ObstinateCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance){
    int speed = rightMotorSpeed;
    Serial.print("Stop distance: ");
    Serial.println(stopDistance);
    unsigned long currentTime = millis();

    switch(this->state){
      case RETREAT:

        Serial.println("retreat");
        if(this->lastDetectTime + this->backUpTime < currentTime ){
          this->state = MOVE;
            
          leftMotorSpeed =   150;
          rightMotorSpeed =  200;
          return;
        }
        leftMotorSpeed =   150 - 255;
        rightMotorSpeed =  150 - 255;
        return;

      case MOVE:
       //checkeo choque
       Serial.println("En move");
       if(distance < stopDistance ){
          //tengo que frenar y cambio de estado
        Serial.println("too close!");
        leftMotorSpeed = 0;
        rightMotorSpeed = 0;
        //change state
        this->lastDetectTime = millis();
        this->state = RETREAT;
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
        Serial.println("swtich default");
        return;

      Serial.println("Despues del switch");
    }
    
   

    



}
