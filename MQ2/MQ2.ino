// Khai báo chân cắm cho cảm biến MQ2
#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#if defined(ESP8266)
#define MQ2_PIN D5
#elif defined(ESP32)
#define MQ2_PIN 15
#endif

// Thiết lập
void setup() {
  // Khởi động Serial
  initOled();
  Serial.begin(115200);
}


void loop() {
  bool smoke = readMQ2();
  if (smoke) {
    Serial.println("Smoke: +");
    printOled("MQ2" ,"Smoke: +");
  } else {
    
    Serial.println("Smoke: -");
    printOled("MQ2" ,"Smoke: -");
  }

  // Chờ 1 giây trước khi đọc lại
  delay(1000);
}

// Hàm đọc giá trị từ cảm biến MQ2
bool readMQ2() {
  int dValue = digitalRead(MQ2_PIN);
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
