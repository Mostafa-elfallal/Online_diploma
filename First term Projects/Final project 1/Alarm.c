#include "Alarm.h"



void Ctrl_Alarm_actuator(int i){
	if (i == OFF_KEY){
		SET_BIT(GPIOA_ODR,ACTUATOR_PIN);
	}
	else if (i == ON_KEY){
		RESET_BIT(GPIOA_ODR,ACTUATOR_PIN);
	}
}


void Delay(int nCount)
{
	for(; nCount != 0; nCount--);
}
