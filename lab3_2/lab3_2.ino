#include <SSD1306.h> // Thư viện cho màn hình OLED SSD1306

// #if defined(ESP8266)
//   #include <FirebaseESP8266.h>
// #elif defined(ESP32)
//   #include <FirebaseESP32.h>
// #endif
// #define AP_SSID "HSU_Students"
// #define AP_PASSWORD "dhhs12cnvch"
// #define D5_PIN D5 // Định nghĩa chân D5
// #define DB_URL "<db_url>"
// #define DB_SECRET "<db_secret>" 
// FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;
// // SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);

// // Hàm thiết lập ban đầu
// void setup() {
//   Serial.begin(115200);
//   // initOled();
//   initWifi();
//   initEpochTime();
//   initFirebase();
// }

// // Hàm lặp lại
// void loop() {
//   bool light = readD5();
//   if (light) {
//     // Serial.println("Light: +");
//     // printOled("Light sensor", "Light: +");
//     setLightToFirebase(light);
//   } else {
//     // Serial.println("Light: -");
//     // printOled("Light sensor", "Light: -");
//     setLightToFirebase(light);
//   }
//   delay(1000);
// }

// bool readD5() {
//   int dValue = digitalRead(D5_PIN); // 0: light; 1:no-light
//   if (dValue) return false;
//   else return true;
// }

// void initWiFi() {
// blinkBuiltinLed(10);
//   Serial.print("\nConnecting to "); Serial.print(AP_SSID);
//   WiFi.begin(AP_SSID, AP_PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
//   Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
//   WiFi.setAutoReconnect(true); WiFi.persistent(true);
//   blinkBuiltinLed(10);
// }

// void blinkBuiltinLed(int n) {
//  pinMode(BUILTIN_LED, OUTPUT);
//   for (int i = 1; i <= n; i++) {
//     #if defined(ESP8266)
//       digitalWrite(BUILTIN_LED, LOW); delay(200);
//       digitalWrite(BUILTIN_LED, HIGH); delay(200);
//     #elif defined(ESP32)
//       digitalWrite(BUILTIN_LED, HIGH); delay(200);
//       digitalWrite(BUILTIN_LED, LOW); delay(200);
//     #endif
//   }
// }

// /* Epoch time */
// void initEpochTime () {
// configTime(0, 0, NTP_SERVER); // GMT time offset, daylight saving time, NTP server
// }

// long getEpochTime() {
//   tm infoTime;
//   if (!getLocalTime(&infoTime)) return 0;
//   time_t epochTime;
//   time(&epochTime);
//   return epochTime;
// }


// /* FIREBASE */
// void initFirebase() {
//   config.database_url = DB_URL;
//   config.signer.tokens.legacy_token = DB_SECRET;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectNetwork(true);
// }

// void setLightToFirebase(int light) {
//   if (Firebase.ready()) {
//     Firebase.setInt(fbdo, "LIGHT/value", light);
//      Firebase.setInt(fbdo, "LIGHT/update", getEpochTime);
//   }
// }
/* Light sensor */
#if defined(ESP8266)
   #define SDA_PIN D7
   #define SCL_PIN D6
#elif defined(ESP32)
    #define SDA_PIN 21
    #define SCL_PIN 22
#endif

#if defined(ESP8266)
  #include <FirebaseESP8266.h>
#elif defined(ESP32)
  #include <FirebaseESP32.h>
#endif

#include <time.h>
#define NTP_SERVER "pool.ntp.org"
// setup to run only once

#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"
#define D0_PIN D0 // Định nghĩa chân D5
#define DB_URL "<https://sonlongquochoa-default-rtdb.asia-southeast1.firebasedatabase.app/>"
#define DB_SECRET "<9xtoVvr0fpfQj0QMqGjYr4gb7C7vZcUruPOg4izD>" 
FirebaseConfig config; 
FirebaseAuth auth; 
FirebaseData fbdo;

// Hàm thiết lập ban đầu
void setup () {
  Serial.begin(115200);
  initWifi(); // Sửa thành initWifi()
  initEpochTime();
  initFirebase();
}

// Hàm lặp lại
void loop() {
  bool light = readD0();
  if (light) {
    setLightToFirebase(light);
  } else {
    setLightToFirebase(light);
  }
  delay(1000);
}

bool readD5() {
  int dValue = digitalRead(D0_PIN); // 0: light; 1:no-light
  if (dValue) return false;
  else return true;
}

void initWifi() { // Sửa tên hàm thành initWifi()
  blinkBuiltinLed(10);
  Serial.print("\nConnecting to "); 
  Serial.print(AP_SSID);
  WiFi.begin(AP_SSID, AP_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print(".");
  }
  Serial.print("\nWiFi connected, IP address: "); 
  Serial.println(WiFi.localIP());
  WiFi.setAutoReconnect(true); 
  WiFi.persistent(true);
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

/* Epoch time */
void initEpochTime () {
 configTime(0, 0, NTP_SERVER); // GMT time offset, daylight saving time, NTP server
}

long getEpochTime() {
 tm infoTime;
  if (!getLocalTime(&infoTime)) return 0;
  time_t epochTime;
  time(&epochTime);
  return epochTime;
}

/* FIREBASE */
void initFirebase() {
  config.database_url = DB_URL;
  config.signer.tokens.legacy_token = DB_SECRET;
  Firebase.begin(&config, &auth);
  Firebase.reconnectNetwork(true);
}

void setLightToFirebase(int light) {
  if (Firebase.ready()) {
    Firebase.setInt(fbdo, "LIGHT/value", light);
    Firebase.setInt(fbdo, "LIGHT/update", getEpochTime()); // Gọi hàm getEpochTime()
  }
}


