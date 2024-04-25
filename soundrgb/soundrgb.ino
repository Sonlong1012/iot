
#define D0_PIN D5

#define LED_PIN D7

void setup(){
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  readD0();
}


int clap =0;
long detection_range_start =0;
long detection_range = 0;
void readD0(){
  int dValue = digitalRead(D0_PIN);
  if (dValue == 0){
    if(clap ==0){
      detection_range_start = detection_range = millis();
      clap++;
    }else if (clap > 0 && millis() - detection_range >=100) {
      detection_range = millis();
      clap++;
    }
  }
  if (millis() - detection_range_start >= 500) {
    if(clap ==1){
      Serial.println("CLAP 1 times");
      digitalWrite(LED_PIN, HIGH);
    }else if (clap== 2) {
      Serial.println("CLAP 2 times");
      digitalWrite(LED_PIN, LOW);
    }
    clap = 0;
  }
}
