#ifndef RCC_H_
#define RCC_H_

/**********************************************/
/**************   Includes    *****************/
/**********************************************/
#include <stdint.h>
#include "..\stm32f103c8t6.h"

/**********************************************/
/**************  Data Types   *****************/
/**********************************************/
 

typedef enum{
   HSI,
   HSE,
   PLL
}CLK_Type;

// typedef struct
// {
//    PLL_PRE pllPre;
//    APB_PRE apbPre;
//    AHB_PRE ahbpre;
// }HSE_config;

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
   PLL_MUL_BY16,
   PLL_MUL_BY16
}PLL_MUL;

typedef enum
{
    PLL_HSE_DIV_BY1,
    PLL_HSE_DIV_BY2
}PLL_PRE;

// typedef enum
// {
//     PLL_HSE_DIV_BY1,
//     PLL_HSE_DIV_BY2
// }APB_PRE;

// typedef enum
// {
//     PLL_HSE_DIV_BY1,
//     PLL_HSE_DIV_BY2
// }AHB_PRE;

typedef enum{
    OFF,
    ON
}CLK_STATUS;

typedef enum{
    DMA1,
    DMA2,
    SRAM,
    FLITF,
    FSMC,
    SDIO
}AHB_PERIPHERAL;

typedef enum{
    TIM2,
    TIM3,
    TIM4,
    TIM5,
    TIM6,
    TIM7,
    TIM12,
    TIM13,
    TIM14,
    WWDG,
    SPI2,
    SPI3,
    USART2,
    USART3,
    USART4,
    USART5,
    I2C1,
    I2C2,
    USB,
    CAN,
    BKP,
    PWR,
    DAC
}APB1_PERIPHERAL;

typedef enum{
    AFIO,
    IOPA,
    IOPB,
    IOPC,
    IOPD,
    IOPE,
    IOPF,
    IOPG,
    ADC1,
    ADC2,
    TIM1,
    SPI1,
    TIM8,
    USART1,
    ADC3,
    TIM9,
    TIM10,
    TIM11
}APB2_PERIPHERAL;


 
RCC_t* RCC =  (RCC_t*) RCC_BASE_ADDRESS;


/**********************************************/
/************  Local Functions   **************/
/**********************************************/



/**********************************************/
/**************  Functions    *****************/
/**********************************************/

/*turn clk on and off*/
STATUS RCC_SetClk_Status(CLK_Type clk_type, CLK_STATUS clk_status);

/*Choose System Clk*/
STATUS RCC_Set_SysClk(CLK_Type clk_type);

/*Set HSE congigurations*/
STATUS RCC_HSE_config();

/*Set PLL congigurations
1- choose multiplication factor (2,3,4,5,6,7,8,9,10,11,12,13,14,15,16)
2- choose src clk(HSI,HSE)*/
STATUS RCC_Pll_config(PLL_MUL mul, CLK_Type clk);

/*
DMA1,DMA2,SRAM,FLITF,FSMC,SDIO
*/
STATUS RCC_AHB_peripheralEnable(AHB_PERIPHERAL peripheral);
/*
DMA1,DMA2,SRAM,FLITF,FSMC,SDIO
*/
STATUS RCC_AHB_peripheralDisable(AHB_PERIPHERAL peripheral);
/*
TIM2,TIM3,TIM4,TIM5,TIM6,TIM7,TIM12,TIM13,
TIM14,WWDG,SPI2,SPI3,USART2,USART3,USART4,
USART5,I2C1,I2C2,USB,CAN,BKP,PWR,DAC
*/
STATUS RCC_APB1_peripheralEnable(APB1_PERIPHERAL peripheral);
/*
TIM2,TIM3,TIM4,TIM5,TIM6,TIM7,TIM12,TIM13,
TIM14,WWDG,SPI2,SPI3,USART2,USART3,USART4,
USART5,I2C1,I2C2,USB,CAN,BKP,PWR,DAC
*/
STATUS RCC_APB1_peripheralDisable(APB1_PERIPHERAL peripheral);
/*
AFIO,IOPA,IOPB,IOPC,IOPD,IOPE,IOPF,IOPG,
ADC1,ADC2,TIM1,SPI1,TIM8,USART1,ADC3,TIM9,TIM10,TIM11
*/
STATUS RCC_APB2_peripheralEnable(APB2_PERIPHERAL peripheral);
/*
AFIO,IOPA,IOPB,IOPC,IOPD,IOPE,IOPF,IOPG,
ADC1,ADC2,TIM1,SPI1,TIM8,USART1,ADC3,TIM9,TIM10,TIM11
*/
STATUS RCC_APB2_peripheralDisable(APB2_PERIPHERAL peripheral);

#endif