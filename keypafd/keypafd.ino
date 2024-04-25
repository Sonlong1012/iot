
#include <SSD1306.h>
#define SDA_PIN D9
#define SCL_PIN D10
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);

#include <Keypad.h>
#define ROWS 4
#define COLS 4
#if defined(ESP8266)
  byte rowPins[ROWS] = {D3, D2, D1, D0};
  byte colPins[COLS] = {D4, D5, D6, D7};
#endif
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup(){
  Serial.begin(115200);
  initOled();
}

void loop(){
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    printOled("Keypad", String(key));
  }
  delay(100);
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