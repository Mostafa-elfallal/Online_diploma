/*
 * Student_management.c
 *
 *  Created on: Apr 15, 2021
 *      Author: Mostafa ElFallal
 */
#include <string.h>
#include <stdio.h>
#include "Student_management.h"
/* * * * * * * * * * * * * * * * * * *
 * This FILE is used to implement all needed APIs for the student management system
 * * * * * * * * * * * * * * * * * * */
/*
 * for displaying the option menu
 */
void options(){
DPRINTF("=========Welcome to Student Management System===========\n");
DPRINTF("=========Here a list of the options you can choose from===========\n");
DPRINTF("1)	 Add student info. manually. \n");
DPRINTF("2)  Add student info. from Text file. \n");
DPRINTF("3)  Find student info. by roll ID. \n");
DPRINTF("4)  Find students info. by First name. \n");
DPRINTF("5)  Find students info. by course ID. \n");
DPRINTF("6)  Find total Number of students. \n");
DPRINTF("7)  Delete student info. by Roll ID. \n");
DPRINTF("8)  update student info. by Roll ID. \n");
DPRINTF("9)  Show All students info. . \n");
DPRINTF("10) exit. \n");
}
/*
 * to add students from pre-written file
 * */
void add_student_file(FIFO * buffer){
	DPRINTF("======Adding Student from text file=======\n");
	FIFO_element dummy;
	FILE * fp;
	char buff[256];
	DPRINTF("Enter the relative path of the file : ");
	gets(buff);
	fp = fopen(buff,"r");		/*open file with entered name from the user*/
	char input[50]={0};
	int buffcounter=0;
	int i;						/*iterator for all for loops*/
	while(fgets(buff,256,fp)!=0){		/*read the whole line*/
		buffcounter=0;					/*line iterator*/
		memset(input,0,50);				/*initializing the input segment with 0*/

		/*read the first segment and make it integer : ID */
		for(int i=0;buff[buffcounter]!=' ';i++){
			input[i]=buff[buffcounter++];
		}
		dummy.roll=atoi(input);
		buffcounter++;			/*skip the space*/
		/*the second segment is for the first name*/
		for(i=0;buff[buffcounter]!=' ';i++){
			dummy.fname[i]=buff[buffcounter++];
		}
		dummy.fname[i]='\0';		/*Terminator*/
		buffcounter++;				/*skip the space*/

		/*third segment is for the last name*/
		for(i=0;buff[buffcounter]!=' ';i++){
			dummy.lname[i]=buff[buffcounter++];
		}
		dummy.lname[i]='\0';		/*terminator*/
		buffcounter++;				/*skip space*/
		memset(input,0,50);			/*re initialize the input for the GPA */
		/*forth is for GPA and making it float*/
		for(int i=0;buff[buffcounter]!=' ';i++){
			input[i]=buff[buffcounter++];
		}
		dummy.GPA=atof(input);
		buffcounter++;		/*space*/
		int ccounter=0; /*course counter*/

		/*reading courses*/
		for(int i=0;buff[buffcounter]!='\0'&&i<20;i++){
				if(buff[buffcounter]>='0'&&buff[buffcounter]<='9'){
					dummy.cid[ccounter++]=buff[buffcounter]-'0';
				}
				buffcounter++;
			}

		for(int i=ccounter;i<10;i++){
				dummy.cid[i]=0;				/*all other fields are 0*/
			}

		/*is this ID exists before ? */
		if(FIFO_activateif(buffer,RL_findcon,&dummy.roll,dummyactive,1)==FIFO_NO_ERROR){
			DPRINTF("[ERROR] student with roll ID : %d can't be added\n",dummy.roll);
		}
		else{
			FIFO_enqueue(buffer,&dummy);
			DPRINTF("[INFO] student with roll ID : %d added successfully\n",dummy.roll);

		}
	}
	fclose(fp);	/*closing*/
}
/*
 * will ask you for every piece of info manually
 * */
void add_student_manually(FIFO * buffer){
	DPRINTF("======Adding Student Manually=======\n");
	FIFO_element dummy;
	char input[50];
	DPRINTF("please enter the student's Roll ID : ");
	gets(input);
	dummy.roll=atoi(input);
	DPRINTF("please enter the student's first name : ");
	gets(input);
	strcpy(dummy.fname,input);
	DPRINTF("please enter the student's last name : ");
	gets(input);
	strcpy(dummy.lname,input);
	DPRINTF("please enter the student's GPA : ");
	gets(input);
	dummy.GPA=atof(input);
	DPRINTF("please enter the student's courses list (max 10 courses) : ");
	gets(input);
	int ccounter=0; /*course counter*/
	for(int i=0;i<20;i++){
		if(input[i]>='0'&&input[i]<='9'){
			dummy.cid[ccounter++]=input[i]-'0';
		}
	}
	for(int i=ccounter;i<10;i++){
		dummy.cid[i]=0;				/*all other fields are 0*/
	}
	if(FIFO_activateif(buffer,RL_findcon,&dummy.roll,dummyactive,1)==FIFO_NO_ERROR){
		DPRINTF("[ERROR] student with roll ID : %d can't be added\n",dummy.roll);
	}
	else{
		FIFO_enqueue(buffer,&dummy);
		DPRINTF("[INFO] student with roll ID : %d added successfully\n",dummy.roll);

	}

}
/*
 * will print the student with user-input roll ID
 * */
void find_rl(FIFO * buffer ){
	DPRINTF("======Searching for a student using Roll ID=======\n");
	char input[50];
	DPRINTF("please enter the student's Roll ID : ");
	gets(input);
	int ID= atoi(input);
	if(FIFO_activateif(buffer,RL_findcon,&ID,printelement,1)==FIFO_NO_ERROR){
		/*internally done */
	}
	else{
		DPRINTF("[ERROR] student with roll ID : %d can't be found\n",ID);
	}
}
/*
 * will print all students with user-input first name
 * */
void find_fn(FIFO * buffer ){
	DPRINTF("======Searching for students using First Name=======\n");
	char input[50];
	DPRINTF("please enter the student's first name : ");
	gets(input);

	if(FIFO_activateif(buffer,FN_findcon,input,printelement,-1)==FIFO_NO_ERROR){
		/*internally done */
	}
	else{
		DPRINTF("[ERROR] student with first name : %s can't be found\n",input);
	}
}
/*
 * will print all students with user-input course
 * */
void find_c(FIFO * buffer){
	DPRINTF("======Searching for students using course ID=======\n");
	DPRINTF("[info] in this version courses ID is from 1 to 9 only\n");
	char input[50];
	DPRINTF("please enter the course ID : ");
	gets(input);
	int ID= atoi(input);
	if(FIFO_activateif(buffer,C_findcon,&ID,printelement,-1)==FIFO_NO_ERROR){
		/*internally done */
	}
	else{
		DPRINTF("[ERROR] no students registered in course with ID : %d \n",ID);
	}
}
/*
 * will print the total number of registered students
 * */
void tot_s(FIFO * buffer){
	DPRINTF("======Total students=======\n");
	DPRINTF("[info] total students registered : %d \n",FIFO_count(buffer));
	DPRINTF("[info] you can add more %d students \n",55 - FIFO_count(buffer));
}
/*
 * will delete a student with user-input roll ID
 * */
void del_s(FIFO * buffer){
	DPRINTF("======Deleting a student using Roll ID=======\n");
	char input[50];
	DPRINTF("please enter the student's Roll ID : ");
	gets(input);
	int ID= atoi(input);
	if(FIFO_deleteif(buffer,RL_findcon,&ID,1)==FIFO_NO_ERROR){
		/*internally done */
		DPRINTF("[INFO] student with roll ID : %d deleted successfully\n",ID);
	}
	else{
		DPRINTF("[ERROR] student with roll ID : %d can't be found\n",ID);
	}
}
/*
 * will update a student with user-input roll ID
 * */
void up_s(FIFO * buffer){
	DPRINTF("======Updating a student using Roll ID=======\n");
	char input[50];
	DPRINTF("please enter the student's Roll ID : ");
	gets(input);
	int ID= atoi(input);
	if(FIFO_activateif(buffer,RL_findcon,&ID,updateelement,1)==FIFO_NO_ERROR){
		/*internally done */
		DPRINTF("[INFO] student with roll ID : %d updated successfully\n",ID);

	}
	else{
		DPRINTF("[ERROR] student with roll ID : %d can't be found\n",ID);
	}
}
/*
 * will display all registered students
 * */
void show_s(FIFO * buffer){
	DPRINTF("======All registered students=======\n");
	int dummyvar;
	FIFO_activateif(buffer,dummysearch,&dummyvar,printelement,-1);
}
