#main pin in is d2
void setup () {
#  setup things
}

void loop() {
  if pin is high
    if (!timing) {
      startofpulse = mills();
      timing=true
    }
    if (startofpulse() - mills() > 2000) {
      digitalWrite(set the pin to high)
    }
  else {
    do nothing
  }
}
