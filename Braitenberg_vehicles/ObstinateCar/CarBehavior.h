#ifndef CARBEHAVIOR_H
#define CARBEHAVIOR_H

class CarBehavior {
public:
  virtual void update(int leftPhotoresistorValue, int rightPhotoresistorValue, int distance);
  virtual int getLeftMotorSpeed();
  virtual int getRightMotorSpeed();

};

#endif