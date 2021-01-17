#include <stdio.h>
int main(){
	struct student {
		char name[50];
		int age;
	}s={	"Mostafa elfallal",22};;
	struct student *p_s=&s;

	printf("Employee name : %s\nID : %d",p_s->name,p_s->age);
}