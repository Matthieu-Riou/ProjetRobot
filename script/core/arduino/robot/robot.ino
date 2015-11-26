#include <Servo.h>

int mAvant = 5;
int mArrier = 6;
int servoPin = 9;
int feedbackPin = A0;
int data = 0;

Servo myservo;

// Calibration values
int minDegrees;
int maxDegrees;
int minFeedback;
int maxFeedback;
int tolerance = 2; // max feedback measurement error
 
/*
This function establishes the feedback values for 2 positions of the servo.
With this information, we can interpolate feedback values for intermediate positions
*/
void calibrate(Servo servo, int analogPin, int minPos, int maxPos)
{
  // Move to the minimum position and record the feedback value
  servo.write(minPos);
  minDegrees = minPos;
  delay(2000); // make sure it has time to get there and settle
  minFeedback = analogRead(analogPin);
  // Move to the maximum position and record the feedback value
  servo.write(maxPos);
  maxDegrees = maxPos;
  delay(2000); // make sure it has time to get there and settle
  maxFeedback = analogRead(analogPin);
}

void setup(){
  Serial.begin(9600);
  Serial.println("Moteur");
  pinMode(mAvant, OUTPUT);
  pinMode(mArrier, OUTPUT);
  digitalWrite(mAvant, HIGH);
  digitalWrite(mArrier, LOW);
  Serial.println("Servo-moteur");
  myservo.attach(servoPin);
  calibrate(myservo, feedbackPin, 20, 160); // calibrate for the 20-160 degree range
  Serial.begin(9600);
  Serial.println("20 : " + minFeedback);
  Serial.println("160 : " + maxFeedback);
  myservo.write(90);
  delay(2000);
  Serial.println("90 : " + analogRead(feedbackPin));
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
        myservo.write(data);
        break;
      default:
        Serial.println('Error');
        break; 
    }
    delay(1);
  }
}
