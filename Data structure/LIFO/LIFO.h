/*
 * LIFO.h
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdint.h>
/*Configure the type and use LIFO_element in your code*/
struct student {
	int id;
	int score;
};
#define LIFO_element struct student
/*ENUM for the various types of Errors*/
typedef enum{
	LIFO_NO_ERROR , LIFO_FULL_ERROR , LIFO_EMPTY_ERROR , LIFO_NOT_EXIST_ERROR
}LIFO_Status;
/*Trying to make it like class :)*/
typedef struct lifo LIFO;
struct lifo{
	LIFO_element* 			base;
	int 					maxlength;
	int 					head;
	/* * *
	 * 	This function is used to push an element to the LIFO
	 *  PRECONDITIONS : 	1- The LIFO is successfully created or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is added to the LIFO
	 *  					2- The head is incremented
	 * * */
	LIFO_Status (*Push)	(LIFO* me , LIFO_element * item);
	/* * *
	 * 	This function is used to pop an element from the LIFO
	 *  PRECONDITIONS : 	1- The LIFO is successfully created or an error will be returned
	 *  					2- There is at least one element is pushed or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is loaded with the value from the LIFO
	 *  					2- The data is removed from the LIFO
	 *  					3- The head is decremented
	 * * */
	LIFO_Status (*Pop)	(LIFO* me , LIFO_element * item);
	/* * *
	 * 	This function is used to perform a custom function for all elements
	 *  PRECONDITIONS : 	1- The LIFO is successfully created or an error will be returned
	 *  					2- There is at least one element is pushed or an error will be returned
	 *  POSTCONDITIONS  :
	 * * */
	LIFO_Status (*Traverse)	(LIFO* me , void (*func)(LIFO_element));
};
/* * *
 * 	This function is used to create and initialize from the LIFO
 *  PRECONDITIONS : 	1- The Buffer is successfully allocated or an error will returned
 *  					2- The allocated memory in buffer is sufficient for the MAXSIZE
 *  POSTCONDITIONS  :	1- head is set to 0
 *  					2- Other functionalities are available
 * * */
LIFO_Status LIFO_Creat(LIFO_element* Buffer , LIFO* me , int maxsize);

#endif /* LIFO_H_ */
