/*
 * timer8.h
 *
 * Created: 06-Jul-18 3:21:36 PM
 *  Author: mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "stdmacros.h"
//comment these if you want to define your own ISR
//#define ENABLE_TIMER0
//#define ENABLE_TIMER1
#define ENABLE_ICR1

void init_timer0_normalMode(uint8_t prescaler, void (*f)());
void init_timer0_ctcMode(uint8_t prescaler, uint8_t ticks, void (*f)());
void init_timer0_FastPWM(uint8_t prescaler, uint8_t ticks, uint8_t COM);
void init_timer0_PhaseCorrectPWM(uint8_t prescaler, uint8_t ticks, uint8_t COM);
void timer0_interrupt(uint8_t overflow, uint8_t outputCompare);
void disable_timer0();
void timer0_setOCR(uint8_t x);
void init_timer1_normalMode(uint8_t prescaler, void (*f)());
void init_timer1_ctcMode(uint8_t prescaler, uint16_t ticks, void (*f)());
void init_timer1_FastPWM(uint8_t prescaler, uint16_t ticksa, uint16_t ticksb, uint8_t COMA, uint8_t COMB, uint16_t inputcapture);
void init_timer1_PhaseCorrectPWM(uint8_t prescaler, uint16_t ticksa, uint16_t ticksb, uint8_t COMA, uint8_t COMB, uint16_t inputcapture);
void init_inputCapture(uint8_t noiseCanceller,uint8_t edgeSelect, uint8_t prescaler, void (*f)());
void timer1_interrupt(uint8_t overflow, uint8_t outputCompareA, uint8_t outputCompareB);
void disable_inputCapture();
void timer1_setOCR(uint16_t a,uint16_t b);
void disable_timer1();
#endif /* TIMER_H_ */