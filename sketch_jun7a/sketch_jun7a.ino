// setup to run only once
void setup() {
  initBILed();
}
// loop to run repeatedly
void loop() {
  sosBILed();
  delay(500);
}
/* Built-in led */
void initBILed() {
  pinMode(BUILTIN_LED, OUTPUT);
}
void sosBILed() {
  for (int i = 1; i <= 3; i++) {
    #if defined(ESP8266)
      digitalWrite(BUILTIN_LED, LOW); delay(50); // turn on
      digitalWrite(BUILTIN_LED, HIGH); delay(100); // turn off
    #elif defined(ESP32)
      digitalWrite(BUILTIN_LED, HIGH); delay(50); // turn on
      digitalWrite(BUILTIN_LED, LOW); delay(100); // turn off
    #endif
  }
  delay(100);
  for (int i = 1; i <= 3; i++) {
    #if defined(ESP8266)
      digitalWrite(BUILTIN_LED, LOW); delay(200);
      digitalWrite(BUILTIN_LED, HIGH); delay(100);
    #elif defined(ESP32)
      digitalWrite(BUILTIN_LED, HIGH); delay(200);
      digitalWrite(BUILTIN_LED, LOW); delay(100);
    #endif
  }
  delay(100);
  for (int i = 1; i <= 3; i++) {
    #if defined(ESP8266)
      digitalWrite(BUILTIN_LED, LOW); delay(50);
      digitalWrite(BUILTIN_LED, HIGH); delay(100);
    #elif defined(ESP32)
      digitalWrite(BUILTIN_LED, HIGH); delay(50);
      digitalWrite(BUILTIN_LED, LOW); delay(100);
    #endif
  }
}