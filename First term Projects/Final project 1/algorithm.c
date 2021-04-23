#include "algorithm.h"

const int threshold = 20;		//can't be changed during the program
static int Pval;				//can't  be used outside this file


void GPIO_INITIALIZATION (void){
	SET_BIT(APB2ENR, 2);
	GPIOA_CRL &= 0xFF0FFFFF;
	GPIOA_CRL |= 0x00000000;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x22222222;
}
enum States{ ReadingPreaure , Thinking , AlarmON , Waiting , AlarmOFF };

void ALGO_start(void){

	static enum States State= ReadingPreaure;
	switch(State){
		case ReadingPreaure:
		Pval=getPressureVal();		//read the value
		State = Thinking;			//next step
		break;

		case Thinking:
		if(Pval > threshold){
			State = AlarmON ;		//Unsafe environment
		}
		else{
			State = AlarmOFF;		//Safe environment
		}
		break;

		case AlarmON:
			Ctrl_Alarm_actuator(ON_KEY);	
			State = Waiting;
		break;

		case Waiting:
			Delay(DUR);
			State = AlarmOFF;
		break;

		case AlarmOFF:
			Ctrl_Alarm_actuator(OFF_KEY);
			State = ReadingPreaure ;
		break;

		default :	//nothing to do for now
		break;
	}
}