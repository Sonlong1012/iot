#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
#if defined(ESP8266)
#define BUZZER_PIN D7
// #elif defined(ESP32)
// #define RELAY_PIN 13
#endif
FirebaseConfig config;
FirebaseAuth auth;
FirebaseData fbdo;

#define DB_URL "https://long-bc130-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define DB_SECRET "Gj0w1L8JKWJQmHzltn9lzsxxOVJZdbjLhxFIUi7c"
#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"

void setup() {
  Serial.begin(115200);
  initBuzzer();
  initWifi();
  initFirebase();
}

void loop() {
  int value = getValueFromFirebase();
  if (value) {
    sosBuzzer();
  } else {
    offBuzzer();
  }
  delay(500);
}

void initBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  offBuzzer();
}

void sosBuzzer() {
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(50);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
  delay(100);
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(200);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
   delay(100);
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(50);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
}

void offBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}
void initWifi() {
  blinkBuiltinLed(10);
  Serial.print("\nConnecting to "); Serial.print(AP_SSID);
  WiFi.begin(AP_SSID, AP_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
  WiFi.setAutoReconnect(true); WiFi.persistent(true);
  blinkBuiltinLed(10);
}

void blinkBuiltinLed(int n) {
  pinMode(BUILTIN_LED, OUTPUT);
  for (int i = 1; i <= n; i++) {
    #if defined(ESP8266)
      digitalWrite(BUILTIN_LED, LOW); delay(200);
      digitalWrite(BUILTIN_LED, HIGH); delay(200);
    #elif defined(ESP32)
      digitalWrite(BUILTIN_LED, HIGH); delay(200);
      digitalWrite(BUILTIN_LED, LOW); delay(200);
    #endif
  }
}
void initFirebase() {
  config.database_url = DB_URL;
  config.signer.tokens.legacy_token = DB_SECRET;
  Firebase.begin(&config, &auth);
  Firebase.reconnectNetwork(true);
}

int getValueFromFirebase() {
  int value = -1;
  if (Firebase.ready()) {
    if (Firebase.getInt(fbdo, "BUZZER/value")) value = fbdo.intData();
    Serial.println("value: " + String(value));
  }
  return value;
}

