
// int l1 = 5;
// int l2 = 4;
// int l3 = 3;
// int l4 = 2;
int rlp = 9;
int blp = 10;
int glp = 11;
unsigned long last_update = 0;
int val = 0;
int bright = 0;

int B[4] = {5, 4, 3, 2};
void setup() {
  pinMode(rlp, OUTPUT);
  pinMode(glp, OUTPUT);
  pinMode(blp, OUTPUT);
  // pinMode(l1, OUTPUT);
  // pinMode(l2, OUTPUT);
  // pinMode(l3, OUTPUT);
  // pinMode(l4, OUTPUT);
  for(int i = 0; i < 4; i++){
    pinMode(B[i], OUTPUT);
  }
  Serial.begin(9600);
}

enum States {INIT, S0, S1} state = INIT;

void Tick() {
  val = analogRead(A0);
  val = map(val, 0, 1021, 0, 4);
  bright = analogRead(A1);
  if(bright > 98){
    bright = 1;
    }
  else{
    bright = 0;
  }
  switch (state) { // State transitions
    
    case INIT:
      //State Transition
      state = S0;
      break;

    case S0:
      if(bright){
        state = S1;
      }
      else{
        state = S0;
      }
      break;

    case S1:
      if(!bright){
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
      for(int i = 0; i < 4; i++){
        digitalWrite(B[i],LOW);
      }
      break;

    case S1:
      for(int i = 0; i < 4; i++){
        digitalWrite(B[i],LOW);
      }
      for(int i = 0; i < val; i++){
        digitalWrite(B[i],HIGH);
      }
      break;
  }
}

void loop() {

  ///Default arduino function

  Serial.println(analogRead(A1));
  Tick();
}
