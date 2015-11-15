int motorPin = 9;

void setup() {
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int onTime = 1000;
  int offTime = 3000;
  

  digitalWrite(motorPin, LOW);
  delay(offTime);

  digitalWrite(motorPin, HIGH);
  delay(onTime);
}
