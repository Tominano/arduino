// Kutyarisztópróba Buzzerrel
const int buzzer=7; // ledpin and soundpin are not changed throughout the process 
const int soundpin=A2;
const int threshold=200; // sets threshold value for sound sensor
////////////////////////////////////////////////////////////////
// Ultrahangos mozgásérzékelő
const int trigPin=12;
const int echoPin=11;
const int ledPin=10;
const int sonarMin=20;  // ezt kell állítani
long duration;
int distance;
////////////////////////////////////////////////////////////////
//   Póstaláda érzékelő
const int sensorPin = A0; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor    //ez nem kell
const int sensorMin=300;// Ezt állítom be, hogy mikor jelezzen a póstaládás motyó
const int postPin = 8;

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
      for (int i = 0; i <= 10000; i++) {
    tone(buzzer, i);
    delay(10);
      } 
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
  }
  else{
    digitalWrite(buzzer,LOW);
    }
/////////////////////////////////////////////////////
digitalWrite(trigPin,LOW);
delayMicroseconds(1);
digitalWrite(trigPin,HIGH);
delayMicroseconds(2);
digitalWrite(trigPin,LOW);
duration= pulseIn(echoPin,HIGH);
distance=duration*(0.034/2);
//Serial.print("Distance:");
//Serial.println(distance);    //mozgásérzékelős risztó

if(distance <= sonarMin){
  digitalWrite(ledPin,HIGH);
}
  else{
  digitalWrite(ledPin,LOW);
  }
///////////////////////////////////////////////
sensorValue = analogRead(sensorPin); // read the value from the sensor
//Serial.println(sensorValue); //A kiírásból be tudom állítani a limitet, hogy mikor jelezzen
delay(20);
if (sensorMin > sensorValue){
  digitalWrite(postPin,HIGH);
  }
  else{
    digitalWrite(postPin,LOW);}

}
