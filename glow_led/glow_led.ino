/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
int brightness = 0;
int MAX_BRIGHTNESS = 255;
int led_pin = 9;
boolean dimming = false;

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(led_pin, OUTPUT);   
  Serial.begin(9600);
}

void loop() {
  if (brightness < MAX_BRIGHTNESS && ! dimming) {
    brightness++;
  } else if (brightness == MAX_BRIGHTNESS) {
    dimming = true;
    brightness--;
  } else if (brightness > 0 && dimming) { 
    brightness--;
  } else {
    dimming = false;
  }

  Serial.println(brightness);
  
  analogWrite(led_pin, brightness);   // set the LED on
  delay(1); 
}
