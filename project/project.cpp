SET(CMAKE_SYSTEM_NAME Generic)

SET(CMAKE_C_COMPILER avr-gcc)
SET(CMAKE_CXX_COMPILER avr-g++)

SET(CSTANDARD "-std=gnu99")
SET(CDEBUG "-gstabs")
SET(CWARN "-Wall -Wstrict-prototypes")
SET(CTUNING "-funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums")
SET(COPT "-Os")
SET(CINCS "-I${Candi_SOURCE_DIR}/libarduino")
SET(CMCU "-mmcu=atmega168")
SET(CDEFS "-DF_CPU=16000000")


SET(CFLAGS "${CMCU} ${CDEBUG} ${CDEFS} ${CINCS} ${COPT} ${CWARN} ${CSTANDARD} ${CEXTRA}")
SET(CXXFLAGS "${CMCU} ${CDEFS} ${CINCS} ${COPT}")

SET(CMAKE_C_FLAGS ${CFLAGS})
SET(CMAKE_CXX_FLAGS ${CXXFLAGS})



// include the library code:
#include <LiquidCrystal.h>

long duration;
int distance; 
int n = 0;
int m = 0;
const int buzzer = A2;
const int soundpin=A5;
const int threshold=200;
const int trigPin=A0;
const int echoPin=A1;
const int sonarMin=30;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("!!Ugat!!!Megy!!");

  pinMode(buzzer,OUTPUT); 
  pinMode(soundpin,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT); 
  Serial.begin(9600);//mozgásérzékelö risztóhoz
  
}

void loop() {

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);


  
  int soundsens=analogRead(soundpin); // reads analog data from sound sensor
  if (soundsens>=threshold) { // Against the dogbarking
      for (int i = 1000; i <= 10000; i++) {
        tone(buzzer, i);
        delay(1);
      } 
           // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(10);
    n++;
  }
  else{
    digitalWrite(buzzer,LOW);
    }
/////////////////////////////////////////////////////

  if(distance <= sonarMin){
  for (int j = 1000; j <= 10000; j++) {
          tone(buzzer, j);
          delay(1);
        } 
            // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(10);
      m++;
    }
    else{
      digitalWrite(buzzer,LOW);
    }
  

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if(n >= 20){
    lcd.setCursor(0,1);
    lcd.print("MuchBark");
    lcd.setCursor(9,1);
    lcd.print(m);}
    else{
      lcd.setCursor(9,1);
      lcd.print(m);
      lcd.setCursor(0,1);
      lcd.print(n);}

}
