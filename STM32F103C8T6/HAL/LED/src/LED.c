#include "../../../MCAL/GPIO/Inc/GPIO.h"
#include "../inc/LED.h"
#include "../inc/LED_private.h"



/********************************************************
*@fn LED_init
*@brief the function initializes the Led pin
*@param[in] LED_t  pin confiiguration
*@retval STATUS
*/
STATUS LED_init(LED_t* led)
{
    STATUS errorState = OK;
    PIN_CFG_t pinCfg;
    
    pinCfg.port = led->port;
    pinCfg.pin = led->pin;
    pinCfg.mode = OUTPUT_2MHZ; /*OUTPUT*/
    pinCfg.outputType = GP_PUSH_PULL;
    GPIO_PinInit(&pinCfg);
    switch (led->activeType)
    {
    case ACTIVE_HIGH:
        
        if (led->ledState == LED_ON)
        {
            GPIO_SetPinValue(led->port,led->pin,HIGH);
        }
        else if(led->ledState == LED_OFF)
        {
            GPIO_SetPinValue(led->port,led->pin,LOW);
        }
        else
        {
            errorState = NOK;
        }
        

        break;
    case ACTIVE_LOW:
        if (led->ledState == LED_ON)
        {
          GPIO_SetPinValue(led->port,led->pin,LOW);  
        }
        else if(led->ledState == LED_OFF)
        {
          GPIO_SetPinValue(led->port,led->pin,HIGH);
        }
        else
        {
            errorState = NOK;
        }
        break;
    default:
    errorState = NOK;
        break;
    }
    
    return errorState;
}


/********************************************************
*@fn LED_setState
*@brief the function set the Led pin
*@param[in] LED_t  pin confiiguration
*@param[in] LED_STATE_t  pin value
*@retval STATUS
*/
STATUS  LED_setState(LED_t* led,LED_STATE_t state)
{
    STATUS errorState = OK;
switch (led->activeType)
    {
    case ACTIVE_HIGH:
        
        if (state == LED_ON)
        {
            GPIO_SetPinValue(led->port,led->pin,HIGH);
        }
        else if(state == LED_OFF)
        {
            GPIO_SetPinValue(led->port,led->pin,LOW);
        }
        else
        {
            errorState = NOK;
        }
        

        break;
    case ACTIVE_LOW:
        if (state == LED_ON)
        {
          GPIO_SetPinValue(led->port,led->pin,LOW);  
        }
        else if(state == LED_OFF)
        {
          GPIO_SetPinValue(led->port,led->pin,HIGH);
        }
        else
        {
            errorState = NOK;
        }
        break;
    default:
    errorState = NOK;
        break;
}    
    return errorState;
}


/********************************************************
*@fn LED_getState
*@brief the function get the Led pin
*@param[in] pinCfg  the initialization values of the pin
*@param[out] LED_STATE_t  the return pin value
*@retval STATUS
*/
STATUS  LED_getState(LED_t* led,LED_STATE_t* state)
{
    STATUS errorState = OK;
    uint8_t pinState;
    GPIO_GetPinValue(led->port,led->pin,&pinState);
    switch (led->activeType)
    {
    case ACTIVE_HIGH:
        
        if (pinState == HIGH)
        {
            *state = LED_ON;
        }
        else if(pinState == LOW)
        {
            *state = LED_OFF;
        }
        else
        {
            errorState = NOK;
        }
        break;
    case ACTIVE_LOW:
        if (pinState == HIGH)
        {
            *state = LED_OFF;
        }
        else if(pinState == LOW)
        {
            *state = LED_ON;
        }
        else
        {
            errorState = NOK;
        }
        break;
    default:
    errorState = NOK;
    break;
    }
    return errorState;
}
