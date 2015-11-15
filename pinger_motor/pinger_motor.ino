int pinger = 13;
int timecount = 0;
int enableMotorPin = 10;
int motorPin1 = 3;
int motorPin2 = 5;


void setup() {
  Serial.begin(9600);
  pinMode(enableMotorPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  
  
 timecount = 0;
 int 
 val = 0;
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
  while(digitalRead(pinger) == LOW) {}// Loop until pin reads a high value
  val = digitalRead(pinger);

  int timecount = 0;
  
  while(digitalRead(pinger) == HIGH) { // Loop until pin reads a high value
    timecount++;
  }

  Serial.println(timecount);
  
  
  
  
  controlMotor(timecount);

}

void controlMotor(int val) {
  int a;
  int b;
  int s;
  
  if (val < 100) {
    a = HIGH;
    b = LOW;
    s = 150;
  } else {
    a = LOW;
    b = HIGH;
    s = 200;
  }  
  drive(a,b,s);
  delay(100);
  
}

void drive(int a, int b,int s) {
  Serial.println(String(a) + " " + String(b) + " " + String(s));
   analogWrite(enableMotorPin, s );
   digitalWrite(motorPin1, a);
   digitalWrite(motorPin2, b);
}

