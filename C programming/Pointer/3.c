#include <stdio.h>
#include <string.h>
int main(){
	char str[1000];
	printf("Input a string : ");
	fflush(stdout);
	fflush(stdin);
	gets(str);
	int len = strlen(str);
	char *p=str;
	printf("Reverse of the string is : ");
	for(;len>=0;len--){
		printf("%c",p[len]);
	}
}