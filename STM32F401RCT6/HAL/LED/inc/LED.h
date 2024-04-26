#ifndef LED_H_
#define LER_H_


#include "../../../Library/ErrorStates.h"

 
/*********************
 * @LED_PORT_t enum
 * 
*/
typedef enum{
    LED_PORTA,
	LED_PORTB,
	LED_PORTC,
	LED_PORTD,
	LED_PORTE,
	LED_PORTCOUNT
}LED_PORT_t;

/*********************
 * @LED_PIN_t enum
 * 
*/
typedef enum{
	LED_PIN0,LED_PIN1,LED_PIN2,LED_PIN3,LED_PIN4,LED_PIN5,LED_PIN6,LED_PIN7,
	LED_PIN8,LED_PIN9,LED_PIN10,LED_PIN11,LED_PIN12,LED_PIN13,LED_PIN14,LED_PIN15,LED_PINCOUNT
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





STATUS  LED_init(LED_t* led);
STATUS  LED_setState(LED_t* led,LED_STATE_t state);
STATUS  LED_getState(LED_t* led,LED_STATE_t* state);

#endif
