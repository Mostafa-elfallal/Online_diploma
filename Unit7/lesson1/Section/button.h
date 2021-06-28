/*
 * button.h
 *
 * Created: 6/28/2021 3:17:33 PM
 *  Author: Darsh
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_


typedef enum {
	pulleddown , pulledup
}buttonpull;


typedef struct {
	char prev;
	char current;
	char * PINREG;
	char pinnum;
	buttonpull pullmode;
}Button;

void buttoninit(Button *b , char * REG, char pin , buttonpull mode);
char readbutton(Button *b );


#endif /* BUTTON_H_ */