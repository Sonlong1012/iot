#if defined(ESP8266)
#define BUZZER_PIN D7
// #elif defined(ESP32)
// #define RELAY_PIN 13
#endif

void setup() {
  initBuzzer();
}

void loop() {
  sosBuzzer();
  delay(500);
  
}

void initBuzzer() {
  pinMode(BUZZER_PIN, OUTPUT);
  offBuzzer();
}

void sosBuzzer() {
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(50);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
  delay(100);
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(200);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
   delay(100);
  for (int i = 1; i <= 3; i++){
    digitalWrite(BUZZER_PIN, LOW); delay(50);
     digitalWrite(BUZZER_PIN, HIGH); delay(100);
  }
}

void offBuzzer() {
  digitalWrite(BUZZER_PIN, HIGH);
}
