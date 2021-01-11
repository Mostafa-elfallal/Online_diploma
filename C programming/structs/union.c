/*
 * union.c
 *
 *  Created on: Jan 11, 2021
 *      Author: mostafa elfallal
 */

#include <stdio.h>
union job{
	char name[32];
	float salary;
	int worker_no;

}u;
struct jobb{
	char name[32];
	float salary;
	int worker_no;

}s;
int main(){
	printf("size of union = %d",sizeof(u));
	printf("\nsize of struct = %d",sizeof(s));
}
