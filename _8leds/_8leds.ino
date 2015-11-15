int led_pins[] = {2,3,4,5,6,7,8,9};
int led_pins_count = 8;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  for (int i = 0 ; i < led_pins_count ; i++) {
    pinMode(led_pins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly: 
 // oneAfterAnotherNoLoop();
  // oneAfterAnotherLoop();
 // oneAtATime();
//  Serial.println("loop is alive!");
  sideToSide();
}

void oneAfterAnotherNoLoop() {
  int delayTime = 50;
  for (int i = 0 ; i < led_pins_count ; i++) { 
    digitalWrite(led_pins[i], HIGH);
    delay(delayTime);
  }
}

void oneAtATime() {
  int delayTime = 50;
  for (int i = 0 ; i < led_pins_count  ; i++) {
    digitalWrite(led_pins[i], HIGH);
    delay(delayTime);
    digitalWrite(led_pins[i], LOW);
  }
 
}

void sideToSide() {
  int delayTime = 50;
  int led = 0;
  int nextLed = 1;  
  while (true) {
    Serial.println(led);
    digitalWrite(led_pins[led], HIGH);
    delay(delayTime);
    digitalWrite(led_pins[led], LOW);
  
    led += nextLed;
    if (led == 0 || led == led_pins_count -1) {
      nextLed = -nextLed;
    }
  }
}
  
void oneAfterAnotherLoop() {
  int delayTime = 50;
  for (int i = 0 ; i < led_pins_count ; i++) { 
    digitalWrite(led_pins[i], HIGH);
    delay(delayTime);
  }
  for (int i = 0 ; i < led_pins_count ; i++) { 
    digitalWrite(led_pins[i], LOW);
    delay(delayTime);
  }
  
}
