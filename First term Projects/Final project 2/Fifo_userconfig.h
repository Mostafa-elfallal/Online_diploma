/*
 * Fifo_userfuncs.h
 *
 *  Created on: Apr 14, 2021
 *      Author: Mostafa ElFallal
 */
#include "stdlib.h"
#include "stdio.h"
#define DPRINTF(...) 	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);\
						}
/* * * * * * * * * * * * * * * * * * *
 * This FILE is used to declare all needed user-defined functions & data for using the FIFO in this application
 * * * * * * * * * * * * * * * * * * */
#include "FIFO.h"
#ifndef FIFO_USERCONFIG_H_
#define FIFO_USERCONFIG_H_

/*Configure the type and use FIFO_element in your code*/
struct sinfo {
	char fname[50];
	char lname[50];
	float GPA;
	int cid[10];
	int roll;
}st[55];
typedef  struct sinfo FIFO_element;

/*this function is used by the FIFO APIs to determine if a student roll ID matches*/
int RL_findcon(FIFO_element * ,void *rollID);
/*this function is used by the FIFO APIs to search if a student first name matches*/
int FN_findcon(FIFO_element * ,void *fn);
/*this function is used by the FIFO APIs to search if a student registered in specific course*/
int C_findcon(FIFO_element * a,void *cid);
/*this function does nothing but it's used as activation function for the FIFO APIs*/
int dummysearch(FIFO_element * a,void *x);
/*used for printing 1 element and used by the buffer APIs*/
void printelement(FIFO_element * a);
/*used by buffer APIs to update student data*/
void updateelement(FIFO_element * a);
/*used as activation function but it does nothing at all*/
void dummyactive(FIFO_element * a);
#endif /* FIFO_USERCONFIG_H_ */
