#if defined(ESP8266)
  #include <Servo.h>
  #define SERVO_PIN D8
#endif
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
Servo servo;

// #elif defined(ESP32)
// #define RELAY_PIN 13

FirebaseConfig config;
FirebaseAuth auth;
FirebaseData fbdo;

#define DB_URL "https://long-bc130-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define DB_SECRET "Gj0w1L8JKWJQmHzltn9lzsxxOVJZdbjLhxFIUi7c"
#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"
void setup() {
  Serial.begin(115200);
  initServo();
  initWifi();
  initFirebase();
  setValueToFirebase(0);
}
int oldValue = 0;
void loop() {
  int newValue = getValueFromFirebase();
  if (newValue == 1 && oldValue == 0) {
    upServo ();
    oldValue = 1;
  } else if (newValue == 0 && oldValue == 1) {
    downServo ();
    oldValue = 0;
  }
  delay(100);
}

void initServo() {
  servo.attach(SERVO_PIN);
  servo.write(0);
}
void upServo() {
  for (int pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(20);
  }
}
void downServo() {
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(20);
  }
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
    if (Firebase.getInt(fbdo, "SERVO/value")) value = fbdo.intData();
    Serial.println("value: " + String(value));
  }
  return value;
}
void setValueToFirebase(int value){
  if (Firebase.ready()) {
    Firebase.setInt(fbdo, "SERVO/value", value);
  }
}
