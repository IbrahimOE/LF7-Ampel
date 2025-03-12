Auto Ampel aktuell

// AutoAmpel
int ROT = 9;
int GELB = 7;
int GRUEN = 5;

// Fußgängerampel
int F_ROT = 3;
int F_GRUEN = 4;

// Taster
int TASTER = 2;

// Status des Tasters
int TasterLesen;

// Piezo-Lautsprecher Pin
int PIEZO = 10;

void setup()
{
  // Fahrbahnampel
  pinMode(ROT, OUTPUT);
  pinMode(GELB, OUTPUT);
  pinMode(GRUEN, OUTPUT);

  // Fußgängerampel
  pinMode(F_ROT, OUTPUT);
  pinMode(F_GRUEN, OUTPUT); 

  // Taster
  pinMode(TASTER, INPUT_PULLUP);

  // Piezo-Lautsprecher
  pinMode(PIEZO, OUTPUT);
}

void loop()
{
  // Ampel grün/Fußgängerampel rot
  digitalWrite(F_ROT, HIGH);
  digitalWrite(GRUEN, HIGH);

  // Zustand des Tasters lesen 
  TasterLesen = digitalRead(TASTER);
  delay(200);
 
  // Taster auf HIGH gesetzt -> gedrückt = LOW
  if (TasterLesen == LOW)
  {
    // 1 s Pause
    delay(1000);

    // Fahrbahnampel grün aus
    digitalWrite(GRUEN, LOW);

    // Fahrbahnampel gelb an 
    digitalWrite(GELB, HIGH);
    delay(1000);
    digitalWrite(GELB, LOW);

    // Fahrbahnampel rot an
    digitalWrite(ROT, HIGH); 

    // 1 s Sicherheitszeit 
    delay(1000); 

    // Fußgängerampel auf grün schalten
    digitalWrite(F_ROT, LOW);
    digitalWrite(F_GRUEN, HIGH);

    // Ton-Signal für Fußgängerampel grün
    tone(PIEZO, 500); // Ton bei 1000 Hz
    delay(1000);       // Ton für 500 ms
    noTone(PIEZO);    // Ton stoppen

    delay(5000); // Fußgängerampel für 5 Sekunden grün

    // Fußgängerampel auf rot schalten
    digitalWrite(F_GRUEN, LOW);
    digitalWrite(F_ROT, HIGH);

    // 1 s Pause
    delay(1000);

    // Fahrbahnampel auf gelb und dann auf rot schalten
    digitalWrite(GELB, HIGH);
    delay(1000);
    digitalWrite(ROT, LOW);
    digitalWrite(GELB, LOW);
  }
}
