/*
 * search_inarray.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
void main() {
	printf("this program takes array and search for element\n\r");

	int arr[15];
	int i, n, element, pos;
	printf("Enter no of elements (max 14) : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &n);
	printf("Enter elements : \n");
	fflush(stdout);
	fflush(stdin);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("\nEnter element to be searched for : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &element);
	for(i=0;i<n;i++){
		if(arr[i]==element){
			pos=i+1;
			break;
		}
	}
	if(i==n){
		printf("element isn't found.");
	}
	else{
		printf("element found at location = %d",pos);
	}
}
