/*
  Inspiring from here: https://www.instructables.com/id/7-Segment-Display-On-Arduino/
    t
   ---
l1|   |r1
  | m |
   ---
l2|   |r2
  |   |
   ---
    b
 */

int l2 = 2;  //For displaying segment "second left"
int b = 3;  //For displaying segment "bottom"
int l1 = 4;  //For displaying segment "first left"
int m = 5;  //For displaying segment "middle"
int r2 = 6;  //For displaying segment "second right"
int t = 8;  //For displaying segment "t"
int r1 = 9;  //For displaying segment "first right"
int p = 10;  //For displaying segment "point"

void setup() {               
  pinMode(l2, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(m, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(t, OUTPUT);
  pinMode(r1, OUTPUT);
  pinMode(p, OUTPUT);
}

void displayDigit(int digit)
{
 //Conditions for displaying segment top
 if(digit!=1 && digit!=4)
 digitalWrite(t,LOW);
 
 //Conditions for displaying segment first left
 if(digit!=1 && digit!=2 && digit!=3 && digit!=7)
 digitalWrite(l1,LOW);
 
 //Conditions for displaying segment second left
 if(digit==2 || digit==6 || digit==8)
 digitalWrite(l2,LOW);
 
 //Conditions for displaying segment middle
 if(digit!=1 && digit!=7)
 digitalWrite(m,LOW);
 
 //Conditions for displaying segment bottom
 if(digit!=1 && digit!=4 && digit!=7)
 digitalWrite(b,LOW);
 
 //Conditions for displaying segment first right
 if(digit!=5 && digit!=6)
 digitalWrite(r1,LOW);
 
 //Conditions for displaying segment second right
 if(digit!=2)
 digitalWrite(r2,LOW);
 
}
void turnOff()
{
  digitalWrite(l1,HIGH);
  digitalWrite(l2,HIGH);
  digitalWrite(t,HIGH);
  digitalWrite(m,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
}


void loop() {
  for(int i=0;i<10;i++) {
   displayDigit(i);
   delay(1000);
   turnOff();
 }
 
//   displayDigit(8);
}
