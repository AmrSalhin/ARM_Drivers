#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

/*************************      GPIO Registers Bits Definition UNION      **************************/
typedef enum 
  {
  MODER0  ,
  MODER1  ,
  MODER2  ,
  MODER3  ,
  MODER4  ,
  MODER5  ,
  MODER6  ,
  MODER7  ,
  MODER8  ,
  MODER9  ,
  MODER10 ,
  MODER11 ,
  MODER12 ,
  MODER13 ,
  MODER14 ,
  MODER15 ,

  }MODER_REG_BIT;

typedef enum 
  {
  OT0  ,
  OT1  ,
  OT2  ,
  OT3  ,
  OT4  ,
  OT5  ,
  OT6  ,
  OT7  ,
  OT8  ,
  OT9  ,
  OT10 ,
  OT11 ,
  OT12 ,
  OT13 ,
  OT14 ,
  OT15 ,
  }OTYPER_REG_BIT;


typedef enum 
  {
  OSPEEDR0  ,
  OSPEEDR1  ,
  OSPEEDR2  ,
  OSPEEDR3  ,
  OSPEEDR4  ,
  OSPEEDR5  ,
  OSPEEDR6  ,
  OSPEEDR7  ,
  OSPEEDR8  ,
  OSPEEDR9  ,
  OSPEEDR10 ,
  OSPEEDR11 ,
  OSPEEDR12 ,
  OSPEEDR13 ,
  OSPEEDR14 ,
  OSPEEDR15 ,
  }OSPEEDR_REG_BIT;


typedef enum 
  {
  PUPDR0  ,
  PUPDR1  ,
  PUPDR2  ,
  PUPDR3  ,
  PUPDR4  ,
  PUPDR5  ,
  PUPDR6  ,
  PUPDR7  ,
  PUPDR8  ,
  PUPDR9  ,
  PUPDR10 ,
  PUPDR11 ,
  PUPDR12 ,
  PUPDR13 ,
  PUPDR14 ,
  PUPDR15 ,
  }PUPDR_REG_BIT;

typedef enum 
  {
  IDR0  ,
  IDR1  ,
  IDR2  ,
  IDR3  ,
  IDR4  ,
  IDR5  ,
  IDR6  ,
  IDR7  ,
  IDR8  ,
  IDR9  ,
  IDR10 ,
  IDR11 ,
  IDR12 ,
  IDR13 ,
  IDR14 ,
  IDR15 ,
  }IDR_REG_BIT;


typedef enum 
  {
  ODR0  ,
  ODR1  ,
  ODR2  ,
  ODR3  ,
  ODR4  ,
  ODR5  ,
  ODR6  ,
  ODR7  ,
  ODR8  ,
  ODR9  ,
  ODR10 ,
  ODR11 ,
  ODR12 ,
  ODR13 ,
  ODR14 ,
  ODR15 ,
  }ODR_REG_BIT;

typedef enum
  {
   BS0  ,
   BS1  ,
   BS2  ,
   BS3  ,
   BS4  ,
   BS5  ,
   BS6  ,
   BS7  ,
   BS8  ,
   BS9  ,
   BS10 ,
   BS11 ,
   BS12 ,
   BS13 ,
   BS14 ,
   BS15 ,
   BR0  ,
   BR1  ,
   BR2  ,
   BR3  ,
   BR4  ,
   BR5  ,
   BR6  ,
   BR7  ,
   BR8  ,
   BR9  ,
   BR10 ,
   BR11 ,
   BR12 ,
   BR13 ,
   BR14 ,
   BR15 ,
  }BSRR_REG_BIT;


typedef enum
  {
   AFRL0  ,
   AFRL1  ,
   AFRL2  ,
   AFRL3  ,
   AFRL4  ,
   AFRL5  ,
   AFRL6  ,
   AFRL7  ,
   AFRL8  ,
   AFRL9  ,
   AFRL10 ,
   AFRL11 ,
   AFRL12 ,
   AFRL13 ,
   AFRL14 ,
   AFRL15 ,
  }AFR_REG_BIT;


#endif