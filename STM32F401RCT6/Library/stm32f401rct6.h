#ifndef STM32F401RCT6_H_
#define STM32F401RCT6_H_

#include "stdint.h"



/*************************         Memories Base Addresses         **************************/

#define FLASH_BASE_ADDRESS          0x08000000UL

#define SRAM_BASE_ADDRESS           0x20000000UL


/*************************      AHB1 peripheral Base Addresses      **************************/


#define DMA2_BASE_ADDRESS           0x40026400UL
#define DMA1_BASE_ADDRESS           0x40026000UL
#define FLASH_INTERFCE_BASE_ADDRESS 0x40023C00UL
#define RCC_BASE_ADDRESS            0x40023800UL
#define CRC_BASE_ADDRESS            0x40023000UL
#define GPIOH_BASE_ADDRESS          0x40021C00UL
#define GPIOE_BASE_ADDRESS          0x40021000UL
#define GPIOD_BASE_ADDRESS          0x40020C00UL
#define GPIOC_BASE_ADDRESS          0x40020800UL
#define GPIOB_BASE_ADDRESS          0x40020400UL
#define GPIOA_BASE_ADDRESS          0x40020000UL

/*************************      AHB2 peripheral Base Addresses      **************************/

#define USB_OTG_FS_BASE_ADDRESS     0x50000000UL

/*************************      APB1 peripheral Base Addresses      **************************/

#define PWR_BASE_ADDRESS            0x40007000UL
#define I2C3_BASE_ADDRESS           0x40005C00UL
#define I2C2_BASE_ADDRESS           0x40005800UL
#define I2C1_BASE_ADDRESS           0x40005400UL
#define USART2_BASE_ADDRESS         0x40004400UL
#define I2C3EXT_BASE_ADDRESS        0x40004000UL
#define SPI3_I2C3_BASE_ADDRESS      0x40003C00UL
#define SPI2_I2C2_BASE_ADDRESS      0x40003800UL
#define I2C2EXT_BASE_ADDRESS        0x40003400UL
#define IWDG_BASE_ADDRESS           0x40003000UL
#define WWDG_BASE_ADDRESS           0x40002C00UL
#define RTC_BKP_BASE_ADDRESS        0x40002800UL
#define TIM5_BASE_ADDRESS           0x40000C00UL
#define TIM4_BASE_ADDRESS           0x40000800UL
#define TIM3_BASE_ADDRESS           0x40000400UL
#define TIM2_BASE_ADDRESS           0x40000000UL

/*************************      APB2 peripheral Base Addresses      **************************/

#define TIM11_BASE_ADDRESS          0x40014800UL
#define TIM10_BASE_ADDRESS          0x40014400UL
#define TIM9_BASE_ADDRESS           0x40014000UL
#define EXTI_BASE_ADDRESS           0x40013C00UL
#define SYSCFG_BASE_ADDRESS         0x40013800UL
#define SPI4_I2C4_BASE_ADDRESS      0x40013400UL
#define SPI1_BASE_ADDRESS           0x40013000UL
#define SDIO_BASE_ADDRESS           0x40012C00UL
#define ADC1_BASE_ADDRESS           0x40012000UL
#define USART6_BASE_ADDRESS         0x40011400UL
#define USART1_BASE_ADDRESS         0x40011000UL
#define TIM8_BASE_ADDRESS           0x40010400UL
#define TIM1_BASE_ADDRESS           0x40010000UL

/******************************    DATA TYPE       *******************************/


#define TIME_OUT        500

typedef enum{
   NOK,
   TIMEOUT,
   OK
}STATUS;

typedef enum{
    NOT_READY,
    READY
}FLAG;

typedef enum{
    DISABLE,
    ENABLE
}PERIFERAL_STATUS;



/*************************      RCC Registers Bits Definition UNION      **************************/

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
        uint32_t PLLI2SON   :1;
        uint32_t PLLI2SRDY  :1;
    }bit;
    
 }RCC_CR_t;

 typedef union 
 {
    uint32_t    reg;
    
    struct PLL_CFGR_BIT
    {
        uint32_t PLLM       :6;
        uint32_t PLLN       :9;
        uint32_t reserved_1 :1;
        uint32_t PLLP       :2;
        uint32_t reserved_2 :4;
        uint32_t PLLSRC     :1;
        uint32_t reserved_3 :1;
        uint32_t PLLQ       :4;
    }bit;
 }RCC_PLL_CFGR_t;

 typedef union 
 {
    uint32_t    reg;
    
    struct CFGR_REG_BIT
    {
        uint32_t SW         :4;
        uint32_t HPRE       :4;
        uint32_t reserved_1 :2;
        uint32_t PPRE1      :3;
        uint32_t PPRE2      :3;
        uint32_t RTCPRE     :5;
        uint32_t MCO1       :2;
        uint32_t I2SSRC     :1;
        uint32_t MCO1PRE    :3;
        uint32_t MCO2PRE    :3;
        uint32_t MCO2       :2;

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
        uint32_t PLLI2SRDYF :1;
        uint32_t reserved_1 :1;
        uint32_t CSSF       :1;
        uint32_t LSIRDYIE   :1;
        uint32_t LSERDYIE   :1;
        uint32_t HSIRDYIE   :1;
        uint32_t HSERDYIE   :1;
        uint32_t PLLRDYIE   :1;
        uint32_t PLLI2SRDYIE :1;
        uint32_t reserved_2 :2;
        uint32_t LSIRDYC    :1;
        uint32_t LSERDYC    :1;
        uint32_t HSIRDYC    :1;
        uint32_t HSERDYC    :1;
        uint32_t PLLRDYC    :1;
        uint32_t PLLI2SRDYC :1;
        uint32_t reserve_3  :1;
        uint32_t CSSC       :1;
    }bit;
 }RCC_CIR_t;

   typedef union 
 {
    uint32_t    reg;
    
    struct AHB1RSTR_REG_BIT
    {
        uint32_t GPIOARST   :1;
        uint32_t GPIOBRST   :1;
        uint32_t GPIOCRST   :1;
        uint32_t GPIODRST   :1;
        uint32_t GPIOERST   :1;
        uint32_t reserved_1 :2;
        uint32_t GPIOHRST   :1;
        uint32_t reserved_2 :4;
        uint32_t CRCRST     :1;
        uint32_t reserved_3 :8;
        uint32_t DMA1RST    :1;
        uint32_t DMA2RST    :1;
    }bit;
 }RCC_AHB1RSTR_t;

   typedef union 
 {
    uint32_t    reg;
    
    struct AHB2RSTR_REG_BIT
    {
        uint32_t reserved_1 :7;
        uint32_t OTGFSRST   :1;
    }bit;
 }RCC_AHB2RSTR_t;

  typedef union
 {
    uint32_t    reg;
    
    struct APB1RSTR_REG_BIT
    {
        uint32_t TIM2RST    :1;
        uint32_t TIM3RST    :1;
        uint32_t TIM4RST    :1;
        uint32_t TIM5RST    :1;
        uint32_t reserved_1 :7;
        uint32_t WWDGRST    :1;
        uint32_t reserved_2 :2;
        uint32_t SPI2RST    :1;
        uint32_t SPI3RST    :1;
        uint32_t reserved_3 :1;
        uint32_t USART2RST  :1;
        uint32_t reserved_4 :3;
        uint32_t I2C1RST    :1;
        uint32_t I2C2RST    :1;
        uint32_t I2C3RST    :1;
        uint32_t reserved_5 :4;
        uint32_t PWRRST     :1;
    }bit;
 }RCC_APB1RSTR_t;

  typedef union 
 {
    uint32_t    reg;
    
    struct APB2RSTR_REG_BIT
    {
        uint32_t TIM1RST    :1;
        uint32_t reserved_1 :3;
        uint32_t USART1RST  :1;
        uint32_t USART6RST  :1;
        uint32_t reserved_2 :2;
        uint32_t ADC1RST    :1;
        uint32_t reserved_3 :2;
        uint32_t SDIORST    :1;
        uint32_t SPI1RST    :1;
        uint32_t SPI4RST    :1;
        uint32_t SYSCFGRST  :1;
        uint32_t reserved_4 :1;
        uint32_t TIM9RST    :1;
        uint32_t TIM10RST   :1;
        uint32_t TIM11RST   :1;
    }bit;
 }RCC_APB2RSTR_t;

  typedef union 
 {
   uint32_t    reg;
    
    struct AHB1ENR_REG_BIT
    {
        uint32_t GPIOAEN   :1;
        uint32_t GPIOBEN   :1;
        uint32_t GPIOCEN   :1;
        uint32_t GPIODEN   :1;
        uint32_t GPIOEEN   :1;
        uint32_t reserved_1 :2;
        uint32_t GPIOHEN   :1;
        uint32_t reserved_2 :4;
        uint32_t CRCEN     :1;
        uint32_t reserved_3 :8;
        uint32_t DMA1EN    :1;
        uint32_t DMA2EN    :1;
    }bit;
 }RCC_AHB1ENR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct AHB2ENR_REG_BIT
    {
        uint32_t reserved_1 :7;
        uint32_t OTGFSEN   :1;
    }bit;
 }RCC_AHB2ENR_t;

  typedef union 
 {
   uint32_t    reg;
    
    struct APB1ENR_REG_BIT
    {
        uint32_t TIM2EN    :1;
        uint32_t TIM3EN    :1;
        uint32_t TIM4EN    :1;
        uint32_t TIM5EN    :1;
        uint32_t reserved_1 :7;
        uint32_t WWDGEN    :1;
        uint32_t reserved_2 :2;
        uint32_t SPI2EN    :1;
        uint32_t SPI3EN    :1;
        uint32_t reserved_3 :1;
        uint32_t USART2EN  :1;
        uint32_t reserved_4 :3;
        uint32_t I2C1EN    :1;
        uint32_t I2C2EN    :1;
        uint32_t I2C3EN    :1;
        uint32_t reserved_5 :4;
        uint32_t PWREN     :1;
    }bit;
 }RCC_APB1ENR_t;

  typedef union 
 {
   uint32_t    reg;
    
    struct APB2ENR_REG_BIT
    {
        uint32_t TIM1EN     :1;
        uint32_t reserved_1 :3;
        uint32_t USART1EN  :1;
        uint32_t USART6EN  :1;
        uint32_t reserved_2 :2;
        uint32_t ADC1EN    :1;
        uint32_t reserved_3 :2;
        uint32_t SDIOEN    :1;
        uint32_t SPI1EN    :1;
        uint32_t SPI4EN    :1;
        uint32_t SYSCFGEN  :1;
        uint32_t reserved_4 :1;
        uint32_t TIM9EN    :1;
        uint32_t TIM10EN   :1;
        uint32_t TIM11EN   :1;
    }bit;
 }RCC_APB2ENR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct AHB1LENR_REG_BIT
    {
        uint32_t GPIOALEN   :1;
        uint32_t GPIOBLEN   :1;
        uint32_t GPIOCLEN   :1;
        uint32_t GPIODLEN   :1;
        uint32_t GPIOELEN   :1;
        uint32_t reserved_1 :2;
        uint32_t GPIOHLEN   :1;
        uint32_t reserved_2 :4;
        uint32_t CRCLEN     :1;
        uint32_t reserved_3 :8;
        uint32_t DMA1LEN    :1;
        uint32_t DMA2LEN    :1;
    }bit;
 }RCC_AHB1LENR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct AHB2LENR_REG_BIT
    {
        uint32_t reserved_1 :7;
        uint32_t OTGFSLEN   :1;
    }bit;
 }RCC_AHB2LENR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct APB1LENR_REG_BIT
    {
        uint32_t TIM2LEN    :1;
        uint32_t TIM3LEN    :1;
        uint32_t TIM4LEN    :1;
        uint32_t TIM5LEN    :1;
        uint32_t reserved_1 :7;
        uint32_t WWDGLEN    :1;
        uint32_t reserved_2 :2;
        uint32_t SPI2LEN    :1;
        uint32_t SPI3LEN    :1;
        uint32_t reserved_3 :1;
        uint32_t USART2LEN  :1;
        uint32_t reserved_4 :3;
        uint32_t I2C1LEN    :1;
        uint32_t I2C2LEN    :1;
        uint32_t I2C3LEN    :1;
        uint32_t reserved_5 :4;
        uint32_t PWRLEN     :1;
    }bit;
 }RCC_APB1LENR_t;

  typedef union 
 {
   uint32_t    reg;
    
    struct APB2LENR_REG_BIT
    {
        uint32_t TIM1LEN     :1;
        uint32_t reserved_1 :3;
        uint32_t USART1LEN  :1;
        uint32_t USART6LEN  :1;
        uint32_t reserved_2 :2;
        uint32_t ADC1LEN    :1;
        uint32_t reserved_3 :2;
        uint32_t SDIOLEN    :1;
        uint32_t SPI1LEN    :1;
        uint32_t SPI4LEN    :1;
        uint32_t SYSCFGLEN  :1;
        uint32_t reserved_4 :1;
        uint32_t TIM9LEN    :1;
        uint32_t TIM10LEN   :1;
        uint32_t TIM11LEN   :1;
    }bit;
 }RCC_APB2LENR_t;

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
    }bit;
 }RCC_BDCR_t;
  typedef union
 {
   uint32_t    reg;
    
    struct CSR_REG_BIT
    {
        uint32_t LSION      :1;
        uint32_t LSIRDY     :1;
        uint32_t reserved_1 :22;
        uint32_t RMVF       :1;
        uint32_t BORRSTF    :1;
        uint32_t PINRSTF    :1;
        uint32_t PORRSTF    :1;
        uint32_t SFTRSTF    :1;
        uint32_t IWDGRSTF   :1;
        uint32_t WWDGRSTF   :1;
        uint32_t LPWRRSTF   :1;
    }bit;
 }RCC_CSR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct SSCGR_REG_BIT
    {
        uint32_t MODPER     :13;
        uint32_t INCSTEP    :15;
        uint32_t reserved_1 :2;
        uint32_t SPREADSEL  :1;
        uint32_t SSCGEN     :1;
    
    }bit;
 }RCC_SSCGR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct PLLI2S_CFGR_REG_BIT
    {
        uint32_t reserved_1 :6;
        uint32_t PLLI2SN    :9;
        uint32_t reserved_2 :13;
        uint32_t PLLI2SR    :3;
        }bit;
 }RCC_PLLI2S_CFGR_t;

   typedef union 
 {
   uint32_t    reg;
    
    struct DCKCFGR_REG_BIT
    {
        uint32_t reserved_1 :24;
        uint32_t TIMPRE     :1;
    }bit;
 }RCC_DCKCFGR_t;
 
 /*************************      RCC Registers Definition Strucre      **************************/

 typedef struct 
 {
    volatile RCC_CR_t RCC_CR;
    volatile RCC_PLL_CFGR_t RCC_PLL_CFGR;
    volatile RCC_CFGR_t RCC_CFGR;
    volatile RCC_CIR_t RCC_CIR;
    volatile RCC_AHB1RSTR_t RCC_AHB1RSTR;
    volatile RCC_AHB2RSTR_t RCC_AHB2RSTR;
    volatile uint32_t reserved_1[2];
    volatile RCC_APB1RSTR_t RCC_APB1RSTR;
    volatile RCC_APB2RSTR_t RCC_APB2RSTR;
    volatile uint32_t reserved_2[2];
    volatile RCC_AHB1ENR_t RCC_AHB1ENR;
    volatile RCC_AHB2ENR_t RCC_AHB2ENR;
    volatile uint32_t reserved_3[2];
    volatile RCC_APB1ENR_t RCC_APB1ENR;
    volatile RCC_APB2ENR_t RCC_APB2ENR;
    volatile uint32_t reserved_4[2];
    volatile RCC_AHB1LENR_t RCC_AHB1LENR;
    volatile RCC_AHB2LENR_t RCC_AHB2LENR;
    volatile uint32_t reserved_5[2];
    volatile RCC_APB1LENR_t RCC_APB1LENR;
    volatile RCC_APB2LENR_t RCC_APB2LENR;
    volatile uint32_t reserved_6[2];
    volatile RCC_BDCR_t RCC_BDCR;
    volatile RCC_CSR_t RCC_CSR;
    volatile uint32_t reserved_7[2];
    volatile RCC_SSCGR_t RCC_SSCGR;
    volatile RCC_PLLI2S_CFGR_t RCC_PLLI2S_CFGR;
    volatile uint32_t reserved_8;
    volatile RCC_DCKCFGR_t RCC_DCKCFGR;

 }RCC_t;

/*************************      RCC peripheral Definition       **************************/

#define RCC         ((RCC_t *) RCC_BASE_ADDRESS)



/*************************       GPIO Registers Definition Strucre        **************************/

typedef struct 
{
  volatile  uint32_t  MODER;
  volatile  uint32_t  OTYPER;
  volatile  uint32_t  OSPEEDR;
  volatile  uint32_t  PUPDR;
  volatile  uint32_t  IDR;
  volatile  uint32_t  ODR;
  volatile  uint32_t  BSRR;
  volatile  uint32_t  LCKR;
  volatile  uint64_t  AFR;

}GPIO_REG_t;

/*************************           GPIO peripheral Definition           **************************/

#define GPIOA    ((GPIO_REG_t *)GPIOA_BASE_ADDRESS)
#define GPIOB    ((GPIO_REG_t *)GPIOB_BASE_ADDRESS)
#define GPIOC    ((GPIO_REG_t *)GPIOC_BASE_ADDRESS)
#define GPIOD    ((GPIO_REG_t *)GPIOD_BASE_ADDRESS)
#define GPIOE    ((GPIO_REG_t *)GPIOE_BASE_ADDRESS)
#define GPIOH    ((GPIO_REG_t *)GPIOH_BASE_ADDRESS)

#endif