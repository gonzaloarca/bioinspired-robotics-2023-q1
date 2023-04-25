// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

const int trigger = 12;  //Pin digital 2 para el Trigger del sensor
const int echo = 11;     //Pin digital 3 para el echo del sensor

void setupDistanceSensor() {
  Serial.begin(9600);          //iniciailzamos la comunicación
  pinMode(trigger, OUTPUT);    //pin como salida
  pinMode(echo, INPUT);        //pin como entrada
  digitalWrite(trigger, LOW);  //Inicializamos el pin con 0
}

int getSensorDistance() {

  long t;  //timepo que demora en llegar el eco
  long d;  //distancia en centimetros

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);  //Enviamos un pulso de 10us
  digitalWrite(trigger, LOW);

  t = pulseIn(echo, HIGH);  //obtenemos el ancho del pulso
  d = t / 59;               //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print(d);  //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  return d;  //Hacemos una pausa de 100ms
}

//recommended 5cm
int computeSpeed(int distance, int minDistance, int maxDistance) {
  if (distance < minDistance) {
    return 0;
  }
  if (distance > maxDistance) {
    return 255;
  }
  return map(distance, minDistance, 1180, 50, 255);
}

void turnOffMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void setup() {
  setupDistanceSensor();

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  turnOffMotors();
}

int MAX_SENSOR_DISTANCE = 20;
int MIN_SENSOR_DISTANCE = 7;

void loop() {
  int d = getSensorDistance();

  int speed = computeSpeed(d, MIN_SENSOR_DISTANCE, MAX_SENSOR_DISTANCE);

  moveForward();

  setMotorsSpeed(speed);
  delay(100);
}

void moveAForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void moveABackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void moveBForward() {
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBBackward() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveForward() {
  moveAForward();
  moveBForward();
}

void moveBackward() {
  moveABackward();
  moveBBackward();
}

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // Turn on motor A & B
  moveForward();
  delay(2000);

  // Now change motor directions
  moveBackward();
  delay(2000);

  // Turn off motors
  turnOffMotors();
}

// This function lets you control speed of the motors
void setMotorsSpeed(int speed) {
  analogWrite(enA, speed);
  analogWrite(enB, speed);
}
