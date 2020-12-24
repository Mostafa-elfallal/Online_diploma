/*
 * inserting_inarray.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
void main() {
	printf(
			"this program takes array and insert element in specific location\n\r");

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
	printf("\nEnter element to be inserted : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &element);
	printf("\nEnter location : ");
	fflush(stdout);
	fflush(stdin);
	scanf("%d", &pos);
	pos--; //we are dealing with 0 start elements
	for (i = n - 1; i >= pos; i--) {
		arr[i + 1] = arr[i];
	}
	arr[pos] = element;
	n++; //expand our array
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}

