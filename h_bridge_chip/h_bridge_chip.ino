// pair 1 - yellow, orange
int enableMotorPin = 10;
int motorPin1 = 3;
int motorPin2 = 5;

void setup() {
  Serial.begin(9600);
  pinMode(enableMotorPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
 
  
  delay(3000
  );
  
  Serial.println("direction a");
  for (int i =120 ; i < 256 ; ++i) {
    Serial.println(i);
    drive(HIGH, LOW, i);
    delay(200);  
  }
  for (int i =255 ; i >120 ; --i) {
    Serial.println(i);
    drive(HIGH, LOW, i);
    delay(200);  
  }
  
  delay(2000);
  
  Serial.println("direction b");
  for (int i =120  ; i < 256 ; ++i) {
    Serial.println(i);
    drive(LOW,HIGH, i);
    delay(200);  
  }
  for (int i =255 ; i >120 ; --i) {
    Serial.println(i);
    drive(LOW, HIGH,
   
    i);
    delay(200);  
  }
  
  
}

void drive(int a, int b,int s) {
   analogWrite(enableMotorPin, s );
   digitalWrite(motorPin1, a);
   digitalWrite(motorPin2, b);
}

