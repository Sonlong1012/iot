#if defined(ESP8266)
#define MOTOR_PIN D7
#define S_PIN D5
#endif

void setup() {
  Serial.begin(115200);
  initMotor();
}

void loop() {
  bool water = readS();
  if (water) {
    Serial.println("Moisture: +");
    onMotor();
  } else {
    Serial.println("Moisture: -");
    offMotor();
  }
  delay(100);
}

void initMotor() {
  pinMode (MOTOR_PIN, OUTPUT);
}

void onMotor() {
  digitalWrite(MOTOR_PIN, LOW);
}

void offMotor() {
  digitalWrite(MOTOR_PIN, HIGH);
}

bool readS() {
  int dValue = digitalRead(S_PIN); // 0: không có nước; 1: có nước
  if (dValue) return 1;
  else return 0;
}