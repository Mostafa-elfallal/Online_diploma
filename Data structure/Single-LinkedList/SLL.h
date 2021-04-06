/*
 * SLL.h
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */

#ifndef SLL_H_
#define SLL_H_
/* * *
 * Please define your data in the node structure and don't touch anything else
 * */
typedef struct SLL_node SLL_node;
struct SLL_node {
	int ID;
	float height;
	char name[30];

	SLL_node * next;
};
/*ENUM for the various types of Errors*/
typedef enum{
	SLL_NO_ERROR , SLL_NOMEMORY_ERROR , SLL_EMPTY_ERROR , SLL_NOTFOUND_ERROR
}SLL_Status;

typedef struct SLL SLL;
struct SLL{
	/*why do you think it's named private ? ha !?*/
	void * privates;
	/*Your data don't ask me about it.*/
	SLL_node node;
	/* * *
	 * 	This function is used to add an element to the linked list
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is added to the linked list
	 * * */
	SLL_Status (*add) (SLL* me , SLL_node * data);
	/* * *
	 * 	This function is used to pop an element from the linked list
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  					2- There is at least one element is added or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is loaded with the value from the linked list
	 *  					2- The data is popped from the linked list
	 * * */
	SLL_Status (*pop) (SLL* me , SLL_node * data);
	/* * *
	 * 	This function is used to remove an element from the linked list using a user function
	 * 	the user function returns 0 or 1 depending on if it is the item to be deleted or not
	 * 	taking arguments : node * and void * key
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  POSTCONDITIONS  :	1- The item is removed from the linked list
	 * * */
	SLL_Status (*remove) (SLL* me ,void *key, int cmp(SLL_node * item , void * key));
	/* * *
	 * 	This function is used to apply a void return user function to every element in the list
	 * 	taking arguments : node *
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  POSTCONDITIONS  :
	 * * */
	SLL_Status (*traverse) (SLL* me , void func(SLL_node * item ));
	/* * *
	 * 	This function is used to all elements in the list
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  					2- There is at least 1 element in the list
	 *  POSTCONDITIONS  :	1- All elements are deleted
	 * * */
	SLL_Status (*deleteALL) (SLL* me );
	/* * *
	 * 	This function is used to reverse all elements in the list
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  					2- There is at least 1 element in the list
	 *  POSTCONDITIONS  :	1- All elements are reversed
	 * * */
	SLL_Status (*reverse) (SLL* me );
	/* * *
	 * 	This function is used to copy the Nth element in the list into the data argument
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  					2- There is at least 1 element in the list
	 *  					3- The n is positive number
	 *  POSTCONDITIONS  :	1- The data argument will be loaded with the data in the nth element if found
	 * * */
	SLL_Status (*getNth) (SLL* me , int n , SLL_node * data );
	/* * *
	 * 	This function is used to copy the Nth element from the end in the list into the data argument
	 *  PRECONDITIONS : 	1- The linked list is successfully created or an error will be returned
	 *  					2- There is at least 1 element in the list
	 *  					3- The n is positive number
	 *  POSTCONDITIONS  :	1- The data argument will be loaded with the data in the nth element if found
	 * * */
	SLL_Status (*getendNth) (SLL* me , int n , SLL_node * data );
};
/* * *
 * 	This function is used to create and initialize from the Linked list
 *  PRECONDITIONS :
 *  POSTCONDITIONS  :	1- linked list is created
 *  					2- Other functionalities are available
 * * */
SLL_Status SLL_create(SLL* me);

#endif /* SLL_H_ */
