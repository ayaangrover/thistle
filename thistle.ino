const int switchPins[4] = {26, 27, 28, 29};
const int ledPins[4] = {6, 7, 0, 1};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  bool swStates[4];
  for (int i = 0; i < 4; i++) {
    swStates[i] = (digitalRead(switchPins[i]) == LOW);
  }

  for (int i = 0; i < 4; i++) {
    digitalWrite(ledPins[i], LOW);
  }

  if (swStates[3]) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
  else if (swStates[2]) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
  else if (swStates[1]) {
    for (int i = 0; i < 2; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
  else if (swStates[0]) {
    digitalWrite(ledPins[0], HIGH);
  }

  delay(10);
}