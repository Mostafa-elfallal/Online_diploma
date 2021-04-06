/*
 * SLL.c
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */
#include "SLL.h"
#include <stdlib.h>
typedef struct {
	SLL_node 	* SLL_head;
	int 	SLL_count;	//number of nodes in the linked list
}head;
/**************************************************************************************************/
SLL_Status getNth(SLL* me , int n,  SLL_node * data){
	if(n > ((head *)(me->privates))->SLL_count|| n<1){
		return SLL_NOTFOUND_ERROR;
	}
	if(!data)
		return SLL_NOMEMORY_ERROR;
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	for(int i = 1 ;i<n;i++){
		temp=temp->next;
	}

	*data = *temp;
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status getendNth(SLL* me , int n,  SLL_node * data){
	if(n > ((head *)(me->privates))->SLL_count|| n<1){
		return SLL_NOTFOUND_ERROR;
	}
	if(!data)
		return SLL_NOMEMORY_ERROR;
	SLL_node* slow= ((head *)(me->privates))->SLL_head ;
	SLL_node* fast= ((head *)(me->privates))->SLL_head ;
	for(int i = 1 ; i<n ; i++){
		if(fast->next)
			fast=fast->next;
		else{
			return SLL_NOTFOUND_ERROR;
		}
	}
	for(int i = 0 ;fast->next;i++){
		slow=slow->next;
		fast=fast->next;
	}

	*data = *slow;
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status add (SLL* me , SLL_node * data){
	/*go until you reach the last element in the linked list*/
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	for(int i = 0;i<((head *)(me->privates))->SLL_count -1 ;i++){
		temp=temp->next;
	}
	/*receive data*/
	SLL_node* item =(SLL_node*)malloc(sizeof(SLL_node));
	*item = *data;
	/*set the connections again*/
	/*but check if it was starting the chain first */
	if(((head *)(me->privates))->SLL_count == 0){
		((head *)(me->privates))->SLL_head = item;
		item->next=0;
		((head *)(me->privates))->SLL_count ++;
		return SLL_NO_ERROR;
	}
	/*there was items before */
	temp->next=item;
	item->next = 0;
	((head *)(me->privates))->SLL_count ++;
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status remove(SLL* me ,void * key, int cmp(SLL_node * item , void * key)){
	if(((head *)(me->privates))->SLL_count == 0){
		return SLL_EMPTY_ERROR;
	}
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	SLL_node* prev=temp;
	for(int i = 0;i<((head *)(me->privates))->SLL_count  ;i++){
		if(cmp(temp,key)){
			if(i==0){
				((head *)(me->privates))->SLL_head = temp->next;
			}
			prev->next=temp->next;
			free(temp);
			((head *)(me->privates))->SLL_count --;
			return SLL_NO_ERROR;
		}
		prev = temp;
		temp=temp->next;
	}
	return SLL_NOTFOUND_ERROR;
}
/**************************************************************************************************/
SLL_Status pop(SLL* me , SLL_node * data){
	/*is it empty ?*/
	if(((head * )(me->privates))->SLL_count == 0)
		return SLL_EMPTY_ERROR;

	/*is there only one item ?*/
	if (((head * )(me->privates))->SLL_count == 1){
		*data = *((head *)(me->privates))->SLL_head ;
		free(((head *)(me->privates))->SLL_head);
		((head *)(me->privates))->SLL_head = 0;
		((head *)(me->privates))->SLL_count =0;
		return SLL_NO_ERROR;
	}
	/*Start with the head*/
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	/*go to last element*/
	for(int i = 0;i<((head *)(me->privates))->SLL_count -2 ;i++){
		temp=temp->next;
	}
	/*now temp is the element before the last element*/
	*data = * (temp->next);
	free(temp->next);
	temp->next=0;
	((head *)(me->privates))->SLL_count --;
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status traverse(SLL* me , void func(SLL_node * item)){
	if(((head *)(me->privates))->SLL_count == 0){
		return SLL_EMPTY_ERROR;
	}
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	for(int i = 0;i<((head *)(me->privates))->SLL_count  ;i++){
		func(temp);
		temp=temp->next;
	}
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status deleteALL(SLL* me ){
	if(((head *)(me->privates))->SLL_count == 0){
		return SLL_EMPTY_ERROR;
	}
	SLL_node* next;
	SLL_node* temp= ((head *)(me->privates))->SLL_head ;
	for(int i = 0;i<((head *)(me->privates))->SLL_count  ;i++){
		next=temp->next;
		free(temp);
		temp = next;
	}
	((head *)(me->privates))->SLL_head = 0;
	((head *)(me->privates))->SLL_count = 0;
	return SLL_NO_ERROR;
}
/**************************************************************************************************/
SLL_Status reverse (SLL * me ){
	if(((head *)(me->privates))->SLL_count == 0){
		return SLL_EMPTY_ERROR;
	}
	SLL_node* prev=0;
	SLL_node* current=((head *)(me->privates))->SLL_head;

	SLL_node* next;
	if(current->next)
	next=current->next;
	for(int i = 0;i<((head *)(me->privates))->SLL_count  ;i++){
		current->next=prev;
		prev=current;
		current=next;
		if(next->next)
		next=next->next;
	}
	((head *)(me->privates))->SLL_head = prev;
	return SLL_NO_ERROR;
}


/**************************************************************************************************/
SLL_Status SLL_create(SLL* me){
	if(!(me->privates = malloc(sizeof(head)))){
		return SLL_NOMEMORY_ERROR;
	}
	((head *)(me->privates))->SLL_head = 0;
	((head *)(me->privates))->SLL_count = 0;
	me->add =	add;
	me->pop = pop;
	me->traverse=traverse;
	me->remove = remove;
	me->deleteALL= deleteALL;
	me->reverse = reverse;
	me->getNth = getNth;
	me->getendNth=getendNth;
	return SLL_NO_ERROR;
}
