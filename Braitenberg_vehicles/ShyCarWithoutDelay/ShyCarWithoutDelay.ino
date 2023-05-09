enum Direction {
  FORWARD,
  BACKWARD,
  STOPPED
};

class Led {
  int ledPin;
  long onTime;
  long offTime;

  int ledState;
  unsigned long previousMillis;

public:
  Led(int pin, long on, long off) {
    this->ledPin = pin;
    pinMode(ledPin, OUTPUT);

    this->onTime = on;
    this->offTime = off;

    ledState = LOW;
    previousMillis = 0;
  }

  void Update() {

    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();

    if ((ledState == HIGH) && (currentMillis - previousMillis >= onTime)) {
      ledState = LOW;                  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    } else if ((ledState == LOW) && (currentMillis - previousMillis >= offTime)) {
      ledState = HIGH;                 // turn it on
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
  }
};

class Motor {
  int speedControlPin;       // enA or enB
  int directionControlPin1;  // in1 or in3
  int directionControlPin2;  // in2 or in4

  static const int MAX_SPEED = 255;

public:
  Motor(int speedControlPin, int dirControlPin1, int dirControlPin2) {
    this->speedControlPin = speedControlPin;
    this->directionControlPin1 = dirControlPin1;
    this->directionControlPin2 = dirControlPin2;

    pinMode(speedControlPin, OUTPUT);
    pinMode(directionControlPin1, OUTPUT);
    pinMode(directionControlPin2, OUTPUT);
  }

  void setDirection(Direction dir) {
    switch (dir) {
      case FORWARD:
        digitalWrite(directionControlPin1, HIGH);
        digitalWrite(directionControlPin2, LOW);
      case BACKWARD:
        digitalWrite(directionControlPin1, LOW);
        digitalWrite(directionControlPin2, HIGH);
      case STOPPED:
      default:
        digitalWrite(directionControlPin1, LOW);
        digitalWrite(directionControlPin2, LOW);
    }
  }

  void setSpeed(int speed) {
    if (speed > 0) {
      setDirection(FORWARD);
    } else if (speed < 0) {
      setDirection(BACKWARD);
    } else {
      setDirection(STOPPED);
    }

    analogWrite(speedControlPin, map(speed, 0, 255, 0, MAX_SPEED));
  }
};

class Photoresistor {
  int ldrPin;

public:
  Photoresistor(int pin) {
    this->ldrPin = pin;
    pinMode(ldrPin, INPUT);
  }

  int read() {
    int r = analogRead(ldrPin);
    Serial.print("Light: ");
    Serial.print(r);
    Serial.println();

    return r;
  }
};

class DistanceSensor {
  int triggerPin;
  int echoPin;

  const static long SENSE_INTERVAL = 100;  // in millis

  unsigned long previousTime;  // millis
  unsigned long senseTime;     // millis, for ping delay computation
  long updateInterval;         // millis, for update interval computation
  bool isReading;

  int latestDistance;

public:
  DistanceSensor(int triggerPin, int echoPin, long updateInterval) {
    this->triggerPin = triggerPin;
    this->echoPin = echoPin;
    this->updateInterval = updateInterval;

    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    digitalWrite(triggerPin, LOW);  // Initialize pin with 0

    previousTime = 0;
    senseTime = 0;
    isReading = false;
  }

  int read() {
    return latestDistance;
  }

  void beginRead() {
    if (isReading) return;

    Serial.println("Begin read");

    digitalWrite(triggerPin, HIGH);
    isReading = true;
    senseTime = millis();
  }

  void
  finishRead() {
    digitalWrite(triggerPin, LOW);
    long t = pulseIn(echoPin, HIGH);  // get pulse width
    latestDistance = t / 59;          // scale time to distance in cm
    isReading = false;                // disable reading mode

    Serial.print("Distance: ");
    Serial.print(latestDistance);  //Enviamos serialmente el valor de la distancia
    Serial.print("cm");
    Serial.println();
  }

  void Update() {
    unsigned long currentTime = millis();

    //begin sense interval, finish update interval
    if (!isReading && currentTime - previousTime > updateInterval) {
      beginRead();
    }

    //begin update interval, finish sense interval
    if (isReading && currentTime - senseTime > SENSE_INTERVAL) {
      finishRead();
      previousTime = millis();
    }
  }
};

class Car {
  DistanceSensor distanceSensor;
  Motor leftMotor;
  Motor rightMotor;
  Photoresistor leftLdr;
  Photoresistor rightLdr;
  Led leftLed;
  Led rightLed;

public:
  Car()
    : distanceSensor(12, 11, 100),
      leftMotor(9, 8, 7),
      rightMotor(3, 5, 4),
      leftLdr(A1),
      rightLdr(A0),
      leftLed(13, 500, 500),
      rightLed(10, 500, 500) {}
};

Car car();

void setup() {
  Serial.begin(9600);
}

void loop() {
  
}
