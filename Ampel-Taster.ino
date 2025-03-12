//AutoAmpel
int ROT = 9;
int GELB = 7;
int GRUEN = 5;

// Fußgängerampel
int F_ROT = 3;
int F_GRUEN = 4;

// Taster
int TASTER = 2;

// Status des Taster
int TasterLesen;

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
  //  INPUT_PULLUP = Modus Eingabe und Eingangspegel auf HIGH setzen
  pinMode(TASTER, INPUT_PULLUP);
}

void loop()
{
  // Ampel grün/Fußgängerampel rot
  digitalWrite(F_ROT, HIGH);
  digitalWrite(GRUEN, HIGH);

  // Zustand des Tasters lesen 
  TasterLesen = digitalRead(TASTER);
  delay(200);
 
  // Taster auf HIGH gesetzt -> gedrückt  = LOW
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
    delay(5000); 

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