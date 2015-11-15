#include <SPI.h>
#include <Ethernet.h>
#include <OneWire.h>


// the media access control (ethernet hardware) address for the shield:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
//the IP address for the shield:
byte ip[] = { 192, 168, 1, 50 };    
byte server[] = { 192, 168, 0, 19 };
String vhost = "python-dev";
String platform_id = "arduino";
String temp_sensor_id = "ds18b20";
String rh_sensor_id = "hih4030";
int temperature_pin = 3;
int humidity_pin = A0;
int led_xmit = 4;
int led_sens = 5;
int led_err = 6;


EthernetClient client;

OneWire  ds(temperature_pin);

void http_post(String rest_path) {
  Serial.println(rest_path);
  if (client.connect(server, 80)) {
    // register platform and sensor
    Serial.println("connescted");
    client.println("POST " + rest_path + " HTTP/1.1");
    client.println("Host: " + vhost);
    client.println();
    flashLed(led_xmit);
    
    // see if we got OK back
    delay(200);
    checkResp();
    client.stop();
    
    
  } else {
    Serial.print("couldn't connect");
    flashLed(led_err);
  }
}

void checkResp() {
  char goodresp[] = "HTTP/1.1 200 OK";
  char resp[16];
  if (client.available()) {
    for (int i = 0 ; i < 15 ; i++) {
      resp[i] = client.read();
    }
    resp[15] = '\0';
    if (strcmp(resp,goodresp)) {
      Serial.println("server error: ");
      Serial.println(goodresp);
      Serial.println(resp);
      flashLed(led_err);
    } else {
      Serial.print("server ok");
    }
  } else {
    Serial.print("no data from server");
    flashLed(led_err);
  }
}

void register_sys() {
  http_post("/" + platform_id);
  http_post("/" + platform_id + "/" + temp_sensor_id);
  http_post("/" + platform_id + "/" + rh_sensor_id);
}

void setup()
{
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  delay(1000);
  register_sys();
}

void flashLed(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, HIGH);
  delay(100);
  digitalWrite(pin, LOW);
}

float readRHSensor() {
  int sensorValue = analogRead(humidity_pin); 
  float voltage= sensorValue * (5.0 / 1024.0);  
  
  float humidity = (voltage - 0.958)/0.0307;
  flashLed(led_sens);
  return humidity;
  
}

float readTempSensor() {
  // send reset pulse

 // device presence pulse
  // rom cmd
  // read rom 33h
  
  // op cmd
  // convert_t 44h
  // while read_timeslots == 0 wait
  
  // read_scratchpad BEh


  byte i;
  byte present = 0;
  byte data[12];
  byte addr[8];
  
  while ( !ds.search(addr)) {
    Serial.print("No more addresses.\n");
    ds.reset_search();
    delay(250);
   // return;
  }
  
  //Serial.print("R=");
 // for( i = 0; i < 8; i++) {
 //   Serial.print(addr[i], HEX);
   // Serial.print(" ");
  //}

  if ( OneWire::crc8( addr, 7) != addr[7]) {
      Serial.print("CRC is not valid!\n");
   //   return;
  }
  
  if ( addr[0] != 0x10) {
   //   Serial.print("Device is not a DS18S20 family device.\n");
    //  return;
  }
  
  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);         // start conversion, with parasite power on at the end
  
  delay(1000);     // maybe 750ms is enough, maybe not
  // we might do a ds.depower() here, but the reset will take care of it.
  
  present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE);         // Read Scratchpad

 // Serial.print("P=");
 // Serial.print(present,HEX);
//  Serial.print(" ");
  for ( i = 0; i < 9; i++) {           // we need 9 bytes
    data[i] = ds.read();
//    Serial.print(data[i], HEX);
//    Serial.print(" ");
  }
//  Serial.print(" CRC=");
//  Serial.print( OneWire::crc8( data, 8), HEX);
//  Serial.println();
  
  unsigned int raw = (data[1] << 8) | data[0];
  if (false) {
    raw = raw << 3; // 9 bit resolution default
    if (data[7] == 0x10) {
      // count remain gives full 12 bit resolution
      raw = (raw & 0xFFF0) + 12 - data[6];
    }
  } else {
    byte cfg = (data[4] & 0x60);
    if (cfg == 0x00) raw = raw << 3;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw << 2; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw << 1; // 11 bit res, 375 ms
    // default is 12 bit resolution, 750 ms conversion time
  }
  float c = (float)raw / 16.0;
  
  Serial.println(c );
  flashLed(led_sens);
  return c;
}


void loop () {
  float reading = readTempSensor();
  float rh = readRHSensor();
  char temp_str[8];
  char rh_str[8];
  dtostrf(reading, 5, 2, temp_str);
  dtostrf(rh, 5, 2, rh_str);

  http_post("/" + 
      platform_id + "/" + 
      temp_sensor_id + "/" + 
      temp_str);
  http_post("/" + 
      platform_id + "/" + 
      rh_sensor_id + "/" + 
      rh_str);    
  delay(1000);
}
