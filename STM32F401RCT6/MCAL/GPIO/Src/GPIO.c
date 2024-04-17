#include "..\Inc\GPIO.h"



STATUS  GPIO_PinInit(const GPIO_CFG_t* gpioCfg)
{
    switch (gpioCfg->port)
    {
    case PORTA:
        /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOA->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOA->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOA->OTYPER,gpioCfg->pin);
        GPIOA->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOA->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOA->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOA->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOA->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOA->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOA->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2));
        break;
    case PORTB:
       /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOB->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOB->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOB->OTYPER,gpioCfg->pin);
        GPIOB->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOB->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOB->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOB->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOB->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOB->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOB->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2)); 
        break;
    case PORTC:
        /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOC->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOC->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOC->OTYPER,gpioCfg->pin);
        GPIOC->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOC->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOC->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOC->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOC->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOC->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOC->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2));
        break;
    case PORTD:
        /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOD->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOD->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOD->OTYPER,gpioCfg->pin);
        GPIOD->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOD->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOD->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOD->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOD->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOD->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOD->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2));
        break;
    case PORTE:
        /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOE->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOE->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOE->OTYPER,gpioCfg->pin);
        GPIOE->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOE->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOE->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOE->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOE->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOE->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOE->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2));
        break;
    case PORTH:
        /*Clearing the Two Bits corresponding to Choosen pin*/
        GPIOH->MODER &= (~(3<<(gpioCfg->pin * 2)));
        /*setting the Two Bits corresponding to Choosen pin*/
        GPIOH->MODER |= (gpioCfg->mode<<(gpioCfg->pin * 2));
        /*Choose Output Type*/
        Clr_bit(GPIOH->OTYPER,gpioCfg->pin);
        GPIOH->OTYPER |= (gpioCfg->outputType<<(gpioCfg->pin * 2));
        /*Choose Output Speed*/
        GPIOH->OSPEEDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOH->OSPEEDR |= (gpioCfg->speed<<(gpioCfg->pin * 2));
        /*Choose PULL type*/
        GPIOH->PUPDR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOH->PUPDR |= (gpioCfg->pullType<<(gpioCfg->pin * 2));
        /*Choose ALTF type*/
        GPIOH->AFR &= (~(3<<(gpioCfg->pin * 2)));
        GPIOH->AFR |= (gpioCfg->altFunc<<(gpioCfg->pin * 2));
        break;

    default:
        return NOK;
        break;
    }


return OK;
}

STATUS  GPIO_SetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t value)
{
    switch (port)
{
case PORTA:
    Clr_bit(GPIOA->ODR,pin);
    GPIOA->ODR |= (value<<pin);
    break;

case PORTB:
    Clr_bit(GPIOB->ODR,pin);
    GPIOB->ODR |= (value<<pin);
    break;
    
case PORTC:
    Clr_bit(GPIOC->ODR,pin);
    GPIOC->ODR |= (value<<pin);
    break;

case PORTD:
    Clr_bit(GPIOD->ODR,pin);
    GPIOD->ODR |= (value<<pin);
    break;

case PORTE:
    Clr_bit(GPIOE->ODR,pin);
    GPIOE->ODR |= (value<<pin);
    break;

case PORTH:
    Clr_bit(GPIOH->ODR,pin);
    GPIOH->ODR |= (value<<pin);
    break;

default:
    return NOK;
    break;
}

return OK;
}

STATUS  GPIO_TogglePinValue(PORT_t port,PIN_t pin)
{
    switch (port)
{
case PORTA:
    Toggle_bit(GPIOA->ODR,pin);
    break;

case PORTB:
    Toggle_bit(GPIOB->ODR,pin);
    break;
    
case PORTC:
    Toggle_bit(GPIOC->ODR,pin);
    break;

case PORTD:
    Toggle_bit(GPIOD->ODR,pin);
    break;

case PORTE:
    Toggle_bit(GPIOE->ODR,pin);
    break;

case PORTH:
    Toggle_bit(GPIOH->ODR,pin);
    break;

default:
    return NOK;
    break;
}
return OK;
}

STATUS  GPIO_GetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t* value)
{
switch (port)
{
case PORTA:
    *value = Get_bit(GPIOA->ODR,pin);
    break;

case PORTB:
    *value = Get_bit(GPIOB->ODR,pin);
    break;
    
case PORTC:
    *value = Get_bit(GPIOC->ODR,pin);
    break;

case PORTD:
    *value = Get_bit(GPIOD->ODR,pin);
    break;

case PORTE:
    *value = Get_bit(GPIOE->ODR,pin);
    break;

case PORTH:
    *value = Get_bit(GPIOH->ODR,pin);
    break;

default:
    return NOK;
    break;
}
return OK;

}