#include <stdio.h>
int main(){
	int m=29;
	printf("Address of m : 0x%u\nValue of m : %d\n",&m,m);
	
	int *ab=&m;
	printf("Now ab is assigned with address of m.\n");
	printf("Address of pointer ab : 0x%u\n content of pointer ab : 0x%u\n",&ab,ab);
	printf("The value in the content of ab is : %d\n",*ab);
	m=34;
	printf("The value of m assigned to 34 now.\n");
	printf("Address of pointer ab : 0x%u\n content of pointer ab : 0x%u\n",&ab,ab);
	printf("The value in the content of ab is : %d\n",*ab);
	*ab=7;
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	printf("Address of m : 0x%u\nValue of m : %d",&m,m);
}