#include <UniversalTelegramBot.h>
#define BOTtoken "7022441552:AAFzlAGXMycYM1IxhxX8cINyBHMdIeCJ0dw"
#define CHAT_ID "6923811961"
#include <WiFiClientSecure.h>
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);
X509List cert(TELEGRAM_CERTIFICATE_ROOT);

#include <SSD1306.h>
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#define DO_PIN D5

#define RED_LED_PIN D6
  #define GREEN_LED_PIN D7
  #define BLUE_LED_PIN D8

#define DB_URL "https://sonlongquochoa-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define DB_SECRET "9xtoVvr0fpfQj0QMqGjYr4gb7C7vZcUruPOg4izD"
#define AP_SSID "HSU_Students"
#define AP_PASSWORD "dhhs12cnvch"

#define NTP_SERVER "pool.ntp.org"

FirebaseConfig config; FirebaseAuth auth; FirebaseData fbdo;

// SSD1306 oled (0x3c, SDA_PIN, SCL_PIN);

void setup() {
  Serial.begin(115200);
  // initOled();
  initWifi();
  initEpochTime();
  initFirebase();
  initRGBLed();
  initTelegram();
}

void loop() {
 int numNewMessages = bot.getUpdates(bot.last_message_received +1);
 while (numNewMessages) {
  handleNewMessages(numNewMessages);
  numNewMessages = bot.getUpdates(bot.last_message_received +1);
 }
  delay(1000);
}

void initRGBLed() {

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
  pinMode(BLUE_LED_PIN, OUTPUT);

}
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


// void printOled(String line1, String line2) {
//   oled.clear();
//   oled.setTextAlignment(TEXT_ALIGN_LEFT);
//   oled.setFont(ArialMT_Plain_24);
//   oled.drawString(0,0,line1);
//   oled.drawString(0,36,line2);
//   oled.display();
// }

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

void initTelegram() {
#if defined(ESP8266)
    configTime(0, 0, "pool.ntp.org");//get UTC time via NTP
    client.setTrustAnchors(&cert);
  #endif
  bot.sendMessage(CHAT_ID, "Bot started up","");
}

void handleNewMessages(int numNewMessages) {
  Serial.println("handleNewMessages: " + String(numNewMessages));
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID){
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
    String text = bot.messages[i].text;
    Serial.println(text);
    String from_name = bot.messages[i].from_name;
    if (text == "/start") {
      String welcome = "Welcome, " + from_name + ". ";
      welcome += "Use the following commands to control your outputs:\n";
      welcome += "/red_on to turn red_led On\n";
      welcome += "/green_on to turn green_led On\n";
      welcome += "/blue_on to turn blue_led On\n";
      welcome += "/led_off to turn all_led OFF\n";
      bot.sendMessage(chat_id, welcome, "");
    } else if (text == "/red_on") {
      onRGBLed(1, 0, 0);
      bot.sendMessage(chat_id, "red_led is ON", "");
    } else if (text == "/green_on") {
      onRGBLed(0, 1, 0);
      bot.sendMessage(chat_id, "green_led is ON", "");
    } else if (text == "/blue_on") {
      onRGBLed(0, 0, 1);
      bot.sendMessage(chat_id, "blue_led is ON", "");
    } else if (text == "/led_off") {
      onRGBLed(0, 0, 0);
      bot.sendMessage(chat_id, "all_led is OFF", "");
    } 
    
  }
}