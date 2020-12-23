/*
 * Assignment2-2.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	char a;
	printf("Enter an alphabet: ");
	fflush(stdout);
	scanf("%c",&a);
	switch(a){
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	case 'A':
	case 'E':
	case 'I':
	case 'O':
	case 'U':
		printf("%c is a vowel.",a);
		break;
	default :
		printf("%c is a consonant.",a);
	}
}

