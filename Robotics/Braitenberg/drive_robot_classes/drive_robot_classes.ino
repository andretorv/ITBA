#include <Servo.h>

class DistanceSensor
{
  int distance; // distance measured
  int updateInterval = 100; 
  unsigned long lastUpdate; 

  public: 
  DistanceSensor(int pinPwm1, int pinPwm2, int pinTrig, int pinEcho) {
    pinMode(pinPwm1, OUTPUT);
    pinMode(pinPwm2, OUTPUT);
    pinMode(pinTrig, OUTPUT);
    pinMode(pinEcho, OUTPUT);
  }
  
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
  
  void Update() {
    if ((millis() - lastUpdate)) > updateInterval) {
      lastUpdate = millis();
      distance = readDistance();
    }
  } 
}

class Vehicle
{
  int velocity; 
  int distance; 
  int updateInterval = 100;
  unsigned long lastUpdate;

  public:
  Vehicle() {
    // setup for motors
    pinMode(motor1pin1, OUTPUT);
    pinMode(motor1pin2, OUTPUT);
    pinMode(motor2pin1, OUTPUT);
    pinMode(motor2pin2, OUTPUT);
  
    pinMode(pwm1, OUTPUT); 
    pinMode(pwm2, OUTPUT);
  }
  
  void driveForward(int v) {
    //Controlling speed (0 = off and 255 = max speed):
    analogWrite(pwm1, v); //ENA pin
    analogWrite(pwm2, v); //ENB pin 
    
    //Controlling spin direction of motors:
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  }

  void driveBackward(int v) {
    //Controlling speed (0 = off and 255 = max speed):
    analogWrite(pwm1, v); //ENA pin
    analogWrite(pwm2, v); //ENB pin 
    
    //Controlling spin direction of motors:
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, HIGH);
  }
  
  void stopMovement() {
    //Controlling speed (0 = off and 255 = max speed):
    analogWrite(pwm1, 0); //ENA pin
    analogWrite(pwm2, 0); //ENB pin 
  }
  
}

class LightSensor 
{
  int lightValue; // light measured
  int updateInterval = 100; 
  unsigned long lastUpdate;

  public: 
  LightSensor(int ldrPin1, int ldrPin2) {
    pinMode(ldrPin1, INPUT);
    pinMode(ldrPin2, INPUT);
  }
  
  int readLight(int ldrPin) { //LOW: 30-50, HIGH: 300 ish
    return analogRead(ldrPin);
    //define values >100 as HIGH LIGHT, <100 as LOW LIGHT
  }
  
  void Update() {
    if ((millis() - lastUpdate)) > updateInterval) {
      lastUpdate = millis();
      lightValue = readLight(ldrPin);
    }
  } 
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  robotMartin = Vehicle(/*place pins here*/);
  leftLightSensor = LightSensor(/*place pins here*/);
  rightLightSensor = LightSensor(/*place pins here*/);
  distanceSensor = DistanceSensor(/*place pins here*/);
}

void loop() {
  // put your main code here, to run repeatedly:
  

}
