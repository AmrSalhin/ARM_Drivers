#include "..\..\..\MCAL\GPIO\Inc\GPIO.h"
#include "..\inc\SWITCH.h"


STATUS Switch_init(SWITCH_t* sw)
{
    STATUS errorState = OK;
    PIN_CFG_t pinCfg;

    pinCfg.mode = INPUT;
    pinCfg.port = sw->swPort;
    pinCfg.pin = sw->swPin;
    pinCfg.inputType = sw->swInputType;
    pinCfg.pullType = sw->swPullType;
    GPIO_PinInit(&pinCfg);
    
    return errorState;
}


STATUS Switch_getState(SWITCH_t *sw,SWITCH_STATE_t* state)
{
    STATUS errorState = OK;
    PIN_STATE_t pinvalue;
    GPIO_GetPinValue(sw->swPort,sw->swPin,&pinvalue);
    if(sw->swPullType == SW_PULL_UP)
    {   
        if (pinvalue == LOW)
        {
            *state = PRESSED;
            while(pinvalue == LOW)
            {
                 GPIO_GetPinValue(sw->swPort,sw->swPin,&pinvalue); 
            }
        }
        else
        {
            *state = RELEASED;
        }
    }
    else if(sw->swPullType == SW_PULL_DOWN)
    {
        if (pinvalue == HIGH)
        {
            *state = PRESSED;
            while(pinvalue == HIGH)
            {
                 GPIO_GetPinValue(sw->swPort,sw->swPin,&pinvalue); 
            }
        }
        else
        {
            *state = RELEASED;
        }
    }
    else
    {
        errorState = NOK;
    }
    

    return errorState;
}