/*
 * students.c
 *
 *  Created on: Jan 11, 2021
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#include <string.h>
struct student {
	char name[50];
	int roll;
	float marks;
};
struct student entry(int i){
	struct student temp;
	printf("Enter information of student %d \n",i+1);
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
	int i=0;
	struct student a[10];
	for(;i<10;i++){
		a[i]=entry(i);
	}
	for(i=0;i<10;i++){
		display(a[i]);
	}
}

