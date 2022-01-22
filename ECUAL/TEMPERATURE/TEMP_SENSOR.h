/*
 * TEMP_SENSOR.h
 *
 * Created: 1/22/2022 6:40:25 PM
 *  Author: Khaled Ali
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#include "../../LIB/Typedef.h"
#include "../../MCAL/ADC/ADC.h"
#include "../../MCAL/DIO/DIO.h"


#define AVCC 5000
#define MAX_ADC 1024
typedef struct{
	uint8_t PORT;
	uint8_t PIN;
	uint8_t channel;
}TEMP_t;


typedef enum{
	TEMP_ERR,
	TEMP_OK
}TEMP_ERR_STATE;


TEMP_ERR_STATE TEMP_u8Init(TEMP_t* temp_sensor);

TEMP_ERR_STATE TEMP_u8GetTemp(TEMP_t* temp_sensor, float* temp);



#endif /* TEMP_SENSOR_H_ */