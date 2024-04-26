#ifndef CLCD_H_
#define CLCD_H_

#include "stdint.h"



void    LCD_Init(void);
void    LCD_sendCommand(uint8_t command);
void 	LCD_clear (void);
void    LCD_sendData(uint8_t data);
void    LCD_sendString(const char* string);
void    LCD_goToPos(uint8_t lineNum,uint8_t columnNum);
void    LCD_sendNumber(uint32_t number);
void    LCD_sendCommand(uint8_t command);
void    LCD_WriteSpecialCharacter(uint8_t* Copy_puPattern,uint8_t Copy_u8PatternNumber,uint8_t Copy_u8XPos,uint8_t Copy_u8YPos);

#endif
