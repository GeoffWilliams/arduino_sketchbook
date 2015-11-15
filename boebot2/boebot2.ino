// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo servoL;  // 0     forward
Servo servoR; // 180   forward
  
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  // kill twiching during startup
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
  servoL.attach(0);  // attaches the servo on pin 9 to the servo object 
  servoR.attach(1);
} 
 
 
void forward() {
  servo(180,0,3000);
}

void left() {
  servo(90,0, 1100);
}

void right() {
  servo(180, 0, 100);
}

void backward() {
   servo(0,180,15);
}

void servo(int l, int r, int t) {
  servoR.write(r);
  servoL.write(l);
  delay(t); 
}
 
void loop() 
{ 
  forward();
  left();
  forward();
  left();
  forward();
  left();
  forward();
} 
