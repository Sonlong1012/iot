/* DHT11 */
#include <SSD1306.h>
#define SDA_PIN D2
#define SCL_PIN D3
SSD1306 oled(0x3c, SDA_PIN, SCL_PIN);
#if defined (ESP8266)
#define DHT_PIN D5
#elif defined (ESP32)
#define DHT_PIN 15
#endif

#include <DHT11.h>
DHT11 dht11(DHT_PIN);

// thiết lập chỉ chạy một lần
void setup() {
  initOled();
  Serial.begin(115200);
}

// vòng lặp chạy liên tục
void loop() {
  int temp = 0, humi = 0;
  readDHT11(temp, humi);

  // Serial.println("Nhiệt độ: " + String(temp));
  // Serial.println("Độ ẩm: " + String(humi));
   printOled("Temp:" + String(temp),"Humi:" + String(humi));
  delay(1000);
}

// Hàm đọc dữ liệu từ DHT11
void readDHT11(int& temp, int& humi) {

  int temperature = dht11.readTemperature();
  delay(10);
  int humidity = dht11.readHumidity();

  if (temperature != DHT11::ERROR_CHECKSUM && temperature != DHT11::ERROR_TIMEOUT &&
      humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT) {
    temp = temperature;
    humi = humidity;
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
