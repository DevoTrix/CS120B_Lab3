int l1 = 5;
int l2 = 4;
int l3 = 3;
int l4 = 2;
int rlp = 9;
int blp = 10;
int glp = 11;
unsigned long last_update = 0;

void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  Serial.begin(9600);
}

enum States {INIT, S0, S1} state = INIT;

void Tick() {

  switch (state) { // State transitions

    case INIT:
      //State Transition
      state = S0;
      break;

    case S0:
      if (millis() > last_update + 1000) {
        last_update = millis(); // Don't forget to update last_update with current time
        state = S1;
      }
      else {
        state = S0;
      }
      break;

    case S1:
      if (millis() > last_update + 1000) {
        last_update = millis();
        state = S0;
      }
      else {
        state = S1;
      }

      //State Transition
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;

    case S0:
      //State Action
      digitalWrite(l1, HIGH);
      digitalWrite(l2, LOW);
      digitalWrite(l3, HIGH);
      digitalWrite(l4, LOW);
      analogWrite(rlp, 255);
      analogWrite(glp, 255);
      analogWrite(blp, 255);
      break;

    case S1:
      //State Action
      digitalWrite(l1, LOW);
      digitalWrite(l2, HIGH);
      digitalWrite(l3, LOW);
      digitalWrite(l4, HIGH);
      analogWrite(rlp, 0);
      analogWrite(glp, 0);
      analogWrite(blp, 0);
      break;
  }
}

void loop() {

  ///Default arduino function
  Serial.println(analogRead(A1));
 
  Tick();
}