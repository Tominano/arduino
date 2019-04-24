const int buzzer=13; // ledpin and soundpin are not changed throughout the process 
const int soundpin=A2;
const int threshold=763; // sets threshold value for sound sensor
void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);
pinMode(soundpin,INPUT);
}
void loop() {
int soundsens=analogRead(soundpin); // reads analog data from sound sensor
if (soundsens>=threshold) {
  tone(buzzer, 200); // Send 1KHz sound signal...
  delay(1000);        // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(1000);
}
else{
digitalWrite(buzzer,LOW);
}
}
