

const int buzzer=13; // ledpin and soundpin are not changed throughout the process 
const int soundpin=A2;
const int threshold=763; // sets threshold value for sound sensor
////////////////////////////////////////////////////////////////
const int trigPin=12;
const int echoPin=11;
const int ledPin=10;
long duration;
int distance;

void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);     // Against the dogbarking
pinMode(soundpin,INPUT);
//////////////////////////////////////////////////////////////
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);  //mozgásérzékelö risztóhoz
pinMode(ledPin, OUTPUT);
}

void loop() {
int soundsens=analogRead(soundpin); // reads analog data from sound sensor
  if (soundsens>=threshold) { // Against the dogbarking
    tone(buzzer, 200); 
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
  }
  else{
    digitalWrite(buzzer,LOW);
    }
/////////////////////////////////////////////////////
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration= pulseIn(echoPin,HIGH);
distance=duration*(0.034/2);
Serial.print("Distance:");
Serial.println(distance);

if (distance < // mérni){
digitalWrite(ledPin,HIGH);
  delay(1000);
  digitalWrite(ledPin,LOW);
  delay(1000);
}
else{
  digitalWrite(ledPin,LOW);
  }
}
