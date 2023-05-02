// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

// Photoresistor connection
const int pResistor1 = A0;  // Photoresistor at Arduino analog pin A0 //DERECHA
const int pResistor2 = A1;  // Photoresistor at Arduino analog pin A0 //IZQUIERDA

// LED conneciton
const int ledPin1 = 10;  //led derecho
const int ledPin2 = 13;  //led izquierdo

// Distance sensor connections
const int trigger = 12;  //Pin digital 2 para el Trigger del sensor
const int echo = 11;     //Pin digital 3 para el echo del sensor

const int MAX_SENSOR_DISTANCE = 20;
const int MIN_SENSOR_DISTANCE = 7;

const int LED_THRESHOLD = 700;

const int WAIT_TIME = 500;

/*

ZONA DE BEHAVIOUR

*/

//recommended 5cm
int computeSpeedFromDistance(int distance, int minDistance, int maxDistance) {
  if (distance < minDistance) {
    return 0;
  }
  if (distance > maxDistance) {
    return 255;
  }
  return map(distance, minDistance, 1180, 50, 255);
}

//recommended 5cm
//strength from 0 to 1024
int computeSpeedFromLight(int strengthL, int strengthR, int threshold) {
  if (strengthL < threshold && strengthR < threshold) {
    return 255;
  }
  return 0;
  // if (distance > maxDistance) {
  //   return 0;
  // }
  // return map(distance, minDistance, 1180, 50, 255);
}
int behaviour() {
  int p1 = readPhotoresistor1();
  int p2 = readPhotoresistor2();
  int speed = computeSpeedFromLight(p1, p2, LED_THRESHOLD);
  Serial.println(speed);
  moveForward();
  setMotorsSpeed(speed);
  return speed;
}

void loop() {
  behaviour();
  delay(100);
}

/*

  ZONA DE SETUPS

*/
void setupDistanceSensor() {
  pinMode(trigger, OUTPUT);    //pin como salida
  pinMode(echo, INPUT);        //pin como entrada
  digitalWrite(trigger, LOW);  //Inicializamos el pin con 0
}

void setupLeds() {
  pinMode(ledPin1, OUTPUT);  // Set lepPin - 9 pin as an output
  pinMode(ledPin2, OUTPUT);  // Set lepPin - 10 pin as an output
}

void setupPhotoresistors() {
  pinMode(pResistor1, INPUT);
  pinMode(pResistor2, INPUT);
}

void setupMotors() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void setup() {
  Serial.begin(9600);  //iniciailzamos la comunicación
  setupDistanceSensor();
  setupMotors();
  setupPhotoresistors();
  setupLeds();

  // Turn off motors - Initial state
  turnOffMotors();
}

/*

  ZONA DE LECTURA DE SENSORES

*/

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


void photoResistorLoop() {
  int p1 = readPhotoresistor1();
  int p2 = readPhotoresistor2();

  Serial.print("Luz 1: ");
  Serial.print(p1);
  Serial.println();

  Serial.print("Luz 2: ");
  Serial.print(p2);
  Serial.println();
  digitalWrite(ledPin1, p1 > LED_THRESHOLD ? HIGH : LOW);
  digitalWrite(ledPin2, p2 > LED_THRESHOLD ? HIGH : LOW);
}

int readPhotoresistor1() {
  return analogRead(pResistor1);
}

int readPhotoresistor2() {
  return analogRead(pResistor2);
}

/*

  MOVIMIENTOS

*/


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
void turnOffMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
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
