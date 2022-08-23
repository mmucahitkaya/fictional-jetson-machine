#include "DHT.h"
#define DHTPIN 4     // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11
 DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial1.begin(115200);
  Serial1.println(F("DHTxx test!"));

  dht.begin();
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if( isnan(h) ||  isnan(t)) {
    Serial1.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial1.print(F("Humidity: "));
  Serial1.print(h);
  Serial1.print(F("%  Temperature: "));
  Serial1.print(t);
  Serial1.println(F("C "));
}
