// Cảm biến nước /
#if defined(ESP8266)
  #define S_PIN D5
// #elif defined(ESP32)
//   #define S_pin 15
  #include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#endif

// thiết lập để chạy chỉ một lần
void setup() {
  Serial.begin(115200);
  initOled();
}

// vòng lặp để chạy liên tục
void loop() {
  bool water = readS();
  if (water) {
  //Serial.println("Water: +");
  printOled("Water sensor", "Water: -");
  } else {
  //Serial.println("Water: -");
  printOled("Water sensor", "Water: +");
  }
  delay(1000);
  }

// Cảm biến nước /
bool readS() {
  int dValue = digitalRead(S_PIN); // 0: không có nước; 1: có nước
  if (dValue) return 1;
  else return 0;
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
