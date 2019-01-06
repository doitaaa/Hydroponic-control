/*
 * ADC.h
 *
 * Created: 08-Jul-18 2:35:41 PM
 *  Author: mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "stdmacros.h"
void init_ADC(); // default settings
void ADC_settings(uint8_t reference, uint8_t presecaler, uint8_t autoTrigger, uint8_t triggerSource);
uint16_t readAnalog(uint8_t pin);

#endif /* ADC_H_ */