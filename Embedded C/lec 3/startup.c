/*
startup.c
Eng Mostafa-Elfallal
*/
#include <stdint.h>

void Reset_Handler();
void Default_Handler(){
	Reset_Handler();
}
void NMI_Handler() __attribute__((weak,alias("Default_Handler")));
extern unsigned int _stack_top;
uint32_t vectors[] __attribute__((section(".vectors"))) = {
	(uint32_t)&_stack_top,
	(uint32_t)&Reset_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&NMI_Handler,
	(uint32_t)&NMI_Handler
	
	
};
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
void Reset_Handler(){
	int i;
	unsigned int data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char * P_src= (unsigned char*)&_E_text;
	unsigned char * P_dst= (unsigned char*)&_S_data;
	for(i=0;i<data_size;i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_src++);
	}
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	P_dst = (unsigned char*)&_S_bss;
	for(i=0;i<bss_size;i++){
		*((unsigned char*)P_dst++) = (unsigned char) 0;
	}
	
	
	main();
}