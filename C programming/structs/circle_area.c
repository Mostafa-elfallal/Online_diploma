/*
 * circle_area.c
 *
 *  Created on: Jan 11, 2021
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#define PI 3.14159f
#define AREA(x) (PI*x*x)
int main(){
	float r;
	printf("Enter the raduis : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&r);
	printf("AREA = %.2f",AREA(r));
}
