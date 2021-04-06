/*
 * main.c
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */
#include "stdlib.h"
#include "stdio.h"
#define DPRINTF(...) 	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);\
						}
#include "LIFO.h"
void print(LIFO_element a){
	DPRINTF("student id = %d\n",a.id);
	DPRINTF("student score = %d\n",a.score);
	DPRINTF("================================================\n");
}
int main(){
	LIFO_element student;
	LIFO_element Buff[10];
	LIFO stack;
	DPRINTF("==== First buffer (static) ====\n");

	if(LIFO_Creat(Buff,&stack,10)==LIFO_NO_ERROR){
		DPRINTF("created successfully :) \n");
		DPRINTF("==== entering data ====\n");
		for(int i =0;i<15;i++){
			student.id=i;
			student.score=i*i;
			if(stack.Push(&stack,&student)==LIFO_NO_ERROR){
				DPRINTF("item added successfully :) \n");
			}
			else{
				DPRINTF("item can't be added :( \n");
			}
		}
		DPRINTF("==== printing all data ====\n");
		stack.Traverse(&stack,print);
		DPRINTF("==== popping ====\n");
		for(int i = 0; i<15;i++){
			if(stack.Pop(&stack,&student)==LIFO_NO_ERROR){
				DPRINTF("item popped successfully :) \n");
				print(student);
			}
			else{
				DPRINTF("item can't be popped :( \n");
			}
		}
	}
	else{
		DPRINTF("can't be created :( \n");
	}
	DPRINTF("========================================================================================================\n");
	LIFO_element * dBuff = (LIFO_element *)malloc(10*sizeof(LIFO_element));
	LIFO dstack;
	DPRINTF("==== Second buffer (dynamic) ====\n");

	if(LIFO_Creat(dBuff,&dstack,10)==LIFO_NO_ERROR){
		DPRINTF("created successfully :) \n");
		DPRINTF("==== entering data ====\n");
		for(int i =0;i<15;i++){
			student.id=i+10;
			student.score=(i+10)*(i+10);
			if(dstack.Push(&dstack,&student)==LIFO_NO_ERROR){
				DPRINTF("item added successfully :) \n");
			}
			else{
				DPRINTF("item can't be added :( \n");
			}
		}
		DPRINTF("==== printing all data ====\n");
		dstack.Traverse(&dstack,print);
		DPRINTF("==== popping ====\n");
		for(int i = 0; i<15;i++){
			if(dstack.Pop(&dstack,&student)==LIFO_NO_ERROR){
				DPRINTF("item popped successfully :) \n");
				print(student);
			}
			else{
				DPRINTF("item can't be popped :( \n");
			}
		}
	}
	else{
		DPRINTF("can't be created :( \n");
	}
}

