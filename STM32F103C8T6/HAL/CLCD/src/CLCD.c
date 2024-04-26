#include "..\..\..\MCAL\GPIO\Inc\GPIO.h"
#include "..\inc\CLCD.h"
#include "..\inc\CLCD_private.h"
#include "..\..\..\MCAL\SYSTICK\inc\SYSTick.h"

typedef enum{
    CTRL_PORT = PORTA,
    DATAPORT = PORTB
}LCD_PORTS;

typedef enum{
	DATA0_Nibble = 3,
    EN_PIN = 8,
    RS_PIN = 11,
	DATA0_PIN,
	DATA1_PIN,
	DATA2_PIN,
	DATA3_PIN
}LCD_PINS;

static void LCD_Pins_INIT(){

PIN_CFG_t rs = {
		.mode = OUTPUT_2MHZ,
		.port = CTRL_PORT,
		.pin = RS_PIN,
		.outputType = GP_PUSH_PULL
};

PIN_CFG_t en = {
		.mode = OUTPUT_2MHZ,
		.port = CTRL_PORT,
		.pin = EN_PIN,
		.outputType = GP_PUSH_PULL
};

PIN_CFG_t d0 = {
		.mode = OUTPUT_2MHZ,
		.port = DATAPORT,
		.pin = DATA0_PIN,
		.outputType = GP_PUSH_PULL
};

PIN_CFG_t d1 = {
		.mode = OUTPUT_2MHZ,
		.port = DATAPORT,
		.pin = DATA1_PIN,
		.outputType = GP_PUSH_PULL
};

PIN_CFG_t d2 = {
		.mode = OUTPUT_2MHZ,
		.port = DATAPORT,
		.pin = DATA2_PIN,
		.outputType = GP_PUSH_PULL
};

PIN_CFG_t d3 = {
		.mode = OUTPUT_2MHZ,
		.port = DATAPORT,
		.pin = DATA3_PIN,
		.outputType = GP_PUSH_PULL
};
	GPIO_PinInit(&rs);
	GPIO_PinInit(&en);
	GPIO_PinInit(&d0);
	GPIO_PinInit(&d1);
	GPIO_PinInit(&d2);
	GPIO_PinInit(&d3);
}




void LCD_Init(void)
{   /*4 bit initialisation*/
	LCD_Pins_INIT();
    SYSTICK_delayMS(45);    /*wait for >40ms*/
    LCD_sendCommand(0x30);
    SYSTICK_delayMS(5);     /* wait for >4.1ms*/
    LCD_sendCommand(0x30);
    SYSTICK_delayUS(200);     /* wait for >100us*/
    LCD_sendCommand(0x30);
    SYSTICK_delayUS(200);
    LCD_sendCommand(0x20);  /* 4bit mode*/
    SYSTICK_delayUS(200);
    /*dislay initialisation*/
    LCD_sendCommand(0x28);  /*Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)*/
    SYSTICK_delayUS(200);
    LCD_sendCommand(0x08);  /*Display on/off control --> D=0,C=0, B=0  ---> display off*/
    SYSTICK_delayUS(200);
    LCD_sendCommand(0x01);  /*clear display*/
    SYSTICK_delayUS(200);
    LCD_sendCommand(0x06);  /*Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)*/
    SYSTICK_delayUS(200);
    LCD_sendCommand(0x0c);  /*Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)*/

}

void LCD_sendCommand(uint8_t command)
{   
    /*Set RS LOW to send command*/
    GPIO_SetPinValue(CTRL_PORT,RS_PIN,LOW);
    /*Set Most significant Four Data pins values*/
    GPIO_SetNibbleValue(DATAPORT,DATA0_Nibble,((command>>4)&0x0f));
    /*Set EN to send command*/
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,HIGH);
    SYSTICK_delayUS(30);
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,LOW);
    SYSTICK_delayUs(30);
    /*Set Least significant Four Data pins values*/
    GPIO_SetNibbleValue(DATAPORT,DATA0_Nibble,(command&0x0f));
    /*Set EN to send command*/
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,HIGH);
    SYSTICK_delayUS(30);
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,LOW);
    SYSTICK_delayUs(30);
}

void LCD_sendData(uint8_t data)
{
    /*Set RS LOW to send command*/
    GPIO_SetPinValue(CTRL_PORT,RS_PIN,HIGH);
    /*Set Most significant Four Data pins values*/
    GPIO_SetNibbleValue(DATAPORT,DATA0_Nibble,((data>>4)&0x0f));
    /*Set EN to send command*/
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,HIGH);
    SYSTICK_delayUS(30);
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,LOW);
    SYSTICK_delayUs(30);
    /*Set Least significant Four Data pins values*/
    GPIO_SetNibbleValue(DATAPORT,DATA0_Nibble,(data&0x0f));
    /*Set EN to send command*/
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,HIGH);
    SYSTICK_delayUS(30);
    GPIO_SetPinValue(CTRL_PORT,EN_PIN,LOW);
    SYSTICK_delayUs(30);

}


void LCD_clear (void)
{
	LCD_sendCommand(0x01);
	SYSTICK_delayMS(2);
}
