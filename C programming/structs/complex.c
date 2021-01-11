/*
 * complex.c
 *
 *  Created on: Jan 11, 2021
 *      Author: mostafa elfallal
 */

#include <stdio.h>
struct complex{
	float real;
	float imi;
};
struct complex get(void){
	struct complex temp;
	printf("\nEnter number in form (R+Ii) : ");
	fflush(stdin);fflush(stdout);
	scanf("%f+%fi",&temp.real,&temp.imi);
	return temp;
}
struct complex add(struct complex a,struct complex b){
	struct complex temp;
	temp.real=a.real+b.real;
	temp.imi=a.imi+b.imi;
	return temp;
}
void display(struct complex temp){
printf("%0.1f+%0.1fi",temp.real,temp.imi);
}
int main(){
	struct complex st=get();
	struct complex nd=get();
	struct complex rd=add(st,nd);
	printf("Sum = ");
	display(rd);
}


