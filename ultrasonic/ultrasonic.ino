// ultra sonic:
#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#if defined(ESP8266)
  #define TRIG_PIN D5
  #define ECHO_PIN D6
#endif

#include <SRF05.h>
SRF05 srf(TRIG_PIN, ECHO_PIN);
void setup() {
  Serial.begin(115200);
  initOled();
}

void loop(){
  float distance = readSRF05();
  Serial.println("Distance (cm): " + String(distance));
  printOled("SRF05", String(distance) + " (cm)");
  delay(1000);
}

float readSRF05() {
  return srf.getCentimeter();
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