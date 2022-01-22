/*
 * ADC.h
 *
 * Created: 1/22/2022 5:20:10 PM
 *  Author: Khaled Ali
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../../LIB/Typedef.h"
#include "../../LIB/Atmega32.h"
#include "../../LIB/BIT_Math.h"

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0


typedef enum{
	ADC_ERR,
	ADC_OK
}ADC_ERR_STATE;

void ADC_u8Init(void);

ADC_ERR_STATE ADC_u8Read(uint8_t channel, uint16_t* ADC_Value);

#endif /* ADC_H_ */