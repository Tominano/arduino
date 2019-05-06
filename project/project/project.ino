#include <LiquidCrystal.h>

// Kutyarisztópróba Buzzerrel
const int buzzer=7; // ledpin and soundpin are not changed throughout the process 
const int soundpin=A2;
const int threshold=200; // sets threshold value for sound sensor
////////////////////////////////////////////////////////////////
// Ultrahangos mozgásérzékelő
const int trigPin=8;
const int echoPin=9;
const int ledPin=10;
const int sonarMin=20;  // ezt kell állítani
long duration;
int distance;
////////////////////////////////////////////////////////////////
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
Serial.begin(9600);
pinMode(buzzer,OUTPUT);     // Against the dogbarking
pinMode(soundpin,INPUT);
//////////////////////////////////////////////////////////////
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);  //mozgásérzékelö risztóhoz
pinMode(ledPin, OUTPUT);
////////////////////////////////////////////
// set up the LCD's number of columns and rows:
lcd.begin(16, 2);
// Print a message to the LCD.
lcd.print("Ugatás, Ajtóhozmenés!");
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

if(distance <= sonarMin){
for (int j = 0; j <= 10000; j++) {
        tone(buzzer, j);
        delay(10);
      } 
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
///////////////////////////////////////////////////
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
// print the number of seconds since reset:
lcd.print(millis() / 1000);
}

///////////////////////////////////////////////
