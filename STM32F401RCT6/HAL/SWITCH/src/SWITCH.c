#include "..\..\..\MCAL\GPIO\Inc\GPIO.h"
#include "..\inc\SWITCH.h"
#include "..\inc\SWITCH_private.h"


STATUS Switch_init(SWITCH_t* sw)
{
    STATUS errorState = OK;
    PIN_CFG_t pinCfg;

    pinCfg.mode = INPUT;
    pinCfg.port = sw->swPort;
    pinCfg.pin = sw->swPin;
    pinCfg.pullType = sw->swInputType;
    GPIO_PinInit(&pinCfg);
    
    return errorState;
}


STATUS Switch_getState(SWITCH_t *sw,SWITCH_STATE_t* state)
{
    STATUS errorState = OK;
    PIN_STATE_t pinvalue;
    GPIO_GetPinValue(sw->swPort,sw->swPin,&pinvalue);
    if(sw->swPullType == SW_PULLED_UP)
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
    else if(sw->swPullType == SW_PULLED_DOWN)
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
