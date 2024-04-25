/* MFRC522 */
#include <MFRC522.h> // ref: https://github.com/miguelbalboa/rfid
#define SDA_PIN D3
#define RST_PIN D4
MFRC522 mfrc522(SDA_PIN, RST_PIN);

// oled
#include <SSD1306.h>
#define SDA_OLED_PIN D2
#define SCL_OLED_PIN D1
SSD1306 oled(0x3c, SDA_OLED_PIN, SCL_OLED_PIN);
// setup to run only once
void setup() {
  Serial.begin(115200);
  initMFRC522();
  initOled();
}
// loop to run repeatedly
void loop() {
  String uid = getCardUID();
  if (uid == "1955212433") {
    Serial.println("blue card");
    printOled("MFRC522", "blue card");
  } else if (uid == "13125511026") {
    Serial.println("white card");
    printOled("MFRC522", "white card");
  }
  // getCardUID();
  delay(500);
}
/* MFRC522 */
void initMFRC522() {
  SPI.begin();
  mfrc522.PCD_Init();
}
// void getCardUID() {
//   if (mfrc522.PICC_IsNewCardPresent()) { // look for new cards
//     if (mfrc522.PICC_ReadCardSerial()) { // select one of the cards
//       String uid = getCardUIDinHEX(mfrc522.uid.uidByte, mfrc522.uid.size);
//       Serial.println("UID card in HEX: " + uid);
//       uid = getCardUIDinDEC(mfrc522.uid.uidByte, mfrc522.uid.size);
//       Serial.println("UID card in DEC: " + uid);
//     }
//   }
//   return uid;
// }
String getCardUID() {
    String uid = "";

    if (mfrc522.PICC_IsNewCardPresent()) { // look for new cards
        if (mfrc522.PICC_ReadCardSerial()) { // select one of the cards
            uid = getCardUIDinDEC(mfrc522.uid.uidByte, mfrc522.uid.size);
        }
    }
    return uid;
}
// String getCardUIDinHEX(byte* buffer, byte bufferSize) {
//   String result = "";
//   for (byte i = 0; i < bufferSize; i++) {
//     result += (buffer[i] < 0x10) ? "0" : "";
//     result += String(buffer[i], HEX);
//     if (i < bufferSize - 1) result += "-";
//   }
//   result.toUpperCase();
//   return result;
// }
String getCardUIDinDEC(byte* buffer, byte bufferSize) {
  String result = "";
  for (byte i = 0; i < bufferSize; i++) {
    result += (buffer[i] < 0x10) ? "0" : "";
    result += String(buffer[i]);
  }
  return result;
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
