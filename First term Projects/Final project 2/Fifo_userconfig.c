/*
 * Fifo_userfuncs.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Mostafa ElFallal
 */

/* * * * * * * * * * * * * * * * * * *
 * This FILE is used to implement all needed user-defined functions declared in Fifo_userconfig.h
 * * * * * * * * * * * * * * * * * * */
#include <string.h>
#include "Fifo_userconfig.h"
int RL_findcon(FIFO_element * a,void * key){
	if(a->roll==*(int * )key){				/*is this roll ID yours ?*/
		return 1;
	}
	return 0;
}

int FN_findcon(FIFO_element * a,void *fn){
	if(strcmp(a->fname,(char*)fn)==0){ /*is this First name yours ?*/
			return 1;
		}
		return 0;
}

int C_findcon(FIFO_element * a,void *cid){
	for(int i =0;i<10;i++){		/*did you registered in that course ?*/
		if(a->cid[i]!=0){
			if(a->cid[i]==*(int*)cid)
				return 1;
		}
	}

	return 0;
}

int dummysearch(FIFO_element * a,void * dummy){
	//do nothing						/*yes you need me*/
	return 1;
}
void dummyactive(FIFO_element * a){

}
void printelement(FIFO_element * a){
	DPRINTF("Roll ID : %d \n",a->roll);
	DPRINTF("First name : %s \n",a->fname);
	DPRINTF("Last name : %s \n",a->lname);
	DPRINTF("GPA : %f \n",a->GPA);
	DPRINTF("courses list :");
	for(int i=0;i<10;i++){
		if(a->cid[i] != 0)
		DPRINTF("%d ",a->cid[i]);
	}
	DPRINTF("\n");
	DPRINTF("======================================\n");
}
void updateelement(FIFO_element * a){
	char input[50];
	printelement(a);
	DPRINTF("Choose one of the next options :- \n");
	DPRINTF("1) update first name \n");
	DPRINTF("2) update last name \n");
	DPRINTF("3) update GPA \n");
	DPRINTF("4) update roll Id \n");
	DPRINTF("5) update course list \n");
	DPRINTF("Enter your choice :");
	gets(input);
	int ID= atoi(input);
	float GP;
	switch(ID){
	case 1:
		DPRINTF("Enter the new First name : ");
		gets(input);
		strcpy(a->fname,input);
		break;
	case 2:
		DPRINTF("Enter the new Last name : ");
		gets(input);
		strcpy(a->lname,input);
		break;
	case 3:
		DPRINTF("Enter the new GPA : ");
		gets(input);
		GP=atof(input);
		a->GPA=GP;
		break;
	case 4:
		DPRINTF("Enter the new roll ID : ");
		gets(input);
		ID=atoi(input);
		a->roll=ID;
		break;
	case 5:
		DPRINTF("please enter the student's courses list (max 10 courses) : ");
		gets(input);
		int ccounter=0;
		for(int i=0;i<20;i++){
			if(input[i]>='0'&&input[i]<='9'){
				a->cid[ccounter++]=input[i]-'0';
			}
		}
		for(int i=ccounter;i<10;i++){
			a->cid[i]=0;
		}
		break;
	default:
		DPRINTF("[ERROR] invalid option .\n");
		break;
	}
}
