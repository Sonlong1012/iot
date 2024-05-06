#if defined(ESP8266)
#define RELAY_PIN D7
#elif defined(ESP32)
#define RELAY_PIN 13
#endif

void setup() {
  initRelay();
}

void loop() {
  onRelay();delay(3000);
  offRelay();delay(3000);
}

void initRelay() {
  pinMode(RELAY_PIN, OUTPUT);
}

void onRelay() {
  digitalWrite(RELAY_PIN, HIGH);
}

void offRelay() {
  digitalWrite(RELAY_PIN, LOW);
}
