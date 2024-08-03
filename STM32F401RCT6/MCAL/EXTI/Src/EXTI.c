#include "..\inc\EXTI.h"
#include "..\inc\EXTI_private.h"
#include "../../../Library/stm32f401rct6.h"

#define EXTI    ((EXTI_REG_t*)EXTI_BASE_ADDRESS)

static void (*pvFunc[LINES_COUNT])(void) = {NULL};



STATUS EXTI_init(EXTI_CFG_t *cfg)
{
    STATUS errorStatus = OK;
    
    errorStatus = EXTI_Set_edge(cfg->line_num, cfg->edge);
    if(cfg->intState == INTERRUPET_ENABLE)
    {
        errorStatus = EXTI_ENABLE_Int(cfg->line_num);
    }
    else if (cfg->intState == INTERRUPET_DISABLE)
    {
        errorStatus = EXTI_Disable_Int(cfg->line_num);
    }
    else{
        errorStatus = NOK;
    }

    if(cfg->eventState == EVENT_ENABLE)
    {
        errorStatus = EXTI_ENABLE_Eve(cfg->line_num);
    }
    else if (cfg->eventState == EVENT_DISABLE)
    {
        errorStatus = EXTI_Disable_Eve(cfg->line_num);
    }
    else{
        errorStatus = NOK;
    }    


    return errorStatus;
}

STATUS EXTI_Set_edge(EXTI_LINE_NUM lineNum,EXTI_EDGE edge)
{
    STATUS errorStatus = OK;
    if(lineNum < LINES_COUNT)
    {
        if(edge == RISING_EDGE)
        {
            EXTI->FTSR &= ~(1<<lineNum); 
            EXTI->RTSR |=  (1<<lineNum);
        }
        else if(edge == FALLING_EDGE)
        {
            EXTI->RTSR &= ~(1<<lineNum); 
            EXTI->FTSR |=  (1<<lineNum);
        }
        else if(edge == ON_CHANGE)
        {
            EXTI->FTSR |=  (1<<lineNum);
            EXTI->RTSR |=  (1<<lineNum);
        }
        else
        {
            errorStatus = NOK;
        }
        
    }
    else{
        errorStatus = NOK;
    }
    return errorStatus;
}

STATUS EXTI_ENABLE_Int(EXTI_LINE_NUM lineNum)
{
    STATUS errorStatus = OK;
    if(lineNum <LINES_COUNT)
    {
        EXTI->IMR |= (1<<lineNum);
    }
    else
    {
        errorStatus = NOK;
    }
    return errorStatus;
}

STATUS EXTI_Disable_Int(EXTI_LINE_NUM lineNum)
{
    STATUS errorStatus = OK;
    if(lineNum <LINES_COUNT)
    {
        EXTI->IMR &= ~(1<<lineNum);
    }
    else
    {
        errorStatus = NOK;
    }
    return errorStatus;
}

STATUS EXTI_ENABLE_Eve(EXTI_LINE_NUM lineNum)
{
    STATUS errorStatus = OK;
    if(lineNum <LINES_COUNT)
    {
        EXTI->EMR |= (1<<lineNum);
    }
    else
    {
        errorStatus = NOK;
    }
    return errorStatus;
}

STATUS EXTI_Disable_Eve(EXTI_LINE_NUM lineNum)
{
    STATUS errorStatus = OK;
    if(lineNum <LINES_COUNT)
    {
        EXTI->EMR &= ~(1<<lineNum);
    }
    else
    {
        errorStatus = NOK;
    }
    return errorStatus;
}

STATUS EXTI_CLear_Flag(EXTI_LINE_NUM lineNum)
{
    STATUS errorStatus = OK;
    if(lineNum <LINES_COUNT)
    {   /*Clearing by set 1*/
        EXTI->PR |= (1<<lineNum);
    }
    else
    {
        errorStatus = NOK;
    }
    return errorStatus;
}

uint8_t EXTI_Read_Flag(EXTI_LINE_NUM lineNum)
{
    return (((EXTI->PR>>lineNum)&1));
}

STATUS EXTI0_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_0] = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI1_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_1]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI2_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_2]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI3_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_3]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI4_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_4]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI5_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_5]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI6_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_6]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI7_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_7]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI8_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_8]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI9_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_9]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI10_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_10]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI11_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_11]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI12_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_12]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI13_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_13]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI14_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_14]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI15_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_15]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI16_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_16]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI17_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_17]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI18_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_18]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI21_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_21]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

STATUS EXTI22_SetCallBack(void (*CopyFun)(void))
{
    STATUS errorStatus = OK;
    if(CopyFun != NULL)
    {
        pvFunc[LINE_22]  = CopyFun;
    }
    else
    {
        errorStatus = NULLPTR;
    }
    return errorStatus;
}

void EXTI0_IRQHandler(){
    EXTI_CLear_Flag(LINE_0);
    if(pvFunc[LINE_0]  != NULL){
        pvFunc[LINE_0] ();
    }
}
void EXTI1_IRQHandler(){
    EXTI_CLear_Flag(LINE_1);
    if(pvFunc[LINE_1]  != NULL){
        pvFunc[LINE_1] ();
    }
}
void EXTI2_IRQHandler(){
    EXTI_CLear_Flag(LINE_2);
    if(pvFunc[LINE_2]  != NULL){
        pvFunc[LINE_2] ();
    }
}
void EXTI3_IRQHandler(){
    EXTI_CLear_Flag(LINE_3);
    if(pvFunc[LINE_3]  != NULL){
        pvFunc[LINE_3] ();
    }
}
void EXTI4_IRQHandler(){
    EXTI_CLear_Flag(LINE_4);
    if(pvFunc[LINE_4]  != NULL){
        pvFunc[LINE_4] ();
    }
}
void EXTI9_5_IRQHandler(){
    if(EXTI5_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_5);
    if(pvFunc[LINE_5]  != NULL){
        pvFunc[LINE_5] ();
    }
    }
    if(EXTI6_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_6);
    if(pvFunc[LINE_6]  != NULL){
        pvFunc[LINE_6] ();
    }
    }
    if(EXTI7_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_7);
    if(pvFunc[LINE_7]  != NULL){
        pvFunc[LINE_7] ();
    }
    }
    if(EXTI8_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_8);
    if(pvFunc[LINE_8]  != NULL){
        pvFunc[LINE_8] ();
    }
    }
    if(EXTI9_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_9);
    if(pvFunc[LINE_9]  != NULL){
        pvFunc[LINE_9] ();
    }
    }
}
void EXTI15_10_IRQHandler()
{
    if(EXTI10_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_10);
    if(pvFunc[LINE_10]  != NULL){
        pvFunc[LINE_10] ();
    }
    }
    if(EXTI11_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_11);
    if(pvFunc[LINE_11]  != NULL){
        pvFunc[LINE_11] ();
    }
    }
    if(EXTI12_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_12);
    if(pvFunc[LINE_12]  != NULL){
        pvFunc[LINE_12] ();
    }
    }
    if(EXTI13_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_13);
    if(pvFunc[LINE_13]  != NULL){
        pvFunc[LINE_13] ();
    }
    }
    if(EXTI14_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_14);
    if(pvFunc[LINE_14]  != NULL){
        pvFunc[LINE_14] ();
    }
    }
    if(EXTI15_FLAG == RAISED)
    {
    EXTI_CLear_Flag(LINE_15);
    if(pvFunc[LINE_15]  != NULL){
        pvFunc[LINE_15] ();
    }
    }
}
void EXTI16_PVD_IRQHandler(){
    EXTI_CLear_Flag(LINE_16);
    if(pvFunc[LINE_16]  != NULL){
        pvFunc[LINE_16] ();
    }
}
void EXTI17_RTC_Alarm_IRQHandler(){
    EXTI_CLear_Flag(LINE_17);
    if(pvFunc[LINE_17]  != NULL){
        pvFunc[LINE_17] ();
    }
}
void EXTI18_OTG_FS_WKUP_IRQHandler(){
        EXTI_CLear_Flag(LINE_18);
    if(pvFunc[LINE_18]  != NULL){
        pvFunc[LINE_18] ();
    }
}
void TAMP_STAMP_IRQHandler(){
    EXTI_CLear_Flag(LINE_21);
    if(pvFunc[LINE_21]  != NULL){
        pvFunc[LINE_21]();
    }
}
void EXTI22_RTC_WKUP_IRQHandler(){
    EXTI_CLear_Flag(LINE_22);
    if(pvFunc[LINE_22]  != NULL){
        pvFunc[LINE_22] ();
    }
}

