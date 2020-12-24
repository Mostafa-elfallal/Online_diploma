/*
 * Reverse_string.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#include <string.h>
void main(){
	char dist[100];
	char scr[100];
	int i ,j;
	printf("Enter the string  : ");
	fflush(stdout);
	gets(scr);
	for(i=0,j=strlen(scr)-1;j>=0;i++,j--){
		dist[i]=scr[j];
	}
	dist[i]=0;
	printf("Reverse string is : %s",dist);
}

