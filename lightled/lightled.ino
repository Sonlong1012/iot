
#if defined (ESP8266)
#define DO_PIN D5
#elif defined (ESP32)
#define DO_PIN 15
#endif            
/* LED RGB */
#if defined (ESP8266)

#define LED_PIN D7
#elif defined (ESP32)
 #define LED_PIN 13
#endif             

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
bool light = readDO();
if (light) {
Serial.println("Light: +"); 
digitalWrite(LED_PIN, LOW);
} else {
Serial.println("Light: -"); 
digitalWrite(LED_PIN, HIGH);
}
delay(100);
}
/* Cảm biến ánh sáng */

bool readDO () {
int dValue = digitalRead(DO_PIN); 
  if (dValue) return 0;
  else return 1;
}


