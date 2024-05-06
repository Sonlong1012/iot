#if defined(ESP8266)
#define BUZZER_PIN D7
#define D0_PIN D5
#endif

void setup() {
  Serial.begin(115200);
  initBuzzer();
}

void loop() {
  bool motion = readD0();
  if (motion) {
    Serial.println("Motion: +");
    sosBuzzer();
  } else {
    Serial.println("Motion: -");
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

bool readD0() {
  int dValue = digitalRead(D0_PIN);
  if (dValue) return 1; 
    else return 0;
}
