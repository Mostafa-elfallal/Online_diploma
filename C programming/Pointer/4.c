#include <stdio.h>
int main(){
	int arr[5];
	int i;
	printf("Input 5 number of elements in the array :\n");
	for(i=0;i<5;i++)
	{
		printf("element - %d : ",i+1);
		fflush(stdout);
		scanf("%d",arr+i);
	}
	int * ptr =arr;
	ptr=ptr+4;
	printf("The elements of array in reverse order are :\n");
	for(i=5;i>0;i--)
	{
		printf("element - %d : %d\n",i,(*ptr)--);
	}
}