/*
 * structs.c
 *
 *  Created on: Jan 8, 2021
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#include <string.h>
struct student {
	char name[50];
	int roll;
	float marks;
};
struct student entry(){
	struct student temp;
	printf("Enter information of student  \n\r");
	printf("Enter name : ");
	fflush(stdout);fflush(stdin);
	gets(temp.name);
	printf("Enter roll number : ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&temp.roll);
	printf("Enter marks : ");
	fflush(stdout);fflush(stdin);
	scanf("%f",&temp.marks);
	return temp;
}
void display(struct student temp){
	printf("\nname : %s\nRoll : %d\nMarks : %0.2f\n",temp.name,temp.roll,temp.marks);
}
int main(){
	struct student a=entry();
	display(a);
}
