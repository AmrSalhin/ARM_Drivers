#include "..\inc\SYSCFG.h"
#include "../../../Library/stm32f401rct6.h"


#define SYSCFG    ((SYSCFG_REG_t*)SYSCFG_BASE_ADDRESS)

STATUS SYSCFG_SetEXTIPort(Px portNum,SYSCFG_LINE_NUM lineNum)
{
    STATUS errorState = OK;
    if(lineNum < SYSCFG_LINES_COUNT)
    {
    /*clearing the Four bits corresponding for EXTI line*/
    SYSCFG->EXTICR[lineNum / 4] &= (15 <<((lineNum % 4)*4) );
    /*set the bits for the port of EXTI*/
    SYSCFG->EXTICR[lineNum/4] |= (portNum<<(lineNum%4)*4);
    }
    else
    {
        errorState = NOK;
    }
    return errorState;
}


