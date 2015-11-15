
int sensorPin = A0;    // select the input pin for the potentiometer
int ledPin = 5;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin); 
  float voltage= sensorValue * (5.0 / 1024.0);  
  
  float humidity = (voltage - 0.958)/0.0307;
  
  
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);  
  delay(1000);          
  // turn the ledPin off:        
  digitalWrite(ledPin, LOW);   
  Serial.println(humidity);           
}
