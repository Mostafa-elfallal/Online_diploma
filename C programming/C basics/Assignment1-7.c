/*
 * Assignment1-7.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
// This is an "eftkasa" from me but it's working on integers only
// i solved the trick in EX6
#include "stdio.h"
void main(){
	int a,b;
	printf("Enter value of a: ");
	fflush(stdout);
	scanf("%d",&a);
	printf("Enter value of b: ");
	fflush(stdout);
	scanf("%d",&b);
	a=a^b;
	b=a^b;
	a=a^b;
	printf("After swapping, value of a = %d\n"
			"After swapping, value of b = %d",a,b);
}


