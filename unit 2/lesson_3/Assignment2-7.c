/*
 * Assignment2-7.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	int a;
	unsigned long Fact=1;
	printf("Enter an integer: ");
	fflush(stdout);
	scanf("%d",&a);
	if(a<0)
		printf("Error!!! Factorial of negative number doesn't exist.");
	else{
		int i;
		for(i=2;i<=a;i++){
			Fact*=i;
		}
		printf("Factorial = %lu",Fact);
	}
}

