#ifndef SWITCH_H_
#define SWITCH_H_

#include "stdint.h"
#include "..\..\..\Library\ErrorStates.h"

typedef enum
{
    SW_PORTA,
    SW_PORTB,
    SW_PORTC,
    SW_PORTD,
    SW_PORTE,
}SWITCh_PORT_t;

typedef enum
{
    SW_PIN0,SW_PIN1,SW_PIN2,SW_PIN3,SW_PIN4,SW_PIN5,SW_PIN6,SW_PIN7,
    SW_PIN8,SW_PIN9,SW_PIN10,SW_PIN11,SW_PIN12,SW_PIN13,SW_PIN14,SW_PIN15
}SWITCh_PIN_t;

typedef enum
{   
    SW_Floating ,
    SW_PULL_UP,
	SW_PULL_DOWN
}SWITCh_INPUT_t;

typedef enum
{
	SW_PULLED_UP,
    SW_PULLED_DOWN,
}SWITCH_PULL_t;

typedef enum
{
    RELEASED,
    PRESSED,
}SWITCH_STATE_t;

typedef struct 
{
    SWITCh_PORT_t      swPort;
    SWITCh_PIN_t       swPin;
    SWITCh_INPUT_t     swInputType;
    SWITCH_PULL_t      swPullType;
    SWITCH_STATE_t     swState;
}SWITCH_t;



STATUS Switch_init(SWITCH_t* sw);
STATUS Switch_getState(SWITCH_t *sw,SWITCH_STATE_t* state);

#endif
