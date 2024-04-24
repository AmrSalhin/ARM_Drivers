#ifndef GPIO_H_
#define GPIO_H_

#include "..\..\..\Library\stm32f401rct6.h"
#include "..\..\..\Library\ErrorStates.h"
#include "..\..\..\Library\BIT_MATH.h"


/*******************************        DATA TYPES         ******************************/

/*******************
 * @PIN_STATE_t enum
 * 
*/
typedef enum{
    LOW,
    HIGH,
}PIN_STATE_t;
/*********************
 * @PORT_t enum
 * 
*/
typedef enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTH,
    PORTCOUNT
}PORT_t;

/*********************
 * @PIN_t enum
 * 
*/
typedef enum{
    PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,
    PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15,PINCOUNT
}PIN_t;

typedef enum{
    INPUT,
    OUTPUT,
    ALTERNATE_FUNCTION,
    ANALOG
}MODE_t;

typedef enum{
    LOW_SPEED,
    MEDIUM_SPEED,
    HIGH_SPEED,
    VERY_HIGH_SPEED
}SPEED_t;

typedef enum{
    PUSH_PULL,
    OPEN_DRAIN,
}OUTPUT_TYPE_t;

typedef enum{
    NO_PULL,
    PULL_UP,
    PULL_DOWN
}PULL_t;

typedef enum{
    AF0,AF1,AF2,AF3,AF4,AF5,AF6,AF7,
    AF8,AF9,AF10,AF11,AF12,AF13,AF14,AF15
}ALTFUNC_t;

typedef struct
{
    PORT_t           port;
    PIN_t            pin;
    MODE_t           mode;
    SPEED_t          speed;
    OUTPUT_TYPE_t    outputType;
    PULL_t           pullType;
    ALTFUNC_t        altFunc;
}PIN_CFG_t;


/*******************************        GLOBAL FUNCTIONS         ******************************/

STATUS  GPIO_PinInit(const PIN_CFG_t* gpioCfg);
STATUS  GPIO_SetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t value);
STATUS  GPIO_TogglePinValue(PORT_t port,PIN_t pin);
STATUS  GPIO_GetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t* value);

#endif
