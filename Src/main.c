

#include <stdint.h>
#include "main.h"
#include "stm32l432xx.h"

//macros' definitions
#define TIM1_PSC_VAL ((uint16_t)0)
#define TIM1_ARR_VAL ((uint8_t)200-1)

#define TIM1_PWM_DutyCycle ((uint8_t)100)


#define TIM2_PSC_VAL ((uint16_t)4000-1)
#define TIM2_ARR_VAL ((uint8_t)(1-1))

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

	void SysClockCFG_Init();
	void TIM1_PWM_Init();
	void TIM2_Init();
	void I2C1_Init();
	void SPI1_Init();
	void GPIO_Init();








    /* Loop forever */
	for(;;);
}

//XYZ_INIT() FUNCS SECTION

void SysClockCFG_Init(void){

}

void TIM1_PWM_Init(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 									//enabling GPIOA for PWM output
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;

	GPIOA->MODER &= ~ ((3<<16)|(3<<22));									//clearing bits 16,17 and 22,23
	GPIOA->MODER |=((1<<23)|(1<<17)); 										//setting pins PA_8 and PA_11 to "Alt Func" mode

	GPIOA->AFR[1] &= ~ ((0xF<<0)|(0xF<<12));								//clearing bits 0-4 and 12-15
	GPIOA->AFR[1] |= ((1<<0)|(1<<12)); 										//enabled AF1 Alt Function mode for PA_8(TIM1C1) and PA_11(TIM1C4)

	//ENABLE PA8(IPWM_A) + PA11(IPWM_B) FOR L9110S PWM OUTPUT

	TIM1->PSC = (TIM1_PSC_VAL);
	TIM1->ARR = (TIM1_ARR_VAL);

	TIM1->CCMR1 = TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE;	/*Enabled TIM1C1 PWM Mode 1 (0110) + Channel 1 preload(OC1PE)
																			(in case of changing the value of CCR, like changing the brightness)*/

	TIM1->CCMR2 = TIM_CCMR2_OC4M_2 | TIM_CCMR2_OC4M_1 | TIM_CCMR2_OC4PE;	/*Enabled TIM1C4 PWM Mode 1 (0110) + Channel 4 preload(OC4PE)
																			(in case of changing the value of CCR, like changing the brightness)*/

	TIM1->CCR1 = TIM1_PWM_DutyCycle;										//Duty cycle of PWM is (Vwanted / Vsource)* ARRVal
	TIM1->CCR4 = TIM1_PWM_DutyCycle;										//In my case (2,5V / 5V)*200 = 100

	TIM1->CCER = TIM_CCER_CC1E |TIM_CCER_CC4E ;								//Enabling output for Channels 1(PA_8) and 4(PA_11)

	TIM1->BDTR = TIM_BDTR_MOE;												//Enabling MOE (as it's advanced timer, it has 1 more layer of protection)

	TIM1->CR1 = TIM_CR1_CEN;												//Enabling counter itself, from this moment Counter starts, I suppose


}

void TIM2_Init(void){
	RCC->APB1ENR1 |= RCC_APB1ENR1_TIM2EN;										//enabling TIM2 peripheral
	TIM2->PSC = TIM2_PSC_VAL;
	TIM2->ARR = (TIM2_ARR_VAL);
}

void I2C1_Init(void){
	RCC->APB1ENR1 |= RCC_APB1ENR1_I2C1EN;										//enabling I2C1 peripheral
}

void SPI1_Init(void){
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;											//enabling SPI1 peripheral
}

void GPIO_Init(void){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN; 										//enabling GPIOA for PWM output


}



//XYZ_ISR() FUNCS SECTION
void TIM2_IRQHandler (void){

}
