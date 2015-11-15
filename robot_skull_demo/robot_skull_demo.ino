// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
 Servo servo2;
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = -20;    // variable to store the servo position 

int mp = 180;
 
void setup() 
{ 
  servo2.attach(6);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
 
void loop() 
{ 
//  servo2.write(20);
//  for(pos = 0; pos < mp; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {           // in steps of 1 degree 
//   
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(10);                       // waits 15ms for the servo to reach the position 
//  } 
//  servo2.write(0); 
//  for(pos = mp; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {    
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(10);                       // waits 15ms for the servo to reach the position 
//  } 
eyes(LOW);
  myservo.write(0);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(-180);
  delay(1000);

servo2.write(0);
delay(400);
servo2.write(15);

delay(400);

eyes(HIGH);

servo2.write(10);
delay(400);
}

void eyes(int state) {
  digitalWrite(2, state);
  digitalWrite(4, state);
}
