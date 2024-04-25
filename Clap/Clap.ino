// Cảm biến âm thanh
#define DO_PIN D5
#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
// Cài đặt chỉ chạy một lần
void setup() {
  initOled();
  Serial.begin(115200);
}

// Vòng lặp chạy liên tục
void loop() {
  readDO();
}

// Đọc giá trị từ cảm biến âm thanh
int clap = 0;
long detection_range_start= 0;
long detection_range= 0;

void readDO() {
  
  int dValue = digitalRead(DO_PIN); 
  if (dValue == 0) {
    if (clap == 0) {
     
      detection_range_start = detection_range = millis();
      clap++;
    } else if (clap > 0 && millis() - detection_range >= 100) {
      
      detection_range = millis();
      clap++;
    }
  }

  if (millis() - detection_range_start >= 500) {
    if (clap == 1) {
      // Serial.println("CLAP 1 times");
       printOled("CLAP","1 times");
    } else if (clap == 2) {
      // Serial.println("CLAP 2 times");
       printOled("CLAP","2 times");
    }
    clap = 0;
  }
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
