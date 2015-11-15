int motorPin = 9;
void setup () {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //motorOnThenOff();
  //motorOnThenOffWithSpeed();
  motorAcceleration();
}

void motorAcceleration() {
  int inc = 5;
  boolean stopping = false;
  int currentInc = 0;
  
  while (true) {
    currentInc += inc;
    if (currentInc == 0 | currentInc == 255) {
      inc = -inc;
    }    
    
    analogWrite(motorPin, currentInc);
    delay(100);
    Serial.println(currentInc);
  }
}

void motorOnThenOffWithSpeed() {
  int onTime = 2500;
  int offTime = 1000;
  int onSpeed = 200;
  int offSpeed = 50;
  analogWrite(motorPin, onSpeed);
  delay(onTime);
  analogWrite(motorPin, offSpeed);
  delay(offTime);
}

void motorOnThenOff() {
  int onTime = 2500;
  int offTime = 1000;
  digitalWrite(motorPin, HIGH);
  delay(onTime);
  digitalWrite(motorPin, LOW);
  delay(offTime);
}
