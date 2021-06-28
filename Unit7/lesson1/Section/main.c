/*
 * unit7-lesson1-section.c
 *
 * Created: 6/26/2021 1:27:54 AM
 * Author : Darsh
 */ 
#define MAXDELAYER 50000
#include <avr/io.h>
#include "button.h"
typedef enum  {
	SEGMENT_MODE,
	TRAIN_MODE,
	COUNTER_MODE
	}Mode;

int main(void)
{
	unsigned long BZdelayer=0;
	Mode Runningmode=SEGMENT_MODE;						//initial mode 
	int i=0;											//our global iterator ( used in every mode xD)
	unsigned long delayer=0;							//the non-blocking delay counter
	char traindir =0;									//0 -> right 1 -> left
	DDRC = 0xFC;										// pin 3 isn't used 
	DDRD = 0xF0;										// 3 LEDs , 1 buzzer and 3 switches
	Button b[3];										// 3 buttons as i said xD
	for(i=0;i<3;i++)									
	{
		buttoninit(&b[i],(char *)(&PIND),i,pulleddown);
	}
	i=0;
    /* Replace with your application code */
    while (1) 
    {
		if(readbutton(&b[2])){								//	buzzer ?
			BZdelayer=MAXDELAYER;
			PORTD|=(1<<4);									//Fiiiiiirrrrrrrrre
		}
		else{
			BZdelayer--;
			if(BZdelayer == 0){
				PORTD&=~(1<<4);
			}
		}	
		if(readbutton(&b[0])){			// change mode ?
			i=0;						//reset the global iterator
			PORTC&=~(0b11<<2);			//turn off both segments
			PORTD&=~(0xE0);				//turn off the 3 LEDs
			delayer=0;					//reset the delay counter
			traindir=0;
			switch(Runningmode){
				case SEGMENT_MODE:
					Runningmode=TRAIN_MODE;
					break;
				case TRAIN_MODE:
					Runningmode=COUNTER_MODE;
					break;
				case COUNTER_MODE:
					Runningmode=SEGMENT_MODE;
					break;
				default:
					Runningmode=SEGMENT_MODE;
			}
		}
		switch(Runningmode)
		{
			case SEGMENT_MODE:
				if(delayer == 0){
					PORTC&=~(1<<3);
					PORTC&=(0x0F);
					PORTC|=((i%10)<<4);
					PORTC|=(1<<2);
					delayer++;
				}
				else if(delayer<MAXDELAYER){
					delayer++;
				}
				else if(delayer == MAXDELAYER){
					PORTC&=~(1<<2);
					PORTC&=(0x0F);
					PORTC|=((i/10)<<4);
					PORTC|=(1<<3);
					delayer++;
				}
				else if(delayer<2*MAXDELAYER){
					delayer++;
				}
				else{
					i++;
					i%=100;
					delayer=0;
				}
				break;
			case TRAIN_MODE:
				if(delayer == 0){
					PORTD|=(1<<(i+5));
					delayer++;
				}
				else if(delayer<MAXDELAYER){
					delayer++;
				}
				else{
					PORTD&=~(1<<(i+5));
					i = (traindir) ?   i-1 : i+1;					
					traindir = (i==2)? 1: (i==0)? 0: traindir;
					delayer=0;
				}
				break;
			case COUNTER_MODE:
				if(readbutton(&b[1])){
				i = (traindir) ?   i-1 : i+1;
				traindir = (i==7)? 1: (i==0)? 0: traindir;
				PORTD&=~(0xE0);
				PORTD|=(i<<5);
				}
				break;
			default:
				break;
		}
	}
}

