#ifndef OSMCAL_H_
#define OSMCAL_H_
#include "stdint.h"
#include "ErrorStates.h"

STATUS  SYSTICK_Init(uint32_t TIME_MS);
__attribute__ ((naked)) void Stack_voidSchedulerStackInit(void);
void Stack_voidTasksStackInit(void);
void OS_CreatTask(void(*Copy_pvTask)());
void Faults_Enable(void);
__attribute__((naked)) void changeToPSP(void);


#endif
