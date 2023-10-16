#include "TM4C123.h"                    // Device header

uint16_t status;
void RccConfig(void);
void GpioConfig(void);

int main(){

	RccConfig();
	SystemCoreClockUpdate();
	GpioConfig(); 

	while(1){
	status = GPIOF->DATA & 0x10;
	GPIOF->DATA = (~status>>3);
	}
}
void RccConfig(void){

	SYSCTL->RCC |= (1<<0);
	SYSCTL->RCC &= ~(1<<4);
	SYSCTL->RCC |= (1<<6);
	SYSCTL->RCC &= ~(1<<7);
	SYSCTL->RCC &= ~(1<<8);
	SYSCTL->RCC |= (1<<9);
  SYSCTL->RCC |= (1<<10);
	SYSCTL->RCC &= ~(1<<11);
	SYSCTL->RCC &= ~(1<<13);
	SYSCTL->RCC |= (1<<22);
	SYSCTL->RCC |= (0x0F<<23);
	SYSCTL->RCC2 &= ~(1<<4);
	SYSCTL->RCC2 &= ~(1<<11);
	SYSCTL->RCC2 &= ~(1<<13);
	SYSCTL->RCC2 &= ~(1<<14);
	SYSCTL->RCC2 |= (1<<31);
	SYSCTL->RCC2 |= (1<<30);
	SYSCTL->RCC2 |= (1<<22);
	SYSCTL->RCC2 &= ~(1<<23);
	SYSCTL->RCC2 |= (1<<24);
	SYSCTL->RCC2 &= ~(1<<25);
	SYSCTL->RCC2 &= ~(1<<26);
	SYSCTL->RCC2 &= ~(1<<27);
	SYSCTL->RCC2 &= ~(1<<28);	
	SYSCTL->DC1 |= (0x02<<12);
}

void GpioConfig(void){
	SYSCTL->RCGCGPIO |= (1<<5);
	GPIOF->LOCK = 0x4C4F434B;
	GPIOF->CR |= (1<<0);
	GPIOF->PUR |= (1<<4);
	GPIOF->DIR |= (1<<1);
	GPIOF->DEN |= (1<<1);
	GPIOF->DEN |= (1<<4);        
}
