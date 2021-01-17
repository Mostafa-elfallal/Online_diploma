#include <stdio.h>
int main(){
	int m='A';
	int i =0;
	int *p=&m;
	for(;i<26;i++){
		printf("%c\t",(*p)++);
	}
}