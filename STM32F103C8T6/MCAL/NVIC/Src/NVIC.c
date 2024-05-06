#include "..\inc\NVIC.h"

/*************************           NVIC Registers Definition           **************************/
#define NVIC_ISER                   ((uint32_t*)0xE000E100UL)  /*Interrupt Set Enable Register*/
#define NVIC_ICER                   ((uint32_t*)0xE000E180UL)  /*Interrupt Clear Enable Register*/
#define NVIC_ISPR                   ((uint32_t*)0xE000E200UL)  /*Interrupt Set Pending Register*/
#define NVIC_ICPR                   ((uint32_t*)0xE000E280UL)  /*Interrupt Clear Pending Register*/
#define NVIC_IABR                   ((uint32_t*)0xE000E300UL)  /*Interrupt Active Bit Register*/
#define NVIC_IPR                    ((uint32_t*)0xE000E400UL)  /*Interrupt Priority Register*/


/****************************************************************
 * @fn Enable_IRQ
 * @brief Enable specific interrupt
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void Enable_IRQ(IRQ_t irq)
{
    NVIC_ISER[irq / 32] = 1 << (irq % 32); 
}

/****************************************************************
 * @fn Disable_IRQ
 * @brief Disable specific interrupt
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void Disable_IRQ(IRQ_t irq)
{
    NVIC_ICER[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn SetPendingFlag
 * @brief Set Pending Flag
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void SetPendingFlag(IRQ_t irq)
{
    NVIC_ISPR[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn CLearPendingFlag
 * @brief CLear Pending Flag
 * @param[in] IRQ_t number of IRQ 
 * @retval none 
*/
void CLearPendingFlag(IRQ_t irq)
{
    NVIC_ICPR[irq / 32] = 1 << (irq % 32);
}

/****************************************************************
 * @fn GetActiveFlag
 * @brief Get Active falg status
 * @param[in] IRQ_t number of IRQ 
 * @retval Active Flag 
*/
uint8_t GetActiveFlag(IRQ_t irq)
{
    return((NVIC_IABR[irq / 32] & (1<<(irq % 32))>>(irq % 32)));
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
    /*Clear the priority bits 0b PPPP XXXX  p -> priority  x -> don't care*/
    NVIC_IPR[irq / 4] &= (~(0xff<<((8*(irq % 4))+4)));

    /*Set priority*/
    NVIC_IPR[irq / 4] |= (priority << ((8*(irq % 4))+4));
}