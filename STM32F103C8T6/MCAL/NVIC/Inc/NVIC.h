#ifndef NVIC_H_
#define NVIC_H_

#include "stdint.h"

/*********************
 * @typedef IRQ_t
 * 
*/
typedef enum{
    NVIC_WWDG,
    NVIC_PVD,
    NVIC_TAMPER,
    NVIC_RTC,
    NVIC_FLASH,
    NVIC_RCC,
    NVIC_EXTI0,
    NVIC_EXTI1,
    NVIC_EXTI2,
    NVIC_EXTI3,
    NVIC_EXTI4,
    NVIC_DMA1_Channel1,
    NVIC_DMA1_Channel2,
    NVIC_DMA1_Channel3,
    NVIC_DMA1_Channel4,
    NVIC_DMA1_Channel5,
    NVIC_DMA1_Channel6,
    NVIC_DMA1_Channel7,
    NVIC_ADC1_2,
    NVIC_USART1 = 37,
    NVIC_USART2,
    NVIC_USART3,
}IRQ_t;

/*********************
 * @typedef GROUP_NUM_t
 * 
*/
typedef enum
{
    SIXTEEN_GROUPS_ZERO_SUB = 3,
    EIGHT_GROUPS_TWO_SUB,
    FOUR_GROUPS_FOUR_SUB,
    TWO_GROUPS_EIGHT_SUB,
    ONE_GROUP_SIXTEEN_SUB
}GROUP_NUM_t;


void Enable_IRQ(IRQ_t irq);
void Disable_IRQ(IRQ_t irq);
void SetPendingFlag(IRQ_t irq);
void CLearPendingFlag(IRQ_t irq);
uint8_t GetActiveFlag(IRQ_t irq);
void SetPriority(IRQ_t irq, uint8_t priority);
void SCB_setPriorityGroup(GROUP_NUM_t number);



#endif // NVIC_H_
