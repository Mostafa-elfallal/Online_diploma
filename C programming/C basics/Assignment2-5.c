/*
 * Assignment2-5.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	char a;
	printf("Enter a character: ");
	fflush(stdout);
	scanf("%c",&a);
	if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
		printf("%c is an alphabet",a);
	else
		printf("%c is not an alphabet",a);
}

