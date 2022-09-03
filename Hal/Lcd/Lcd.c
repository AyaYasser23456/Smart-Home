/*
 * Lcd.c
 *
 * Created: 6/8/2022 1:22:43 AM
 *  Author: Ahmed Hesham
 */ 
#include "Lcd.h"

void H_Lcd_Init				(void)
{
	#if		LCD_MODE	==	_8_BIT_MODE	
	M_Dio_PinMode(LCD_DATA_0_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_1_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_2_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_3_PIN,OUTPUT);
	#elif	LCD_MODE	==	_4_BIT_MODE
	#endif
	M_Dio_PinMode(LCD_DATA_4_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_5_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_6_PIN,OUTPUT);
	M_Dio_PinMode(LCD_DATA_7_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);	
	
	_delay_ms(1000);
	
	#if			LCD_MODE	==	_8_BIT_MODE	
	H_Lcd_WriteCommand(LCD_CMD_SELECT_8_BIT_MODE);				// to select 8 bit mode
	#elif		LCD_MODE	==	_4_BIT_MODE	
	H_Lcd_WriteCommand(0X33);
	H_Lcd_WriteCommand(0X32);
	H_Lcd_WriteCommand(LCD_CMD_SELECT_4_BIT_MODE);				// to select 4 bit mode
	#endif		
	H_Lcd_WriteCommand(LCD_CMD_DISPLAY_ON_CURSOR_OFF);			// to Display ON, cursor OFF
	H_Lcd_WriteCommand(LCD_CMD_CLEAR);							// to clear LCD
	H_Lcd_WriteCommand(LCD_CMD_RETURN_HOME);					// to return home
	//H_Lcd_WriteCommand(LCD_CMD_WRITE_FROM_LEFT_TO_RIGHT);		// to write from left to right

	
}

// void H_Lcd_Init(void)
// {
// 	#if   LCD_MODE          ==        _8_BIT_MODE
// 	M_Dio_PinMode(LCD_DATA_0_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_1_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_2_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_3_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_4_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_5_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_6_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_7_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
// 	_delay_ms(1000);
// 	H_Lcd_WriteCommand(0x38);   // to select 8 bit mode
// 	H_Lcd_WriteCommand(0x0C);   // to Display ON, cursor OFF
// 	H_Lcd_WriteCommand(0x01);   // to clear lcd
// 	H_Lcd_WriteCommand(0x02);   // to return home
// 	#elif LCD_MODE          ==        _4_BIT_MODE
// 	M_Dio_PinMode(LCD_DATA_4_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_5_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_6_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_DATA_7_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_RS_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_RW_PIN,OUTPUT);
// 	M_Dio_PinMode(LCD_EN_PIN,OUTPUT);
// 	_delay_ms(1000);
// 	H_Lcd_WriteCommand(0x33);   // to select 4 bit mode
// 	H_Lcd_WriteCommand(0x32);
// 	H_Lcd_WriteCommand(0x28);
// 	H_Lcd_WriteCommand(0x0C);   // to Display ON, cursor OFF
// 	H_Lcd_WriteCommand(0x01);   // to clear lcd
// 	H_Lcd_WriteCommand(0x02);   // to return home
// 	//H_Lcd_WriteCommand(0x06);
// 	#endif
// }


void H_Lcd_WriteCharacter	(u8 Local_u8_Character)
{
	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
	#if			LCD_MODE	==	_8_BIT_MODE
	LCD_DATA_PORT =  Local_u8_Character;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	#elif		LCD_MODE	==	_4_BIT_MODE
	
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F)| (Local_u8_Character & 0XF0);	
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	

	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F)| (Local_u8_Character << 4);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	#endif 

	
}

// void H_Lcd_WriteCharacter(u8 Local_u8_Character)
// {
// 	#if LCD_MODE          ==          _8_BIT_MODE
// 	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
// 	LCD_DATA_PORT = Local_u8_Character;
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	#elif LCD_MODE          ==        _4_BIT_MODE
// 	M_Dio_PinWrite(LCD_RS_PIN,HIGH);
// 	LCD_DATA_PORT = (( Local_u8_Character & 0xF0 ) | ( LCD_DATA_PORT & 0x0F ));
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	LCD_DATA_PORT =  (( Local_u8_Character << 4 ) | ( LCD_DATA_PORT & 0x0F ));
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	#endif
// }


void H_Lcd_WriteCommand		(u8 Local_u8_Command)
{
	M_Dio_PinWrite(LCD_RS_PIN,LOW);
	#if			LCD_MODE	==	_8_BIT_MODE
	LCD_DATA_PORT =  Local_u8_Command;
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	
	#elif		LCD_MODE	==	_4_BIT_MODE
	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (Local_u8_Command & 0XF0);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);

	LCD_DATA_PORT = (LCD_DATA_PORT & 0X0F) | (Local_u8_Command << 4);
	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
	_delay_ms(1);
	M_Dio_PinWrite(LCD_EN_PIN,LOW);
	_delay_ms(5);
	#endif

}

// void H_Lcd_WriteCommand(u8 Local_u8_Command)
// {
// 	#if LCD_MODE          ==          _8_BIT_MODE
// 	M_Dio_PinWrite(LCD_RS_PIN,LOW);
// 	LCD_DATA_PORT = Local_u8_Command;
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	#elif LCD_MODE          ==        _4_BIT_MODE
// 	M_Dio_PinWrite(LCD_RS_PIN,LOW);
// 	LCD_DATA_PORT = (( Local_u8_Command & 0xF0 ) | ( LCD_DATA_PORT & 0x0F ));
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	LCD_DATA_PORT =  (( Local_u8_Command << 4 ) | ( LCD_DATA_PORT & 0x0F ));
// 	M_Dio_PinWrite(LCD_EN_PIN,HIGH);
// 	_delay_ms(1);
// 	M_Dio_PinWrite(LCD_EN_PIN,LOW);
// 	_delay_ms(5);
// 	#endif
// }

void H_Lcd_WriteNumber		(s32 Local_s32_Number)
{
 	s32 check_reminder = Local_s32_Number;
 	if (Local_s32_Number == 0)
 	{
 		H_Lcd_WriteCharacter('0');
 	}
 	check_reminder*=1000;
 	
 	if ((check_reminder % 1000)== 0)
 	{
 		if (Local_s32_Number < 0)
 		{
 		
 			H_Lcd_WriteCharacter('-');
 			Local_s32_Number = Local_s32_Number * -1;
 		}
 		if (Local_s32_Number > 0)
 		{
 			u32 Local_u32_Printed_Number = Local_s32_Number;
 			u8  Local_u8_DigitCounter = 0;
 			while (Local_u32_Printed_Number)
 			{
 				if (Local_u32_Printed_Number)
 				{
 					Local_u32_Printed_Number/= 10;
 					Local_u8_DigitCounter++;
 				}
 
 			}
 			u32 arr[Local_u8_DigitCounter] ;
 			u32 Local_u8_ArrCounter = 0;
 			while (Local_u8_ArrCounter < Local_u8_DigitCounter)
 			{
 				Local_u8_ArrCounter ++;
 				arr[Local_u8_DigitCounter-Local_u8_ArrCounter] = Local_s32_Number % 10;
 				Local_s32_Number /= 10;
 			
 			}
 			Local_u8_ArrCounter = 0;
 			while (Local_u8_ArrCounter < Local_u8_DigitCounter)
 			{
 				H_Lcd_WriteCharacter(arr[Local_u8_ArrCounter]+48);
 				Local_u8_ArrCounter++;
 			}	
 		}
 	}
 	
 }

// void H_Lcd_WriteNumber(s32 Local_s32_Number)
// {
// 	if(Local_s32_Number == 0)
// 	{
// 		H_Lcd_WriteCharacter('0');
// 	}
// 	if(Local_s32_Number < 0)
// 	{
// 		H_Lcd_WriteCharacter('-');
// 		Local_s32_Number = Local_s32_Number * -1;
// 	}
// 	if(Local_s32_Number > 0)
// 	{
// 		u8 Local_u8_Arr [10] = {0};
// 		s8 Local_s8_Counter  = 0;
// 		while(Local_s32_Number != 0)
// 		{
// 			Local_u8_Arr[Local_s8_Counter] = Local_s32_Number % 10;
// 			Local_s8_Counter++;
// 			Local_s32_Number = Local_s32_Number / 10;
// 		}
// 		Local_s8_Counter--;
// 		while(Local_s8_Counter > -1)
// 		{
// 			H_Lcd_WriteCharacter(Local_u8_Arr[Local_s8_Counter] + 48);
// 			Local_s8_Counter--;
// 		}
// 	}
// }

void H_Lcd_Clear (void)
{
	
	H_Lcd_WriteCommand(LCD_CMD_CLEAR);	// to clear LCD
	H_Lcd_GoTo(0,0);
}

void H_Lcd_GoTo	(u8 Local_u8_Row,u8 Local_u8_Coloumn )
{
	u8 arr [2] = {LCD_CMD_FIRST_ROW, LCD_CMD_SECOND_ROW};
	H_Lcd_WriteCommand(arr [Local_u8_Row] + Local_u8_Coloumn);
	
}

void H_Lcd_WriteString		(u8* Local_u8_PtrToString)
{
	u8 Local_u8_Counter = 0;
	while (Local_u8_PtrToString[Local_u8_Counter] != '\0')
	{
		H_Lcd_WriteCharacter(Local_u8_PtrToString[Local_u8_Counter]);
		Local_u8_Counter++;
		if (Local_u8_Counter == 16)
		{
			H_Lcd_GoTo(1,0);
		}
	}
}