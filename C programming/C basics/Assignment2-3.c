/*
 * Assignment2-3.c
 *
 *  Created on: Dec 20, 2020
 *      Author: mostafa elfallal
 */
#include "stdio.h"
void main(){
	float a[3];
	printf("Enter three numbers: ");
	fflush(stdout);
	scanf("%f %f %f",a+0,a+1,a+2);
	printf("Largest number = %f",(a[0]>a[1]? (a[0]>a[2]? a[0]:a[2]):(a[1]>a[2]? a[1]:a[2])));
	//I know it's a low readability or maintainability but it's good to enhance my skills
}

