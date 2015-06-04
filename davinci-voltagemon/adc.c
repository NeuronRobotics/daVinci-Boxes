#include "adc.h"
#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <avr/interrupt.h> 

void initADC()
{
  // this function initialises the ADC 

  // prescaler set to 128 for mcu running at 8MHz

  ADMUX =
            (1 << ADLAR) |     // left shift result
            (1 << REFS1) |     // Sets ref. voltage to 1.1, bit 1
            (0 << REFS0) |     // Sets ref. voltage to 1.1, bit 0
	    (0 << MUX4)  |     // use ADC2 for input (PB4), MUX bit 4
            (0 << MUX3)  |     // use ADC2 for input (PB4), MUX bit 3
            (0 << MUX2)  |     // use ADC2 for input (PB4), MUX bit 2
            (0 << MUX1)  |     // use ADC2 for input (PB4), MUX bit 1
            (0 << MUX0);       // use ADC2 for input (PB4), MUX bit 0

  ADCSRA = 
	    (0 << ADATE) |     // auto trigger mode, off
            (1 << ADEN)  |     // Enable ADC 
            (0 << ADPS2) |     // set prescaler to 2, bit 2 
            (0 << ADPS1) |     // set prescaler to 2, bit 1 
            (0 << ADPS0);      // set prescaler to 2, bit 0  
}

unsigned long int getAdc(int channel){

ADMUX =(ADMUX&0xe0)+(channel&0x1f); // Select channel
ADCSRA |= (1 << ADSC);         // start ADC measurement
while (ADCSRA & (1 << ADSC) ); // wait till conversion complete 

return (ADCL>>6)+(ADCH<<2); // need to read ADCL FIRST otherwise ADC won't work. says DS.

}

unsigned long int getVCCVolts(int channel){
/*
// Reconfigure ADC. set ref voltage to vcc and measure ref.
  ADMUX =
            (1 << ADLAR) |     // left shift result
            (0 << REFS1) |     // Sets ref. voltage to vcc, bit 1
            (0 << REFS0) |     // Sets ref. voltage to vcc, bit 0
	    (1 << MUX4)  |     // use ADC2 for input (PB4), MUX bit 4
            (1 << MUX3)  |     // use ADC2 for input (PB4), MUX bit 3
            (1 << MUX2)  |     // use ADC2 for input (PB4), MUX bit 2
            (1 << MUX1)  |     // use ADC2 for input (PB4), MUX bit 1
            (0 << MUX0);       // use ADC2 for input (PB4), MUX bit 

ADCSRA |= (1 << ADSC);         // start ADC measurement
while (ADCSRA & (1 << ADSC) ); // wait till conversion complete 
unsigned long int result=(ADCL>>6)+(ADCH<<2);

// restore ADC to previous CFG
initADC();
*/
return 0;

}
