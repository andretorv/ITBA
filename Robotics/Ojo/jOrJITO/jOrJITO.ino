//include library for servo
#include <Servo.h>

//define name of the servo motors
Servo upDownServo;
Servo rightLeftServo;

//define position name and value
#define left 60
#define right 120
#define middle 90
#define closed 60
#define fullOpen 160
#define halfOpen 120

#define waitTime 600 //estaba 750

#define increment 10

int rightLeftMode = 0;
int upDownMode = 0;

void setup(){
  //define pin numbers of the servo motors
  upDownServo.attach(6);
  rightLeftServo.attach(5);

  //starting position of the servo motors
  delay(5); //estaba 10
  upDownServo.write(closed);
  rightLeftServo.write(middle);
}

int incrementLeftRight(int mode) {
  // move left or right, with increments
  if (mode == 0) { // Move right
    newPosition = currentPosition + increment;
    rightLeftServo.write(newPosition);
    return newPosition;
  } else {
    newPosition = currentPosition - increment;
    rightLeftServo.write(newPosition);
    return newPosition;
  }
  return currentPosition
}

int incrementUpDown(int mode) {
  // move left or right, with increments
  if (mode == 0) { // Move up
    newPosition = currentPosition + increment;
    upDownServo.write(newPosition);
    return newPosition;
  } else {
    newPosition = currentPosition - increment;
    upDownServo.write(newPosition);
    return newPosition;
  }
  return currentPosition
}



void loop(){
  
  delay(1000); //estaba 1000
  upDownServo.write(halfOpen);
  delay(waitTime);
  rightLeftServo.write(right);
  delay(waitTime);
  rightLeftServo.write(left);
  delay(waitTime);
  rightLeftServo.write(middle);

  delay(1000); //estaba 1000
  upDownServo.write(closed);
  delay(waitTime);
  upDownServo.write(fullOpen);
  delay(waitTime);
  upDownServo.write(closed);
  delay(waitTime);
  upDownServo.write(fullOpen);
  delay(waitTime);
  rightLeftServo.write(right);
  delay(waitTime);
  rightLeftServo.write(left);
  delay(waitTime);
  rightLeftServo.write(middle);
  upDownServo.write(halfOpen);
  delay(waitTime);
  rightLeftServo.write(right);
  delay(waitTime);
  rightLeftServo.write(left);
  delay(waitTime);
  rightLeftServo.write(middle);
  delay(waitTime);
  upDownServo.write(fullOpen);
  delay(waitTime);
  upDownServo.write(halfOpen);
  delay(waitTime);
  upDownServo.write(fullOpen);
  delay(waitTime);
  rightLeftServo.write(right);
  delay(waitTime);
  rightLeftServo.write(left);
  delay(waitTime);
  rightLeftServo.write(middle);
}
