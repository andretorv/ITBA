
// include library for servo
#include <Servo.h>

// define name of the servo motors
Servo horizontalServo;
Servo verticalServo;

// define position name and value
  // horizontal movement
#define right    45
#define middle   90
#define left     145

  //vertical movement
#define closed   90
#define halfOpen 130
#define fullOpen 170

// speed configurations for eye movement
#define eyeSpeed  20
#define increment 2

#define waitTime 600

// pin variables
#define pinHorizontal 5
#define pinVertical   6

// initialize current position variables
int vertPos;
int horiPos;

////////////////////////////////////////
///////// CODE FOR MOVING //////////////
////////////////////////////////////////

  // HORIZONTAL DIRECTION //
void moveRight(int setpoint) {
  int startPoint = horiPos;
  for (horiPos = startPoint; horiPos >= setpoint; horiPos -= increment) {
    horizontalServo.write(horiPos);
    delay(eyeSpeed);
  }
}

void moveLeft(int setpoint) {
  int startPoint = horiPos;
  for (horiPos = startPoint; horiPos <= setpoint; horiPos += increment) {
    horizontalServo.write(horiPos);
    delay(eyeSpeed);
  }
}

// Create function so the code understands whether to move right or left
// based on current position
void moveHorizontal(int setpoint) {
  int startPoint = horiPos;
  int dir = setpoint - startPoint;
  if (dir > 0) {
    moveLeft(setpoint);
  } else {
    moveRight(setpoint);
  }
}

  // VERTICAL DIRECTION //
void moveUp(int setpoint) {
  int startPoint = vertPos;
  for (vertPos = startPoint; vertPos <= setpoint; vertPos += increment) {
    verticalServo.write(vertPos);
    delay(eyeSpeed);
  }
}

void moveDown(int setpoint) {
  int startPoint = vertPos;
  for (vertPos = startPoint; vertPos >= setpoint; vertPos -= increment) {
    verticalServo.write(vertPos);
    delay(eyeSpeed);
  }
}

// Create function so the code understands whether to move up or down
// based on current position
void moveVertical(int setpoint) {
  int startPoint = vertPos;
  int dir = setpoint - startPoint;
  if (dir > 0) {
    moveUp(setpoint);
  } else {
    moveDown(setpoint);
  }
}


////////////////////////////////////////
/////////     MAIN CODE   //////////////
////////////////////////////////////////

void setup(){
  //define pin numbers of the servo motors
  horizontalServo.attach(pinHorizontal);
  verticalServo.attach(pinVertical);

  //starting position of the servo motors
  vertPos = closed; // modes: closed, halfOpen, fullOpen
  horiPos = middle; // modes: right, left, middle
  
  delay(10);
  verticalServo.write(vertPos);
  horizontalServo.write(horiPos);
}

void loop(){
  
  delay(2000); // wait two seconds before starting movement

  // Perform sequence of movement:
    // open eye
  moveVertical(halfOpen);
  delay(waitTime);
  moveVertical(fullOpen);
  delay(waitTime);

    // look around
  moveHorizontal(right);
  delay(waitTime);
  moveHorizontal(left);
  delay(waitTime);
  moveHorizontal(middle);
  delay(waitTime);

    // close, halfwayy open, close eye
  moveVertical(halfOpen);
  delay(waitTime);
  moveVertical(closed);
  delay(waitTime);
  moveVertical(halfOpen);
  delay(waitTime);
  moveVertical(closed);
  delay(waitTime);
}
