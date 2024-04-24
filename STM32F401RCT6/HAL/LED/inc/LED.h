#ifndef LED_H_
#define LER_H_

#include "../../../MCAL/RCC/Inc/RCC.h"
#include "../../../MCAL/GPIO/Inc/GPIO.h"
#include "../../../Library/ErrorStates.h"

 

/*********************
 *@LED_t enum
 * 
*/
typedef struct
{    
   LED_PORT_t       port;
   LED_PIN_t        pin;
   ACTIVE_TYPE_t    activeType;
   LED_STATE_t      ledState; 
}LED_t;

/*********************
 * @LED_PORT_t enum
 * 
*/
typedef enum{
    PORTA,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTCOUNT
}LED_PORT_t;

/*********************
 * @LED_PIN_t enum
 * 
*/
typedef enum{
    PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7,
    PIN8,PIN9,PIN10,PIN11,PIN12,PIN13,PIN14,PIN15,PINCOUNT
}LED_PIN_t;

/*********************
 *@LED_STATE_t enum
 * 
*/
typedef enum{
    LED_OFF,
    LED_ON
}LED_STATE_t;

/*********************
 *@ACTIVE_TYPE_t enum
 * 
*/
typedef enum{
    ACTIVE_LOW,
    ACTIVE_HIGH
}ACTIVE_TYPE_t;



STATUS  LED_init(LED_t* led);
STATUS  LED_setState(LED_t* led,LED_STATE_t state);
STATUS  LED_getState(LED_t* led,LED_STATE_t* state);

#endif