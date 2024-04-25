
#define D0_PIN D5

#define LED_PIN D7

void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
   readD0();
}

bool readD0() {
  int dValue = digitalRead(D0_PIN);
  if(dValue) return 0;
  else return 1;
}