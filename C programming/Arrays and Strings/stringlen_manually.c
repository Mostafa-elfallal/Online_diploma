/*
 * stringlen_manually.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
void main(){
	char s[1000];
	int i;
	printf("Enter a string: ");
	fflush(stdout);
	gets(s);
	for(i=0;s[i]!=0;i++);
	printf("Length of string: %d",i);
}

