/*
 * timer.c
 *
 * Created: 06-Jul-18 3:42:04 PM
 *  Author: mohamed
 */ 
#include "timer.h"

void (*_t0_func)();
void (*_t0_CTC_func)();
void (*_t1_func)();
void (*_t1_CTC_func)();
void(*_INC1_func)();
#ifdef ENABLE_TIMER0
ISR(TIMER0_OVF_vect){
	_t0_func();
}
ISR(TIMER0_COMP_vect){
	_t0_CTC_func();
}
#endif
#ifdef ENABLE_TIMER1
ISR(TIMER1_OVF_vect){
	_t1_func();
}
ISR(TIMER1_COMPA_vect){
	_t1_CTC_func();
}
#endif
#ifdef ENABLE_ICR1
ISR(TIMER1_CAPT_vect){
	_INC1_func();
}
#endif
void init_timer0_normalMode(uint8_t prescaler, void (*f)()){
	CLRBIT(TIMSK,TOIE0); // disable interrupt
	TCCR0 = 0x00; //clear register setting it to normal mode
	if(prescaler >=0 && prescaler <=7){ TCCR0 |= prescaler;} //set prescaler value
	_t0_func = f; //set interrupt function
	TCNT0 = 0; //clear timer
	SETBIT(TIMSK,TOIE0); // enable interrupt
}

void init_timer1_normalMode(uint8_t prescaler, void (*f)()){
	CLRBIT(TIMSK,TOIE1); // disable interrupt
	TCCR1A = 0x00; //clear register setting it to normal mode
	if(prescaler >=0 && prescaler <=7){ TCCR1B |= prescaler;} //set prescaler value
	_t1_func = f; //set interrupt function
	TCNT1 = 0; //clear timer
	SETBIT(TIMSK,TOIE1); // enable interrupt
}

void init_timer0_ctcMode(uint8_t prescaler, uint8_t ticks, void (*f)()){
	CLRBIT(TIMSK,OCIE0); // disable interrupt
	TCCR0 = _BV(WGM01); //enable ctc mode
	if(prescaler >=0 && prescaler <=7){ TCCR0 |= prescaler;} //set prescaler value
	_t0_CTC_func = f; //set interrupt function
	OCR0=ticks;
	TCNT0 = 0; //clear timer
	SETBIT(TIMSK,OCIE0); // enable interrupt	
}

void init_timer1_ctcMode(uint8_t prescaler, uint16_t ticks, void (*f)()){
	CLRBIT(TIMSK,OCIE1A); // disable interrupt
	TCCR1B = _BV(WGM12); //enable ctc mode
	if(prescaler >=0 && prescaler <=7){ TCCR1B |= prescaler;} //set prescaler value
	_t1_CTC_func = f; //set interrupt function
	OCR1A=ticks;
	TCNT1 = 0; //clear timer
	SETBIT(TIMSK,OCIE1A); // enable interrupt
}

void init_timer0_FastPWM(uint8_t prescaler, uint8_t ticks, uint8_t COM){
	TCCR0 = 1 << WGM01 | 1 << WGM00 | COM << 4; //enable PWM mode
	if(prescaler >=0 && prescaler <=7){ TCCR0 |= prescaler;} //set prescaler value
	//TCCR0 |= COM << 4; // 0 normal 1 reserved on OCR 2 noninverting 3 inverting
	OCR0=ticks;
	TCNT0 = 0; //clear timer	
}

void init_timer1_FastPWM(uint8_t prescaler, uint16_t ticksa, uint16_t ticksb, uint8_t COMA, uint8_t COMB, uint16_t inputcapture){
	//TCCR1A = _BV(WGM11) | _BV(WGM10) | COMB << 4 | COMA << 6; //10 bit mode
	//TCCR1B = _BV(WGM12);
	
	//TCCR1A = _BV(WGM11) | COMB << 4 | COMA << 6; //9 bit mode
	//TCCR1B = _BV(WGM12);
	
	//TCCR1A = _BV(WGM10) | COMB << 4 | COMA << 6; //8 bit mode
	//TCCR1B = _BV(WGM12);
	
	//TCCR1A = _BV(WGM11) | _BV(WGM10) | COMB << 4 | COMA << 6; // OCR1A as top usually you set coma to 1 for 50% duty cycle and set comb for whatever!!
	//TCCR1B = _BV(WGM12) | _BV(WGM13);
	
	TCCR1A = _BV(WGM11) | COMB << 4 | COMA << 6; // ICR1 as top
	TCCR1B = _BV(WGM12) | _BV(WGM13);
	ICR1 = inputcapture;
	
	if(prescaler >=0 && prescaler <=7){ TCCR1B |= prescaler;}
	OCR1A = ticksa;
	OCR1B = ticksb;
	TCNT1 = 0;
	
}

void init_timer0_PhaseCorrectPWM(uint8_t prescaler, uint8_t ticks, uint8_t COM){
	TCCR0 = 1 << WGM00 | COM << 4; //enable PWM mode
	if(prescaler >=0 && prescaler <=7){ TCCR0 |= prescaler;} //set prescaler value
	//TCCR0 |= COM << 4; // 0 normal 1 reserved on OCR 2 noninverting 3 inverting
	OCR0=ticks;
	TCNT0 = 0; //clear timer	
	
}

void init_timer1_PhaseCorrectPWM(uint8_t prescaler, uint16_t ticksa, uint16_t ticksb, uint8_t COMA, uint8_t COMB, uint16_t inputcapture){
	TCCR1A = _BV(WGM11) | _BV(WGM10) | COMB << 4 | COMA << 6; //10 bit mode
	
	//TCCR1A = _BV(WGM11) | COMB << 4 | COMA << 6; //9 bit mode
	
	//TCCR1A = _BV(WGM10) | COMB << 4 | COMA << 6; //8 bit mode
	
	//TCCR1A = _BV(WGM11) | _BV(WGM10) | COMB << 4 | COMA << 6; // OCR1A as top usually you set coma to 1 for 50% duty cycle and set comb for whatever!!
	//TCCR1B = _BV(WGM13);
	
	//TCCR1A = _BV(WGM11) | COMB << 4 | COMA << 6; // ICR1 as top
	//TCCR1B = _BV(WGM13);
	//ICR1 = inputcapture;
	
	//frequency correct
	//TCCR1A = _BV(WGM10) | COMB << 4 | COMA << 6; // OCR1A as top usually you set coma to 1 for 50% duty cycle and set comb for whatever!!
	//TCCR1B = _BV(WGM13);
		
	//TCCR1A = COMB << 4 | COMA << 6; // ICR1 as top
	//TCCR1B = _BV(WGM13);
	//ICR1 = inputcapture;
	
	if(prescaler >=0 && prescaler <=7){ TCCR1B |= prescaler;}
	OCR1A = ticksa;
	OCR1B = ticksb;
	TCNT1 = 0;
	
}

void init_inputCapture(uint8_t noiseCanceller,uint8_t edgeSelect, uint8_t prescaler, void (*f)()){
	TCCR1B |= noiseCanceller << ICNC1 | edgeSelect << ICES1 | prescaler;
	TIMSK |= _BV(TICIE1);
	_INC1_func=f;
	TCNT1 =0;
}

void timer1_interrupt(uint8_t overflow, uint8_t outputCompareA, uint8_t outputCompareB){
	if(overflow){
		SETBIT(TIMSK,TOIE1);
	}else{
		CLRBIT(TIMSK,TOIE1);
	}
	if(outputCompareA){
		SETBIT(TIMSK,OCIE1A);
	}else{
		CLRBIT(TIMSK,OCIE1A);
	}
	if(outputCompareB){
		SETBIT(TIMSK,OCIE1B);
	}else{
		CLRBIT(TIMSK,OCIE1B);
	}
}

void timer0_interrupt(uint8_t overflow, uint8_t outputCompare){
	if(overflow){
		SETBIT(TIMSK,TOIE0);
	}else{
		CLRBIT(TIMSK,TOIE0);
	}
	if(outputCompare){
		SETBIT(TIMSK,OCIE0);
	}else{
		CLRBIT(TIMSK,OCIE0);
	}
}

void timer1_setOCR(uint16_t a,uint16_t b){
	
	OCR1A = a;
	OCR1B = b;
}

void timer0_setOCR(uint8_t x){
	OCR0 = x;
}
void disable_timer0(){
	TCCR0=0;
}
void disable_timer1(){
	TCCR1B=0;
}