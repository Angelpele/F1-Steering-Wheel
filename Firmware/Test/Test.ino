// ================= ADC =================
const int buttonsPin = 4;

// ================= BUZZER =================
const int buzzerPin = 12;

// ================= DISPLAY 7 SEG =================
// Segmentos
const int segA = 15;
const int segB = 20;
const int segC = 18;
const int segD = 13;
const int segE = 10;
const int segF = 23;
const int segG = 19;

// Dígitos (cátodos comunes)
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

// ================= BUTTON DEBOUNCE =================
unsigned long lastStableTime = 0;
int lastButton = 0;
int activeButton = 0;
int displayValue = 8;              // default = 8
const unsigned long debounceTime = 120;

// ================= SETUP =================
void setup() {
  pinMode(buttonsPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  for (int i = 0; i < 7; i++) pinMode(segPins[i], OUTPUT);
  for (int i = 0; i < 4; i++) pinMode(digPins[i], OUTPUT);
}

// ================= LOOP =================
void loop() {
  int adc = analogRead(buttonsPin);
  int currentButton = decodeButton(adc);

  if (currentButton != lastButton) {
    lastStableTime = millis();
    lastButton = currentButton;
  }

  if (millis() - lastStableTime > debounceTime) {
    activeButton = currentButton;
  }

  // -------- BUZZER --------
  if (activeButton > 0) {
    tone(buzzerPin, buttonTone(activeButton));
  } else {
    noTone(buzzerPin);
  }

  // -------- DISPLAY LOGIC --------
  if (activeButton == 0) {
    displayValue = 0;      // sin botón → muestra 8
  } else if (activeButton == 8) {
    displayValue = 8;      // botón 8 → muestra 0
  } else {
    displayValue = activeButton;
  }

  mostrarNumero(displayValue);
}

// ================= BUTTON DECODER =================
int decodeButton(int adc) {
  if (adc > 2900) return 1;
  if (adc > 2800) return 2;
  if (adc > 2400) return 3;
  if (adc > 1900) return 4;
  if (adc > 1400) return 5;
  if (adc > 900)  return 6;
  if (adc > 550)  return 7;
  if (adc > 300)  return 0;
  return 8;
}

// ================= BUTTON → TONE =================
int buttonTone(int btn) {
  switch (btn) {
    case 1: return 400;
    case 2: return 500;
    case 3: return 600;
    case 4: return 700;
    case 5: return 800;
    case 6: return 900;
    case 7: return 1000;
    case 8: return 1100;
    default: return 0;
  }
}

// ================= DISPLAY FUNCTIONS =================
void mostrarNumero(int num) {
  int digits[4] = {0, 0, 0, num};

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
