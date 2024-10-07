#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);
int a = 9600, b = 1000;
String c = "DHT okuma hatası!" , d = "Nem: " , e = "%  Sıcaklık: ", f ="°C" ;

void setup() {
  Serial.begin(a);
  dht.begin();
}
 void loop() {
    float h = dht.readHumidity(), t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println(c);
    return;
  }
  Serial.println(d + String(h) + e + String(t) + f);
  delay(b);
}