// #if defined(ESP8266)
//   #include <ESP8266WiFi.h>
// // #define AP_SSID "HSU_Students"
// // #define AP_PASSWORD "dhhs12cnvch"
//   #define RED_LED_PIN D6
//   #define GREEN_LED_PIN D7
//   #define BLUE_LED_PIN D8
// FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;
// #endif
// #define DB_URL "https://sonlongquochoa-default-rtdb.asia-southeast1.firebasedatabase.app/"
// #define DB_SECRET "9xtoVvr0fpfQj0QMqGjYr4gb7C7vZcUruPOg4izD"
// #define AP_SSID "HSU_Students"
// #define AP_PASSWORD "dhhs12cnvch"

// #define NTP_SERVER "pool.ntp.org"


// // Hàm setup để khởi tạo
// void setup() {
//   Serial.begin(115200);
//   initRGBLed();
//   initWifi();
//   initFirebase();

// }


// void loop() {
//   int red = 0, green = 0, blue = 0;
//   getRGBfromFirebase(red, green, blue);
//   onRGBLed(red, green, blue);
//   delay(100);
// }

// /* Hàm khởi tạo đèn LED RGB */
// void initRGBLed() {

//   pinMode(RED_LED_PIN, OUTPUT);
//   pinMode(GREEN_LED_PIN, OUTPUT);
//   pinMode(BLUE_LED_PIN, OUTPUT);

// }

// /* Hàm bật đèn LED RGB */
// void onRGBLed(int red, int green, int blue) {
//   if (red == 1) {
//     digitalWrite(RED_LED_PIN, HIGH);
//   } else {
//     digitalWrite(RED_LED_PIN, LOW);
//   }

//   if (green == 1) {
//     digitalWrite(GREEN_LED_PIN, HIGH);
//   } else {
//     digitalWrite(GREEN_LED_PIN, LOW);
//   }

//   if (blue == 1) {
//     digitalWrite(BLUE_LED_PIN, HIGH);
//   } else {
//     digitalWrite(BLUE_LED_PIN, LOW);
//   }
// }
// void initWifi() {
//   blinkBuiltinLed(10);
//   Serial.print("\nConnecting to "); Serial.print(AP_SSID);
//   WiFi.begin(AP_SSID, AP_PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
//   Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
//   WiFi.setAutoReconnect(true); WiFi.persistent(true);
//   blinkBuiltinLed(10);
// }

// void blinkBuiltinLed(int n) {
//   pinMode(BUILTIN_LED, OUTPUT);
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

// void initFirebase(){
//   config.database_url = DB_URL;
//   config.signer.tokens.legacy_token = DB_SECRET;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectNetwork(true);
// }

// void getRGBfromFirebase(int& red, int& green, int& blue) {
//   if (Firebase.ready()) {
//     if (Firebase.getInt(fbdo, "LEDs/R")) red = fbdo.intData();
//     if (Firebase.getInt(fbdo, "LEDs/G")) green = fbdo.intData();
//     if (Firebase.getInt(fbdo, "LEDs/B")) blue = fbdo.intData();
//     Serial.println("RGB: " + String(red) + String(green) + String(blue));
//   }
// }


#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define RED_LED_PIN D6
#define GREEN_LED_PIN D7
#define BLUE_LED_PIN D8

FirebaseConfig config;
FirebaseAuth auth;
FirebaseData fbdo;

#define DB_URL "https://long-bc130-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define DB_SECRET "Gj0w1L8JKWJQmHzltn9lzsxxOVJZdbjLhxFIUi7c"
#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"

void setup() {
  Serial.begin(115200);
  initRGBLed();
  initWifi();
  initFirebase();
}

void loop() {
  int red = 0, green = 0, blue = 0;
  getRGBfromFirebase(red, green, blue, fbdo); // Pass fbdo as parameter
  onRGBLed(red, green, blue);
  delay(100);
}
/* Hàm bật đèn LED RGB */
void onRGBLed(int red, int green, int blue) {
  if (red == 1) {
    digitalWrite(RED_LED_PIN, HIGH);
  } else {
    digitalWrite(RED_LED_PIN, LOW);
  }

  if (green == 1) {
    digitalWrite(GREEN_LED_PIN, HIGH);
  } else {
    digitalWrite(GREEN_LED_PIN, LOW);
  }

  if (blue == 1) {
    digitalWrite(BLUE_LED_PIN, HIGH);
  } else {
    digitalWrite(BLUE_LED_PIN, LOW);
  }
}
void initRGBLed() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);
}

// void onRGBLed(int red, int green, int blue) {
//   digitalWrite(RED_LED_PIN, red);
//   digitalWrite(GREEN_LED_PIN, green);
//   digitalWrite(BLUE_LED_PIN, blue);
// }
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

void getRGBfromFirebase(int& red, int& green, int& blue, FirebaseData& fbdo) {
  if (Firebase.ready()) {
    if (Firebase.getInt(fbdo, "LEDs/R")) red = fbdo.intData();
    if (Firebase.getInt(fbdo, "LEDs/G")) green = fbdo.intData();
    if (Firebase.getInt(fbdo, "LEDs/B")) blue = fbdo.intData();
    Serial.println("RGB: " + String(red) + String(green) + String(blue));
  }
}
