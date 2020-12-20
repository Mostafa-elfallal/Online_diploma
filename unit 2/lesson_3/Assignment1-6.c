/*
 * Assignment1-6.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	float a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%f",&b);
	a+=b;
	b=a-b;
	a-=b;
	printf("After swapping, value of a = %f\n"
			"After swapping, value of b = %f",a,b);
}

