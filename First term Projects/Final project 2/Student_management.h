/*
 * Student_management.h
 *
 *  Created on: Apr 15, 2021
 *      Author: Mostafa ElFallal
 */
/* * * * * * * * * * * * * * * * * * *
 * This FILE is used to declare all needed APIs for student management system application
 * * * * * * * * * * * * * * * * * * */
#include "Fifo_userconfig.h"
#ifndef STUDENT_MANAGEMENT_H_
#define STUDENT_MANAGEMENT_H_
#include <stdio.h>
#define DPRINTF(...) 	{fflush(stdin);\
						fflush(stdout);\
						printf(__VA_ARGS__);\
						fflush(stdin);\
						fflush(stdout);\
						}
/*
 * for displaying the option menu
 */
void options();
/*
 * to add students from pre-written file
 * */
void add_student_file(FIFO *);
/*
 * will ask you for every piece of info manually
 * */
void add_student_manually(FIFO *);
/*
 * will print the student with user-input roll ID
 * */
void find_rl(FIFO *);
/*
 * will print all students with user-input first name
 * */
void find_fn(FIFO *);
/*
 * will print all students with user-input course
 * */
void find_c(FIFO *);
/*
 * will print the total number of registered students
 * */
void tot_s(FIFO *);
/*
 * will delete a student with user-input roll ID
 * */
void del_s(FIFO *);
/*
 * will update a student with user-input roll ID
 * */
void up_s(FIFO *);
/*
 * will display all registered students
 * */
void show_s(FIFO *);

#endif /* STUDENT_MANAGEMENT_H_ */
