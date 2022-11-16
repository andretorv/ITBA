#include <Servo.h>

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

//sensamos luz
int luz(int ldr){
  if ( ldr < 100){
    return ldr+50;
    }
  if (ldr>=100) {
    return ldr+55;
    }
  }

//manejamos con luz
void driveLuz(int v1, int v2){
  analogWrite(pwm1, v1); //ENA pin
  analogWrite(pwm2, v2); //ENB pin
  if (v1 >= 150){
    //esta yendo para atras
    digitalWrite(motorIn2, LOW);
    digitalWrite(motorIn1, HIGH);
    }
   else  {
    //ir para adelante
    digitalWrite(motorIn2, HIGH);
    digitalWrite(motorIn1, LOW);
    }
    if (v2 >=150){
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
void loop() {
  ldr1=analogRead(ldrPin1);
  ldr2=analogRead(ldrPin2);
  V1 = luz(ldr1);
  Serial.println("A0: ");
  Serial.println(V1);
  V2=luz(ldr2);
  Serial.println("A1: ");
  Serial.println(V2);
  driveLuz(V1,V2);
}
