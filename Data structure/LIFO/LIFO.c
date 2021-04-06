/*
 * LIFO.c
 *
 *  Created on: Mar 29, 2021
 *      Author: Darsh
 */
#include "LIFO.h"
LIFO_Status LIFO_Push (LIFO* me , LIFO_element * item){
	if(!me->base){
		return LIFO_NOT_EXIST_ERROR;
	}
	if(me->head==me->maxlength){
		return LIFO_FULL_ERROR;
	}
	me->base[me->head] = *item;
	me->head++ ;
	return LIFO_NO_ERROR;
}

LIFO_Status LIFO_Pop (LIFO* me , LIFO_element * item){
	if(!me->base){
		return LIFO_NOT_EXIST_ERROR;
	}

	if(me->head==0){
		return LIFO_EMPTY_ERROR;
	}
	me->head--;
	*item = me->base[me->head];

	return LIFO_NO_ERROR;
}
LIFO_Status LIFO_Traverse	(LIFO* me , void (*func)(LIFO_element)){
	if(!me->base){
		return LIFO_NOT_EXIST_ERROR;
	}
	int i = 0 ;
	for(;i<me->head;i++){
		func(me->base[i]);
	}
	return LIFO_NO_ERROR;
}
LIFO_Status LIFO_Creat(LIFO_element* Buffer , LIFO* me , int maxsize){
	if(!Buffer){
		return LIFO_NOT_EXIST_ERROR;
	}
	me->base = Buffer;
	me->maxlength = maxsize;
	me->head =0;
	me->Push=LIFO_Push;
	me->Pop=LIFO_Pop;
	me->Traverse=LIFO_Traverse;
	return LIFO_NO_ERROR;
}
