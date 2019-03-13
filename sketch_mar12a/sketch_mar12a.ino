#define ROW_1 2
#define ROW_2 3
#define ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7 8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3 12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7 A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

byte ja[] = {B01110000,B00100100,B00101010,B00101010,B00101110,B10101010,B01101010,B00000000};
byte nl[] = {B00000000,B00001000,B10001000,B11101000,B10101000,B10101000,B10101111,B00000000};
byte ee[] = {B00000000,B00000000,B11101110,B10101010,B11101110,B10001000,B11101110,B00000000};
byte is[] = {B00000000,B00000000,B11100110,B01001000,B01001110,B01000010,B11101100,B00000000};
byte a[] = {B00000000,B00011000,B00100100,B00100100,B00111100,B00100100,B00100100,B00000000};
byte pa[] = {B00000000,B11100110,B10101001,B10101001,B11101111,B10001001,B10001001,B00000000};
byte nd[] = {B00000000,B00000010,B00000010,B10001110,B11101010,B10101010,B10101110,B00000000};
byte aa[] = {B00000000,B00000000,B01000000,B10100000,B11100000,B10100000,B00000000,B00000000};
byte panda[] = {B01100110,B10000001,B00100100,B00000000,B00011000,B00011000,B01000010,B00111100};

float timeCount = 0;

void setup() {
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If the pins are set to input
    // the display will be very dim.
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void loop() 
{
  // This could be rewritten to not use a delay, which would make it appear brighter
delay(1);
timeCount += 1;
if(timeCount <  200) {
drawScreen(ja);
} else if (timeCount <  220) {
drawScreen(nl);
} else if (timeCount <  240) {
drawScreen(ee);
} else if (timeCount <  260) {
 drawScreen(is);
} else if (timeCount <  280) {
drawScreen(a);
} else if (timeCount <  300) {
drawScreen(pa);
} else if (timeCount <  320) {
drawScreen(nd);
} else if (timeCount <  340) {
drawScreen(aa);
} else if (timeCount <  450) {
drawScreen(panda);
} else if (timeCount <  1030) {
// nothing
} else if (timeCount <  1200) {
//drawScreen(angry);
} else if (timeCount <  1230) {
// nothing
} else {
// back to the start
timeCount = 0;
}
}
 void  drawScreen(byte buffer2[]){
     
    
   // Turn on each row in series
    for (byte i = 0; i < 8; i++) {
        setColumns(buffer2[i]); // Set columns for this specific row
        
        digitalWrite(rows[i], HIGH);
        delay(2); // Set this to 50 or 100 if you want to see the multiplexing effect!
        digitalWrite(rows[i], LOW);
        
    }
}
