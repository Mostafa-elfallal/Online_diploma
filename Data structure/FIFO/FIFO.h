/*
 * FIFO.h
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdint.h>
/*Configure the type and use FIFO_element in your code*/
struct student {
	int id;
	int score;
};
#define FIFO_element struct student
/*ENUM for the various types of Errors*/
typedef enum{
	FIFO_NO_ERROR , FIFO_FULL_ERROR , FIFO_EMPTY_ERROR , FIFO_NOT_EXIST_ERROR
}FIFO_Status;
/*Trying to make it like class :)*/
typedef struct FIFO FIFO;
struct FIFO{
	FIFO_element* 			base;
	int 					maxlength;
	int 					head;
	int 					tail;
	int						count;
	/* * *
	 * 	This function is used to enqueue an element to the FIFO
	 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is added to the FIFO
	 *  					2- The head is incremented
	 * * */
	FIFO_Status (*enqueue)	(FIFO* me , FIFO_element * item);
	/* * *
	 * 	This function is used to dequeue an element from the FIFO
	 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
	 *  					2- There is at least one element is enqueued or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is loaded with the value from the FIFO
	 *  					2- The data is removed from the FIFO
	 *  					3- The tail is incremented
	 * * */
	FIFO_Status (*dequeue)	(FIFO* me , FIFO_element * item);
	/* * *
	 * 	This function is used to perform a custom function for all elements
	 *  PRECONDITIONS : 	1- The FIFO is successfully created or an error will be returned
	 *  					2- There is at least one element is pushed or an error will be returned
	 *  POSTCONDITIONS  :
	 * * */
	FIFO_Status (*Traverse)	(FIFO* me , void (*func)(FIFO_element));
};
/* * *
 * 	This function is used to create and initialize from the FIFO
 *  PRECONDITIONS : 	1- The Buffer is successfully allocated or an error will returned
 *  					2- The allocated memory in buffer is sufficient for the MAXSIZE
 *  POSTCONDITIONS  :	1- head is set to 0
 *  					2- Other functionalities are available
 * * */
FIFO_Status FIFO_Creat(FIFO_element* Buffer , FIFO* me , int maxsize);



#endif /* FIFO_H_ */
