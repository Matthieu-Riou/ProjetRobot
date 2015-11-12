int mAvant = 5;
int mArrier = 6;
int angle = 9;
int data = 0;

void setup(){
  Serial.begin(9600);
  pinMode(angle, OUTPUT);
  analogWrite(angle, 0);
  pinMode(mAvant, OUTPUT);
  pinMode(mArrier, OUTPUT);
  digitalWrite(mAvant, LOW);
  digitalWrite(mArrier, LOW);
}

void loop(){
  if (Serial.available()) {
    data = Serial.read()-'0';
    Serial.println(data);
    switch(data){
      case 0:
        digitalWrite(mAvant, LOW);
        digitalWrite(mArrier, LOW);
        break;
      case 1:
        digitalWrite(mAvant, HIGH);
        digitalWrite(mArrier, LOW);
        break;
      case 2:
        digitalWrite(mAvant, LOW);
        digitalWrite(mArrier, HIGH);
        break;
      case 3:
        while(Serial.available() <= 0)
          delay(1);
        data = Serial.read() - '0';
        analogWrite(angle, data);
        break;
      default:break; 
    }
    delay(1);
  }
}
