#include "..\Inc\RCC.h"

/*************************      RCC peripheral Definition       **************************/

#define RCC         ((RCC_t *) RCC_BASE_ADDRESS)

/*************************      RCC Functions implementation       **************************/


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
        return TIMEOUT;
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

STATUS RCC_HSE_HSI_division(uint8_t div)
{
    RCC->RCC_PLL_CFGR.bit.PLLM = div;
    return OK;
}


STATUS RCC_Pll_config(const PLL_CFGR* pll_cfgr)
{
    RCC->RCC_PLL_CFGR.bit.PLLSRC = pll_cfgr->clk;
    /*division factor for SYSCLK 
    The software has to set these bits correctly not to exceed 84 MHz*/
    RCC->RCC_PLL_CFGR.bit.PLLP = pll_cfgr->pllP;
    /*The software has to set these bits correctly to ensure that the VCO output 
    frequency is between 192 and 432 MHz*/
    RCC->RCC_PLL_CFGR.bit.PLLN = pll_cfgr->pllN;

    return OK;
}

STATUS RCC_AHB1_peripheralEnable(AHB1_PERIPHERAL peripheral)
{
    Set_bit(RCC->RCC_AHB1ENR.reg,peripheral);

    return OK;
}


STATUS RCC_AHB1_peripheralDisable(AHB1_PERIPHERAL peripheral)
{
    Clr_bit(RCC->RCC_AHB1ENR.reg,peripheral);

    return OK;

}

STATUS RCC_AHB2_peripheralEnable(AHB2_PERIPHERAL peripheral)
{
    Set_bit(RCC->RCC_AHB2ENR.reg,peripheral);

    return OK;
}

STATUS RCC_AHB2_peripheralDisable(AHB2_PERIPHERAL peripheral)
{
    Clr_bit(RCC->RCC_AHB2ENR.reg,peripheral);

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
