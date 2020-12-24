/*
 * Transpose_matrix.c
 *
 *  Created on: Dec 24, 2020
 *      Author: mostafa elfallal
 */
#include <stdio.h>
void main(){
	printf("This program takes matrix and outputs the transpose\n\r");
	int rows,columns;
	int a[10][10];
	int i,j;
	printf("Enter the number of rows of matrix(max 10): ");
	fflush(stdout);
	scanf("%d",&rows);
	printf("Enter the number of columns of matrix(max 10): ");
	fflush(stdout);
	scanf("%d",&columns);
	printf("\nEnter elements of matrix:\n");
	//taking matrix
	for(i=0;i<rows;i++){
		for(j=0;j<columns;j++){
			printf("Enter element a%d%d: ",i+1,j+1);
			fflush(stdout);
			scanf("%d",&a[i][j]);
		}
	}
	//printing entered matrix
	printf("\nEntered matrix:\n");
	for(i=0;i<rows;i++){
			for(j=0;j<columns;j++){
				printf("%d\t",a[i][j]);
			}
			printf("\n\r");
		}
	//printing transpose
	printf("\nTranspose of matrix:\n");
	for(i=0;i<columns;i++){
		for(j=0;j<rows;j++){
			printf("%d\t",a[j][i]);
			}
		printf("\n\r");
		}
}

