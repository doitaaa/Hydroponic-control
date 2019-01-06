/*
 * ADC.h
 *
 * Created: 08-Jul-18 2:35:41 PM
 *  Author: mohamed
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "IO_Macros.h"
#include "config.h"
#define ADC_resolution 1024
//buffer for analogue readings
uint16_t buff[10];

void init_ADC(); // default settings
uint16_t readAnalog(uint8_t pin);
uint16_t readAnalog_Average(uint8_t pin);
double  readVoltage(uint8_t pin);
double  readVoltage_Average(uint8_t pin);

#endif /* ADC_H_ */