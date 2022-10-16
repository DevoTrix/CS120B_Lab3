int l1 = 5;
int l2 = 4;
int l3 = 3;
int l4 = 2;
int rlp = 9;
int blp = 10;
int glp = 11;
int rmap = 0;
int bmap = 0;
int gmap = 0;
unsigned long last_update = 0;
int timer = 500;
double s1= 1;
double s2 = 0;
double s3 = 0;  
long temp = 0;
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
      if(millis() > last_update + timer){
        last_update = millis();
        // temp = millis();
        // temp = temp / 100;
        // temp = temp * 2*3.14;
        s1 = sin((millis()/100));
        s2 = sin((millis()/100))*2;
        s3 = sin((millis()/100))*4;
        state = S1;
      }
      else{
        
        state = S0;
      }
      break;
    case S1:
      if(millis() > last_update + timer){
        last_update = millis();
        // temp = millis();
        // temp = temp / 100;
        // temp = temp * 2*3.14;
        s1 = sin((millis()/100));
        s2 = sin((millis()/100))*2;
        s3 = sin((millis()/100))*4;
        state = S0;
      }
      else {
        state = S1;
      }
      break;
    
  }

  switch (state) { // State Action
  
    case INIT:
      //State Action
      break;
    case S0:
      Serial.println( s1);
      Serial.println( s2);      
      rmap = map(s1, -1, 1, 0, 255);
      gmap = map(s2, -1, 2, 0, 255);
      bmap = map(s3, -1, 4, 0, 255);
      analogWrite(rlp,rmap);
      analogWrite(glp,gmap);
      analogWrite(blp,bmap);
      // analogWrite(rlp, 0);
      // analogWrite(glp, 230);
      // analogWrite(blp, 255);
      break;
    case S1:
      // int coss= cos(millis()/50) * (180/3.14);
      // int sins = sin(millis()/50 + 2) * (180/3.14) - .7;
      // int cossines = cos(millis() / 25) * (180/3.14);        
      rmap = map(s1, -1, 1, 0, 255);
      gmap = map(s2, -1, 1, 0, 255);
      bmap = map(s3, -1, 1, 0, 255);
      analogWrite(rlp,rmap);
      analogWrite(glp,gmap);
      analogWrite(blp,bmap);
      break;
    
  }
}

void loop() {

  ///Default arduino function

 
  Tick();
}