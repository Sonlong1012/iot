// #include <UniversalTelegramBot.h>
// #define BOTtoken "7022441552:AAFzlAGXMycYM1IxhxX8cINyBHMdIeCJ0dw"
// #define CHAT_ID "6923811961"
// #include <WiFiClientSecure.h>
// WiFiClientSecure client;
// UniversalTelegramBot bot(BOTtoken, client);
// X509List cert(TELEGRAM_CERTIFICATE_ROOT);

// #include <SSD1306.h>
// #include <FirebaseESP8266.h>
// #include <ESP8266WiFi.h>
// #define DO_PIN D5
// #define SDA_PIN D2
// #define SCL_PIN D3

// #define DB_URL "https://sonlongquochoa-default-rtdb.asia-southeast1.firebasedatabase.app/"
// #define DB_SECRET "9xtoVvr0fpfQj0QMqGjYr4gb7C7vZcUruPOg4izD"
// #define AP_SSID "HSU_Students"
// #define AP_PASSWORD "dhhs12cnvch"

// #define NTP_SERVER "pool.ntp.org"

// FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;

// SSD1306 oled (0x3c, SDA_PIN, SCL_PIN);

// void setup() {
//   Serial.begin(115200);
//   initOled();
//   initWifi();
//   initEpochTime();
//   initFirebase();
//   initTelegram();
// }

// void loop() {
//   bool light = readD0();
//   if(light) {
//     bot.sendMessage(CHAT_ID,"LIGHT +","");
//     // Serial.println(light);
//     // setLightToFirebase(light);
//     // printOled("Light sensor:","Light: +");
//   }else {
//     bot.sendMessage(CHAT_ID,"LIGHT -","");
//     // Serial.println(light);
//     // setLightToFirebase(light);
//     // printOled("Light sensor:","Light: -");
//   }
//   delay(1000);
// }

// bool readD0() {
//   int dValue = digitalRead(DO_PIN);
//   if(dValue) return 0;
//   else return 1;
// }

// void initOled(){
//   oled.init();
//   oled.flipScreenVertically();
// }

// void printOled(String line1, String line2) {
//   oled.clear();
//   oled.setTextAlignment(TEXT_ALIGN_LEFT);
//   oled.setFont(ArialMT_Plain_24);
//   oled.drawString(0,0,line1);
//   oled.drawString(0,36,line2);
//   oled.display();
// }

// void initWifi(){
//   blinkBuiltinLed(10);
//   Serial.print("\nConnecting to "); Serial.print(AP_SSID);
//   WiFi.begin(AP_SSID, AP_PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
//   Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
//   WiFi.setAutoReconnect(true); WiFi.persistent(true);
//   blinkBuiltinLed(10);
// }
// void blinkBuiltinLed(int n){
//     pinMode(BUILTIN_LED, OUTPUT);
//   for (int i = 1; i <= n; i++) {
//       #if defined(ESP8266)
//   digitalWrite(BUILTIN_LED, LOW); delay(200);
//   digitalWrite(BUILTIN_LED, HIGH); delay(200);
//       #elif defined(ESP32)
//   digitalWrite(BUILTIN_LED, HIGH); delay(200);
//   digitalWrite(BUILTIN_LED, LOW); delay(200);
//       #endif
//     }
// }

// void initEpochTime(){
//   configTime(0, 0, NTP_SERVER); // GMT time offset, daylight saving time, NTP server
// }

// long getEpochTime(){
//   tm infoTime;
//   if (!getLocalTime(&infoTime)) return 0;
//   time_t epochTime;
//   time(&epochTime);
//   return epochTime;
// }

// void initFirebase(){
//   config.database_url = DB_URL;
//   config.signer.tokens.legacy_token = DB_SECRET;
//   Firebase.begin(&config, &auth);
//   Firebase.reconnectNetwork(true);
// }

// void setLightToFirebase(int light){
//   if (Firebase.ready()){
//     Firebase.setInt(fbdo,"LIGHT/value",light);
//     Firebase.setInt(fbdo,"LIGHT/updated",getEpochTime());
//   }
// }

// void initTelegram() {
//   #if defined(ESP8266)
//     configTime(0, 0, "pool.ntp.org");//get UTC time via NTP
//     client.setTrustAnchors(&cert);
//   #endif
//   bot.sendMessage(CHAT_ID, "Bot started up","");
// }





//  #include <SSD1306.h>
// // #include <FirebaseESP8266.h>
// #include <ESP8266WiFi.h>
// #define DO_PIN D5
// #define SDA_PIN D2
// #define SCL_PIN D3

// #define DB_URL "https://sonlongquochoa-default-rtdb.asia-southeast1.firebasedatabase.app/"
// #define DB_SECRET "9xtoVvr0fpfQj0QMqGjYr4gb7C7vZcUruPOg4izD"
// #define AP_SSID "HSU_Students"
// #define AP_PASSWORD "dhhs12cnvch"

// #define NTP_SERVER "pool.ntp.org"

// FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;

// SSD1306 oled (0x3c, SDA_PIN, SCL_PIN);
// #if defined(ESP8266)
//  #include <Callmetbot_ESP8266.h>
// #elif defined(ESP32)
//  #include <Callmetbot_ESP32.h>
// #endif
// #define API_KEY "2wVd1wL6QtlNWGAG "
// void setup() {
//   Serial.begin(115200);
//   initOled();
//   initWifi();
//   initEpochTime();
//   initFirebase();
//   initTelegram();
// }
// void loop() {
//   bool light = readD0();
//   if(light) {
//     // bot.sendMessage(CHAT_ID,"LIGHT +","");
//     // Serial.println(light);
//     // setLightToFirebase(light);
//     // printOled("Light sensor:","Light: +");
//     Callmetbot.facebookMessage(API_KEY , "Light: +") ;
//     Serial.println(Callmebot.debug());
//   }else {
//      Callmetbot.facebookMessage(API_KEY , "Light: +") ;
//     Serial.println(Callmebot.debug());
//     // Serial.println(light);
//     // setLightToFirebase(light);
//     // printOled("Light sensor:","Light: -");
//   }
//   delay(60000);
// }
// bool readD0() {
//   int dValue = digitalRead(DO_PIN);
//   if(dValue) return 0;
//   else return 1;
// }
// void initWifi(){
//   blinkBuiltinLed(10);
//   Serial.print("\nConnecting to "); Serial.print(AP_SSID);
//   WiFi.begin(AP_SSID, AP_PASSWORD);
//   while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
//   Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
//   WiFi.setAutoReconnect(true); WiFi.persistent(true);
//   blinkBuiltinLed(10);
// }
// void blinkBuiltinLed(int n){
//     pinMode(BUILTIN_LED, OUTPUT);
//   for (int i = 1; i <= n; i++) {
//       #if defined(ESP8266)
//   digitalWrite(BUILTIN_LED, LOW); delay(200);
//   digitalWrite(BUILTIN_LED, HIGH); delay(200);
//       #elif defined(ESP32)
//   digitalWrite(BUILTIN_LED, HIGH); delay(200);
//   digitalWrite(BUILTIN_LED, LOW); delay(200);
//       #endif
//     }
// }
// void initMessenger() {
//   #if defined(ESP8266)
//     Callmetbot.begin();
//     #endif
// }
// #include <UniversalTelegramBot.h>
// #define BOTtoken "6459981410:AAGzUcH2_3YBsB01dfvrQK1QLFgv4PKVe88"
// #define CHAT_ID "6728868889"
// #include <WiFiClientSecure.h>
// WiFiClientSecure client;
// UniversalTelegramBot bot(BOTtoken, client);
// X509List cert(TELEGRAM_CERTIFICATE_ROOT);

#include <Callmebot_ESP8266.h>
#define API_KEY "2wVd1wL6QtlNWGAG"

#include <SSD1306.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#define DO_PIN D5
#define SDA_PIN D2
#define SCL_PIN D3

#define DB_URL "https://dmcuocdoi-a155f-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define DB_SECRET "MX0BdfPfMSp5pcIMTh8BvwWfzVywxoROUaIdT1ty"
#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"

#define NTP_SERVER "pool.ntp.org"

FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;

SSD1306 oled (0x3c, SDA_PIN, SCL_PIN);

void setup() {
  Serial.begin(115200);
  initOled();
  initWifi();
  initEpochTime();
  initFirebase();
  // initTelegram();
  initMessenger();
}

void loop() {
  bool light = readD0();
  // if(light) {
  //   bot.sendMessage(CHAT_ID,"LIGHT +","");
  //   // Serial.println(light);
  //   // setLightToFirebase(light);
  //   // printOled("Light sensor:","Light: +");
  // }else {
  //   bot.sendMessage(CHAT_ID,"LIGHT -","");
  //   // Serial.println(light);
  //   // setLightToFirebase(light);
  //   // printOled("Light sensor:","Light: -");
  // }
  // delay(1000);
   if (light) {
    Callmebot.facebookMessage (API_KEY, "Light: +");
    Serial.println(Callmebot.debug());
  }
  else {
    Callmebot.facebookMessage (API_KEY, "Light: -");
    Serial.println(Callmebot.debug());
  }
  delay(60000);
}

bool readD0() {
  int dValue = digitalRead(DO_PIN);
  if(dValue) return 0;
  else return 1;
}

void initOled(){
  oled.init();
  oled.flipScreenVertically();
}

void printOled(String line1, String line2) {
  oled.clear();
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
  oled.setFont(ArialMT_Plain_24);
  oled.drawString(0,0,line1);
  oled.drawString(0,36,line2);
  oled.display();
}

void initWifi(){
  blinkBuiltinLed(10);
  Serial.print("\nConnecting to "); Serial.print(AP_SSID);
  WiFi.begin(AP_SSID, AP_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.print("\nWiFi connected, IP address: "); Serial.println(WiFi.localIP());
  WiFi.setAutoReconnect(true); WiFi.persistent(true);
  blinkBuiltinLed(10);
}
void blinkBuiltinLed(int n){
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

void initEpochTime(){
  configTime(0, 0, NTP_SERVER); // GMT time offset, daylight saving time, NTP server
}

long getEpochTime(){
  tm infoTime;
  if (!getLocalTime(&infoTime)) return 0;
  time_t epochTime;
  time(&epochTime);
  return epochTime;
}

void initFirebase(){
  config.database_url = DB_URL;
  config.signer.tokens.legacy_token = DB_SECRET;
  Firebase.begin(&config, &auth);
  Firebase.reconnectNetwork(true);
}

void setLightToFirebase(int light){
  if (Firebase.ready()){
    Firebase.setInt(fbdo,"LIGHT/value",light);
    Firebase.setInt(fbdo,"LIGHT/updated",getEpochTime());
  }
}

// void initTelegram() {
//   #if defined(ESP8266)
//     configTime(0, 0, "pool.ntp.org");//get UTC time via NTP
//     client.setTrustAnchors(&cert);
//   #endif
//   bot.sendMessage(CHAT_ID, "Bot started up","");
// }

void initMessenger() {
  #if defined(ESP8266)
  Callmebot.begin();
  #endif
}













