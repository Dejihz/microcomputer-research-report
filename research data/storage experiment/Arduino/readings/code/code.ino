#include <DHT.h>

#define DHTPIN 2     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

bool label = true;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // Wait a 2 seconds
  delay(2000);

  while (label){
    Serial.print("Temperature (c), Humidity (%)");
    Serial.print("\n");
    label = false;
  }
  delay(2000);

  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  Serial.print(t);
  Serial.print(F(", "));
  Serial.print(h);
  Serial.print("\n");

  
}