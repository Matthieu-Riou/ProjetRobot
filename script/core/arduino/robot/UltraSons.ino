int TRIG = 3;
int ECHO = 4;

void setup(){
  Serial.begin(9600);
  initUltraSons(TRIG, ECHO);
}

void loop(){
    Serial.println(distance(TRIG, ECHO));
    delay(200);
}

//************ Gestion du capteur ultrasons ************
void initUltraSons(int trig, int echo){
  pinMode(TRIG, OUTPUT);
  digitalWrite(TRIG, LOW);
  pinMode(ECHO, INPUT);
}

int distance(int trig, int echo){
    long lecture_echo;
    long cm;
    
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
    
    lecture_echo = pulseIn(echo, HIGH);
    cm = lecture_echo / 58;
    return cm;
}
//**************** FIN ****************
