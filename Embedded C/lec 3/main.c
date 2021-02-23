/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

typedef unsigned int vuint32_t;
#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
#define RCC_APB2ENR	*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH	*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(vuint32_t *)(GPIOA_BASE + 0x0C)
volatile char bss[100];
volatile char data[100]={1,2,3};
char const ro[100]={1,2,3};
int main(){
	int i;
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH 	&= 0xff0fffff;
	GPIOA_CRH	|=	0x00200000;
	while(1){
		GPIOA_ODR ^= (1<<13);
		for(i =0;i<5000;i++);
	}
}
