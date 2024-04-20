#ifndef RCC_H_
#define RCC_H_

/**********************************************/
/**************   Includes    *****************/
/**********************************************/
#include <stdint.h>
#include "..\..\..\Library\stm32f401rct6.h"
#include "..\..\..\Library\BIT_MATH.h"

/**********************************************/
/**************  Data Types   *****************/
/**********************************************/
 


typedef enum{
   HSI,
   HSE,
   PLL
}CLK_Type;

typedef enum{
   PLL_MUL_BY2,
   PLL_MUL_BY3,
   PLL_MUL_BY4,
   PLL_MUL_BY5,
   PLL_MUL_BY6,
   PLL_MUL_BY7,
   PLL_MUL_BY8,
   PLL_MUL_BY9,
   PLL_MUL_BY10,
   PLL_MUL_BY11,
   PLL_MUL_BY12,
   PLL_MUL_BY13,
   PLL_MUL_BY14,
   PLL_MUL_BY15,
   PLL_MUL_BY16
}PLL_MUL;

typedef enum
{
    PLL_DIV_BY2,
    PLL_DIV_BY4,
    PLL_DIV_BY6,
    PLL_DIV_BY8,
}PLL_DIV;

typedef enum{
    OFF,
    ON
}CLK_STATUS;

typedef enum{
    GPIOA,
    GPIOB,
    GPIOC,
    GPIOD,
    GPIOE,
    GPIOH = 7,
    CRC = 12,
    DMA1 = 21,
    DMA2,
}AHB1_PERIPHERAL;

typedef enum{
    OTGFS = 7,
}AHB2_PERIPHERAL;

typedef enum{
    TIM2,
    TIM3,
    TIM4,
    TIM5,
    WWDG = 11,
    SPI2 = 14,
    SPI3,
    USART2 = 17,
    I2C1 = 21,
    I2C2,
    I2C3,
    PWR = 28,
}APB1_PERIPHERAL;

typedef enum{
    TIM1,
    USART1 = 4,
    USART6,
    ADC1 = 8,
    SDIO = 11,
    SPI1,
    SPI4,
    SYSCFG,
    TIM9 = 16,
    TIM10,
    TIM11
}APB2_PERIPHERAL;

typedef struct 
{
    CLK_Type clk;
    /*multiplcation factor range from 192 to 432*/
    uint16_t pllN;
    PLL_DIV pllP;
}PLL_CFGR;



 


/**********************************************/
/************  Local Functions   **************/
/**********************************************/



/**********************************************/
/**************  Functions    *****************/
/**********************************************/

/*turn CLK on and off*/
STATUS RCC_SetClk_Status(CLK_Type clk_type, CLK_STATUS clk_status);

/*Choose System CLK*/
STATUS RCC_Set_SysClk(CLK_Type clk_type);

/*Set HSE & HSI division for pll input (PLLM)
The software has to set these bits correctly to ensure that the VCO input frequency 
ranges from 1 to 2 MHz
*/
STATUS RCC_HSE_HSI_division(uint8_t div);

/*Set PLL configurations
1- choose multiplication N factor  192 ≤ PLLN ≤ 432
The software has to set these bits correctly to ensure that the VCO output 
frequency is between 192 and 432 MHz
2- choose SRC CLK(HSI,HSE)
3- choose division P factor  2,4,6,8
The software has to set these bits correctly not to exceed 84 MHz
*/
STATUS RCC_Pll_config(const PLL_CFGR* pll_cfgr);

/*
GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH,CRC,DMA1,DMA2
*/
STATUS RCC_AHB1_peripheralEnable(AHB1_PERIPHERAL peripheral);

STATUS RCC_AHB1_peripheralDisable(AHB1_PERIPHERAL peripheral);

/*
OTGFS
*/
STATUS RCC_AHB2_peripheralEnable(AHB2_PERIPHERAL peripheral);

STATUS RCC_AHB2_peripheralDisable(AHB2_PERIPHERAL peripheral);


/*
TIM2,TIM3,TIM4,TIM5,WWDG,SPI2,SPI3,USART2 ,I2C1,I2C2,I2C,3PWR
*/
STATUS RCC_APB1_peripheralEnable(APB1_PERIPHERAL peripheral);

STATUS RCC_APB1_peripheralDisable(APB1_PERIPHERAL peripheral);

/*
TIM1,USART1,USART6,ADC1,SDIO,SPI1,SPI4,SYSCFG,TIM9,TIM10,TIM11
*/
STATUS RCC_APB2_peripheralEnable(APB2_PERIPHERAL peripheral);

STATUS RCC_APB2_peripheralDisable(APB2_PERIPHERAL peripheral);

#endif
