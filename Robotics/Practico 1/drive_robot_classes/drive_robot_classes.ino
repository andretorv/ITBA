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

  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

}
