/*
 * ADC.c
 *
 * Created: 1/22/2022 5:20:01 PM
 *  Author: Khaled Ali
 */ 

#include "ADC.h"
/*
* brief: This function is used to initialize the ADC and Enable it
*/
void ADC_u8Init(void){
	//Configure Refernce to be AVCC
	CLR_BIT(ADMUX_REG, REFS1);
	SET_BIT(ADMUX_REG, REFS0);
	//Right Adjustment
	CLR_BIT(ADMUX_REG, ADLAR);
	//SET PRESCALER to be 128
	SET_BIT(ADCSRA_REG, ADPS2);
	SET_BIT(ADCSRA_REG, ADPS1);
	SET_BIT(ADCSRA_REG, ADPS0);
	//Enable ADC
	SET_BIT(ADCSRA_REG, ADEN);	
}
/*
* brief: This function is used to Read the analog signal on one of the channels
* param.: (input) the channel to read from
* param.: (input) a pointer to a variable to get the ADC readings
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
ADC_ERR_STATE ADC_u8Read(uint8_t channel, uint16_t* ADC_Value){
	ADC_ERR_STATE state = ADC_OK;
	if(channel < 0 || channel > 7){
		state = ADC_ERR;
	}
	else{
		ADMUX_REG &= 0xF8;
		ADMUX_REG |= channel;
		SET_BIT(ADCSRA_REG, ADSC);
		while(GET_BIT(ADCSRA_REG, ADIF) == 0);
		SET_BIT(ADCSRA_REG, ADIF);
		*ADC_Value = ADC_REG;
	}
	return state;
}