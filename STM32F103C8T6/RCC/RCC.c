#include "RCC.h"

STATUS RCC_SetClk_Status(CLK_Type clk_type, CLK_STATUS clk_status)
{
    uint32_t timeoutCounter = 0;
    switch (clk_type)
    {
    case HSE:
        RCC->RCC_CR.bit.HSEON = clk_status;
        while (READY !=RCC->RCC_CR.bit.HSERDY || timeoutCounter <   500)
        {
            timeoutCounter++;
        }
        break;
    case HSI:
        RCC->RCC_CR.bit.HSION = clk_status;
        while (READY !=RCC->RCC_CR.bit.HSIRDY || timeoutCounter <   500)
        {
            timeoutCounter++;
        }
        break;
    case PLL:
        RCC->RCC_CR.bit.PLLON = clk_status;
        while (READY !=RCC->RCC_CR.bit.PLLRDY || timeoutCounter <   500)
        {
            timeoutCounter++;
        }
        break;
    default:
        return NOK;
        break;
    }
    if (timeoutCounter < 500)
    {
        return NOK;
    }
    else
    {
        return OK;
    }   
}

STATUS RCC_Set_SysClk(CLK_Type clk_type)
{
    switch (clk_type)
    {
    case HSE:
        if(NOT_READY == RCC->RCC_CR.bit.HSERDY)
        {
            return NOK;
        }
        else
        {
            RCC->RCC_CFGR.bit.SW = HSE;
        }
        break;
    case HSI:
        if(NOT_READY == RCC->RCC_CR.bit.HSIRDY)
        {
            return NOK;
        }
        else
        {
            RCC->RCC_CFGR.bit.SW = HSI;
        }
        break;
    case PLL:
        if(NOT_READY == RCC->RCC_CR.bit.PLLRDY)
        {
            return NOK;
        }
        else
        {
            RCC->RCC_CFGR.bit.SW = PLL;
        }
        break;
    default:
         return NOK;
        break;
    }
    
    return OK;
}
