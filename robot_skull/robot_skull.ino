/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
#include <Servo.h>
Servo jaw;
Servo neck;

 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int L_LED = 2;
int R_LED = 4;
int JAW_OPEN = 20;
int JAW_CLOSED  = -10;
int SOUND_THRESHOLD = 40;
int SOUND_SENSOR = A5;
int JAW_DELAY = 300;

int BUTTON_PIN = 12;
int NECK_PIN = 6;
int JAW_PIN = 7;
byte noise;
int button_state = 0;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(R_LED, OUTPUT); 
  pinMode(L_LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);  
  jaw.attach(JAW_PIN);
  neck.attach(NECK_PIN);  
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void flash(int led) {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(10);               // wait for a second
}

void eyes(int state) {
  digitalWrite(R_LED, state);
  digitalWrite(L_LED, state);
}

void move_jaw(int pos) {
  jaw.write(pos);
}

void move_neck() {
  neck.write(random(-45,45));
}

void loop() {
  //listen_sound();
  listen_button();
  delay(10);
  
}

void listen_button() {
  button_state = digitalRead(BUTTON_PIN);
  Serial.println(button_state);
  if (button_state == 1) {
    Serial.println("MOVE JAW");
    eyes(HIGH);
    move_jaw(JAW_OPEN);
    delay(JAW_DELAY);
    move_jaw(JAW_CLOSED);
    eyes(LOW);
    move_neck();
  } else {
    // stop buzzing servo
    Serial.println("CLOSE JAW");
    move_jaw(JAW_CLOSED);
  }
}



void listen_sound() {
  noise = analogRead(SOUND_SENSOR);
  Serial.println(noise);
  if (noise >= SOUND_THRESHOLD) {
    Serial.println("MOVE JAW");
    eyes(HIGH);
    move_jaw(JAW_OPEN);
    delay(JAW_DELAY);
    move_jaw(JAW_CLOSED);
    eyes(LOW);
  } else {
    // stop buzzing servo
    move_jaw(JAW_CLOSED);
  }
}


