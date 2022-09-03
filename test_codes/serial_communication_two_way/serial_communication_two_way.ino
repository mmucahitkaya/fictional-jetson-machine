#include <Servo.h>
#include "DHT.h"
#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin
int angle;

void setup() {
  Serial1.begin(115200); // Initialize hardware serial port, pins 0/1
  myservo.attach(5);  // attaches the servo on pin 5 to the servo object
  Serial1.println(F("DHTxx test!"));
  Serial1.println(myservo.read());
  dht.begin();
}

void loop() {

    val = Serial1.parseInt();
    myservo.write(val); 
    angle = myservo.read(); 
    Serial1.println((String)" Pin 5: " + angle);
    read_temp();
}

void read_temp(){
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if( isnan(h) ||  isnan(t)) {
    Serial1.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial1.print((String)"Humidity: " + h + "\n" + (String)"% Temperature: " + t + "C");
}
