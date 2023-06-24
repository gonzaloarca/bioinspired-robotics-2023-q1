#ifndef LED_H
#define LED_H

class Led
{
private:
  int ledPin;
  long onTime;
  long offTime;

  int ledState;
  unsigned long previousMillis;

public:
  Led(int pin, long on, long off);

  void Update();
};

#endif