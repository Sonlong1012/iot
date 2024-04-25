// #include <LiquidCrystal_I2C.h>

// #define LCD_COLS 16
// #define LCD_ROWS 2

// LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);

// void setup() {
//   initLcd();

// }

// void loop() {
//   String line1 = "longts + hoanq";
//   String line2 = "hoanq + longts";

//   printLcd(line1, ""); delay(2000);
//   printLcd(line1, line2); delay(2000);
// }

// void initLcd(){
//   lcd.init();
//   lcd.backlight();
// }

// void printLcd(String line1, String line2){
//   lcd.clear();
//   lcd.setCursor(0, 0);
//   lcd.print(line1);
//   lcd.setCursor(0, 1);
//   lcd.print(line2);
// }
// #include <SSD1306.h> // Thư viện cho màn hình OLED SSD1306

// #if defined(ESP8266)
//    #define SDA_PIN D9
//    #define SCL_PIN D10
// #elif defined(ESP32)
//     #define SDA_PIN 21
//     #define SCL_PIN 22
// #endif
// SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);

// // Hàm thiết lập ban đầu
// void setup() {
//   initOled();
// }

// // Hàm lặp lại
// void loop() {
//   String line1 = "+ LongTS";
//   String line2 = "+ HoaNQ";
//   String line3 = ">> Long";
//   String line4 = ">> Hoa";
//   printOled(line1, line2); delay(2000);
//   printOled(line1, line2, line3); delay(2000);
//   printOled(line1, line2, line3, line4); delay(2000);
// }

// /* OLED */
// void initOled() {
//   oled.init();
//   oled.flipScreenVertically();
// }
// void printOled(String line1, String line2) {
//   oled.clear();
//   oled.setTextAlignment(TEXT_ALIGN_LEFT);
//   oled.setFont(ArialMT_Plain_24);
//   oled.drawString(0, 0, line1);
//   oled.drawString(0, 36, line2);
//   oled.display();
// }
// void printOled(String line1, String line2, String line3) {
//   oled.clear();
//   oled.setTextAlignment(TEXT_ALIGN_LEFT);
//   oled.setFont(ArialMT_Plain_16);
//   oled.drawString(0, 0, line1);
//   oled.drawString(0, 24, line2);
//   oled.drawString(0, 48, line3);
//   oled.display();
// }
// void printOled(String line1, String line2, String line3, String line4) {
//   oled.clear();
//   oled.setTextAlignment(TEXT_ALIGN_LEFT);
//   oled.setFont(ArialMT_Plain_10);
//   oled.drawString(0, 0, line1);
//   oled.drawString(0, 16, line2);
//   oled.drawString(0, 32, line3);
//   oled.drawString(0, 48, line4);
//   oled.display();
// }

// #if defined (ESP8266)
//   #define D0_PIN D5
// #elif defined (ESP32)
//   #define D0_PIN 15
// #endif 
// //setup to run only once
// void setup() {
//   Serial.begin(115200);
// }
// //loop to run repeatedly
// void loop() {
//   bool light = readD0 ();
//   if (light) {
//     Serial.println("Light: +");
//   } else {
//     Serial.println ("Light: -");
//   }
//   delay(1000);
// }
// /* Light sensor */
// bool readD0 () {
//   int dValue = digitalRead(D0_PIN); // 0: light; 1:no-light
//   if (dValue) return 0;
//   else return 1;
// }




// #if defined (ESP8266)
//   #define A0_PIN A0
// #elif defined (ESP32)
//   #define A0_PIN 34
// #endif 
// //setup to run only once
// void setup() {
//   Serial.begin(115200);
// }
// //loop to run repeatedly
// void loop() {
//   int light = readA0 ();
//   Serial.println("Light: " + String(light));
//   delay(1000);
// }
// /* Light sensor */
// int readA0 () {
//   int aValue = analogRead(A0_PIN); // form 0 to 1024 or 4095
//   #if defined (ESP8266)
//     int light = map(aValue , 0 , 1024 , 0 , 100); // map aValue from 0-1024 to 0-100 (percentage)
//   #elif defined (ESP32)
//     int light = map(aValue , 0 , 4095 , 0 , 100); // map aValue from 0-4095 to 0-100 (percentage)
//   #endif
//   return light;
// }



#include <SSD1306.h> // Thư viện cho màn hình OLED SSD1306

#if defined(ESP8266)
   #define SDA_PIN D7
   #define SCL_PIN D6
#elif defined(ESP32)
    #define SDA_PIN 21
    #define SCL_PIN 22
#endif

#define D5_PIN D5 // Định nghĩa chân D5
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);

// Hàm thiết lập ban đầu
void setup() {
  Serial.begin(115200);
  initOled();
}

// Hàm lặp lại
void loop() {
  bool light = readD5();
  if (light) {
    // Serial.println("Light: +");
    printOled("Light sensor", "Light: +");
  } else {
    // Serial.println("Light: -");
    printOled("Light sensor", "Light: -");
  }
  delay(1000);
}

bool readD5() {
  int dValue = digitalRead(D5_PIN); // 0: light; 1:no-light
  if (dValue) return false;
  else return true;
}

/* OLED */
void initOled() {
  oled.init();
  oled.flipScreenVertically();
}

void printOled(String line1, String line2) {
  oled.clear();
  oled.setTextAlignment(TEXT_ALIGN_LEFT);
  oled.setFont(ArialMT_Plain_24);
  oled.drawString(0, 0, line1);
  oled.drawString(0, 16, line2);
  oled.display();
}















