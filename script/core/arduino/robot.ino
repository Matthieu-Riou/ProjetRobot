int mAvant = 3;
int mArrier = 4;
int angle = 5;
int data = 0;

void setup(){
  Serial.begin(9600);
  analogWrite(angle, 90);
  digitalWrite(mAvant, LOW);
  digitalWrite(mArrier, LOW);
}

void loop(){
  if (Serial.available() > 0) {
    data = Serial.read();
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
        data = Serial.read();
        analogWrite(angle, data);
        break;
      default:break; 
    }
    analogWrite(angle);
  }
}
