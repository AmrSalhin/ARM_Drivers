#include "..\inc\NVIC.h"
#include "../../../Library/stm32f401rct6.h"


#define NVIC    ((NVIC_REG_t*)NVIC_BASE_ADDRESS)

#define AIRCR   *((uint32_t*)0xE000ED0C)

/****************************************************************
 * @fn Enable_IRQ
 * @brief Enable specific interrupt
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void Enable_IRQ(IRQ_t irq)
{
    NVIC->ISER[irq / 32] = 1 << (irq % 32); 
}

/****************************************************************
 * @fn Disable_IRQ
 * @brief Disable specific interrupt
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void Disable_IRQ(IRQ_t irq)
{
    NVIC->ICER[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn SetPendingFlag
 * @brief Set Pending Flag
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void SetPendingFlag(IRQ_t irq)
{
    NVIC->ISPR[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn CLearPendingFlag
 * @brief CLear Pending Flag
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void CLearPendingFlag(IRQ_t irq)
{
    NVIC->ICPR[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn GetActiveFlag
 * @brief Get Active falg status
 * @param[in] IRQ_t number of IRQ 
 * @retval Active Flag 
*/
uint8_t GetActiveFlag(IRQ_t irq)
{
    return((NVIC->IABR[irq / 32] & (1<<(irq % 32))>>(irq % 32)));
}

/****************************************************************
 * @fn SetPriority
 * @brief Set interrupt Priority
 * @param[in] IRQ_t number of IRQ 
 * @param[in] priority interrupet priority Max 15 
 * @retval none 
*/
void SetPriority(IRQ_t irq, uint8_t priority)
{   
    /*Set priority*/
    NVIC->IPR[irq] = (priority <<4);
}

/****************************************************************
 * @fn SCB_setPriorityGroup
 * @brief Set interrupt Groups Number
 * @param[in] GROUP_NUM_t number of Groups 
 * @retval none 
*/
void SCB_setPriorityGroup(GROUP_NUM_t number)
{
    /*Must write 5FA from 16th to write any thing in this rgister*/
    uint32_t value = 0x05FA0000 | (number<<8);
    AIRCR =   value;
}