/*
 * FIFO.c
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */
#include "FIFO.h"
FIFO_Status FIFO_enqueue (FIFO* me , FIFO_element * item){
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	if(me->count==me->maxlength){
		return FIFO_FULL_ERROR;
	}
	me->base[me->head] = *item;
	me->head++ ;
	me->count++;
	me->head%=me->maxlength;
	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_dequeue (FIFO* me , FIFO_element * item){
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	if(me->count==0){
		return FIFO_EMPTY_ERROR;
	}
	*item = me->base[me->tail];
	me->tail++;
	me->count --;
	me->tail%=me->maxlength;
	return FIFO_NO_ERROR;
}
FIFO_Status FIFO_Traverse	(FIFO* me , void (*func)(FIFO_element)){
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}

	for(int i =0;i<me->count;i++){
		func(me->base[i+me->tail]);
		i=(i+me->tail == me->maxlength)? -1*me->tail:i;
	}
	return FIFO_NO_ERROR;
}
FIFO_Status FIFO_Creat(FIFO_element* Buffer , FIFO* me , int maxsize){
	if(!Buffer){
		return FIFO_NOT_EXIST_ERROR;
	}
	me->base = Buffer;
	me->maxlength = maxsize;
	me->head =	0;
	me->count = 0;
	me->tail = 	0;
	me->enqueue=FIFO_enqueue;
	me->dequeue=FIFO_dequeue;
	me->Traverse=FIFO_Traverse;
	return FIFO_NO_ERROR;
}


