// 74LS154 address pins
const int addrPins[4] = {5, 6, 7, 11};

// LED pattern (values 0–15 correspond to outputs Y0–Y15)
int pattern[] = {0, 1, 2, 3, 4, 5, 6, 7,
                 8, 9, 10, 11, 12, 13, 14, 15};

int patternLength = sizeof(pattern) / sizeof(pattern[0]);

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(addrPins[i], OUTPUT);
  }
}

void selectOutput(int value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(addrPins[i], (value >> i) & 0x01);
  }
}

// Multiplex all LEDs ON for a given time (ms)
void allLedsOn(int duration_ms) {
  unsigned long start = millis();
  while (millis() - start < duration_ms) {
    for (int i = 0; i < 16; i++) {
      selectOutput(i);
      delayMicroseconds(500);  // escaneo rápido
    }
  }
}

// Turn all LEDs OFF
void allLedsOff(int duration_ms) {
  delay(duration_ms);
}

void loop() {

  // Forward pattern
  for (int i = 0; i < patternLength; i++) {
    selectOutput(pattern[i]);
    delay(100);
  }

  // Reverse pattern
  for (int i = patternLength - 1; i >= 0; i--) {
    selectOutput(pattern[i]);
    delay(100);
  }

  // Blink all LEDs 3 times (100 ms ON / 100 ms OFF)
  for (int i = 0; i < 3; i++) {
    allLedsOn(500);
    allLedsOff(500);
  }
}
