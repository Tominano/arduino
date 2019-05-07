//segments
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
//int p = 9;
//digits
int d4 = 10;
int d3 = 11;
int d2 = 12;
int d1 = 13;
//other
long n = 0;
int x = 100;
int del = 45;



long duration;
int distance;
int i = 0;
const int buzzer = A2;
const int soundpin=A5;
const int threshold=200;
const int trigPin=A0;
const int echoPin=A1;
const int sonarMin=30;
///////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////

void setup() {
  pinMode(buzzer,OUTPUT); 
  pinMode(soundpin,INPUT);
  
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT); 
  Serial.begin(9600);//mozgásérzékelö risztóhoz

  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
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
  
  //Serial.print("Distance: ");
  //Serial.println(distance);


  
  int soundsens=analogRead(soundpin); // reads analog data from sound sensor
  if (soundsens>=threshold) { // Against the dogbarking
      for (int i = 100; i <= 10000; i++) {
        tone(buzzer, i);
        delay(2);
      } 
    delay(8);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(10);
  }
  else{
    digitalWrite(buzzer,LOW);
    }
/////////////////////////////////////////////////////

  if(distance <= sonarMin){
  for (int j = 100; j <= 10000; j++) {
          tone(buzzer, j);
          delay(2);
        } 
      delay(8);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(10);
    }
    else{
      digitalWrite(buzzer,LOW);
    }

  //if(soundsens>=threshold && distance <= sonarMin){
  //n ++;}

  clearLEDs();
  pickDigit(1);
  pickNumber((n/x/1000)%10);
  delayMicroseconds(del);
  
  clearLEDs();
  pickDigit(2);
  pickNumber((n/x/100)%10);
  delayMicroseconds(del);
  
  clearLEDs();
  pickDigit(3);
  pickNumber((n/x/10)%10);
  delayMicroseconds(del);
  
  clearLEDs();
  pickDigit(4);
  pickNumber(n/x%10);
  delayMicroseconds(del);
  
  //if(soundsens>=threshold && distance <= sonarMin){
  //n ++;}
  n++;
  if (digitalRead(13) == HIGH)
  {
    n = 0;
    }
}

void pickDigit(int x)
{
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
  
  switch(x)
  {
    case 1: digitalWrite(d1, HIGH); break;
    case 2: digitalWrite(d2, HIGH); break;
    case 3: digitalWrite(d3, HIGH); break;
    default: digitalWrite(d4, HIGH); break;
  }
}

void pickNumber(int x)
{
  switch(x)
  {
    default: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
  }
}


void clearLEDs()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
//  digitalWrite(p, HIGH);
}

void zero()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}

void one()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void two()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void three()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}

void four()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void five()
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void six()
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void seven()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void eight()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void nine()
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

///////////////////////////////////////////////
