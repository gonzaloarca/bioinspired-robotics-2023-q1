#include <Servo.h>

class ServoMotor {
public:
  ServoMotor(int pin, int updateInterval, int initialPos, float smoothFactor)
    : pin(pin),
      pos((float)initialPos),
      targetPos((float)initialPos),
      lastUpdateMillis(0),
      updateInterval(updateInterval),
      smoothFactor(smoothFactor) {

    servo.attach(pin);
    servo.write((int)this->pos);
  }

  void moveTo(int newPos) {
    this->startPos = this->pos;
    this->targetPos = (float)newPos;
    this->lastUpdateMillis = millis();
  }

  void update() {
    unsigned long currentMillis = millis();
    if (abs(this->targetPos - this->pos) >= POS_THRESHOLD && currentMillis - this->lastUpdateMillis >= this->updateInterval) {
      this->lastUpdateMillis = currentMillis;

      this->pos = (this->pos * (1 - this->smoothFactor)) + (this->targetPos * this->smoothFactor);
      // this->pos += (this->targetPos - this->pos) * 0.05;
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
  float smoothFactor;
  float targetPos;
  unsigned long updateInterval;
  unsigned long lastUpdateMillis;
  static const float POS_THRESHOLD = 1;
};

class Eye {
public:
  Eye(int pinUpDown, int pinRightLeft)
    : upDownServo(pinUpDown, VERTICAL_SERVO_UPDATE_INTERVAL, CLOSED, VERTICAL_SERVO_SMOOTH_FACTOR),
      rightLeftServo(pinRightLeft, HORIZONTAL_SERVO_UPDATE_INTERVAL, MIDDLE, HORIZONTAL_SERVO_SMOOTH_FACTOR),
      state(0) {}

  void update() {
    unsigned long currentMillis = millis();
    if (currentMillis - this->lastMillis >= this->WAIT_TIME) {
      this->lastMillis = currentMillis;
      switch (this->state) {
        case 0:  // Eye open and look right
          this->upDownServo.moveTo(HALF_OPEN);
          this->rightLeftServo.moveTo(RIGHT);
          this->state = 1;
          break;
        case 1:  // Eye looks left
          this->rightLeftServo.moveTo(LEFT);
          this->state = 2;
          break;
        case 2:  // Eye looks middle
          this->rightLeftServo.moveTo(MIDDLE);
          this->state = 3;
          break;
        case 3:  // Eye closed
          this->upDownServo.moveTo(CLOSED);
          this->state = 4;
          break;
        case 4:  // Eye full open
          this->upDownServo.moveTo(FULL_OPEN);
          this->state = 5;
          break;
        case 5:  // Eye closed
          this->upDownServo.moveTo(CLOSED);
          this->state = 6;
          break;
        case 6:  // Eye full open
          this->upDownServo.moveTo(FULL_OPEN);
          this->state = 7;
          break;
        case 7:  // Eye looks right
          this->rightLeftServo.moveTo(RIGHT);
          this->state = 8;
          break;
        case 8:  // Eye looks left
          this->rightLeftServo.moveTo(LEFT);
          this->state = 9;
          break;
        case 9:  // Eye looks middle
          this->rightLeftServo.moveTo(MIDDLE);
          this->state = 10;
          break;
        case 10:  // Eye half open
          this->upDownServo.moveTo(HALF_OPEN);
          this->state = 11;
          break;
        case 11:  // Eye looks right
          this->rightLeftServo.moveTo(RIGHT);
          this->state = 12;
          break;
        case 12:  // Eye looks left
          this->rightLeftServo.moveTo(LEFT);
          this->state = 13;
          break;
        case 13:  // Eye looks middle
          this->rightLeftServo.moveTo(MIDDLE);
          this->state = 14;
          break;
        case 14:  // Eye full open
          this->upDownServo.moveTo(FULL_OPEN);
          this->state = 15;
          break;
        case 15:  // Eye half open
          this->upDownServo.moveTo(HALF_OPEN);
          this->state = 16;
          break;
        case 16:  // Eye full open
          this->upDownServo.moveTo(FULL_OPEN);
          this->state = 17;
          break;
        case 17:  // Eye looks right
          this->rightLeftServo.moveTo(RIGHT);
          this->state = 18;
          break;
        case 18:  // Eye looks left
          this->rightLeftServo.moveTo(LEFT);
          this->state = 19;
          break;
        case 19:  // Eye looks middle and then cycle the state back to 0
          this->rightLeftServo.moveTo(MIDDLE);
          this->state = 0;
          break;
      }
    }
    this->upDownServo.update();
    this->rightLeftServo.update();
  }

private:
  ServoMotor upDownServo;
  ServoMotor rightLeftServo;
  static const unsigned long VERTICAL_SERVO_UPDATE_INTERVAL = 5;
  static const unsigned long HORIZONTAL_SERVO_UPDATE_INTERVAL = 50;
  static const float VERTICAL_SERVO_SMOOTH_FACTOR = 0.3;
  static const float HORIZONTAL_SERVO_SMOOTH_FACTOR = 0.1;
  int state;
  unsigned long lastMillis;

  static const int FULL_OPEN = 180;
  static const int HALF_OPEN = 150;
  static const int CLOSED = 130;
  static const int RIGHT = 130;
  static const int MIDDLE = 90;
  static const int LEFT = 30;
  static const unsigned int WAIT_TIME = 1500;
};

Eye* eye;

void setup() {
  eye = new Eye(6, 5);
  Serial.begin(9600);
}

void loop() {
  eye->update();
}
