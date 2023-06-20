#include <Servo.h>

class ServoMotor
{
public:
  ServoMotor(int pin, int updateInterval)
      : pin(pin), pos(0), targetPos(0), lastUpdateMillis(0), updateInterval(updateInterval)
  {
    servo.attach(pin);
  }

  void moveTo(int newPos)
  {
    this->startPos = this->pos;
    this->targetPos = (float)newPos;
    this->totalDistance = abs(newPos - this->startPos);
    this->lastUpdateMillis = millis();
  }

  void update()
  {
    unsigned long currentMillis = millis();
    if (abs(this->targetPos - this->pos) >= POS_THRESHOLD && currentMillis - this->lastUpdateMillis >= this->updateInterval)
    {
      this->lastUpdateMillis = currentMillis;

      this->pos += (this->targetPos - this->pos) * 0.05;
      Serial.print("pos: ");
      Serial.print(this->pos);
      Serial.print(", pos casteado: ");
      Serial.print((int)this->pos);
      Serial.print(", targetPos: ");
      Serial.println(this->targetPos);

      this->servo.write((int)this->pos);
    }
  }

private:
  Servo servo;
  int pin;
  float startPos;
  float pos;
  float targetPos;
  int totalDistance;
  unsigned long updateInterval;
  unsigned long lastUpdateMillis;
  static const float POS_THRESHOLD = 0.75;
};

class Eye
{
public:
  Eye(int pinUpDown, int pinRightLeft)
      : upDownServo(pinUpDown, SERVO_UPDATE_INTERVAL), rightLeftServo(pinRightLeft, SERVO_UPDATE_INTERVAL), state(0) {}

  void update()
  {
    unsigned long currentMillis = millis();
    if (currentMillis - this->lastMillis >= this->waitTime)
    {
      this->lastMillis = currentMillis;
      switch (this->state)
      {
      case 0: // Eye open and look right
        // this->upDownServo.moveTo(halfOpen);
        this->rightLeftServo.moveTo(right);
        this->state = 1;
        break;
      case 1: // Eye looks left
        this->rightLeftServo.moveTo(left);
        this->state = 2;
        break;
      case 2: // Eye looks middle
        this->rightLeftServo.moveTo(middle);
        this->state = 3;
        break;
      case 3: // Eye closed
        // this->upDownServo.moveTo(closed);
        this->state = 4;
        break;
      case 4: // Eye full open
        // this->upDownServo.moveTo(fullOpen);
        this->state = 5;
        break;
      case 5: // Eye closed
        // this->upDownServo.moveTo(closed);
        this->state = 6;
        break;
      case 6: // Eye full open
        // this->upDownServo.moveTo(fullOpen);
        this->state = 7;
        break;
      case 7: // Eye looks right
        this->rightLeftServo.moveTo(right);
        this->state = 8;
        break;
      case 8: // Eye looks left
        this->rightLeftServo.moveTo(left);
        this->state = 9;
        break;
      case 9: // Eye looks middle
        this->rightLeftServo.moveTo(middle);
        this->state = 10;
        break;
      case 10: // Eye half open
        // this->upDownServo.moveTo(halfOpen);
        this->state = 11;
        break;
      case 11: // Eye looks right
        this->rightLeftServo.moveTo(right);
        this->state = 12;
        break;
      case 12: // Eye looks left
        this->rightLeftServo.moveTo(left);
        this->state = 13;
        break;
      case 13: // Eye looks middle
        this->rightLeftServo.moveTo(middle);
        this->state = 14;
        break;
      case 14: // Eye full open
        // this->upDownServo.moveTo(fullOpen);
        this->state = 15;
        break;
      case 15: // Eye half open
        // this->upDownServo.moveTo(halfOpen);
        this->state = 16;
        break;
      case 16: // Eye full open
        // this->upDownServo.moveTo(fullOpen);
        this->state = 17;
        break;
      case 17: // Eye looks right
        this->rightLeftServo.moveTo(right);
        this->state = 18;
        break;
      case 18: // Eye looks left
        this->rightLeftServo.moveTo(left);
        this->state = 19;
        break;
      case 19: // Eye looks middle and then cycle the state back to 0
        this->rightLeftServo.moveTo(middle);
        this->state = 0;
        break;
      }
    }
    // this->upDownServo.update();
    this->rightLeftServo.update();
  }

private:
  ServoMotor upDownServo;
  ServoMotor rightLeftServo;
  static const unsigned long SERVO_UPDATE_INTERVAL = 200;
  int state;
  unsigned long lastMillis;

  const int fullOpen = 70;
  const int halfOpen = 40;
  const int closed = 20;
  const int right = 205;
  const int middle = 165;
  const int left = 135;
  const unsigned int waitTime = 5000;
};

Eye eye(6, 5);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  eye.update();
}
