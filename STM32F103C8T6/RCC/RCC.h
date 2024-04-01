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
 typedef union 
 {
    uint32_t    reg;

    struct CR_REG_BIT
    {
        uint32_t HSION      :1;
        uint32_t HSIRDY     :1;
        uint32_t reserved_1 :1;
        uint32_t HSITRIM    :5;
        uint32_t HSICAL     :8;
        uint32_t HSEON      :1;
        uint32_t HSERDY     :1;
        uint32_t HSEBYP     :1;
        uint32_t CSSON      :1;
        uint32_t reserved_2 :4;
        uint32_t PLLON      :1;
        uint32_t PLLRDY     :1;
        uint32_t reserved_3 :6;
    }bit;
    
 }RCC_CR_t;
 typedef union 
 {
    uint32_t    reg;
    
    struct CFGR_REG_BIT
    {
        uint32_t SW         :2;
        uint32_t SWS        :2;
        uint32_t HPRE       :4;
        uint32_t PPRE1      :3;
        uint32_t PPRE2      :3;
        uint32_t ADCPRE     :2;
        uint32_t PLLSRC     :1;
        uint32_t PLLXTPRE   :1;
        uint32_t PLLMUL     :4;
        uint32_t USBPRE     :1;
        uint32_t reserved_1 :1;
        uint32_t MCO        :3;
        uint32_t reserved_2 :5;
    }bit;
 }RCC_CFGR_t;
  typedef union 
 {
    uint32_t    reg;
    
    struct CIR_REG_BIT
    {
        uint32_t LSIRDYF    :1;
        uint32_t LSERDYF    :1;
        uint32_t HSIRDYF    :1;
        uint32_t HSERDYF    :1;
        uint32_t PLLRDYF    :1;
        uint32_t reserved_1 :2;
        uint32_t CSSF       :1;
        uint32_t LSIRDYIE   :1;
        uint32_t LSERDYIE   :1;
        uint32_t HSIRDYIE   :1;
        uint32_t HSERDYIE   :1;
        uint32_t PLLRDYIE   :1;
        uint32_t reserved_2 :3;
        uint32_t LSIRDYC    :1;
        uint32_t LSERDYC    :1;
        uint32_t HSIRDYC    :1;
        uint32_t HSERDYC    :1;
        uint32_t PLLRDYC    :1;
        uint32_t reserve_3  :2;
        uint32_t CSSC       :1;
        uint32_t reserved_4 :8;
    }bit;
 }RCC_CIR_t;
  typedef union 
 {
    uint32_t    reg;
    
    struct APB2RSTR_REG_BIT
    {
        uint32_t AFIORST    :1;
        uint32_t reserved_1 :1;
        uint32_t IOPARST    :1;
        uint32_t IOPBRST    :1;
        uint32_t IOPCRST    :1;
        uint32_t IOPDRST    :1;
        uint32_t IOPERST    :1;
        uint32_t IOPFRST    :1;
        uint32_t IOPGRST    :1;
        uint32_t ADC1RST    :1;
        uint32_t ADC2RST    :1;
        uint32_t TIM1RST    :1;
        uint32_t SPI1RST    :1;
        uint32_t TIM8RST    :1;
        uint32_t USART1RST  :1;
        uint32_t ADC3RST    :1;
        uint32_t reserved_2 :3;
        uint32_t TIM9RST    :1;
        uint32_t TIM10RST   :1;
        uint32_t TIM11RST   :1;
        uint32_t reserved_3 :10;
    }bit;
 }RCC_APB2RSTR_t;
  typedef union
 {
    uint32_t    reg;
    
    struct APB1RSTR_REG_BIT
    {
        uint32_t TIM2RST    :1;
        uint32_t TIM3RST    :1;
        uint32_t TIM4RST    :1;
        uint32_t TIM5RST    :1;
        uint32_t TIM6RST    :1;
        uint32_t TIM7RST    :1;
        uint32_t TIM12RST   :1;
        uint32_t TIM13RST   :1;
        uint32_t TIM14RST   :1;
        uint32_t reserved_1 :2;
        uint32_t WWDGRST    :1;
        uint32_t reserved_2 :2;
        uint32_t SPI2RST    :1;
        uint32_t SPI3RST    :1;
        uint32_t reserved_3 :1;
        uint32_t USART2RST  :1;
        uint32_t USART3RST  :1;
        uint32_t USART4RST  :1;
        uint32_t USART5RST  :1;
        uint32_t I2C1RST    :1;
        uint32_t I2C2RST    :1;
        uint32_t USBRST     :1;
        uint32_t reserved_4 :1;
        uint32_t CANRST     :1;
        uint32_t reserved_5 :1;
        uint32_t BKPRST     :1;
        uint32_t PWRRST     :1;
        uint32_t DACRST     :1;
        uint32_t reserved_6 :2;
    }bit;
 }RCC_APB1RSTR_t;
  typedef union 
 {
   uint32_t    reg;
    
    struct AHBENR_REG_BIT
    {
        uint32_t DMA1EN     :1;
        uint32_t DMA2EN     :1;
        uint32_t SRAMEN     :1;
        uint32_t reserved_1 :1;
        uint32_t FLITFEN    :1;
        uint32_t reserved_2 :1;
        uint32_t CRCEN      :1;
        uint32_t reserved_3 :1;
        uint32_t FSMCEN     :1;
        uint32_t reserved_4 :1;
        uint32_t SDIOEN     :1;
        uint32_t reserved_5 :21;
    }bit;
 }RCC_AHBENR_t;
  typedef union 
 {
   uint32_t    reg;
    
    struct APB2ENR_REG_BIT
    {
        uint32_t AFIOEN     :1;
        uint32_t reserved_1 :1;
        uint32_t IOPAEN     :1;
        uint32_t IOPBEN     :1;
        uint32_t IOPCEN     :1;
        uint32_t IOPDEN     :1;
        uint32_t IOPEEN     :1;
        uint32_t IOPFEN     :1;
        uint32_t IOPGEN     :1;
        uint32_t ADC1EN     :1;
        uint32_t ADC2EN     :1;
        uint32_t TIM1EN     :1;
        uint32_t SPI1EN     :1;
        uint32_t TIM8EN     :1;
        uint32_t USART1EN   :1;
        uint32_t ADC3EN     :1;
        uint32_t reserved_2 :3;
        uint32_t TIM9EN     :1;
        uint32_t TIM10EN    :1;
        uint32_t TIM11EN    :1;
        uint32_t reserved_3 :10;
    }bit;
 }RCC_APB2ENR_t;
  typedef union 
 {
   uint32_t    reg;
    
    struct APB1ENR_REG_BIT
    {
        uint32_t TIM2EN     :1;
        uint32_t TIM3EN     :1;
        uint32_t TIM4EN     :1;
        uint32_t TIM5EN     :1;
        uint32_t TIM6EN     :1;
        uint32_t TIM7EN     :1;
        uint32_t TIM12EN    :1;
        uint32_t TIM13EN    :1;
        uint32_t TIM14EN    :1;
        uint32_t reserved_1 :2;
        uint32_t WWDGEN     :1;
        uint32_t reserved_2 :2;
        uint32_t SPI2EN     :1;
        uint32_t SPI3EN     :1;
        uint32_t reserved_3 :1;
        uint32_t USART2EN   :1;
        uint32_t USART3EN   :1;
        uint32_t USART4EN   :1;
        uint32_t USART5EN   :1;
        uint32_t I2C1EN     :1;
        uint32_t I2C2EN     :1;
        uint32_t USBEN      :1;
        uint32_t reserved_4 :1;
        uint32_t CANEN      :1;
        uint32_t reserved_5 :1;
        uint32_t BKPEN      :1;
        uint32_t PWREN      :1;
        uint32_t DACEN      :1;
        uint32_t reserved_6 :2;
    }bit;
 }RCC_APB1ENR_t;
  typedef union 
 {
   uint32_t    reg;
    
    struct BDCR_REG_BIT
    {
        uint32_t LSEON      :1;
        uint32_t LSERDY     :1;
        uint32_t LSEBYP     :1;
        uint32_t reserved_1 :5;
        uint32_t RTCSEL     :2;
        uint32_t reserved_2 :5;
        uint32_t RTCEN      :1;
        uint32_t BDRST      :1;
        uint32_t reserved_3 :15;
    }bit;
 }RCC_BDCR_t;
  typedef union
 {
   uint32_t    reg;
    
    struct BDCR_REG_BIT
    {
        uint32_t LSION      :1;
        uint32_t LSIRDY     :1;
        uint32_t reserved_1 :22;
        uint32_t RMVF       :1;
        uint32_t reserved_2 :1;
        uint32_t PINRSTF    :1;
        uint32_t PORRSTF    :1;
        uint32_t SFTRSTF    :1;
        uint32_t IWDGRSTF   :1;
        uint32_t WWDGRSTF   :1;
        uint32_t LPWRRSTF   :1;
    }bit;
 }RCC_CSR_t;
 
 
 typedef struct 
 {
    volatile RCC_CR_t RCC_CR;
    volatile RCC_CFGR_t RCC_CFGR;
    volatile RCC_CIR_t RCC_CIR;
    volatile RCC_APB2RSTR_t RCC_APB2RSTR;
    volatile RCC_APB1RSTR_t RCC_APB1RSTR;
    volatile RCC_AHBENR_t RCC_AHBENR;
    volatile RCC_APB2ENR_t RCC_APB2ENR;
    volatile RCC_APB1ENR_t RCC_APB1ENR;
    volatile RCC_BDCR_t RCC_BDCR;
    volatile RCC_CSR_t RCC_CSR;

 }RCC_t;

typedef enum{
   HSI,
   HSE,
   PLL
}CLK_Type;

typedef enum{
    OFF,
    ON
}CLK_STATUS;

typedef enum{
    NOT_READY,
    READY
}CLK_FLAG;

typedef enum{
   NOK,
   OK
}STATUS;
 
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





#endif