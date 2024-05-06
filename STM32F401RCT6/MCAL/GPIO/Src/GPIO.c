#include "..\Inc\GPIO.h"
#include "..\Inc\GPIO_private.h"
#include "..\..\..\Library\stm32f401rct6.h"

/*************************           GPIO peripheral Definition           **************************/

#define GPIOA    ((GPIO_REG_t *)GPIOA_BASE_ADDRESS)
#define GPIOB    ((GPIO_REG_t *)GPIOB_BASE_ADDRESS)
#define GPIOC    ((GPIO_REG_t *)GPIOC_BASE_ADDRESS)
#define GPIOD    ((GPIO_REG_t *)GPIOD_BASE_ADDRESS)
#define GPIOE    ((GPIO_REG_t *)GPIOE_BASE_ADDRESS)
#define GPIOH    ((GPIO_REG_t *)GPIOH_BASE_ADDRESS)

static GPIO_REG_t* GPIOPort[PORTCOUNT] = {GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOH};


/*********************************************************************************
*@fn GPIO_PinInit
*@brief the function initializes the gpio pin according to input parameters
*@param[in] pinCfg  the initialization values of the pin
*@retval STATUS
*/

STATUS  GPIO_PinInit(const PIN_CFG_t* pinCfg)
{   STATUS errorState = OK;
    if(pinCfg != NULL)
    {
        if (pinCfg->port < PORTCOUNT && pinCfg->pin < PINCOUNT )
        {
            /*Clearing the Two Bits corresponding to Choosen pin*/
           GPIOPort[pinCfg->port]->MODER &= (~(MODER_MASK <<(pinCfg->pin * MODER_PIN_ACCESS)));
            /*setting the Two Bits corresponding to Choosen pin*/
            GPIOPort[pinCfg->port]->MODER |= (pinCfg->mode<<(pinCfg->pin * MODER_PIN_ACCESS));
            /*Choose PULL type*/
            GPIOPort[pinCfg->port]->PUPDR &= (~(PUPDR_MASK<<(pinCfg->pin * PUPDR_PIN_ACCESS)));
            GPIOPort[pinCfg->port]->PUPDR |= (pinCfg->pullType<<(pinCfg->pin * PUPDR_PIN_ACCESS));
            /*Choose Output Type and Choose Output Speed in case of OUTPUT or ALTF.*/
            if((pinCfg->mode == OUTPUT) || (pinCfg->mode == ALTERNATE_FUNCTION))
            {
                /*Choose Output Type*/
                GPIOPort[pinCfg->port]->OTYPER &= (~(OTYPER_MASK<<(pinCfg->pin)));
                GPIOPort[pinCfg->port]->OTYPER |= (pinCfg->outputType<<pinCfg->pin);
                /*Choose Output Speed*/
                GPIOPort[pinCfg->port]->OSPEEDR &= (~(OSPEEDR_MASK<<(pinCfg->pin * OSPEEDR_PIN_ACCESS)));
                GPIOPort[pinCfg->port]->OSPEEDR |= (pinCfg->speed<<(pinCfg->pin * OSPEEDR_PIN_ACCESS));
            if(pinCfg->mode == ALTERNATE_FUNCTION)
            {
                /*Choose ALTF type*/
                GPIOPort[pinCfg->port]->AFR[pinCfg->pin / 8] &= (~(AFR_MASK<<((pinCfg->pin % 8) * AFR_PIN_ACCESS)));
                GPIOPort[pinCfg->port]->AFR[pinCfg->pin / 8] |= (pinCfg->altFunc<<((pinCfg->pin % 8) * AFR_PIN_ACCESS));
            }
            }
        }
        else 
        {
            errorState = NOK;
        }
    }
    else
    {
        errorState = NULLPTR;
    }    
return errorState;
}


/*********************************************************************************
*@fn GPIO_SetPinValue
*@brief the function set pin value according to input parameters
*@param[in] port port number ,get options @PORT_t enum
*@param[in] pin pin number ,get options @PIN_t enum
*@param[in] value output value ,get options @PIN_STATE_t enum
*@retval STATUS
*/
STATUS  GPIO_SetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t value)
{
   STATUS errorState = OK;
   if((port < PORTCOUNT) && (pin<PINCOUNT))
   {
    if(value == LOW)
    {
        GPIOPort[port]->ODR &= (~(1<<pin));
    }
    else if(value == HIGH)
    {
        GPIOPort[port]->ODR |= (1<<pin);
    }
    else
    {
        errorState = NOK;
    }
   }
   else
   {
    errorState = NOK;
   }

return errorState;
}

/*********************************************************************************
*@fn GPIO_TogglePinValue
*@brief the function toggle pin value to input parameters
*@param[in] port port number ,get options @PORT_t enum
*@param[in] pin pin number ,get options @PIN_t enum
*@retval STATUS 
*/
STATUS  GPIO_TogglePinValue(PORT_t port,PIN_t pin)
{   STATUS errorState = OK;
    if ((port < PORTCOUNT) && (pin < PINCOUNT))
    {  
        GPIOPort[port]->ODR ^= (1<<pin);
    }
    else
    {
        errorState = NOK;
    }
    
return errorState;
}

/*********************************************************************************
*@fn GPIO_GetPinValue
*@brief the function read pin value
*@param[in] port port number ,get options @PORT_t enum
*@param[in] pin pin number ,get options @PIN_t enum
*@retval STATUS
*/
STATUS  GPIO_GetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t* value)
{
    STATUS errorState = OK;
    if ((port < PORTCOUNT) && (pin < PINCOUNT))
    {
        *value = (GPIOPort[port]->IDR>>pin)&1;
    }
    else
    {
        errorState = NOK;
    }
return errorState;

}
