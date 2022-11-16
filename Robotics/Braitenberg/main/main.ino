
#include <Servo.h>
// Define stuff and pins

  //sensor de distancia pines
  #define TRIG 49
  #define ECHO 48
  
  //motor A pines
  int pwm1 = 9; //ENA
  int motorIn2 = 2; //out2
  int motorIn1 = 3; //out1
  
  //motor B pines
  int pwm2 = 10; //ENB
  int motorIn3 = 4; 
  int motorIn4 = 5;
  
  //sensor Luz
  const int ldrPin1 = A0; //motor A
  const int ldrPin2 = A2; //motor B
  int V1;
  int V2;
  int ldr1;
  int ldr2;

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
  duration=pulseIn(ECHO, HIGH);
  distance = duration * (0.034/2); // s = t * (0.034/2) m/s
  
  return distance;
}

int distanceLevel(distance) {
  // return definition of distance level
}

////////////////////////////////////////////
// Code for light sensor: 
////////////////////////////////////////////
int readLight(int ldrPin) {
  return analogRead(ldrPin);
}

int lightLevel(int light1, int light2){
  // define light levels based on the two
}

////////////////////////////////////////////
// Code for driving the vehicle:
////////////////////////////////////////////
void driveForward(int v){
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin 
  
  //Controlling spin direction of motors:
  digitalWrite(motorIn2, HIGH);
  digitalWrite(motorIn1, LOW);
  
  digitalWrite(motorIn3, HIGH);
  digitalWrite(motorIn4, LOW);
}

void driveTurn(int v){
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin 
  
  //Controlling spin direction of motors:
  digitalWrite(motorIn1, LOW);
  digitalWrite(motorIn2, HIGH);
  
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
}

void driveBackward(int v){
  analogWrite(pwm1, v); //ENA pin
  analogWrite(pwm2, v); //ENB pin 
  
  //Controlling spin direction of motors:
  digitalWrite(motorIn2, LOW);
  digitalWrite(motorIn1, HIGH);
  
  digitalWrite(motorIn3, LOW);
  digitalWrite(motorIn4, HIGH);
}

////////////////////////////////////////////
// Update function of values 
////////////////////////////////////////////
void Update() {
  if ((millis() - lastUpdate)) > updateInterval) {
    lastUpdate  = millis();
    distance    = readDistance();
    lightRight  = readLight(ldrPin1);
    lightLeft   = readLight(ldrPin2);
  }
} 

////////////////////////////////////////////
// MAIN CODE
////////////////////////////////////////////

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  
  pinMode(ldrPin1, INPUT);
  pinMode(ldrPin2, INPUT);
  
  pinMode(motorIn2, OUTPUT);
  pinMode(motorIn1, OUTPUT);
  pinMode(motorIn3, OUTPUT);
  pinMode(motorIn4, OUTPUT);
  pinMode(pwm1, OUTPUT); 
  pinMode(pwm2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
