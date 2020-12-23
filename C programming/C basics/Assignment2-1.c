/*
 * Assignment2-1.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	int a;
	printf("Enter an integer you wanna check: ");
	fflush(stdout);
	scanf("%d",&a);
	if(a&1){
		printf("%d is odd.",a);
	}
	else{
		printf("%d is even.",a);
	}
}

