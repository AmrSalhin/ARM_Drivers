#include <OSMCAL.h>
#include <OSMCAL_cfg.h>
#include "stm32f401rct6.h"
#include "ErrorStates.h"

/*************************           peripheral Definition           **************************/

#define SYSTICK    ((SYSTICK_REG_t *)SysTick_BASE_ADDRESS)
#define SCB	  	   ((SCB_REG_t*)SCB_BASE_ADDRESS)



/*************************            Global Variables				***********************/
/*array of pointers to FUNC*/
void(*pv_Task[MAX_NUM_OF_TASKS])() = {NULL};
uint32_t psp[MAX_NUM_OF_TASKS] = {T1_STACK_START,T2_STACK_START,T3_STACK_START,T4_STACK_START};

uint8_t currentTask = 0;

/*********************************************************************************
*@fn SYSTICK_Init
*@brief the function the function Reload Systick with required TICK time in milli seconds
*@param[in] TIME_MS  the required TIME
*@retval STATUS
*/
STATUS  SYSTICK_Init(uint32_t TIME_MS)
{
    /*SYStem CLK HSI 16MHZ*/
    /*MAX TIME = */
    STATUS  errorState = OK;
    uint32_t reloadValue = 0;
    reloadValue = TIME_MS * FREQUENCY_IN_KHZ - 1;
    if(reloadValue < MAXMUM_TICKS_NUM){
    SYSTICK->SYST_RVR = reloadValue;
    /*SYSTICK Interrupet Enable*/
    SYSTICK->SYST_CSR.bit.TICKINT = 1;
    /*Set CLK SRC*/
    SYSTICK->SYST_CSR.bit.CLKSOURCE = 1;
    /*SYSTICK Start*/
    SYSTICK->SYST_CSR.bit.ENABLE = 1;
    }
    else{
        errorState = NOK;
    }
    
    
    return errorState;
}

void OS_CreatTask(void(*Copy_pvTask)())
{
	static uint8_t Tasks_counter = 0;
	if(Tasks_counter < MAX_NUM_OF_TASKS)
	{
		pv_Task[Tasks_counter] = Copy_pvTask;
		Tasks_counter++;
	}
	else
	{

	}
}

__attribute__ ((naked)) void Stack_voidSchedulerStackInit(void)
{
	__asm volatile ("MSR MSP , %0"::"r"(SCHED_STACK_START));
	__asm volatile ("BX LR");
}

void Stack_voidTasksStackInit(void)
{
	uint8_t i, j;
	uint32_t* Local_pvSP;
	for(i = 0; i<MAX_NUM_OF_TASKS; i++)
	{
		Local_pvSP = (uint32_t*) psp[i];
		Local_pvSP--;
		*Local_pvSP = DUMMY_PSR;
		Local_pvSP--;
		*Local_pvSP = (uint32_t) pv_Task[i];
		Local_pvSP--;
		*Local_pvSP = DUMMY_LR;
		for(j = 0; j<13; j++)
		{
			Local_pvSP--;
			*Local_pvSP = 0;
		}
		psp[i] = (uint32_t) Local_pvSP;
	}

}

void Faults_Enable(void)
{
	SCB->SHCRS |= (7<<16);
}

uint32_t getCurrentPSPValue(void)
{
	return psp[currentTask];
}

__attribute__((naked)) void changeToPSP(void)
{
	/*initialize PSP with Task PSP*/
	__asm volatile("PUSH {LR}");

	__asm volatile("BL getCurrentPSPValue");

	__asm volatile("MSR PSP , R0");

	__asm volatile("POP {LR}");

	/*Change control to PSP*/
	__asm volatile("MOV R0 , #0x02");

	__asm volatile("MSR CONTROL , R0");

	__asm volatile("BX LR");
}

void SavePSPValue(uint32_t copy_u32PSPValue)
{
	psp[currentTask] = copy_u32PSPValue;
}

void UpdateNextTask(void)
{
	currentTask++;

	currentTask %= MAX_NUM_OF_TASKS;
}

__attribute__((naked)) void  SysTick_Handler()
{
	/*1- Save Context for current Task*/
		/*1- get the Current value of PSP*/
		__asm volatile("MRS R0 , PSP");

		/*2- PUSH Registers {R4-R11} into Task Stack*/
		__asm volatile("STMDB R0!, {R4-R11}");

		__asm volatile("PUSH {LR}");

		/*3- Save the PSP Value*/
		__asm volatile("BL SavePSPValue");


	/*2- retrieve Context for the next Task*/
		/*1- decide which task to run*/
		__asm volatile("BL UpdateNextTask");

		/*2- get PSP value*/
		__asm volatile("BL getCurrentPSPValue");

		__asm volatile("POP {LR}");

		/*3- Use PSP to retrieve {R4-R11}*/
		__asm volatile("LDM R0! , {R4-R11}");

		/*4- Update PSP value*/
		__asm volatile("MSR PSP, R0");

		/*5- EXIT*/
		__asm volatile("BX LR");

}


