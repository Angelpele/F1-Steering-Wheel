// ================= 74LS154 =================
const int addrPins[4] = {5, 6, 7, 11};

int pattern[] = {0, 1, 2, 3, 4, 5, 6, 7,
                 8, 9, 10, 11, 12, 13, 14, 15};
int patternLength = sizeof(pattern) / sizeof(pattern[0]);

// ================= ADC =================
const int buttonsPin = 4;

// ================= DISPLAY 7 SEG =================
// Segments
const int segA = 15;
const int segB = 20;
const int segC = 18;
const int segD = 13;
const int segE = 10;
const int segF = 23;
const int segG = 19;

// Digits (common cathode)
const int dig1 = 17;
const int dig2 = 22;
const int dig3 = 21;
const int dig4 = 16;

const int segPins[7] = {segA, segB, segC, segD, segE, segF, segG};
const int digPins[4] = {dig1, dig2, dig3, dig4};

// a b c d e f g
const byte numbers[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};

// ================= SETUP =================
void setup() {
  pinMode(buttonsPin, INPUT);

  for (int i = 0; i < 4; i++) pinMode(addrPins[i], OUTPUT);
  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digPins[i], OUTPUT);
}

// ================= 74LS154 FUNCTIONS =================
void selectOutput(int value) {
  for (int i = 0; i < 4; i++) {
    digitalWrite(addrPins[i], (value >> i) & 0x01);
  }
}

void allLedsOn(int duration_ms) {
  unsigned long start = millis();
  while (millis() - start < duration_ms) {
    for (int i = 0; i < 16; i++) {
      selectOutput(i);
      delayMicroseconds(500);
    }
  }
}

// ================= DISPLAY FUNCTIONS =================
void mostrarNumero(int num) {
  int digits[4];

  digits[0] = (num / 1000) % 10;
  digits[1] = (num / 100)  % 10;
  digits[2] = (num / 10)   % 10;
  digits[3] = num % 10;

  for (int i = 0; i < 4; i++) {
    activarDigito(i);
    mostrarDigito(digits[i]);
    delay(1);
    apagarDigitos();
  }
}

void mostrarDigito(int n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], numbers[n][i]);
  }
}

void activarDigito(int d) {
  apagarDigitos();
  digitalWrite(digPins[d], LOW);
}

void apagarDigitos() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(digPins[i], HIGH);
  }
}

// ================= LOOP =================
void loop() {

  // --- LED Forward pattern ---
  for (int i = 0; i < patternLength; i++) {
    selectOutput(pattern[i]);
    delay(10);
  }

  // --- LED Reverse pattern ---
  for (int i = patternLength - 1; i >= 0; i--) {
    selectOutput(pattern[i]);
    delay(100);
  }

  // --- Blink all LEDs visually ---
  for (int i = 0; i < 3; i++) {
    allLedsOn(500);
    delay(500);
  }

  // --- Read ADC and display RAW value ---
  int adcValue = analogRead(buttonsPin);

  for (int i = 0; i < 50; i++) {   // refresh display for visibility
    mostrarNumero(adcValue);
  }
}
