#include "uart.h"
unsigned char msg[200]="Mostafa Elfallal";
void main(){
	Uart_Send_String(msg);
}