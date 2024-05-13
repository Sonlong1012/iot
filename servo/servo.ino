#if defined(ESP8266)
  #include <Servo.h>
  #define SERVO_PIN D8
#endif
Servo servo;

void setup() {
  initServo();
}
void loop() {
  upServo();
  downServo();
}
void initServo() {
  servo.attach(SERVO_PIN);
  servo.write(0);
}
void upServo() {
  for (int pos = 0; pos <= 180; pos += 1) {
    servo.write(pos);
    delay(20);
  }
}

void downServo() {
  for (int pos = 180; pos >= 0; pos -= 1) {
    servo.write(pos);
    delay(20);
  }
}
