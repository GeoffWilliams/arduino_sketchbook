const int rpin = 9;
const int gpin = 10;
const int bpin = 11;

void setup() {}
void loop() {
  int sensorValue = analogRead(0);
  int redValue = constrain( 
    map(sensorValue, 0, 512, 255, 0), 0, 255);
    
   int greenValue = constrain(
    map(sensorValue, 0, 512, 0, 255), 
    0, 
    255) -
    constrain(
      map(sensorValue, 512, 1023, 0, 255), 0, 255);
    
    int blueValue = constrain(
      map(sensorValue, 512, 1023, 0, 255), 0, 255);
      
      analogWrite(rpin, redValue);
      analogWrite(gpin, greenValue);
      analogWrite(bpin, blueValue);
}
