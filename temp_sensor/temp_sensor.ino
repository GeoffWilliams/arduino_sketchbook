int temperaturePin = A0;

// value of each milivolt increment (5 / 1024)
float mvInc = .004882814;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float temperature = getVoltage(temperaturePin);
  float tempF;
  temperature = (temperature - .5) * 100;
  tempF = temperature * 1.8 + 32;
  Serial.println(
    convertFloat(temperature) + "C     " + 
    convertFloat(tempF) + "F");
    
 // Serial.println(temperature);
    
  delay(1000);
}

float getVoltage(int pin) {
  return analogRead(pin) * mvInc;
}

String convertFloat(float f) {
  int SF = 100;
  int integer = (int) f;
  int fractionPart = (f - integer)* SF;
  String fraction = "X";// String(f * SF - integer * SF);
  
  return String(integer) + "." + String(fractionPart);
}
