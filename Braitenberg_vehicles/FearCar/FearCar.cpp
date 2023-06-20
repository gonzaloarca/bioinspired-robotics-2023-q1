#include "Print.h"
#include "FearCar.h"
#include "Motor.h"

 int FearCar::getLeftMotorSpeed() 
{
  return leftMotorSpeed;
}

 int FearCar::getRightMotorSpeed() 
{
  return rightMotorSpeed;
}

FearCar::FearCar(int stopDistance, int slowDownDistance)
  {
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void FearCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
  {
    Serial.print("[DEBUG]= leftPrV: ");
    Serial.print(leftPhotoresistorValue);
    Serial.print(" rightPrv: ");
    Serial.println(rightPhotoresistorValue);
  
    if (distance < stopDistance)
    {
      Serial.println("too close!");
      leftMotorSpeed = 0;
      rightMotorSpeed = 0;
      return;
    }
    if (distance < slowDownDistance)
    {
      Serial.println("Slow down!");
      leftMotorSpeed /= 4;
      rightMotorSpeed /= 4;
      // int speed = map(distance, stopDistance, slowDownDistance, 50, Motor::MAX_SPEED_INPUT);
      // leftMotorSpeed = speed;
      // rightMotorSpeed = speed;
       return;
    }
    

  
    Serial.println("Im  fearful");
    
    leftMotorSpeed = map( leftPhotoresistorValue, 300 , 1023 , 0 , 255 );
    rightMotorSpeed = map( rightPhotoresistorValue , 300 , 1023 , 0 , 255 );
}
