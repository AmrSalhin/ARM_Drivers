#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "stdint.h"
#include "..\..\..\Library\ErrorStates.h"
#include "..\..\..\Library\BIT_MATH.h"


STATUS  SYSTICK_delayMS(uint32_t TIME_MS);
STATUS  SYSTICK_delayUS(uint32_t TIME_US);

#endif