#if defined(ESP8266)
#define MOTOR_PIN D7
#define D0_PIN D5
#endif

void setup() {
  Serial.begin(115200);
  initMotor();
}

void loop() {
  bool moisture = readD0();
  if (moisture) {
    Serial.println("Moisture: +");
    offMotor();
  } else {
    Serial.println("Moisture: -");
    onMotor();
  }
  delay(100);
}

void initMotor() {
  pinMode (MOTOR_PIN, OUTPUT);
}

void onMotor() {
  digitalWrite(MOTOR_PIN, HIGH);
}

void offMotor() {
  digitalWrite(MOTOR_PIN, LOW);
}

bool readD0() {
  int dValue = digitalRead(D0_PIN);
  if (dValue) return 0;
  else return 1;
}