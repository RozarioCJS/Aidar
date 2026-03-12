#include <Servo.h>

Servo myservo;

const int trigPin = 9;  
const int echoPin = 10; 
const int servoPin = 8;
long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  myservo.attach(servoPin);
	Serial.begin(9600);  

}

void ScanD() {
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  delay(100);
}

void PrintDistance( int distance) {
    Serial.print("Distance: ");
    Serial.println(distance);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  ScanD();
  PrintDistance(distance);
  for (int pos = 0; pos <= 180; pos +=1) {
    myservo.write(pos);
    Serial.print("Pos: ");
    Serial.println(pos);
    delay(15);
  }
  PrintDistance(distance);
 for (int pos = 180; pos >= 0; pos -=1) {
    myservo.write(pos);
    Serial.print("Pos: ");
    Serial.println(pos);
    delay(15);
 }
  
}
