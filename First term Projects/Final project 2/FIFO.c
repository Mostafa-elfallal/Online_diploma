/*
 * FIFO.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Mostafa ElFallal
 */
#include "FIFO.h"

int FIFO_count(FIFO * a){
	return a->count;
}
FIFO_Status FIFO_enqueue (FIFO* me , FIFO_element * item){
	/*is it successfully created  ?*/
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	/*don't overload the buffer*/
	if(me->count==me->maxlength){
		return FIFO_FULL_ERROR;
	}
	/*now put data*/
	me->base[me->head] = *item;
	/*don't forget to increase the head for the next insertion*/
	me->head++ ;
	/*don't forget to increase the count for the next insertion*/
	me->count++;
	/*Circular array*/
	me->head%=me->maxlength;
	return FIFO_NO_ERROR;
}

FIFO_Status FIFO_dequeue (FIFO* me , FIFO_element * item){
	/*is it successfully created  ?*/
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	/*is anybody here ?*/
	if(me->count==0){
		return FIFO_EMPTY_ERROR;
	}
	/*it's safe to take You now*/
	*item = me->base[me->tail];
	me->tail++;
	me->count --;
	/*circular*/
	me->tail%=me->maxlength;
	return FIFO_NO_ERROR;
}
/* * * * * * * * * * * * * * * * *
 * static function to increase readability
 * takes the fifo and index offset of desired item to be deleted
 * * * * * * * * * */
static void delete (FIFO* me, int offset){
	/*there are 3 possible probabilities offset is positive , negative or 0 */
	/*for positive : it's better to loop down to tail by shifting the elements up*/
	/*negative offset means that the head is below tail because of circularity*/
	/*at zero we are going to delete the tail -> dequeue*/
	if(offset > 0){
		while(offset>0){
			me->base[me->tail+offset]=me->base[me->tail+offset-1];
			offset--;
		}
		me->tail++;
		me->count --;
	}
	else if (offset < 0){
		while(me->tail + offset < me->head){
				me->base[me->tail+offset + 1 ]=me->base[me->tail+offset];
				offset++;
			}
			me->head--;
			me->count --;
	}
	else{
		FIFO_element dummy;
		FIFO_dequeue(me,&dummy);
	}
}
FIFO_Status FIFO_deleteif	(FIFO* me ,int (*cond)(FIFO_element *,void * key) ,void * key,int times){
	/*is it successfully created  ?*/
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	int satisfying=times;
	/*let's try to loop all elements*/
	for(int i =0;i<me->count;i++){
		/*variable i is just an offset for the tail*/
		if(satisfying == 0){
			/*reached the needed number of items*/
			return FIFO_NO_ERROR;
		}
		if(cond(&(me->base[i+me->tail]),key) == 1 ){
			/*satisfying the user conditions*/
			delete(me,i);/*delete this*/
			satisfying--;
		}
		/*when ever you reach the end start from the zero*/
		i=(i+me->tail == me->maxlength)? -1*me->tail:i;
	}
	return FIFO_NO_ERROR;
}
FIFO_Status FIFO_activateif	(FIFO* me ,int (*cond)(FIFO_element *,void * key) ,void * key,void (*func)(FIFO_element*),int times){
	/*is it successfully created  ?*/
	if(!me->base){
		return FIFO_NOT_EXIST_ERROR;
	}
	int satisfying=times;
	/*let's try to loop all elements*/
	for(int i =0;i<me->count;i++){
		/*variable i is just an offset for the tail*/
		if(satisfying == 0){
			/*reached the needed number of items*/
			return FIFO_NO_ERROR;
		}
		if(cond(&me->base[i+me->tail],key) == 1 ){
			/*satisfying the user conditions*/
			func(&(me->base[i+me->tail]));/*apply the desired action*/
			satisfying--;
		}
		/*when ever you reach the end start from the zero*/
		i=(i+me->tail == me->maxlength)? -1*me->tail:i;
	}
	if(satisfying == times ){
		return FIFO_NOT_EXIST_ERROR;
	}
	return FIFO_NO_ERROR;
}
FIFO_Status FIFO_Creat( FIFO* me , FIFO_element* Buffer , int maxsize){
	/*is buffer exist ?*/
	if(!Buffer){
		return FIFO_NOT_EXIST_ERROR;
	}
	/*initialization*/
	me->base = Buffer;
	me->maxlength = maxsize;
	me->head =	0;
	me->count = 0;
	me->tail = 	0;
	return FIFO_NO_ERROR;
}


