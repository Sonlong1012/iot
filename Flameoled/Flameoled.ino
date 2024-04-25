// /* Cảm biến ngọn lửa */
// #if defined (ESP8266)

// #define DO_PIN D5
// #elif defined (ESP32)

// #define DO_PIN 15
// #endif

// // Thiết lập chỉ chạy một lần
// void setup() {
// Serial.begin(115200);
// }

// // Vòng lặp chạy liên tục
// void loop() {
// bool flame = readDO();
// if (flame) {
//  Serial.println("Ngọn lửa: +");
//   } else {      
//   Serial.println("Ngọn lửa: -");
// }                             
// delay(1000);


// }
// /* Cảm biến ngọn lửa */

// bool readDO () {
// int dValue =
// digitalRead(DO_PIN); // 0:có ngọn lửa; 1:không có ngọn lửa

// if (dValue) return 0;
// else return 1;

// }


#define DO_PIN D5
// oled
#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);

void setup() {

  initOled();
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  bool flame = readDO();
  if(flame){
    printOled("Flame sensor","Flame: +");
    // Serial.println("Flame: +");
  }else {
    printOled("Flame sensor","Flame: -");
    // Serial.println("Flame: -");
  }
  delay (1000);
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

















