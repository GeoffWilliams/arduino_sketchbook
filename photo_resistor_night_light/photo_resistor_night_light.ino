int lightPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(lightPin);
  int threshold = 400;
 
  if (lightLevel < 400) {
      //light
      digitalWrite(ledPin, LOW);
  } else {
      digitalWrite(ledPin, HIGH);
  }
  
}
