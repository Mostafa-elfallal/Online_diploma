/*
 * main.c
 *
 *  Created on: Mar 30, 2021
 *      Author: Darsh
 */
#include "SLL.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define DPRINTF(...) 	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);\
						}
int cmp(SLL_node * item , void * key){
	if(item->ID == *(int *)key){
		return 1;
	}
	return 0;
}
void print(SLL_node * item){
	DPRINTF("Student ID :  %d\n\n",item->ID);
	DPRINTF("Student name :  %s\n\n",item->name);
	DPRINTF("Student Height :  %f\n\n",item->height);

}
int main(){
	SLL list;
	SLL_create(&list);
	SLL_node student;
	char temp[40];
	while(1){
		DPRINTF("===============================================\n");
		DPRINTF("\t Choose one of the following options \n");
		DPRINTF("\t 1: Add a student \n");
		DPRINTF("\t 2: Delete a student \n");
		DPRINTF("\t 3: view all students \n");
		DPRINTF("\t 4: Delete all students \n");
		DPRINTF("\t 5: Reverse all records \n");
		DPRINTF("\t 6: Find Nth student \n");
		DPRINTF("\t 7: Find Nth student from the end \n");
		DPRINTF("\t 8: Exit \n");
		DPRINTF("Enter option number : ");
		gets(temp);
		DPRINTF("===============================================\n");
		switch(atoi(temp)){
		case 1:
			DPRINTF("Adding student\n");
			DPRINTF("Enter student ID : ");
			gets(temp);
			student.ID=atoi(temp);
			DPRINTF("Enter student Name : ");
			gets(student.name);
			DPRINTF("Enter student height : ");
			gets(temp);
			student.height=atof(temp);
			list.add(&list,&student);
			break;
		case 2:
			DPRINTF("removing student\n");
			DPRINTF("Enter student ID : ");
			gets(temp);
			student.ID=atoi(temp);
			list.remove(&list,&student.ID,cmp);
			break;
		case 3:
			DPRINTF("viewing all students\n");
			list.traverse(&list,print);
			break;
		case 4:
			DPRINTF("deleting all students\n");
			list.deleteALL(&list);
			break;
		case 5:
			DPRINTF("reversing all students\n");
			list.reverse(&list);
			break;
		case 6:
			DPRINTF("finding Nth student \n");
			DPRINTF("Enter N : ");
			gets(temp);
			student.ID=atoi(temp);
			list.getNth(&list,student.ID,&student);
			print(&student);
			break;
		case 7:
			DPRINTF("finding Nth student from the end\n");
			DPRINTF("Enter N : ");
			gets(temp);
			student.ID=atoi(temp);
			list.getendNth(&list,student.ID,&student);
			print(&student);
			break;
		case 8:
			exit(1);
			break;
		default:
			DPRINTF("Invalid option \n");
			break;
		}
	}

}

