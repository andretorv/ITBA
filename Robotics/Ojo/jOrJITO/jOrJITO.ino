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


int vertPos = 180;
int horiPos = 90;


void setup(){
  //define pin numbers of the servo motors
  upDownServo.attach(6);
  rightLeftServo.attach(5);

  //starting position of the servo motors
  delay(5); //estaba 10
  upDownServo.write(vertPos);
  rightLeftServo.write(horiPos);
}





void moveUp(int setpoint) {
  int startPoint = vertPos;
  for (vertPos = startPoint; vertPos <= setpoint; vertPos += 1) {
    upDownServo.write(vertPos);
    delay(15);
  }
}

void moveDown(int setpoint) {
  int startPoint = vertPos;
  for (vertPos = startPoint; vertPos >= setpoint; vertPos -= 1) {
    upDownServo.write(vertPos);
    delay(15);
  }
}

void  lookRight(int setpoint) {
  int startPoint = horiPos;
  for (horiPos = startPos; horiPos >= setpoint; horiPos -= 1) {
    rightLeftServo.write(horiPos);
    delay(15);
  }
}

void  lookLeft(int setpoint) {
  int startPoint = horiPos;
  for (horiPos = startPos; horiPos <= setpoint; horiPos += 1) {
    rightLeftServo.write(horiPos);
    delay(15);
  }
}

void moveHorizontal(int setpoint) {
  int startPoint = horiPos;
  int dir = setpoint - startPoint;
  if (dir > 0) {
    moveLeft(setpoint);
  } else {
    moveRight(setpoint);
  }
}

void moveVertical(int setpoint) {
  int startPoint = vertPos;
  int dir = setpoint - starTPoint;
  if (dir > 0) {
    moveUp(setpoint);
  } else {
    moveDown(setpoint);
  }
}


void loop(){

  delay(1000);
  moveDown(145);
  delay(1000);
  moveDown(90);
  delay(1000);
  moveUp(180);


  delay(1000);

  upDownServo.write(0);
  delay(2000);
  upDownServo.write(90);
  delay(2000);
  upDownServo.write(180);
  /*
  delay(1000); //estaba 1000
  upDownServo.write(halfOpen);

  upDwonServo.write(halfOpen + 10);
  upDownServo.write(halfOpen + 20);
  
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
  */
}
