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
  digitalWrite(mAvant, HIGH);
  digitalWrite(mArrier, LOW);
  Serial.println("Go !");
}

void loop(){
  if (Serial.available()) {
    data = Serial.read();
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
        data = Serial.read();
        Serial.println(data);
        analogWrite(angle, data);
        break;
      default:
        Serial.println('Error');
        break; 
    }
    delay(1);
  }
}
