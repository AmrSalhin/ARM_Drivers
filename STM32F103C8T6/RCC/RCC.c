#include "RCC.h"

RCC_t* RCC =  (RCC_t*) RCC_BASE_ADDRESS;


STATUS RCC_SetClk_Status(CLK_Type clk_type, CLK_STATUS clk_status)
{
    uint32_t timeoutCounter = 0;
    switch (clk_type)
    {
    case HSE:
        RCC->RCC_CR.bit.HSEON = clk_status;
        while (READY !=RCC->RCC_CR.bit.HSERDY && timeoutCounter <   TIME_OUT)
        {
            timeoutCounter++;
        }
        break;
    case HSI:
        RCC->RCC_CR.bit.HSION = clk_status;
        while (READY !=RCC->RCC_CR.bit.HSIRDY && timeoutCounter <   TIME_OUT)
        {
            timeoutCounter++;
        }
        break;
    case PLL:
        RCC->RCC_CR.bit.PLLON = clk_status;
        while (READY !=RCC->RCC_CR.bit.PLLRDY && timeoutCounter <   TIME_OUT)
        {
            timeoutCounter++;
        }
        break;
    default:
        return NOK;
        break;
    }
    if (timeoutCounter < TIME_OUT)
    {
        return OK;
    }
    else
    {
        return NOK;
    }
}

STATUS RCC_Set_SysClk(CLK_Type clk_type)
{
    switch (clk_type)
    {
    case HSE:
        if(OFF == RCC->RCC_CR.bit.HSEON)
        {
            return NOK;
        }
        else
        {
            RCC->RCC_CFGR.bit.SW = HSE;
        }
        break;
    case HSI:
        if(OFF == RCC->RCC_CR.bit.HSION)
        {
            return NOK;
        }
        else
        {
            RCC->RCC_CFGR.bit.SW = HSI;
        }
        break;
    case PLL:
        if(OFF == RCC->RCC_CR.bit.PLLON)
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

STATUS RCC_HSE_division(HSE_DIV div)
{
    RCC->RCC_CFGR.bit.PLLXTPRE = div;
    return OK;
}

STATUS RCC_Pll_config(CLK_Type clk, PLL_MUL mul)
{
    RCC->RCC_CFGR.bit.PLLSRC = clk;
    RCC->RCC_CFGR.bit.PLLMUL = mul;

    return OK;
}

STATUS RCC_AHB_peripheralEnable(AHB_PERIPHERAL peripheral)
{
    Set_bit(RCC->RCC_AHBENR.reg,peripheral);

    return OK;
}

STATUS RCC_AHB_peripheralDisable(AHB_PERIPHERAL peripheral)
{
    Clr_bit(RCC->RCC_AHBENR.reg,peripheral);

    return OK;

}

STATUS RCC_APB1_peripheralEnable(APB1_PERIPHERAL peripheral)
{
    Set_bit(RCC->RCC_APB1ENR.reg,peripheral);
    return OK;
}

STATUS RCC_APB1_peripheralDisable(APB1_PERIPHERAL peripheral)
{
    Clr_bit(RCC->RCC_APB1ENR.reg,peripheral);

    return OK;
}

STATUS RCC_APB2_peripheralEnable(APB2_PERIPHERAL peripheral)
{
    Set_bit(RCC->RCC_APB2ENR.reg,peripheral);

    return OK;
}

STATUS RCC_APB2_peripheralDisable(APB2_PERIPHERAL peripheral)
{
    Clr_bit(RCC->RCC_APB2ENR.reg,peripheral);

    return OK;
}
