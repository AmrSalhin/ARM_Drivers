#include  "../inc/SYSTick.h"
#include  "../inc/SYSTICK_private.h"

/*************************           SYSTICK peripheral Definition           **************************/

#define SYSTICK    ((SYSTICK_REG_t *)SysTick_BASE_ADDRESS)



/*********************************************************************************
*@fn SYSTICK_delayMS
*@brief the function the function Reload Systick with required delay time in milli seconds
*@param[in] TIME_MS  the required TIME
*@retval STATUS
*/
STATUS  SYSTICK_delayMS(uint32_t TIME_MS)
{
    /*SYStem CLK HSI 16MHZ*/
    /*MAX TIME = */
    STATUS  errorState = OK;
    uint32_t reloadValue = 0;
    reloadValue = TIME_MS * FREQUENCY_IN_KHZ;
    if(reloadValue < MAXMUM_TICKS_NUM){
    SYSTICK->SYST_RVR = reloadValue;
    SYSTICK->SYST_CSR.bit.ENABLE = 1;
    while (!SYSTICK->SYST_CSR.bit.COUNTFLAG);
    SYSTICK->SYST_CSR.bit.ENABLE = 0;
    }
    else{
        errorState = NOK;
    }
    
    
    return errorState;
}

/*********************************************************************************
*@fn SYSTICK_delayUS
*@brief the function Reload Systick with required delay time in micro seconds
*@param[in] TIME_US  the required TIME
*@retval STATUS
*/
STATUS  SYSTICK_delayUS(uint32_t TIME_US)
{
    /*SYStem CLK HSI 16MHZ*/
    STATUS  errorState = OK;   
    uint32_t reloadValue;
    reloadValue = TIME_US * FREQUENCY_IN_MHZ;
        if(reloadValue < MAXMUM_TICKS_NUM){
    SYSTICK->SYST_RVR = reloadValue;
    SYSTICK->SYST_CSR.bit.ENABLE = 1;
    while (!SYSTICK->SYST_CSR.bit.COUNTFLAG);
    SYSTICK->SYST_CSR.bit.ENABLE = 0;
    }
    else{
        errorState = NOK;
    }
    return errorState;
}
