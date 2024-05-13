#if defined(ESP8266)
#include <Servo.h>
#define SERVO_PIN D8
#endif
#include <Keypad.h>
#define ROWS 4
#define COLS 4
#if defined(ESP8266)
  byte rowPins[ROWS] = {D3, D2, D1, D0};
  byte colPins[COLS] = {D4, D5, D6, D7};
#endif
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
Servo servo;

void setup() {
  Serial.begin(115200);
  initServo();
}

String pwd = "159"; int pos = 0;
void loop() {
  char key = keypad.getKey();
  if (key == '*' || key == '#') {
    Serial.println(key);
    downServo();
    pos = 0;
  } else if (key == pwd[pos]) {
    Serial.println(key);
    pos++;
    if (pos == pwd.length()) {
      upServo();
      pos = 0;
    }
  }
  delay(100);
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