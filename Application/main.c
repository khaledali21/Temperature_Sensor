/*
 * main.c
 *
 * Created: 1/22/2022 12:30:42 AM
 *  Author: Khaled Ali
 */ 

#include "../ECUAL/TEMPERATURE/TEMP_SENSOR.h"
#include "../ECUAL/LCD/LCD.h"
int main(void){
	LCD_u8Init();
	TEMP_t temp_sensor = {PORTA, PIN0, 0};
	TEMP_u8Init(&temp_sensor);
	float temp_value;
	while(1){
		TEMP_u8GetTemp(&temp_sensor, &temp_value);
		LCD_u8SendString((uint8_t*) "TEMP: ");
		LCD_u8SendNumber((uint16_t) temp_value);
		TIMER0_u8PollingDelay(2000);
		LCD_u8SendCommand(LCD_CLEAR);
	}
}