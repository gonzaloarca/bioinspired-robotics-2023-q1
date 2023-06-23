#include "Print.h"
#include "ExplorerCar.h"
#include "Motor.h"

 int ExplorerCar::getLeftMotorSpeed() 
{
  return rightMotorSpeed;
}

 int ExplorerCar::getRightMotorSpeed() 
{
  return leftMotorSpeed;
}

ExplorerCar::ExplorerCar(int stopDistance, int slowDownDistance)
  {
    this->stopDistance = stopDistance;
    this->slowDownDistance = slowDownDistance;
    leftMotorSpeed = 0;
    rightMotorSpeed = 0;
  }

 void ExplorerCar::update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance)
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
    

  
    Serial.println("exploring");
    

    //estan cruzados los motores, left es right y right es left
    


    rightMotorSpeed = 255 - map( leftPhotoresistorValue, 300 , 1023 , 0 , 200 );
    leftMotorSpeed = 255 - map( rightPhotoresistorValue , 300 , 1023 , 0 , 200 );
}
