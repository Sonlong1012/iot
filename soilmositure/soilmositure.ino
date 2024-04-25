#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#if defined(ESP8266)
#define DO_PIN D5
#elif defined(ESP32)
#define DO_PIN 15
#endif

// thiết lập để chỉ chạy một lần
void setup() {
  initOled();
  Serial.begin(115200);
}

// vòng lặp để chạy liên tục
void loop() {
  bool moisture = readDO(); // 0: ẩm, 1: khô
  if (moisture) {
    printOled("Moisture sensor","Moisture: +");
    // Serial.println("Độ ẩm: +");
  } else {
    // Serial.println("Độ ẩm: -");
     printOled("Moisture sensor","Moisture: -");
  }
  delay(1000);
}

bool readDO() {
  int dValue = digitalRead(DO_PIN);
  if (dValue) return 0;
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
