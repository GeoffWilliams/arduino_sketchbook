int lightPin = A0;
int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightLevelOrig = analogRead(lightPin);
  int lightLevelMapped;
  int lightLevelConstrained;
  
  lightLevelMapped = map(lightLevelOrig, 370, 500, 0, 255);
  lightLevelConstrained = constrain(lightLevelMapped, 0, 255);

  Serial.println(
    String(lightLevelOrig) + "      " + 
    String(lightLevelMapped) + "      " +
    String(lightLevelConstrained));
  analogWrite(ledPin, lightLevelConstrained);
}
