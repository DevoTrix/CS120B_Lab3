int l1 = 5;
int l2 = 4;
int l3 = 3;
int l4 = 2;
int rlp = 9;
int blp = 10;
int glp = 11;
unsigned long last_update = 0;
int timer = 2000;
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

enum States {INIT, S0, S1, S2, S3} state = INIT;

void Tick() {

  switch (state) { // State transitions

    case INIT:
      //State Transition
      state = S0;
      break;
    case S0:
      if(millis() > last_update + timer){
        last_update = millis();
        state = S1;
      }
      else{
        state = S0;
      }
      break;
    case S1:
      if(millis() > last_update + timer){
        last_update = millis();
        state = S2;
      }
      else {
        state = S1;
      }
      break;
    case S2:
      if(millis() > last_update + timer){
        last_update = millis();
        state = S3;
      }
      else{
        state = S2;
      }
      break;
    case S3:
      if(millis() > last_update + timer){
        last_update = millis();
        state = S0;
      }
      else {
        state = S3;
      }
      break;
  }

  switch (state) { // State Action

    case INIT:
      //State Action
      break;
    case S0:
      analogWrite(rlp, 0);
      analogWrite(glp, 230);
      analogWrite(blp, 255);
      break;
    case S1:
      analogWrite(rlp, 111);
      analogWrite(glp, 0);
      analogWrite(blp, 255);
      break;
    case S2:
      analogWrite(rlp, 205);
      analogWrite(glp, 139);
      analogWrite(blp, 41);
      break;
    case S3:
      analogWrite(rlp, 142);
      analogWrite(glp, 55);
      analogWrite(blp, 136);
      break;
  }
}

void loop() {

  ///Default arduino function

 
  Tick();
}