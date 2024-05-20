#define led1 13
#define led2 12
#define led3 11

#define button1 9
#define button2 8
#define button3 7

int livello = 0;
bool risultato = true;
int gioco[8];
int risposta[8];

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  risultato = true;
  livello = 0;
  for (int n = 0; n < 8; n++) {
    gioco[n] = random(0, 3);
    risposta[n] = 3;
  }

  do {
    for (int i = 0; i <= livello; i++) {
      accendi(gioco[i]);
      delay(200);
    }

    prova();

    if (risultato)
      livello++;
  } while ((risultato) && (livello < 8));

  if (livello == 8) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      delay(100);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(100);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(100);
      
      
    }
  } else {
    for (int i = 0; i < 3; i++) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      delay(200);
    }
  }
}

void accendi(int val) {
  if (val == 0) {
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
  } else if (val == 1) {
    digitalWrite(led2, HIGH);
    delay(500);
    digitalWrite(led2, LOW);
  } else if (val == 2) {
    digitalWrite(led3, HIGH);
    delay(500);
    digitalWrite(led3, LOW);
  }
}

void prova() {
  int s = 0;
  do {
    Serial.println();
    if (digitalRead(button1) == 0) {
      risposta[s] = 0;
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
    if (digitalRead(button2) == 0) {
      risposta[s] = 1;
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
    if (digitalRead(button3) == 0) {
      risposta[s] = 2;
      delay(300);
      if (risposta[s] != gioco[s])
        risultato = false;
      s++;
    }
  } while ((risposta[livello] == 3) && (risultato));

  for (int i = 0; i < 8; i++) {
    risposta[i] = 3;
  }
}
