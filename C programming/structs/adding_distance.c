/*
 * adding_distance.c
 *
 *  Created on: Jan 11, 2021
 *      Author: mostafa elfallal
 */
#include <stdio.h>
struct distance{
	int feet;
	float inches;
};
struct distance get(void){
	struct distance temp;
	printf("\nEnter distance info\n");
	printf("Enter feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&temp.feet);
	printf("Enter inches : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&temp.inches);
	return temp;
}
struct distance add(struct distance a,struct distance b){
	struct distance temp;
	temp.feet=a.feet+b.feet;
	temp.inches=a.inches+b.inches;
	if(temp.inches >=12){
		temp.inches-=12;
		temp.feet++;
	}
	if (temp.inches >=12 ){
		printf("Warning : check your input.");
	}
	return temp;
}
void display(struct distance temp){
printf("%d\'-%1.1f",temp.feet,temp.inches);
}
int main(){
	struct distance st=get();
	struct distance nd=get();
	struct distance rd=add(st,nd);
	printf("Sum of distances = ");
	display(rd);
}
