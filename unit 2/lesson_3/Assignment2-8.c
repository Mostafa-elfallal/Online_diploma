/*
 * Assignment2-8.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	char op;
	float a,b;
	printf("Enter operator either + , - , * or / : ");
	fflush(stdout);
	scanf("%c",&op);
	printf("Enter two operands: ");
	fflush(stdout);
	scanf("%f %f",&a,&b);
	switch(op){
	case '+':
	{
		printf("%f %c %f = %f",a,op,b,a+b);
	}
	break;
	case '-':
	{
		printf("%f %c %f = %f",a,op,b,a-b);
	}
	break;
	case '*':
	{
		printf("%f %c %f = %f",a,op,b,a*b);
	}
	break;
	case '/':
	{
		printf("%f %c %f = %f",a,op,b,a/b);
	}
	break;
	default :
		printf("You didn't enter a valid operator");
	}
}

