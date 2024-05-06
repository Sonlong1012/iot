#if defined(ESP8266)
#define MOTOR_PIN D7
#define DHT_PIN D5
#endif

#include <DHT11.h>
DHT11 dht11(DHT_PIN);

void setup() {
  Serial.begin(115200);
  initMotor();
}

void loop() {
  int temp = 0, humi = 0;
  readDHT11(temp, humi);
  Serial.println("Temperature: " + String(temp));
  Serial.println("Humidity: " + String(humi));
  if (temp > 31) {
    onMotor();
  } else {
    offMotor();
  }
  delay(100);
}

void initMotor() {
  pinMode (MOTOR_PIN, OUTPUT);
}

void onMotor() {
  digitalWrite(MOTOR_PIN, HIGH);
}

void offMotor() {
  digitalWrite(MOTOR_PIN, LOW);
}

void readDHT11(int& temp, int& humi) {

  int temperature = dht11.readTemperature();
  delay(10);
  int humidity = dht11.readHumidity();

  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT &&
      humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
    temp = temperature;
    humi = humidity;
  }
}