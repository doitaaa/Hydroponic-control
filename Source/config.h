/*
 * config.h
 * configuration file for servos and pumps
 * Created: 25-Dec-18 4:29:06 PM
 *  Author: mohamed
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

//servo configurations
#define servoPh_pin D, 4 //OC1B
#define servoEC_pin D, 5 //OC1A

//pumps configurations for stepper motor drivers
#define pumpPhPlus_StepPin    B, 0
#define pumpPhMinus_StepPin   B, 1
#define pumpNutrients_StepPin B, 2

//DHT sensor configurations
#define DHT_Type	DHT22          //DHT11 or DHT22
#define DHT_Pin		A, 7

//Ph/ECT sensor configurations
#define Ph_Pin
#define ECT_Pin

//LCD configurations
#define LCD_D4
#define LCD_D5
#define LCD_D6
#define LCD_D7
#define LCD_E
#define LCD_RW
#define LCD_RS

//Keypad configurations
#define KP_A
#define KP_B
#define KP_C
#define KP_D
#define KP_1
#define KP_2
#define KP_3


#endif /* CONFIG_H_ */