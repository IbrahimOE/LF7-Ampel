//1(Ampel läuft zyklisch)

// Pins für die Ampel-LEDs definieren
const int redPin = 9;
const int yellowPin = 7;
const int greenPin = 4;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Rot leuchtet für 5 Sekunden
  digitalWrite(redPin, HIGH);
  delay(5000);
  
  // Rot & Gelb leuchten zusammen für 2 Sekunden
  digitalWrite(yellowPin, HIGH);
  delay(2000);

  // Grün leuchtet für 5 Sekunden
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(5000);

  // Gelb leuchtet für 2 Sekunden
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  
  // Gelb aus, Zyklus beginnt von vorne
  digitalWrite(yellowPin, LOW);
}

