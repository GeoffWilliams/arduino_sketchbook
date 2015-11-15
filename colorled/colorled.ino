const int RED_LED_PIN = 9;
const int GREEN_LED_PIN = 10;
const int BLUE_LED_PIN = 11;

int redIntensity = 0;
int greenIntensity = 0;
int blueIntensity = 0;

const int DISPLAY_TIME = 100;

void setup() {}

void updateLed() {
   analogWrite(RED_LED_PIN, redIntensity);
   analogWrite(GREEN_LED_PIN, greenIntensity);
   analogWrite(BLUE_LED_PIN, blueIntensity);
 }

void loop() {
  for (  greenIntensity = 0 ; 
         greenIntensity <= 255;
         greenIntensity++) {
           
     redIntensity = 255 - greenIntensity; 
      updateLed();
      delay(DISPLAY_TIME );
    }
    
    for (blueIntensity = 0 ;
      blueIntensity <= 255;
      blueIntensity++) {
        greenIntensity = 255 - blueIntensity;
         updateLed();
        delay(DISPLAY_TIME ); 
      }
    
    for  (redIntensity = 0 ; 
        redIntensity <= 255 ;
        redIntensity++) {
          blueIntensity = 255 - redIntensity;
          updateLed();
          delay(DISPLAY_TIME );
        }
        
}
