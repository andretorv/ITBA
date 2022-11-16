
#include <Servo.h>

#define TRIG 2
#define ECHO 3

Servo myservo;  // create servo object to control a servo
int duration;
int distance;
int pos = 0;    // variable to store the servo position


void setup() {
  // put your setup code here, to run once:
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);

  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 64286; // = 65536 - 16MHz/256/50Hz (every 20ms)
  TCCR1B |= (1<<CS12);
  TIMSK1 |= (1<<TOIE1);
  interrupts(); // Enable interrupts
}


// Return distance from audio distance sensor in centimeters
int distanceSensor() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration=pulseIn(ECHO, HIGH);
  distance = duration/58; // s = t * (0.034/2) m/s = t / 58
  return distance;
}


// Move the servo motor back and forth, 0-180 deg
void moveServo(){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}



void loop() {
  // put your main code here, to run repeatedly:
  distance = distanceSensor();

  if (distance < 10) {
    moveServo();
  } 
}
