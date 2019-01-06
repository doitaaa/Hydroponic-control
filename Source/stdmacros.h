/*
 * stdmacros.h
 *
 * Created: 05-Jul-18 3:12:30 PM
 *  Author: mohamed
 */ 


#ifndef STDMACROS_H_
#define STDMACROS_H_
#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>



#define SETBIT(REG,BIT)  (REG |= 1 << BIT)
#define CLRBIT(REG,BIT)  (REG &= ~(1 << BIT))
#define TOGBIT(REG,BIT)  (REG ^= 1 << BIT)
#define READBIT(REG,BIT) ((REG >> BIT) & 1)



#endif /* STDMACROS_H_ */