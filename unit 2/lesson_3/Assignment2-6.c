/*
 * Assignment2-6.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	unsigned int a;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&a);
	printf("Sum = %u",a/2*(a+1));
}

