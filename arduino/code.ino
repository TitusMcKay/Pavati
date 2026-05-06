//main pin in is d2
const int fobPin = 2;
const int switchPin = 7;

unsigned long startOfPulse=0;
bool timing = false;

void setup () {
  pinMode(fobPin, INPUT);
  pinMode(switchPin, OUTPUT);
  digitalWrite(switchPin, LOW);
}

void loop() {
  if (digitalRead(fobPin) == HIGH){
    if (!timing) {
      startOfPulse = millis();
      timing=true;
    }
    if (millis()- startOfPulse > 2000) { // see if you have waited long enough
      digitalWrite(switchPin, HIGH);
      delay(2250); // wait two an a quarter seconds
    }
  } else {
    timing = false;
    digitalWrite(switchPin, LOW);
  }
}
/*
this is code gened by a clanker 🤮, so im hand wrighting the code above 😃👍
const int inPin  = 2;   // input
const int outPin = 3;   // output

unsigned long start = 0;
bool timing = false;

void setup() {
  pinMode(inPin,  INPUT);
  pinMode(outPin, OUTPUT);
}

void loop() {
  if (digitalRead(inPin) == HIGH) {
    if (!timing) {
      start = millis();
      timing = true;
    }
    if (millis() - start > 2000) {
      digitalWrite(outPin, HIGH);   // set pin 3 high
    }
  } else {
    timing = false;
    digitalWrite(outPin, LOW);      // optional: reset output when input is low
  }
}
*/

