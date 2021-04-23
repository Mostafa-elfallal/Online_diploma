/*
 * main.c
 *
 *  Created on: Apr 14, 2021
 *      Author: Mostafa ElFallal
 */
#include "stdlib.h"
#include "stdio.h"
#include "FIFO.h"
#include "Student_management.h"
#define DPRINTF(...) 	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);\
						}

void (*OPTarr[]) (FIFO *)={
	add_student_manually,add_student_file,find_rl,find_fn,find_c,tot_s,del_s,up_s,show_s
};

int main(){
options();
int opt;
FIFO Students;
FIFO_Creat(&Students,st,55);
while(1){
	DPRINTF("===============================\n");
	DPRINTF("Please Enter option number : ");
	scanf("%d",&opt);
	if(opt >=0&&opt<=9){
		OPTarr[opt-1](&Students);
	}
	else if(opt == 10){
		DPRINTF("Bye Bye :)");
		exit(1);
	}
	else{
		DPRINTF("Invalid Option number \n");
	}
}
}


