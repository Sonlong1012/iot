/* Cảm biến âm thanh */
#if defined (ESP8266)

#define DO_PIN D5
#elif defined (ESP32)

#define DO PIN 15
#endif
// thiết lập để chỉ chạy một lần
void setup() {
  Serial.begin(115200);
}
// vòng lặp để chạy liên tục
void loop() {
  bool sound = readDO();
  if (sound) {
    Serial.println("Sound: +");
  } else {
    Serial.println("Sound: -");
  }
  delay(1000);
}
/* Cảm biến âm thanh */
bool readDO() {
  int dValue = digitalRead(DO_PIN); // 0: có âm thanh; 1: không có âm thanh
  if (dValue) return 0;
  else return 1;
}
