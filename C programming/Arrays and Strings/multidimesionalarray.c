/*
 * multidimesionalarray.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
#include "stdlib.h"
void main(){
	printf("this program finds the sum of two matrices of order 2*2\n");
	float mat1[2][2];
	float mat2[2][2];
	printf("Enter the elements of 1st matrix :\n");//
	int i; //outer loop iterator
	int j;	// inner loop iterator
	char input[100];
	// taking first mat from user
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%s",input);
			mat1[i][j]=atof(input);
		}
	}
	// taking second mat from user
	printf("Enter the elements of 2nd matrix :\n");
	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				printf("Enter b%d%d: ",i+1,j+1);
				fflush(stdout);
				scanf("%s",input);
				mat2[i][j]=atof(input);
			}
		}
	// printing summation
	printf("\nSum of matrices\n");
	for(i=0;i<2;i++){
			for(j=0;j<2;j++){
				printf("%.1f\t",mat1[i][j]+mat2[i][j]);
			}
			printf("\n");
		}
}

