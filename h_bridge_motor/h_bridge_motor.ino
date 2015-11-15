// pair 1 - yellow, orange
int p1a = 5;
int p1b = 10;

// pair 2 - blue, green
int p2a = 9;
int p2b = 6;


void setup() {
  pinMode(p1a, OUTPUT);
  pinMode(p1b, OUTPUT);
  pinMode(p2a, OUTPUT);
  pinMode(p2b, OUTPUT);
}

void loop() {
  int onTime = 1000;
  int offTime = 3000;
  

  delay(offTime);

  hBridge(LOW,HIGH);
  
  delay(onTime);
  
  hBridge(HIGH,LOW);
}


void hBridge(int stateP1, int stateP2) {
  digitalWrite(p1a, stateP1);
  digitalWrite(p1b, stateP1);
  digitalWrite(p2a, stateP2);
  digitalWrite(p2b, stateP2);  
}
