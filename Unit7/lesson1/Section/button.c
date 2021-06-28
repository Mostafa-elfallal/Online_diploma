/*
 * button.c
 *
 * Created: 6/28/2021 3:17:46 PM
 *  Author: Darsh
 */ 
#include "button.h"
void buttoninit(Button *b , char * REG, char pin , buttonpull mode){
	b->pullmode=mode;
	b->prev=(char)b->pullmode;
	b->current = (char)b->pullmode;
	b->PINREG=REG;
	b->pinnum=pin;
}

char readbutton(Button *b ){
	if(((( *(b->PINREG)) & (1 << b->pinnum)) >> (b->pinnum)) != (b->pullmode)){				//pressed now
		b->current=(b->pullmode == pulleddown)? (char)pulledup : (char)pulleddown;						//the current state is opposite to the default state
		if(b->prev == b->current )															//the previous state is pressed ?
		{
			return 0;
		}
		else{																				//the previous state is  notpressed
			b->prev = b->current;															//make it pressed for the next call
			return 1;
		}
	}
	else{																					//the button is not pressed now
		b->current =(char)b->pullmode;														//the current state is the default
		if(b->prev != b->current){															// it was pressed ?
			b->prev = b->current;
			return 0;																		// this line can be changed to return 1 to work for any edge
		}
		else{
			return 0;																					//it wasn't pressed too
		}
	}
}