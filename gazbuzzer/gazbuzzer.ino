#if defined(ESP8266)
#define BUZZER_PIN D7
#define MQ2_PIN D5
#endif

void setup() {
  Serial.begin(115200);
  initBuzzer();
}

void loop() {
  bool smoke = readMQ2();
  if (smoke) {
    Serial.println("Smoke: +");
    sosBuzzer();
  } else {
    Serial.println("Smoke: -");
    offBuzzer();
  }
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

bool readMQ2() {
  int dValue = digitalRead(MQ2_PIN);
  if (dValue) return 0; 
    else return 1;
}