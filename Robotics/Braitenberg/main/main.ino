
#include <Servo.h>
// Define stuff and pins

//sensor de distancia pines
#define TRIG 49
#define ECHO 48

//motor A pines ( LEFT )
int pwm1 = 9; //ENA
int motorIn2 = 2; //out2
int motorIn1 = 3; //out1

//motor B pines ( RIGHT )
int pwm2 = 10; //ENB
int motorIn3 = 4;
int motorIn4 = 5;

//sensor Luz
const int ldrPinRight = A0; //motor A
const int ldrPinLeft = A2; //motor B


// Global variables
unsigned long lastUpdate = 0;
unsigned long updateInterval = 500;
int distance;

////////////////////////////////////////////
// Code for distance sensor:
////////////////////////////////////////////

// Return distance from audio distance sensor in centimeters
int readDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  int duration = pulseIn(ECHO, HIGH);
  distance = duration * (0.034 / 2); // s = t * (0.034/2) m/s

  return distance;
}

void checkDistance() {
  if ((millis() - lastUpdate) > updateInterval) {
    lastUpdate  = millis();
    while (readDistance() < 15) {
      driveTurn(50); // velocity of 100
    }

    Serial.println("Distance: ");
    Serial.println(readDistance());
  }
}

////////////////////////////////////////////
// Code for light sensor:
////////////////////////////////////////////
int readLight(int ldrPin) {
  return analogRead(ldrPin);
}

int lightToVelocity(int ldr) {
  if ( ldr < 100) {
    return ldr+50;
  }
  if (ldr >= 100) {
    return ldr+50;
  }
}

void driveLuz() {

  int ldrRight = readLight(ldrPinRight);
  int ldrLeft = readLight(ldrPinLeft);

  Serial.println("Left light: ");
  Serial.println(ldrLeft);
  Serial.println("Right light:");
  Serial.println(ldrRight);

  int vRight = lightToVelocity(ldrRight);
  int vLeft = lightToVelocity(ldrLeft);

  analogWrite(pwm1, vRight); //ENA pin
  analogWrite(pwm2, vLeft); //ENB pin


  if (ldrLeft >= 100) { // too much light, go backwards
    //esta yendo para atras
    digitalWrite(motorIn1, LOW);
    digitalWrite(motorIn2, HIGH);
  }
  else  { // little light, keep going
    //ir para adelante
    digitalWrite(motorIn1, HIGH);
    digitalWrite(motorIn2, LOW);
  }
  if (ldrRight >= 100) {
    //esta yendo para atras
    digitalWrite(motorIn3, LOW);
    digitalWrite(motorIn4, HIGH);
  }
  else {
    //ir para adelante
    digitalWrite(motorIn3, HIGH);
    digitalWrite(motorIn4, LOW);
  }
}

////////////////////////////////////////////
// Code for driving the vehicle:
////////////////////////////////////////////
void driveForward(int v) {
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);

  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
}

void driveTurn(int v) {
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);

  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
}

void driveBackward(int v) {
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn1, HIGH);

  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
}


////////////////////////////////////////////
// MAIN CODE
////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(ldrPinLeft, INPUT);
  pinMode(ldrPinRight, INPUT);

  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);

  updateInterval = 100;
  lastUpdate = 0;
}

void loop() {
  // put your main code here, to run repeatedly:

  driveLuz(); // this one is based on light. This one just runs
  delay(1000);

  checkDistance(); // sometimes, check if there is an obstruction. This one runs with millis
}
