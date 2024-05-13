
#include <MFRC522.h>
#include <Servo.h>
#define SERVO_PIN D8
Servo servo;
#define SDA_PIN D3
#define RST_PIN D4
MFRC522 mfrc522(SDA_PIN, RST_PIN);


// setup to run only once
void setup() {
  Serial.begin(115200);
  initServo();
  initMFRC522();
}
// loop to run repeatedly
int oldValue = 0;
void loop() {
  String uid = getCardUID();

  if (uid == "13125511026" && oldValue == 0) {
    Serial.println("white card");
    upServo();
    oldValue = 1;
  } else if (uid == "1955212433" && oldValue == 1) {
    Serial.println("blue card");
    downServo();
    oldValue = 0;
  }
  delay(500);
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

void initMFRC522() {
  SPI.begin();
  mfrc522.PCD_Init();
}


String getCardUID (){
  String uid ="";
  if(mfrc522.PICC_IsNewCardPresent()){
    if(mfrc522.PICC_ReadCardSerial()){
      uid = getCardUIDinDEC(mfrc522.uid.uidByte, mfrc522.uid.size);
    }
  }
  return uid;
}

String getCardUIDinDEC(byte buffer[], byte bufferSize) {
    String result = "";
    for (int i = 0; i < bufferSize; i++) {
        result += (buffer[i] < 0x10) ? "0" : "";
        result += String(buffer[i]);
    }
    return result;
}
