/*
 * main.h
 *
 *  Created on: Sep 21, 2026
 *      Author: troll
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdint.h>

typedef struct{
		uint32_t tim2_en : 1;
		uint32_t tim3_en : 1;
		uint32_t  : 2;
		uint32_t tim6_en : 1;
		uint32_t tim7_en : 1;
		uint32_t  : 3;
		uint32_t lcd_en : 1;
		uint32_t rtcapb_en : 1;
		uint32_t wwdg_en : 1;
		uint32_t  : 2;
		uint32_t spi2_en : 1;
		uint32_t spi3_en : 1;
		uint32_t  : 1;
		uint32_t usart2_en : 1;
		uint32_t usart3_en : 1;
		uint32_t usart4_en : 1;
		uint32_t  : 1;
		uint32_t i2c1_en : 1;
		uint32_t i2c2_en : 1;
		uint32_t i2c3_en : 1;
		uint32_t crs_en : 1;
		uint32_t can1_en : 1;
		uint32_t usbfs_en : 1;
		uint32_t  : 1;
		uint32_t pwr_en : 1;
		uint32_t dac1_en : 1;
		uint32_t opamp_en : 1;
		uint32_t lptim1_en : 1;


}RCC_APB1ENR_t_1;

typedef struct{
		uint32_t syscfg_en : 1;
		uint32_t	: 6;
		uint32_t fw_en : 1;
		uint32_t	: 2;
		uint32_t sdmmc1_en : 1;
		uint32_t tim1_en : 1;
		uint32_t spi1_en : 1;
		uint32_t	: 1;
		uint32_t usart1_en : 1;
		uint32_t	: 1;
		uint32_t tim15_en : 1;
		uint32_t tim16_en : 1;
		uint32_t	: 3;
		uint32_t sai1_en : 1;
		uint32_t	: 2;
		uint32_t dfsdm1_en : 1;
		uint32_t	: 7;

}RCC_APB2ENR_t;

/* typedef struct{
	uint32_t gpioa_en : 1;
		uint32_t gpiob_en : 1;
		uint32_t gpioc_en : 1;
		uint32_t gpiod_en : 1;
		uint32_t gpioe_en : 1;
		uint32_t  : 2;
		uint32_t gpioh_en : 1;			IF DMA OR OTHER THINGS NEEDED I'LL COME BACK
		uint32_t  : 5;
		uint32_t adc_en: 1;
		uint32_t  : 2;
		uint32_t aes_en : 1;
		uint32_t  : 1;
		uint32_t rng_en : 1;
		uint32_t  : 13;
}RCC_AHB1ENR_t;		 */

typedef struct{
	uint32_t gpioa_en : 1;
		uint32_t gpiob_en : 1;
		uint32_t gpioc_en : 1;
		uint32_t gpiod_en : 1;
		uint32_t gpioe_en : 1;
		uint32_t  : 2;
		uint32_t gpioh_en : 1;
		uint32_t  : 5;
		uint32_t adc_en: 1;
		uint32_t  : 2;
		uint32_t aes_en : 1;
		uint32_t  : 1;
		uint32_t rng_en : 1;
		uint32_t  : 13;
}RCC_AHB2ENR_t;

typedef	struct
{
	uint32_t mode0 : 2;
	uint32_t mode1 : 2;
	uint32_t mode2 : 2;
	uint32_t mode3 : 2;
	uint32_t mode4 : 2;
	uint32_t mode5 : 2;
	uint32_t mode6 : 2;
	uint32_t mode7 : 2;
	uint32_t mode8 : 2;
	uint32_t mode9 : 2;
	uint32_t mode10 : 2;
	uint32_t mode11 : 2;
	uint32_t mode12 : 2;
	uint32_t mode13 : 2;
	uint32_t mode14 : 2;
	uint32_t mode15: 2;
}GPIOx_MODE_t;

typedef struct
{
	uint32_t od0 : 1 ;
	uint32_t od1 : 1 ;
	uint32_t od2 : 1 ;
	uint32_t od3 : 1 ;
	uint32_t od4 : 1 ;
	uint32_t od5 : 1 ;
	uint32_t od6 : 1 ;
	uint32_t od7 : 1 ;
	uint32_t od8 : 1 ;
	uint32_t od9 : 1 ;
	uint32_t od10 : 1 ;
	uint32_t od11 : 1 ;
	uint32_t od12 : 1 ;
	uint32_t od13 : 1 ;
	uint32_t od14 : 1 ;
	uint32_t od15 : 1 ;
	uint32_t : 16;

}GPIOx_ODR_t;

#endif /* MAIN_H_ */
