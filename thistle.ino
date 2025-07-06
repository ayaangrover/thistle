const int switchPins[4] = {26, 27, 28, 29};
const int ledPins[4] = {6, 7, 0, 1};

const int maxSequenceLength = 20;
int sequence[maxSequenceLength];
int sequenceLength = 1;
int userIndex = 0;
bool gameOver = false;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(switchPins[i], INPUT_PULLUP);
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  randomSeed(analogRead(0));
  generateSequence();
}

void loop() {
  if (gameOver) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    delay(500);
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    delay(500);
    return; 
  }

  playSequence();

  while (userIndex < sequenceLength) {
    int pressed = getPressedButton();
    if (pressed != -1) {
      flashLED(pressed);

      if (pressed != sequence[userIndex]) {
        gameOver = true;
        return;
      }
      userIndex++;
    }
  }

  delay(500);
  userIndex = 0;
  sequenceLength++;
  if (sequenceLength > maxSequenceLength) {
    sequenceLength = 1;
  }
}

void generateSequence() {
  for (int i = 0; i < maxSequenceLength; i++) {
    sequence[i] = random(0, 4);
  }
}

void playSequence() {
  for (int i = 0; i < sequenceLength; i++) {
    flashLED(sequence[i]);
    delay(250);
  }
}

void flashLED(int ledIndex) {
  digitalWrite(ledPins[ledIndex], HIGH);
  delay(300);
  digitalWrite(ledPins[ledIndex], LOW);
  delay(150);
}

int getPressedButton() {
  for (int i = 0; i < 4; i++) {
    if (digitalRead(switchPins[i]) == LOW) {
      while (digitalRead(switchPins[i]) == LOW) {
        delay(10); 
      }
      return i;
    }
  }
  return -1;
}
