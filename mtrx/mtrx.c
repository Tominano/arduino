//Jlouage.com

/* 
  stdlib_noniso.h - nonstandard (but usefull) conversion functions
  Copyright (c) 2014 Ivan Grokhotkov. All rights reserved.
  This file is part of the esp8266 core for Arduino environment.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef STDLIB_NONISO_H
#define STDLIB_NONISO_H

#ifdef __cplusplus
extern "C"{
#endif

int atoi(const char *s);

long atol(const char* s);

double atof(const char* s);

char* itoa (int val, char *s, int radix);

char* ltoa (long val, char *s, int radix);

char* utoa (unsigned int val, char *s, int radix);

char* ultoa (unsigned long val, char *s, int radix);
 
char* dtostrf (double val, signed char width, unsigned char prec, char *s);

void reverse(char* begin, char* end);

#ifdef __cplusplus
} // extern "C"
#endif


#endif

/*
 * MaxMatrix
 * Version 1.0 Feb 2013
 * Copyright 2013 Oscar Kin-Chung Au
 */

/*
 Arduino.h - Main include file for the Arduino SDK
 Copyright (c) 2005-2013 Arduino Team.  All right reserved.
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef Arduino_h
#define Arduino_h

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "stdlib_noniso.h"
#include "binary.h"
#include "esp8266_peri.h"
#include "twi.h"
#include "core_esp8266_features.h"
#include "core_esp8266_version.h"

#define HIGH 0x1
#define LOW  0x0

#define PWMRANGE 1023

//GPIO FUNCTIONS
#define INPUT             0x00
#define INPUT_PULLUP      0x02
#define INPUT_PULLDOWN_16 0x04 // PULLDOWN only possible for pin16
#define OUTPUT            0x01
#define OUTPUT_OPEN_DRAIN 0x03
#define WAKEUP_PULLUP     0x05
#define WAKEUP_PULLDOWN   0x07
#define SPECIAL           0xF8 //defaults to the usable BUSes uart0rx/tx uart1tx and hspi
#define FUNCTION_0        0x08
#define FUNCTION_1        0x18
#define FUNCTION_2        0x28
#define FUNCTION_3        0x38
#define FUNCTION_4        0x48

#define PI 3.1415926535897932384626433832795
#define HALF_PI 1.5707963267948966192313216916398
#define TWO_PI 6.283185307179586476925286766559
#define DEG_TO_RAD 0.017453292519943295769236907684886
#define RAD_TO_DEG 57.295779513082320876798154814105
#define EULER 2.718281828459045235360287471352

#define SERIAL  0x0
#define DISPLAY 0x1

#define LSBFIRST 0
#define MSBFIRST 1

//Interrupt Modes
#define RISING    0x01
#define FALLING   0x02
#define CHANGE    0x03
#define ONLOW     0x04
#define ONHIGH    0x05
#define ONLOW_WE  0x0C
#define ONHIGH_WE 0x0D

#define DEFAULT 1
#define EXTERNAL 0

//timer dividers
enum TIM_DIV_ENUM {
  TIM_DIV1 = 0,   //80MHz (80 ticks/us - 104857.588 us max)
  TIM_DIV16 = 1,  //5MHz (5 ticks/us - 1677721.4 us max)
  TIM_DIV256 = 3 //312.5Khz (1 tick = 3.2us - 26843542.4 us max)
};


//timer int_types
#define TIM_EDGE	0
#define TIM_LEVEL	1
//timer reload values
#define TIM_SINGLE	0 //on interrupt routine you need to write a new value to start the timer again
#define TIM_LOOP	1 //on interrupt the counter will start with the same value again

#define timer1_read()           (T1V)
#define timer1_enabled()        ((T1C & (1 << TCTE)) != 0)
#define timer1_interrupted()    ((T1C & (1 << TCIS)) != 0)

typedef void(*timercallback)(void);

void timer1_isr_init(void);
void timer1_enable(uint8_t divider, uint8_t int_type, uint8_t reload);
void timer1_disable(void);
void timer1_attachInterrupt(timercallback userFunc);
void timer1_detachInterrupt(void);
void timer1_write(uint32_t ticks); //maximum ticks 8388607

// timer0 is a special CPU timer that has very high resolution but with
// limited control.
// it uses CCOUNT (ESP.GetCycleCount()) as the non-resetable timer counter
// it does not support divide, type, or reload flags
// it is auto-disabled when the compare value matches CCOUNT
// it is auto-enabled when the compare value changes
#define timer0_interrupted()    (ETS_INTR_PENDING() & (_BV(ETS_COMPARE0_INUM)))
#define timer0_read() ((__extension__({uint32_t count;__asm__ __volatile__("esync; rsr %0,ccompare0":"=a" (count));count;})))
#define timer0_write(count) __asm__ __volatile__("wsr %0,ccompare0; esync"::"a" (count) : "memory")

void timer0_isr_init(void);
void timer0_attachInterrupt(timercallback userFunc);
void timer0_detachInterrupt(void);

// undefine stdlib's abs if encountered
#ifdef abs
#undef abs
#endif

#define abs(x) ((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) ((deg)*DEG_TO_RAD)
#define degrees(rad) ((rad)*RAD_TO_DEG)
#define sq(x) ((x)*(x))

void ets_intr_lock();
void ets_intr_unlock();

#ifndef __STRINGIFY
#define __STRINGIFY(a) #a
#endif

// these low level routines provide a replacement for SREG interrupt save that AVR uses
// but are esp8266 specific. A normal use pattern is like
//
//{
//    uint32_t savedPS = xt_rsil(1); // this routine will allow level 2 and above
//    // do work here
//    xt_wsr_ps(savedPS); // restore the state
//}
//
// level (0-15), interrupts of the given level and above will be active
// level 15 will disable ALL interrupts,
// level 0 will enable ALL interrupts,
//
#define xt_rsil(level) (__extension__({uint32_t state; __asm__ __volatile__("rsil %0," __STRINGIFY(level) : "=a" (state)); state;}))
#define xt_wsr_ps(state)  __asm__ __volatile__("wsr %0,ps; isync" :: "a" (state) : "memory")

#define interrupts() xt_rsil(0)
#define noInterrupts() xt_rsil(15)


#define clockCyclesPerMicrosecond() ( F_CPU / 1000000L )
#define clockCyclesToMicroseconds(a) ( (a) / clockCyclesPerMicrosecond() )
#define microsecondsToClockCycles(a) ( (a) * clockCyclesPerMicrosecond() )

#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

// avr-libc defines _NOP() since 1.6.2
#ifndef _NOP
#define _NOP() do { __asm__ volatile ("nop"); } while (0)
#endif

typedef uint16_t word;

#define bit(b) (1UL << (b))
#define _BV(b) (1UL << (b))

typedef bool boolean;
typedef uint8_t byte;

void init(void);
void initVariant(void);

int atexit(void (*func)()) __attribute__((weak));

void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);
void analogWriteFreq(uint32_t freq);
void analogWriteRange(uint32_t range);

unsigned long millis(void);
unsigned long micros(void);
uint64_t micros64(void);
void delay(unsigned long);
void delayMicroseconds(unsigned int us);
unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout);

void shiftOut(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder, uint8_t val);
uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder);

void attachInterrupt(uint8_t pin, void (*)(void), int mode);
void detachInterrupt(uint8_t pin);

void preinit(void);
void setup(void);
void loop(void);

void yield(void);
void optimistic_yield(uint32_t interval_us);

#define _PORT_GPIO16    1
#define digitalPinToPort(pin)       (((pin)==16)?(_PORT_GPIO16):(0))
#define digitalPinToBitMask(pin)    (((pin)==16)?(1):(1UL << (pin)))
#define digitalPinToTimer(pin)      (0)
#define portOutputRegister(port)    (((port)==_PORT_GPIO16)?((volatile uint32_t*) &GP16O):((volatile uint32_t*) &GPO))
#define portInputRegister(port)     (((port)==_PORT_GPIO16)?((volatile uint32_t*) &GP16I):((volatile uint32_t*) &GPI))
#define portModeRegister(port)      (((port)==_PORT_GPIO16)?((volatile uint32_t*) &GP16E):((volatile uint32_t*) &GPE))

#define NOT_A_PIN -1
#define NOT_A_PORT -1
#define NOT_AN_INTERRUPT -1
#define NOT_ON_TIMER 0

#ifdef __cplusplus
} // extern "C"
#endif


//for compatibility, below 4 lines to be removed in release 3.0.0
#ifdef __cplusplus
extern "C"
#endif
const int TIM_DIV265 __attribute__((deprecated, weak)) = TIM_DIV256;



#ifdef __cplusplus

#include <algorithm>
#include <pgmspace.h>

#include "WCharacter.h"
#include "WString.h"

#include "HardwareSerial.h"
#include "Esp.h"
#include "Updater.h"
#include "debug.h"

using std::min;
using std::max;
using std::isinf;
using std::isnan;

#define _min(a,b) ((a)<(b)?(a):(b))
#define _max(a,b) ((a)>(b)?(a):(b))

uint16_t makeWord(uint16_t w);
uint16_t makeWord(byte h, byte l);

#define word(...) makeWord(__VA_ARGS__)

unsigned long pulseIn(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);
unsigned long pulseInLong(uint8_t pin, uint8_t state, unsigned long timeout = 1000000L);

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration = 0);
void tone(uint8_t _pin, int frequency, unsigned long duration = 0);
void tone(uint8_t _pin, double frequency, unsigned long duration = 0);
void noTone(uint8_t _pin);

// WMath prototypes
long random(long);
long random(long, long);
void randomSeed(unsigned long);
long secureRandom(long);
long secureRandom(long, long);
long map(long, long, long, long, long);

extern "C" void configTime(long timezone, int daylightOffset_sec,
    const char* server1, const char* server2 = nullptr, const char* server3 = nullptr);

#endif

#include "pins_arduino.h"

#endif

#ifdef DEBUG_ESP_OOM
// reinclude *alloc redefinition because of <cstdlib> undefining them
// this is mandatory for allowing OOM *alloc definitions in .ino files
#include "umm_malloc/umm_malloc_cfg.h"
#endif

#ifndef _MaxMatrix_H_
#define _MaxMatrix_H_

#include "Arduino.h"

#define max7219_reg_noop        0x00
#define max7219_reg_digit0      0x01
#define max7219_reg_digit1      0x02
#define max7219_reg_digit2      0x03
#define max7219_reg_digit3      0x04
#define max7219_reg_digit4      0x05
#define max7219_reg_digit5      0x06
#define max7219_reg_digit6      0x07
#define max7219_reg_digit7      0x08
#define max7219_reg_decodeMode  0x09
#define max7219_reg_intensity   0x0a
#define max7219_reg_scanLimit   0x0b
#define max7219_reg_shutdown    0x0c
#define max7219_reg_displayTest 0x0f

class MaxMatrix
{
  private:
    byte data;
    byte load;
    byte clock;
    byte num;
    byte buffer[80];
    
    void reload();
	
  public:
    MaxMatrix(byte data, byte load, byte clock, byte num);
    
    void init();
    void clear();
    void setCommand(byte command, byte value);
    void setIntensity(byte intensity);
    void setColumn(byte col, byte value);
    void setColumnAll(byte col, byte value);
    void setDot(byte col, byte row, byte value);
    void writeSprite(int x, int y, const byte* sprite);
    
    void shiftLeft(bool rotate = false, bool fill_zero = true);
    void shiftRight(bool rotate = false, bool fill_zero = true);
    void shiftUp(bool rotate = false);
    void shiftDown(bool rotate = false);
};

#endif
//
#include <MaxMatrix.h>
#include <avr/pgmspace.h>
const unsigned char CH[] PROGMEM = {
  3, 8, B00000000, B00000000, B00000000, B00000000, B00000000, // space
  1, 8, B01011111, B00000000, B00000000, B00000000, B00000000, // !
  3, 8, B00000011, B00000000, B00000011, B00000000, B00000000, // "
  5, 8, B00010100, B00111110, B00010100, B00111110, B00010100, // #
  4, 8, B00100100, B01101010, B00101011, B00010010, B00000000, // $
  5, 8, B01100011, B00010011, B00001000, B01100100, B01100011, // %
  5, 8, B00110110, B01001001, B01010110, B00100000, B01010000, // &
  1, 8, B00000011, B00000000, B00000000, B00000000, B00000000, // '
  3, 8, B00011100, B00100010, B01000001, B00000000, B00000000, // (
  3, 8, B01000001, B00100010, B00011100, B00000000, B00000000, // )
  5, 8, B00101000, B00011000, B00001110, B00011000, B00101000, // *
  5, 8, B00001000, B00001000, B00111110, B00001000, B00001000, // +
  2, 8, B10110000, B01110000, B00000000, B00000000, B00000000, // ,
  4, 8, B00001000, B00001000, B00001000, B00001000, B00000000, // -
  2, 8, B01100000, B01100000, B00000000, B00000000, B00000000, // .
  4, 8, B01100000, B00011000, B00000110, B00000001, B00000000, // /
  4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // 0
  3, 8, B01000010, B01111111, B01000000, B00000000, B00000000, // 1
  4, 8, B01100010, B01010001, B01001001, B01000110, B00000000, // 2
  4, 8, B00100010, B01000001, B01001001, B00110110, B00000000, // 3
  4, 8, B00011000, B00010100, B00010010, B01111111, B00000000, // 4
  4, 8, B00100111, B01000101, B01000101, B00111001, B00000000, // 5
  4, 8, B00111110, B01001001, B01001001, B00110000, B00000000, // 6
  4, 8, B01100001, B00010001, B00001001, B00000111, B00000000, // 7
  4, 8, B00110110, B01001001, B01001001, B00110110, B00000000, // 8
  4, 8, B00000110, B01001001, B01001001, B00111110, B00000000, // 9
  2, 8, B01010000, B00000000, B00000000, B00000000, B00000000, // :
  2, 8, B10000000, B01010000, B00000000, B00000000, B00000000, // ;
  3, 8, B00010000, B00101000, B01000100, B00000000, B00000000, // <
  3, 8, B00010100, B00010100, B00010100, B00000000, B00000000, // =
  3, 8, B01000100, B00101000, B00010000, B00000000, B00000000, // >
  4, 8, B00000010, B01011001, B00001001, B00000110, B00000000, // ?
  5, 8, B00111110, B01001001, B01010101, B01011101, B00001110, // @
  4, 8, B01111110, B00010001, B00010001, B01111110, B00000000, // A
  4, 8, B01111111, B01001001, B01001001, B00110110, B00000000, // B
  4, 8, B00111110, B01000001, B01000001, B00100010, B00000000, // C
  4, 8, B01111111, B01000001, B01000001, B00111110, B00000000, // D
  4, 8, B01111111, B01001001, B01001001, B01000001, B00000000, // E
  4, 8, B01111111, B00001001, B00001001, B00000001, B00000000, // F
  4, 8, B00111110, B01000001, B01001001, B01111010, B00000000, // G
  4, 8, B01111111, B00001000, B00001000, B01111111, B00000000, // H
  3, 8, B01000001, B01111111, B01000001, B00000000, B00000000, // I
  4, 8, B00110000, B01000000, B01000001, B00111111, B00000000, // J
  4, 8, B01111111, B00001000, B00010100, B01100011, B00000000, // K
  4, 8, B01111111, B01000000, B01000000, B01000000, B00000000, // L
  5, 8, B01111111, B00000010, B00001100, B00000010, B01111111, // M
  5, 8, B01111111, B00000100, B00001000, B00010000, B01111111, // N
  4, 8, B00111110, B01000001, B01000001, B00111110, B00000000, // O
  4, 8, B01111111, B00001001, B00001001, B00000110, B00000000, // P
  4, 8, B00111110, B01000001, B01000001, B10111110, B00000000, // Q
  4, 8, B01111111, B00001001, B00001001, B01110110, B00000000, // R
  4, 8, B01000110, B01001001, B01001001, B00110010, B00000000, // S
  5, 8, B00000001, B00000001, B01111111, B00000001, B00000001, // T
  4, 8, B00111111, B01000000, B01000000, B00111111, B00000000, // U
  5, 8, B00001111, B00110000, B01000000, B00110000, B00001111, // V
  5, 8, B00111111, B01000000, B00111000, B01000000, B00111111, // W
  5, 8, B01100011, B00010100, B00001000, B00010100, B01100011, // X
  5, 8, B00000111, B00001000, B01110000, B00001000, B00000111, // Y
  4, 8, B01100001, B01010001, B01001001, B01000111, B00000000, // Z
  2, 8, B01111111, B01000001, B00000000, B00000000, B00000000, // [
  4, 8, B00000001, B00000110, B00011000, B01100000, B00000000, // \ backslash
  2, 8, B01000001, B01111111, B00000000, B00000000, B00000000, // ]
  3, 8, B00000010, B00000001, B00000010, B00000000, B00000000, // hat
  4, 8, B01000000, B01000000, B01000000, B01000000, B00000000, // _
  2, 8, B00000001, B00000010, B00000000, B00000000, B00000000, // `
  4, 8, B00100000, B01010100, B01010100, B01111000, B00000000, // a
  4, 8, B01111111, B01000100, B01000100, B00111000, B00000000, // b
  4, 8, B00111000, B01000100, B01000100, B00101000, B00000000, // c
  4, 8, B00111000, B01000100, B01000100, B01111111, B00000000, // d
  4, 8, B00111000, B01010100, B01010100, B00011000, B00000000, // e
  3, 8, B00000100, B01111110, B00000101, B00000000, B00000000, // f
  4, 8, B10011000, B10100100, B10100100, B01111000, B00000000, // g
  4, 8, B01111111, B00000100, B00000100, B01111000, B00000000, // h
  3, 8, B01000100, B01111101, B01000000, B00000000, B00000000, // i
  4, 8, B01000000, B10000000, B10000100, B01111101, B00000000, // j
  4, 8, B01111111, B00010000, B00101000, B01000100, B00000000, // k
  3, 8, B01000001, B01111111, B01000000, B00000000, B00000000, // l
  5, 8, B01111100, B00000100, B01111100, B00000100, B01111000, // m
  4, 8, B01111100, B00000100, B00000100, B01111000, B00000000, // n
  4, 8, B00111000, B01000100, B01000100, B00111000, B00000000, // o
  4, 8, B11111100, B00100100, B00100100, B00011000, B00000000, // p
  4, 8, B00011000, B00100100, B00100100, B11111100, B00000000, // q
  4, 8, B01111100, B00001000, B00000100, B00000100, B00000000, // r
  4, 8, B01001000, B01010100, B01010100, B00100100, B00000000, // s
  3, 8, B00000100, B00111111, B01000100, B00000000, B00000000, // t
  4, 8, B00111100, B01000000, B01000000, B01111100, B00000000, // u
  5, 8, B00011100, B00100000, B01000000, B00100000, B00011100, // v
  5, 8, B00111100, B01000000, B00111100, B01000000, B00111100, // w
  5, 8, B01000100, B00101000, B00010000, B00101000, B01000100, // x
  4, 8, B10011100, B10100000, B10100000, B01111100, B00000000, // y
  3, 8, B01100100, B01010100, B01001100, B00000000, B00000000, // z
  3, 8, B00001000, B00110110, B01000001, B00000000, B00000000, // {
  1, 8, B01111111, B00000000, B00000000, B00000000, B00000000, // |
  3, 8, B01000001, B00110110, B00001000, B00000000, B00000000, // }
  4, 8, B00001000, B00000100, B00001000, B00000100, B00000000, // ~
};
int data = 12; // DIN pin of MAX7219 module
int load = 10; // CS pin of MAX7219 module
int clock = 11; // CLK pin of MAX7219 module
int maxInUse = 1; //how many MAX7219 are connected
MaxMatrix m(data, load, clock, maxInUse); // define Library
byte buffer[10];
char string1[] = " JLOUAGE.COM "; // Scrolling Text
void setup(){
  m.init(); // module MAX7219
  m.setIntensity(5); // LED Intensity 0-15
}
void loop(){
byte c;
  delay(100);
  m.shiftLeft(false, true);
  printStringWithShift(string1, 200); // Send scrolling Text
}
// Put extracted character on Display
void printCharWithShift(char c, int shift_speed){
  if (c < 32) return;
  c -= 32;
  memcpy_P(buffer, CH + 7*c, 7);
  m.writeSprite(maxInUse*8, 0, buffer);
  m.setColumn(maxInUse*8 + buffer[0], 0);
  
  for (int i=0; i<buffer[0]+1; i++)
  {
    delay(shift_speed);
    m.shiftLeft(false, false);
  }
}
// Extract characters from Scrolling text
void printStringWithShift(char* s, int shift_speed){
  while (*s != 0){
    printCharWithShift(*s, shift_speed);
    s++;
  }
}
