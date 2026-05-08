//main pin in is d2
const int fobPin = 2;
const int switchPin = 7;

unsigned long startOfPulse=0;
bool timing = false;

void setup () {
  pinMode(fobPin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, LOW);
  Serial.begin(9600);
}

void loop() {
  Serial.print("\r fobPin bool value:");
  Serial.print( digitalRead(fobPin) );
  Serial.print(" switchPin bool value:");
  Serial.print( digitalRead(switchPin) );



  if (digitalRead(fobPin) == HIGH){
    if (!timing) { // locks in when pulse started
      startOfPulse = millis();
      timing=true;
    }

    if (millis() - startOfPulse > 2000) { // see if you have waited long enough
      digitalWrite(switchPin, HIGH);
      delay(2250); // wait two an a quarter seconds
    }
  } else {
    timing = false;
    digitalWrite(switchPin, LOW);
    //startOfPulse = millis(); // if ever touches low "timer" resets
  }
}

