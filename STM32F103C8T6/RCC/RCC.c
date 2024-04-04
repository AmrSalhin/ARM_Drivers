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


STATUS RCC_AHB_peripheralEnable(AHB_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case DMA1:
    RCC->RCC_AHBENR.bit.DMA1EN = ENABLE;
        break;
    
    case DMA2:
    
    RCC->RCC_AHBENR.bit.DMA2EN = ENABLE;
        break;
    
    case SRAM:
    RCC->RCC_AHBENR.bit.SRAMEN = ENABLE;
        break;
    case FLITF:
    RCC->RCC_AHBENR.bit.FLITFEN = ENABLE;
        break;
    case FSMC:
    RCC->RCC_AHBENR.bit.FSMCEN = ENABLE;
        break;
    case SDIO:
    RCC->RCC_AHBENR.bit.SDIOEN = ENABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;
}

STATUS RCC_AHB_peripheralDisable(AHB_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case DMA1:
    RCC->RCC_AHBENR.bit.DMA1EN = DISABLE;
        break;
    case DMA2:
    RCC->RCC_AHBENR.bit.DMA2EN = DISABLE;
        break; 
    case SRAM:
    RCC->RCC_AHBENR.bit.SRAMEN = DISABLE;
        break;
    case FLITF:
    RCC->RCC_AHBENR.bit.FLITFEN = DISABLE;
        break;
    case FSMC:
    RCC->RCC_AHBENR.bit.FSMCEN = DISABLE;
        break;
    case SDIO:
    RCC->RCC_AHBENR.bit.SDIOEN = DISABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;

}

STATUS RCC_APB1_peripheralEnable(APB1_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case TIM2:
    RCC->RCC_APB1ENR.bit.TIM2EN = ENABLE;
        break;
    case TIM3:
    RCC->RCC_APB1ENR.bit.TIM3EN = ENABLE;
        break; 
    case TIM4:
    RCC->RCC_APB1ENR.bit.TIM4EN = ENABLE;
        break;
    case TIM5:
    RCC->RCC_APB1ENR.bit.TIM5EN = ENABLE;
        break;
    case TIM6:
    RCC->RCC_APB1ENR.bit.TIM6EN = ENABLE;
        break;
    case TIM7:
    RCC->RCC_APB1ENR.bit.TIM7EN = ENABLE;
        break;
    case TIM12:
    RCC->RCC_APB1ENR.bit.TIM12EN = ENABLE;
        break;
    case TIM13:
    RCC->RCC_APB1ENR.bit.TIM13EN = ENABLE;
        break;
    case TIM14:
    RCC->RCC_APB1ENR.bit.TIM14EN = ENABLE;
        break;
    case WWDG:
    RCC->RCC_APB1ENR.bit.WWDGEN = ENABLE;
        break;
    case SPI2:
    RCC->RCC_APB1ENR.bit.SPI2EN = ENABLE;
        break;
    case SPI3:
    RCC->RCC_APB1ENR.bit.SPI3EN = ENABLE;
        break;
    case USART2:
    RCC->RCC_APB1ENR.bit.USART2EN = ENABLE;
        break;
    case USART3:
    RCC->RCC_APB1ENR.bit.USART3EN = ENABLE;
        break;
    case USART4:
    RCC->RCC_APB1ENR.bit.USART4EN = ENABLE;
        break;
    case USART5:
    RCC->RCC_APB1ENR.bit.USART5EN = ENABLE;
        break;
    case I2C1:
    RCC->RCC_APB1ENR.bit.I2C1EN = ENABLE;
        break;
    case I2C2:
    RCC->RCC_APB1ENR.bit.I2C2EN = ENABLE;
        break;
    case USB:
    RCC->RCC_APB1ENR.bit.USBEN = ENABLE;
        break;
    case CAN:
    RCC->RCC_APB1ENR.bit.CANEN = ENABLE;
        break;
    case BKP:
    RCC->RCC_APB1ENR.bit.BKPEN = ENABLE;
        break;
    case PWR:
    RCC->RCC_APB1ENR.bit.PWREN = ENABLE;
        break;
    case DAC:
    RCC->RCC_APB1ENR.bit.DACEN = ENABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;
}

STATUS RCC_APB1_peripheralDisable(APB1_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case TIM2:
    RCC->RCC_APB1ENR.bit.TIM2EN = DISABLE;
        break;
    case TIM3:
    RCC->RCC_APB1ENR.bit.TIM3EN = DISABLE;
        break; 
    case TIM4:
    RCC->RCC_APB1ENR.bit.TIM4EN = DISABLE;
        break;
    case TIM5:
    RCC->RCC_APB1ENR.bit.TIM5EN = DISABLE;
        break;
    case TIM6:
    RCC->RCC_APB1ENR.bit.TIM6EN = DISABLE;
        break;
    case TIM7:
    RCC->RCC_APB1ENR.bit.TIM7EN = DISABLE;
        break;
    case TIM12:
    RCC->RCC_APB1ENR.bit.TIM12EN = DISABLE;
        break;
    case TIM13:
    RCC->RCC_APB1ENR.bit.TIM13EN = DISABLE;
        break;
    case TIM14:
    RCC->RCC_APB1ENR.bit.TIM14EN = DISABLE;
        break;
    case WWDG:
    RCC->RCC_APB1ENR.bit.WWDGEN = DISABLE;
        break;
    case SPI2:
    RCC->RCC_APB1ENR.bit.SPI2EN = DISABLE;
        break;
    case SPI3:
    RCC->RCC_APB1ENR.bit.SPI3EN = DISABLE;
        break;
    case USART2:
    RCC->RCC_APB1ENR.bit.USART2EN = DISABLE;
        break;
    case USART3:
    RCC->RCC_APB1ENR.bit.USART3EN = DISABLE;
        break;
    case USART4:
    RCC->RCC_APB1ENR.bit.USART4EN = DISABLE;
        break;
    case USART5:
    RCC->RCC_APB1ENR.bit.USART5EN = DISABLE;
        break;
    case I2C1:
    RCC->RCC_APB1ENR.bit.I2C1EN = DISABLE;
        break;
    case I2C2:
    RCC->RCC_APB1ENR.bit.I2C2EN = DISABLE;
        break;
    case USB:
    RCC->RCC_APB1ENR.bit.USBEN = DISABLE;
        break;
    case CAN:
    RCC->RCC_APB1ENR.bit.CANEN = DISABLE;
        break;
    case BKP:
    RCC->RCC_APB1ENR.bit.BKPEN = DISABLE;
        break;
    case PWR:
    RCC->RCC_APB1ENR.bit.PWREN = DISABLE;
        break;
    case DAC:
    RCC->RCC_APB1ENR.bit.DACEN = DISABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;
}

STATUS RCC_APB2_peripheralEnable(APB2_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case AFIO:
    RCC->RCC_APB2ENR.bit.AFIOEN = ENABLE;
        break;
    case IOPA:
    RCC->RCC_APB2ENR.bit.IOPAEN = ENABLE;
        break; 
    case IOPB:
    RCC->RCC_APB2ENR.bit.IOPBEN = ENABLE;
        break;
    case IOPC:
    RCC->RCC_APB2ENR.bit.IOPCEN = ENABLE;
        break;
    case IOPD:
    RCC->RCC_APB2ENR.bit.IOPDEN = ENABLE;
        break;
    case IOPE:
    RCC->RCC_APB2ENR.bit.IOPEEN = ENABLE;
        break;
    case IOPF:
    RCC->RCC_APB2ENR.bit.IOPFEN = ENABLE;
        break;
    case IOPG:
    RCC->RCC_APB2ENR.bit.IOPGEN = ENABLE;
        break;
    case ADC1:
    RCC->RCC_APB2ENR.bit.ADC1EN = ENABLE;
        break;
    case ADC2:
    RCC->RCC_APB2ENR.bit.ADC2EN = ENABLE;
        break;
    case TIM1:
    RCC->RCC_APB2ENR.bit.TIM1EN = ENABLE;
        break;
    case SPI1:
    RCC->RCC_APB2ENR.bit.SPI1EN = ENABLE;
        break;
    case TIM8:
    RCC->RCC_APB2ENR.bit.TIM8EN = ENABLE;
        break;
    case USART1:
    RCC->RCC_APB2ENR.bit.USART1EN = ENABLE;
        break;
    case ADC3:
    RCC->RCC_APB2ENR.bit.ADC3EN = ENABLE;
        break;
    case TIM9:
    RCC->RCC_APB2ENR.bit.TIM9EN = ENABLE;
        break;
    case TIM10:
    RCC->RCC_APB2ENR.bit.TIM10EN = ENABLE;
        break;
    case TIM11:
    RCC->RCC_APB2ENR.bit.TIM11EN = ENABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;
}

STATUS RCC_APB2_peripheralDisable(APB2_PERIPHERAL peripheral)
{
    switch (peripheral)
    {
    case AFIO:
    RCC->RCC_APB2ENR.bit.AFIOEN = DISABLE;
        break;
    case IOPA:
    RCC->RCC_APB2ENR.bit.IOPAEN = DISABLE;
        break; 
    case IOPB:
    RCC->RCC_APB2ENR.bit.IOPBEN = DISABLE;
        break;
    case IOPC:
    RCC->RCC_APB2ENR.bit.IOPCEN = DISABLE;
        break;
    case IOPD:
    RCC->RCC_APB2ENR.bit.IOPDEN = DISABLE;
        break;
    case IOPE:
    RCC->RCC_APB2ENR.bit.IOPEEN = DISABLE;
        break;
    case IOPF:
    RCC->RCC_APB2ENR.bit.IOPFEN = DISABLE;
        break;
    case IOPG:
    RCC->RCC_APB2ENR.bit.IOPGEN = DISABLE;
        break;
    case ADC1:
    RCC->RCC_APB2ENR.bit.ADC1EN = DISABLE;
        break;
    case ADC2:
    RCC->RCC_APB2ENR.bit.ADC2EN = DISABLE;
        break;
    case TIM1:
    RCC->RCC_APB2ENR.bit.TIM1EN = DISABLE;
        break;
    case SPI1:
    RCC->RCC_APB2ENR.bit.SPI1EN = DISABLE;
        break;
    case TIM8:
    RCC->RCC_APB2ENR.bit.TIM8EN = DISABLE;
        break;
    case USART1:
    RCC->RCC_APB2ENR.bit.USART1EN = DISABLE;
        break;
    case ADC3:
    RCC->RCC_APB2ENR.bit.ADC3EN = DISABLE;
        break;
    case TIM9:
    RCC->RCC_APB2ENR.bit.TIM9EN = DISABLE;
        break;
    case TIM10:
    RCC->RCC_APB2ENR.bit.TIM10EN = DISABLE;
        break;
    case TIM11:
    RCC->RCC_APB2ENR.bit.TIM11EN = DISABLE;
        break;
    default:
        return NOK;
        break;
    }

    return OK;
}
