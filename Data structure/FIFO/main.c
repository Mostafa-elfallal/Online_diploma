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
#include "FIFO.h"
void print(FIFO_element a){
	DPRINTF("student id = %d\n",a.id);
	DPRINTF("student score = %d\n",a.score);
	DPRINTF("================================================\n");
}
int main(){
	FIFO_element student;
	FIFO_element Buff[10];
	FIFO stack;
	DPRINTF("==== First buffer (static) ====\n");

	if(FIFO_Creat(Buff,&stack,10)==FIFO_NO_ERROR){
		DPRINTF("created successfully :) \n");
		DPRINTF("==== queuing data ====\n");
		for(int i =0;i<15;i++){
			student.id=i;
			student.score=i*i;
			if(stack.enqueue(&stack,&student)==FIFO_NO_ERROR){
				DPRINTF("item enqueued successfully :) \n");
			}
			else{
				DPRINTF("item can't be enqueued :( \n");
			}
		}
		DPRINTF("==== printing all data ====\n");
		stack.Traverse(&stack,print);
		DPRINTF("==== dequeuing ====\n");
		for(int i = 0; i<15;i++){
			if(stack.dequeue(&stack,&student)==FIFO_NO_ERROR){
				DPRINTF("item dequeued successfully :) \n");
				print(student);
			}
			else{
				DPRINTF("item can't be dequeued :( \n");
			}
		}
	}
	else{
		DPRINTF("can't be created :( \n");
	}
	DPRINTF("========================================================================================================\n");
	FIFO_element * dBuff = (FIFO_element *)malloc(10*sizeof(FIFO_element));
	FIFO dstack;
	DPRINTF("==== Second buffer (dynamic) ====\n");

	if(FIFO_Creat(dBuff,&dstack,10)==FIFO_NO_ERROR){
		DPRINTF("created successfully :) \n");
		DPRINTF("==== queuing data ====\n");
		for(int i =0;i<15;i++){
			student.id=i+10;
			student.score=(i+10)*(i+10);
			if(dstack.enqueue(&dstack,&student)==FIFO_NO_ERROR){
				DPRINTF("item enqueued successfully :) \n");
			}
			else{
				DPRINTF("item can't be enqueued :( \n");
			}
		}
		DPRINTF("==== printing all data ====\n");
		dstack.Traverse(&dstack,print);
		DPRINTF("==== dequeuing ====\n");
		for(int i = 0; i<15;i++){
			if(dstack.dequeue(&dstack,&student)==FIFO_NO_ERROR){
				DPRINTF("item dequeued successfully :) \n");
				print(student);
			}
			else{
				DPRINTF("item can't be dequeued :( \n");
			}
		}
	}
	else{
		DPRINTF("can't be created :( \n");
	}
}



