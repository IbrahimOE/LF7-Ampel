// AutoAmpel
int ROT = 9;
int GELB = 7;
int GRUEN = 5;

// Fußgängerampel
int F_ROT = 3;
int F_GRUEN = 4;

// Taster (2 Straßenseiten)
int TASTER1 = 2;
int TASTER2 = 3;

// Status der Taster
int TasterLesen1;
int TasterLesen2;

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

  // Taster (beide Seiten)
  pinMode(TASTER1, INPUT_PULLUP);
  pinMode(TASTER2, INPUT_PULLUP);

  // Piezo-Lautsprecher
  pinMode(PIEZO, OUTPUT);
}

void loop()
{
  // Ampel grün/Fußgängerampel rot
  digitalWrite(F_ROT, HIGH);
  digitalWrite(GRUEN, HIGH);

  // Zustand der Taster lesen
  TasterLesen1 = digitalRead(TASTER1);
  TasterLesen2 = digitalRead(TASTER2);
  delay(200);
 
  // Wenn **einer** der beiden Taster gedrückt wird
  if (TasterLesen1 == LOW || TasterLesen2 == LOW)
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

    // Fußgängerampel auf grün schalten (beide Seiten)
    digitalWrite(F_ROT, LOW);
    digitalWrite(F_GRUEN, HIGH);

    // Ton-Signal für Blinde alle 0,5 Sekunden
    unsigned long previousMillis = 0;
    const long interval = 500;

    unsigned long startMillis = millis();  // Zeit merken
    while (millis() - startMillis < 5000) // 5 Sekunden lang
    {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval)
      {
        previousMillis = currentMillis;
        tone(PIEZO, 1000);
        delay(250);
        noTone(PIEZO);
      }
    }

    // Fußgängerampel auf rot schalten
    digitalWrite(F_GRUEN, LOW);
    digitalWrite(F_ROT, HIGH);

    // 1 s Pause
    delay(1000);

    // Fahrbahnampel auf gelb und dann auf grün schalten
    digitalWrite(GELB, HIGH);
    delay(1000);
    digitalWrite(ROT, LOW);
    digitalWrite(GELB, LOW);
    digitalWrite(GRUEN, HIGH);
  }
}
