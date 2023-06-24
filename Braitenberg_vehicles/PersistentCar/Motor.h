#ifndef MOTOR_H
#define MOTOR_H

enum Direction
{
  FORWARD,
  BACKWARD,
  STOPPED
};

class Motor
{
private:
  int speedControlPin;      // enA or enB
  int directionControlPin1; // in1 or in3
  int directionControlPin2; // in2 or in4

  int maxSpeed;

  void setDirection(Direction dir);

public:
  static const int MAX_SPEED_INPUT = 255;
  Motor(int speedControlPin, int dirControlPin1, int dirControlPin2, int MaxSpeed);
  void setSpeed(int speed);
};

#endif