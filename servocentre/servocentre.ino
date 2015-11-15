// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo servoA;  // 0     forward
Servo servoB; // 180   forward
  
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  // kill twiching during startup
  servoA.attach(10);  // attaches the servo on pin 9 to the servo object 
  servoB.attach(11);
} 
 
void loop() {
  //  servoA.write(90);
    //servoB.write(90);

  for (int i = 0 ; i  < 181 ; i++) {
    servoA.write(i);
    servoB.write(i);
    delay(5);
  }
  for (int i = 180 ; i  > -1 ; i--) {
    servoA.write(i);
    servoB.write(i);
    delay(5);
  } 
 
}
 

