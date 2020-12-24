/*
 * char_freq.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#include <string.h>
void main(){
	char s[100];
	char c;
	int i,count=0;
	printf("This program takes a string and an character to output its frequency\n\r");
	printf("Enter a string : ");
	fflush(stdout);
	gets(s);
	printf("\nEnter a character to find frequency : ");
	fflush(stdout);
	c=getchar();
	for(i=0;s[i]!='\0';i++){
		if(s[i]==c){
			count++;
		}
	}
	printf("\nFrequency of %c = %d",c,count);
}

