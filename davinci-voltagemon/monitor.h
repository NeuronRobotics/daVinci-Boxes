#ifndef monitor_H
#define monitor_H

#include "leds.h"
void initTimer();

typedef enum {
	NONE=0,
	LOW,
	NOMINAL,
	HIGH

} rail_state;

typedef struct {
	unsigned long int upperLimit;		// upper bound of "good" voltage
	unsigned long int lowerlimit;		// lower bound of "good" voltage
} voltage_rail;

void checkRails();
void setLEDs();
#define getSW (PINB & 0x07)

//  1 2
//  2 3
//  3 1
#define MTM   0x7   // 000
#define ECM   0x5   // 001
#define PSM   0x3   // 010 
#define SUJ   0x1   // 011
#define F_CPU 1000000

// this line switches between master and slave
//#define master
//#define ECM


// If LEDs populated backwards
#define swapleds

#ifdef __AVR_ATtiny261__
  #define v12uppper   155
  #define v12lower    125
  #define v24upper    290
  #define v24lower    258
  #define v36upper    435
  #define v36lower    387
  
    #define rail_min 10
      // (1024×1.1)÷5.1 = 220.862745098
  #define vlogic_upper 221

  // (1024×1.1)÷4.9 = 229.87755102
  #define vlogic_lower 230
#else
  #define v12uppper   62
  #define v12lower    49
  #define v24upper    109
  #define v24lower    98
  #define v36upper    160
  #define v36lower    149
  
  #define rail_min 10

  #define vlogic_upper 221

  #define vlogic_lower 230	

#endif
#endif
