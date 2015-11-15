int pinger = 2;
int val = 0;
int timecount = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("!BOOT");
}

void loop() {
 timecount = 0;
 val = 0;
 pinMode(pinger, OUTPUT); // Switch signalpin to output

  /* Send low-high-low pulse to activate the trigger pulse of the sensor
   * -------------------------------------------------------------------
   */

  digitalWrite(pinger, LOW); // Send low pulse  
  delayMicroseconds(2); // Wait for 2 microseconds
  digitalWrite(pinger, HIGH); // Send high pulse
  delayMicroseconds(5); // Wait for 5 microseconds
  digitalWrite(pinger, LOW); // Holdoff
  
  
  /* Listening for echo pulse
   * -------------------------------------------------------------------
   */

  pinMode(pinger, INPUT); // Switch signalpin to input
  while(digitalRead(pinger) == LOW) {}// Loop until pin reads a high value
  val = digitalRead(pinger);

  int timecount = 0;
  while(digitalRead(pinger) == HIGH) { // Loop until pin reads a high value
    timecount++;
  }

  Serial.println(timecount);
  delay(100);

}
