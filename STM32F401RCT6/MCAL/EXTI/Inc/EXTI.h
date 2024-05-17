#ifndef EXTI_H_
#define EXTI_H_

#include "stdint.h"
#include "../../../Library/ErrorStates.h"

/**
 * @typedef EXTI_LINE_NUM
*/
typedef enum{
    LINE_0,
    LINE_1,
    LINE_2,
    LINE_3,
    LINE_4,
    LINE_5,
    LINE_6,
    LINE_7,
    LINE_8,
    LINE_9,
    LINE_10,
    LINE_11,
    LINE_12,
    LINE_13,
    LINE_14,
    LINE_15,
    LINE_16,
    LINE_17,
    LINE_18,
    LINE_21 = 21,
    LINE_22,
    LINES_COUNT
}EXTI_LINE_NUM;

/**
 * @typedef EXTI_EDGE
*/
typedef enum{
    FALLING_EDGE,
    RISING_EDGE,
    ON_CHANGE,
}EXTI_EDGE;

/**
 * @typedef INTERRUPET_STATUS
*/
typedef enum{
    INTERRUPET_DISABLE,
    INTERRUPET_ENABLE,
}INTERRUPET_STATUS;

/**
 * @typedef EVENT_STATUS;

*/
typedef enum{
    EVENT_DISABLE,
    EVENT_ENABLE,
}EVENT_STATUS;

typedef struct
{
    EXTI_LINE_NUM     line_num;
    EXTI_EDGE         edge;
    INTERRUPET_STATUS intState;
    EVENT_STATUS      eventState;
}EXTI_CFG_t;


STATUS  EXTI_init(EXTI_CFG_t* cfg);
STATUS  EXTI_Set_edge(EXTI_LINE_NUM lineNum,EXTI_EDGE edge);
STATUS  EXTI_ENABLE_Int(EXTI_LINE_NUM lineNum);
STATUS  EXTI_Disable_Int(EXTI_LINE_NUM lineNum);
STATUS  EXTI_ENABLE_Eve(EXTI_LINE_NUM lineNum);
STATUS  EXTI_Disable_Eve(EXTI_LINE_NUM lineNum);
STATUS  EXTI_CLear_Flag(EXTI_LINE_NUM lineNum);
uint8_t EXTI_Read_Flag(EXTI_LINE_NUM lineNum);

STATUS  EXTI0_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI1_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI2_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI3_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI4_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI5_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI6_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI7_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI8_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI9_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI10_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI11_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI12_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI13_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI14_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI15_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI16_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI17_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI18_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI21_SetCallBack(void (*CopyFun)(void));
STATUS  EXTI22_SetCallBack(void (*CopyFun)(void));

#endif // NVIC_H_
