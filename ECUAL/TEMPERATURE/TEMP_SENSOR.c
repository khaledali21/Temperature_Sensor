/*
 * TEMP_SENSOR.c
 *
 * Created: 1/22/2022 6:40:37 PM
 *  Author: Khaled Ali
 */ 

#include "TEMP_SENSOR.h"



/*
* brief: This function is used to set initialize the pin connected to the temperature sensor and initialize the ADC
* param.: (input) a pointer to a temperature structure describing which port, pin and ADC channel will be used
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
TEMP_ERR_STATE TEMP_u8Init(TEMP_t* temp_sensor){
	TEMP_ERR_STATE state = TEMP_OK;
	if(temp_sensor == NULL){
		state = TEMP_ERR;
	}
	else{
		state = DIO_u8SetPinDirection(temp_sensor->PORT, temp_sensor->PIN, INPUT_PIN_NO_PULLUP);
		ADC_u8Init();
	}
	return state;
}
/*
* brief: This function is used to set get the current temperature
* param.: (input) a pointer to a temperature structure describing which port, pin and ADC channel will be used
* param.: (input) a pointer to float value to get the temperature value
* return: (output) the Error state of the function 0 if an error happens and 1 otherwise
*/
TEMP_ERR_STATE TEMP_u8GetTemp(TEMP_t* temp_sensor, float* temp){
	TEMP_ERR_STATE state = TEMP_OK;
	if(temp_sensor == NULL){
		state = TEMP_ERR;
	}
	else{
		uint16_t ADC_value;
		state = ADC_u8Read(temp_sensor->channel, &ADC_value);
		if(state == TEMP_OK){
			*temp = ((float) ADC_value / MAX_ADC) * AVCC;
			*temp /= 10;
		}
	}
	return state;
}