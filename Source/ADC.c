/*
 * ADC.c
 *
 * Created: 08-Jul-18 2:46:47 PM
 *  Author: mohamed
 */ 
#include "ADC.h"
void init_ADC(){
	
	ADCSRA = _BV(ADEN) | _BV(ADPS2) | _BV(ADPS1) | _BV(ADPS0); // enables the ADC and sets the sampling prescaler to 128
	ADMUX = _BV(REFS0); // reference set to AVCC
	
}

uint16_t readAnalog(uint8_t pin){
	ADMUX &= 0b11111000; // clear the last 3 bits
	ADMUX |= pin;
	SETBIT(ADCSRA,ADSC); // starts conversion
	while(!READBIT(ADCSRA,ADIF)); //wait till conversion fisnihes
	SETBIT(ADCSRA,ADIF);// clear interrupt flag
	return ADCL + (ADCH << 8) ;
}