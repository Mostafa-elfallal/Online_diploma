/*
 * functions.c
 *
 *  Created on: Jan 2, 2021
 *      Author: mostafa elfallal
 */
	/*
	 * This is one file with all homework problems
	 */
#include <inttypes.h>
#include <stdio.h>
#include <string.h>
void primes(int ,int);
long long int Factorial(int );
void reverse(char [],int);
float power(float ,int);
int main(){
	int i;
	do
	{
		fflush(stdin);
		fflush(stdout);
		printf("\nEnter the problem number or 0 to end : ");
		fflush(stdout);
		scanf("%d",&i);
		if(i==1){
			// prime function
			printf("########### The prime problem ###########\n");
			printf("Enter two numbers (the intervals) : ");
			fflush(stdout);
			int a,b;
			scanf("%d %d",&a,&b);
			primes(a,b);

		}
		else if(i==2){
			printf("########### The factorial problem ###########\n");
			// factorial using recursion
			printf("Enter positive number : ");
			fflush(stdout);
			int n;
			scanf("%d",&n);
			printf("\nFactorial of %d = %"PRIu64"",n,Factorial(n));
		}
		else if(i==3){
			//reverse array of char
			printf("########### reversing sentence problem ###########\n");
			char sen[100];
			printf("Enter a sentence : ");
			fflush(stdout);
			fflush(stdin);
			gets(sen);
			fflush(stdin);
			fflush(stdout);
			reverse(sen,0);
		}
		else if(i==4){
		//power using recursion
			printf("########### The power problem ###########\n");
			float a;
			int b;
			printf("Enter base number : ");
			fflush(stdin);fflush(stdout);
			scanf("%f",&a);
			fflush(stdin);fflush(stdout);
			printf("Enter power number (positive integer) : ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&b);
			printf("%0.0f^%d = %0.0f",a,b,power(a,b));
		}
		else{
			break;
		}
	}while(1);
	printf("########### END ###########\n");
}
float power(float a, int b){
	if(b>1){
		return a*power(a,b-1);
	}
	else{
		return a;
	}
}
void reverse(char sen[],int i){
	if(sen[i]!='\0'){
		reverse(sen,i+1);
		printf("%c",sen[i]);
	}
}
long long int Factorial(int n){
	if(n>1){
		return n*Factorial(n-1);
	}
	else{
		return 1;
	}

}
void primes(int a , int b){
	// this algorithm is too much time consuming
	//can be done using Sieve algorithm which is much faster
	//but it takes more memory and needs dynamic allocation or defining the maximum input range
	int i,j;
	char flag=0;
	if (a>b){ //input checking
		a+=b;
		b=a-b;
		a-=b;
	}
	printf("Prime numbers between %d and %d are : ",a,b);
	for(i=a;i<=b;i++){
		flag=1;
		for(j=2;j*j<=i;j++){
			if(i%j==0){  	// i is divisble by j
				flag=0;
				break;
			}
		}
		if(flag){			//flag is still equal 1;
			printf("%d ",i);
		}
	}
}
