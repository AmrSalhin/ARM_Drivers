#ifndef SYSCFG_H_
#define SYSCFG_H_

#include "stdint.h"
#include "../../../Library/ErrorStates.h"

typedef enum{
PA,
PB,
PC,
PD,
PE,
PH = 7,
}Px;

typedef enum{
    SYSCFG_LINE_0,
    SYSCFG_LINE_1,
    SYSCFG_LINE_2,
    SYSCFG_LINE_3,
    SYSCFG_LINE_4,
    SYSCFG_LINE_5,
    SYSCFG_LINE_6,
    SYSCFG_LINE_7,
    SYSCFG_LINE_8,
    SYSCFG_LINE_9,
    SYSCFG_LINE_10,
    SYSCFG_LINE_11,
    SYSCFG_LINE_12,
    SYSCFG_LINE_13,
    SYSCFG_LINE_14,
    SYSCFG_LINE_15,
    SYSCFG_LINE_16,
    SYSCFG_LINE_17,
    SYSCFG_LINE_18,
    SYSCFG_LINE_21 = 21,
    SYSCFG_LINE_22,
    SYSCFG_LINES_COUNT
}SYSCFG_LINE_NUM;

STATUS  SYSCFG_SetEXTIPort(Px portNum,SYSCFG_LINE_NUM lineNum);

#endif // NVIC_H_
