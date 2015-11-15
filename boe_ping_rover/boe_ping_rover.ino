// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo servoL;  // 0     forward
Servo servoR; // 180   forward
int pinger = 5;
  
 
void setup() 
{ 

  // kill twiching during startup
  Serial.begin(9600);
  servoL.attach(6);  // attaches the servo on pin 9 to the servo object 
  servoR.attach(7);
  
  // kill twichingss - move to stop position immediately
  servoL.write(90);
  servoR.write(90);
} 
 
 
void forward() {
  Serial.println("^");
  servo(180,0,15);
}

void left() {
  Serial.println("<");
  servo(90,0, 30);
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

}
 
long distance() {
  pinMode(pinger, OUTPUT); // Switch signalpin to output

  /* Send low-high-low pulse to activate the trigger pulse of the sensor
   * -------------------------------------------------------------------
   */

  digitalWrite(pinger, LOW); // Send low pulse  
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(pinger, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(pinger, LOW); // Holdoff
  
  
  /* Listening for echo pulse
   * -------------------------------------------------------------------
   */

  pinMode(pinger, INPUT); // Switch signalpin to input
  return pulseIn(pinger, HIGH);
} 
 
void loop() 
{ 

  long duration = distance();
  //Serial.println(duration);


  if (duration > 2000) {
    forward();
  } else {
    left();
  }
  delay(1000);
} 
