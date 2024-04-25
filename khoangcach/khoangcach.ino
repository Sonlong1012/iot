// Obstacle sensor:

#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#if defined(ESP8266)
  #define D0_PIN D5
#endif

void setup() {
  Serial.begin(115200);
  initOled();
}

void loop(){
  bool obstacle = readD0();
  if (obstacle) {
    Serial.println("Obstacle: +");
    printOled("Infrared sensor", "Obstacle: +");
  } else {
    Serial.println("Obstacle: -");
    printOled("Infrared sensor", "Obstacle: -");
  }
  delay(1000);
}

bool readD0() {
  int dValue = digitalRead(D0_PIN);
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