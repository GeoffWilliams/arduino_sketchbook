#include <Servo.h>

Servo myServo;
int potpin = A0;

int val;

void setup() {
  Serial.begin(9600);
  myServo.attach(9);
}


void loop() {
  val = analogRead(potpin);
  Serial.println(val);
  val = map(val, 286, 110, 0, 179);
  myServo.write(val);
  delay(15);
}
