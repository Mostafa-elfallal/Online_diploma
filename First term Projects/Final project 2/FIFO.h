/*
 * FIFO.h
 *
 *  Created on: Apr 14, 2021
 *      Author: Mostafa ElFallal
 */

#ifndef FIFO_H_
#define FIFO_H_
#include <stdint.h>
#include "Fifo_userconfig.h"
/*ENUM for the various types of Errors*/
typedef enum{
	FIFO_NO_ERROR , FIFO_FULL_ERROR , FIFO_EMPTY_ERROR , FIFO_NOT_EXIST_ERROR
}FIFO_Status;
struct FIFO{
	/*The buffer of the queue*/
	FIFO_element* 			base;
	/*can't assign more than the max*/
	int 				maxlength;
	/*array index*/
	int 					head;
	/*another array index*/
	int 					tail;
	/*used to reduce the algorithm for some functions*/
	int						count;
};

/*Trying to make it like class :)*/
typedef struct FIFO FIFO;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 	This function is used to enqueue an element to the FIFO
 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
 *  POSTCONDITIONS  :	1- The item is added to the FIFO
 *  					2- The head is incremented
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
FIFO_Status FIFO_enqueue	(FIFO* me , FIFO_element * item);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 	This function is used to dequeue an element from the FIFO
 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
 *  					2- There is at least one element is enqueued or an error will be returned
 *  POSTCONDITIONS  :	1- The item is loaded with the value from the FIFO
 *  					2- The data is removed from the FIFO
 *  					3- The tail is incremented
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
FIFO_Status FIFO_dequeue	(FIFO* me , FIFO_element * item);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 	This function is used to perform a custom function (func) for the first custom-defined elements that return true
 * 	from the (cond) function
 * 	the first times element that satisfy the (cond) function will be passed to (func)
 * 	pass -1 in times to pass all satisfying elements
 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
 *  					2- There is at least one element is pushed or an error will be returned
 *  POSTCONDITIONS  :	1- The element(s) will be passed to the (func)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
FIFO_Status FIFO_activateif	(FIFO* ,int (*cond)(FIFO_element *,void * key) ,void * ,void (*func)(FIFO_element*),int);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 	This function is used to delete the first custom-defined elements that return true
 * 	from the (cond) function
 * 	the first times element that satisfy the (cond) function will be deleted
 * 	pass -1 in times to delete all satisfying elements
 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
 *  					2- There is at least one element is pushed or an error will be returned
 *  POSTCONDITIONS  :	1- The element(s) will be deleted from the queue
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
FIFO_Status FIFO_deleteif	(FIFO* me ,int (*cond)(FIFO_element *,void * key) ,void * ,int times);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * 	This function is used to create and initialize from the FIFO
 *  PRECONDITIONS : 	1- The Buffer is successfully allocated or an error will returned
 *  					2- The allocated memory in buffer is sufficient for the MAXSIZE
 *  POSTCONDITIONS  :	1- head is set to 0
 *  					2- Other functionalities are available
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
FIFO_Status FIFO_Creat( FIFO* me , FIFO_element* Buffer , int maxsize);

int FIFO_count(FIFO * a);

#endif /* FIFO_H_ */
