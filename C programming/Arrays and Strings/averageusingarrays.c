/*
 * averageusingarrays.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
//takes n elements from user to calculate average
#include <stdio.h>
void main(){
	printf("this program calculates average using arrays\n");
	float arr[100];
	int n;
	int i;
	float avg=0;
	//taking the number of elements
	printf("Enter the number of data: ");
	fflush(stdout);
	scanf("%d",&n);
	//taking elements
	for(i=0;i<n;i++){
		printf("%d. Enter number: ",i+1);
		fflush(stdout);
		scanf("%f",arr+i);
	}
	//summing data
	for(i=0;i<n;i++){
		avg+=arr[i];
	}
	//avg
	avg/=n;
	printf("Average = %.2f",avg);
}

