#ifndef GPIO_H_
#define GPIO_H_

#include "..\..\..\Library\stm32f103c8t6.h"
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
/*********************
 * @MODE_t enum
 * 
*/
typedef enum{
    INPUT,
    OUTPUT_10MHZ,
    OUTPUT_2MHZ,
    OUTPUT_50MHZ
}MODE_t;
/*********************
 * @INPUT_t enum
 * 
*/
typedef enum{
    Analog,
    Floating_INPUT,
    PUSH_PULL_INPUT,
}INPUT_TYPE_t;
/*********************
 * @OUTPUT_TYPE_t enum
 * 
*/
typedef enum{
    GP_PUSH_PULL,
    GP_OPEN_DRAIN,
    AF_PUSH_PULL,
    AF_OPEN_DRAIN
}OUTPUT_TYPE_t;

/*********************
 * @PULLTYPE_t enum
 * 
*/
typedef enum{
    PULL_DOWN,
    PULL_UP,
}PULLTYPE_t;

/*********************
 * @PIN_CFG_t struct
 * 
*/
typedef struct
{
    PORT_t           port;
    PIN_t            pin;
    MODE_t           mode;
    OUTPUT_TYPE_t    outputType;
    INPUT_TYPE_t     inputType;
    PULLTYPE_t       pullType;
}PIN_CFG_t;


/*******************************        GLOBAL FUNCTIONS         ******************************/

STATUS  GPIO_PinInit(const PIN_CFG_t* gpioCfg);
STATUS  GPIO_SetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t value);
STATUS  GPIO_SetNibbleValue(PORT_t port,uint8_t nibble,uint8_t value);
STATUS  GPIO_TogglePinValue(PORT_t port,PIN_t pin);
STATUS  GPIO_GetPinValue(PORT_t port,PIN_t pin,PIN_STATE_t* value);

#endif