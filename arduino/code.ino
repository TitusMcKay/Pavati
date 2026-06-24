//main pin in is d2
const int fobPin = 2;
const int switchPin = 7;

unsigned long startOfPulse=0;
unsigned long startOfDelay=0;
bool timing = false;
bool offPulse = false;

void setup () {
  pinMode(fobPin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  Serial.print("\r fobPin bool value:");
  Serial.print( digitalRead(fobPin) );
  Serial.print(" switchPin bool value:");
  Serial.print( digitalRead(switchPin) );
  Serial.print("  time after pulse started:");
  //Serial.print(millis() - startOfPulse);


  if (digitalRead(fobPin) == HIGH){
    if (!timing) { // locks in when pulse started
      startOfPulse = millis();
      timing=true;
    }

    if (millis() - startOfPulse < 2000) {
      offPulse = false;
    }
    if (millis() - startOfPulse > 2000) { // see if you have waited long enough
      startOfDelay = millis();
      offPulse = true;
      //delay(6000); // time before signal is sent out to the switch
      //digitalWrite(switchPin, LOW); // 12v is now common with line going to switch beause of transistor
      //delay(2250); // wait two an a quarter seconds
    }
  } else {
    timing = false;
    //digitalWrite(switchPin, HIGH);
    startOfPulse = millis(); // if ever touches low "timer" resets
    Serial.print(millis() - startOfPulse);
  }
  if (offPulse && (millis() - startOfDelay > 6000)) {
    digitalWrite(switchPin, LOW);
  } else {
    digitalWrite(switchPin, HIGH);
  }
}

