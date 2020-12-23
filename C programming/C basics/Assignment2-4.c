/*
 * Assignment2-4.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	float a;
	printf("Enter a number: ");
	fflush(stdout);
	scanf("%f",&a);
	a>0? printf("%f is positive.",a): (a<0? printf("%f is negative.",a):printf("You entered zero."));
}

