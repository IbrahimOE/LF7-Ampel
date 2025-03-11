// Pins für die Ampel-LEDs definieren
const int redPin = 9;
const int yellowPin = 7;
const int greenPin = 4;

// Pins für die Fußgängerampel-LEDs definieren
const int redPedestrianPin = 2;  // Rote LED für Fußgänger
const int greenPedestrianPin = 3;  // Grüne LED für Fußgänger

void setup() {
  // Setze alle Pins als Ausgang
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPedestrianPin, OUTPUT);
  pinMode(greenPedestrianPin, OUTPUT);
}

void loop() {
  // Hauptampel: Rot leuchtet für 5 Sekunden
  digitalWrite(redPin, HIGH);
  digitalWrite(redPedestrianPin, HIGH);  // Fußgängerampel rot
  digitalWrite(greenPedestrianPin, LOW);  // Fußgängerampel grün aus
  delay(5000);
  
  // Hauptampel: Rot & Gelb leuchten zusammen für 2 Sekunden
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  
  // Hauptampel: Grün leuchtet für 5 Sekunden
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPedestrianPin, LOW);  // Fußgängerampel rot aus
  digitalWrite(greenPedestrianPin, HIGH);  // Fußgängerampel grün an
  delay(5000);
  
  // Hauptampel: Gelb leuchtet für 2 Sekunden
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  
  // Gelb aus, Zyklus beginnt von vorne
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPedestrianPin, LOW);  // Fußgängerampel grün aus
}
