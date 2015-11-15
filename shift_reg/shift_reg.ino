int data = 2;
int clock = 3;
int latch = 4;

//Used for single LED manipulation
int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup() {
  pinMode(data, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(latch, OUTPUT);
}

void loop() {
  int delayTime = 100;
  for (int i = 0 ; i < 8 ; i++) {
    changeLED(i,ON);
    delay(delayTime);
  }
  for (int i = 0 ; i < 8 ; i++) {
    changeLED(i, OFF);
    delay(delayTime);
  }

}
    
 
 //These are used in the bitwise math that we use to change individual LEDs
//For more details http://en.wikipedia.org/wiki/Bitwise_operation
int bits[] = {B00000001, B00000010, B00000100, B00001000, B00010000, B00100000, B01000000, B10000000};
int masks[] = {B11111110, B11111101, B11111011, B11110111, B11101111, B11011111, B10111111, B01111111};
/*
 * changeLED(int led, int state) - changes an individual LED 
 * LEDs are 0 to 7 and state is either 0 - OFF or 1 - ON
 */
 void changeLED(int led, int state){
   ledState = ledState & masks[led];  //clears ledState of the bit we are addressing
   if(state == ON){ledState = ledState | bits[led];} //if the bit is on we will add it to ledState
   updateLEDs(ledState);              //send the new LED state to the shift register
}
 
 
void updateLEDs(int value) {
    digitalWrite(latch, LOW);
    shiftOut(data, clock, MSBFIRST, value);
    digitalWrite(latch, HIGH);
}


