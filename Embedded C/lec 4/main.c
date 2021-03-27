#define SYSCTL_RCGC2_R 		(*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DIR_R 	(*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R 	(*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R 	(*((volatile unsigned long *)0x400253FC))

int main(){
	SYSCTL_RCGC2_R = 0x20;
	volatile int x;
	x = 5000;
	GPIO_PORTF_DIR_R |= (1U<<3U);
	GPIO_PORTF_DEN_R |= (1U<<3U);
	while(1){
		GPIO_PORTF_DATA_R ^= (1U<<3U);
		for(x = 0 ; x < 200000 ; x++ ) ;
	}
}
