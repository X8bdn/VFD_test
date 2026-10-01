

#include <stdint.h>
#include "main.h"
#include "stm32l432xx.h"

//XYZ_Init(); func prototypes section
void SysClockCFG_Init(void);
void TIM1_PWM_Init(void);
void TIM2_Init(void);
void I2C1_Init(void);
void SPI1_Init(void);
void GPIO_Init(void);


//XYZ_InterruptFunc(); func prototypes section
void TIM2_IRQHandler(void);

int main(void)
{

	/*RCC_APB1ENR_t_1 volatile *const pAPB1Reg = (RCC_APB1ENR_t_1*) 0x40021058 ;
	RCC_APB2ENR_t volatile *const pAPB2Reg = (RCC_APB2ENR_t*) 0x40021060 ;
	RCC_AHB2ENR_t volatile *const pAHB2Reg = (RCC_AHB2ENR_t*)  0x4002104C;
	GPIOx_MODE_t volatile *const pGPIOA_moder = (GPIOx_MODE_t*) 0x48000000;
	GPIOx_ODR_t  volatile *const pGPIOA_odr = (GPIOx_ODR_t*) 0x48000014;

	РОБОЧІ ЗАПИСКИ:

	у мене застосовуються:
	-I2C1
	-TIM2
	-TIM1(PWM Generator)
	-SPI1
	-GPIOA


	*/

	void SysClockCFG_Init(void);
	void TIM1_PWM_Init(void);
	void TIM2_Init(void);
	void I2C1_Init(void);
	void SPI1_Init(void);
	void GPIO_Init(void);








    /* Loop forever */
	for(;;);
}

//XYZ_INIT() FUNCS SECTION

void SysClockCFG_Init(void){

}

void TIM1_PWM_Init(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 	//enabling GPIOA for PWM output
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;		//enabling TIM1 peripheral( NO PWM GENERATION YET)
	GPIOA->MODER |=((1<<23)|(1<<17)); 		//setting pins PA_8 and PA_11 to "Alt Func" mode
	GPIOA->AFR[1] |= ((1<<0)|(1<<12)); 		//enabled AF1 Alt Function mode for PA_8(TIM1C1) and PA_11(TIM1C4)
	//ENABLE PA8(IPWM_A) + PA11(IPWM_B) FOR L9110S PWM OUTPUT
}

void TIM2_Init(void){
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;		//enabling TIM2 peripheral
}

void I2C1_Init(void){
	RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN;	//enabling I2C1
}

void SPI1_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;		//enabling SPI1
}

void GPIO_Init(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 	//enabling GPIOA for PWM output


}



//XYZ_ISR() FUNCS SECTION
void TIM2_IRQHandler (void){

}
