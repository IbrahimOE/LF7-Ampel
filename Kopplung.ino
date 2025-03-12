int ROT = 13;
int GELB = 12;
int GRUEN = 11;

int F_ROT = 7;
int F_GRUEN = 6;

int TASTER1 = 3;
int TASTER2 = 4;

int TasterLesen1;
int TasterLesen2;

int PIEZO = 2;

void setup()
{
  pinMode(ROT, OUTPUT);
  pinMode(GELB, OUTPUT);
  pinMode(GRUEN, OUTPUT);

  pinMode(F_ROT, OUTPUT);
  pinMode(F_GRUEN, OUTPUT); 

  pinMode(TASTER1, INPUT_PULLUP);
  pinMode(TASTER2, INPUT_PULLUP);

  pinMode(PIEZO, OUTPUT);
}

void loop()
{
  digitalWrite(F_ROT, HIGH);
  digitalWrite(GRUEN, HIGH);

  TasterLesen1 = digitalRead(TASTER1);
  TasterLesen2 = digitalRead(TASTER2);
  delay(0);
 
  if (TasterLesen1 == LOW || TasterLesen2 == LOW)
  {
    delay(1000);

    digitalWrite(GRUEN, LOW);

    digitalWrite(GELB, HIGH);
    delay(1000);
    digitalWrite(GELB, LOW);

    digitalWrite(ROT, HIGH); 

    delay(1000); 

    digitalWrite(F_ROT, LOW);
    digitalWrite(F_GRUEN, HIGH);

    unsigned long previousMillis = 0;
    const long interval = 500;

    unsigned long startMillis = millis();  // Zeit merken
    while (millis() - startMillis < 5000) // 5 Sekunden lang
    {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= interval)
      {
        previousMillis = currentMillis;
        tone(PIEZO, 500);
        delay(80);
        noTone(PIEZO);
      }
    }

    digitalWrite(F_GRUEN, LOW);
    digitalWrite(F_ROT, HIGH);

    delay(1000);

    digitalWrite(GELB, HIGH);
    delay(1000);
    digitalWrite(ROT, LOW);
    digitalWrite(GELB, LOW);
    digitalWrite(GRUEN, HIGH);

  }
}
