int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

int pwm1 = 9;
int pwm2 = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(pwm1, OUTPUT); 
  pinMode(pwm2, OUTPUT);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:   

  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(pwm1, 100); //ENA pin
  analogWrite(pwm2, 200); //ENB pin

  //Controlling spin direction of motors:
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(1000);

  analogWrite(pwm1, 0); //ENA pin
  analogWrite(pwm2, 0); //ENB pin
  delay(1000);
  analogWrite(pwm1, 100); //ENA pin
  analogWrite(pwm2, 200); //ENB pin
  
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(1000);

  analogWrite(pwm1, 0); //ENA pin
  analogWrite(pwm2, 0); //ENB pin
  delay(1000);
  analogWrite(pwm1, 100); //ENA pin
  analogWrite(pwm2, 200); //ENB pin

  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
