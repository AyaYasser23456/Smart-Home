/*
 * Reg.h
 *
 * Created: 6/2/2022 3:24:39 AM
 *  Author: Hesham
 */ 

#include "StdTypes.h"

#ifndef REG_H_
#define REG_H_

/********************************_DIO_REGISTERS_**********************************/
#define DDRA		(*(volatile u8*)0x3A)
#define PORTA		(*(volatile u8*)0x3B)
#define PINA		(*(volatile u8*)0x39)

#define DDRB		(*(volatile u8*)0x37)
#define PORTB		(*(volatile u8*)0x38)
#define PINB		(*(volatile u8*)0x36)

//#define DDRC		(*((volatile Uint8 *)  (0X34)))
#define DDRC		(*(volatile u8*)0x34)
#define PORTC		(*(volatile u8*)0x35)
#define PINC		(*(volatile u8*)0x33)
								 
#define DDRD		(*(volatile u8*)0x31)
#define PORTD		(*(volatile u8*)0x32)
#define PIND		(*(volatile u8*)0x30)

/********************************_INTERRUPTS_REGISTERS_**********************************/
#define MCUCR		(*(volatile u8*)0x55)			/*MCU Control Register*/
#define ISC00		bit0
#define ISC01		bit1
#define ISC10		bit2
#define ISC11		bit3

#define MCUCSR		(*(volatile u8*)0x54)			/*MCU Control and Status Register*/
#define ISC2		bit6
#define WDRF		bit3

#define GICR		(*(volatile u8*)0x5B)			/*General Interrupt Control Register*/
#define INT1		bit7
#define INT0		bit6
#define INT2		bit5

/********************************_SREG_REGISTER_**********************************/
#define SREG		(*(volatile u8*)0x5F)			/*AVR Status Register*/
#define Ibit		bit7							/*Global Interrupt Enable*/	

/********************************_ADC_REGISTERS_**********************************/
#define ADMUX		(*(volatile u8*)0x27)			/*ADC Multiplexer Selection Register*/
#define REF1		bit7							/*Reference Selection Bits*/
#define REF0		bit6							/*Reference Selection Bits*/
#define ADLAR		bit5							/*ADC Left Adjust Result*/
#define MUX4		bit4							/*Analog Channel and Gain Selection Bits*/
#define MUX3		bit3							/*Analog Channel and Gain Selection Bits*/
#define MUX2		bit2							/*Analog Channel and Gain Selection Bits*/
#define MUX1		bit1							/*Analog Channel and Gain Selection Bits*/
#define MUX0		bit0							/*Analog Channel and Gain Selection Bits*/

#define ADCSRA		(*(volatile u8*)0x26)			/*ADC Control and Status Register A*/
#define ADEN		bit7							/*ADC Enable*/
#define ADSC		bit6							/*ADC Start Conversion*/
#define ADATE		bit5							/*ADC Auto Trigger Enable*/
#define ADIF		bit4							/*ADC Interrupt Flag*/
#define ADIE		bit3							/*ADC Interrupt Enable*/
#define ADPS2		bit2							/*ADC Prescaler Select Bits*/
#define ADPS1		bit1							/*ADC Prescaler Select Bits*/
#define ADPS0		bit0							/*ADC Prescaler Select Bits*/

#define ADCH		(*(volatile u8*)0x25)

#define ADCL		(*(volatile u8*)0x24)

/********************************_TIMER0_REGISTERS_**********************************/
#define TCCR0		(*(volatile u8*)0x53)
#define FOC0		bit7
#define WGM00		bit6
#define COM01		bit5
#define	COM00		bit4
#define WGM01		bit3
#define CS02		bit2
#define	CS01		bit1
#define	CS00		bit0

#define TIMSK		(*(volatile u8*)0x59)			/*Timer/Counter Interrupt Mask Register*/
#define OCIE2		bit7
#define TOIE2		bit6
#define TICIE1		bit5
#define	OCIE1A		bit4
#define OCIE1B		bit3
#define TOIE1		bit2
#define	OCIE0		bit1
#define	TOIE0		bit0

#define TCNT0		(*(volatile u8*)0x52)

#define OCR0		(*(volatile u8*)0x5C)

/********************************_TIMER1_REGISTERS_**********************************/
#define ICR1		(*(volatile u16*)0x46)
#define ICR1L		(*(volatile u8*)0x46)
#define ICR1H		(*(volatile u8*)0x47)

#define OCR1A		(*(volatile u16*)0x4A)
#define OCR1AL		(*(volatile u8*)0x4A)
#define OCR1AH		(*(volatile u8*)0x4B)
#define OCR1B		(*(volatile u16*)0x48)
#define OCR1BL		(*(volatile u8*)0x48)
#define OCR1BH 		(*(volatile u8*)0x49)


#define TCNT1		(*(volatile u16*)0x4C)
#define TCNT1L		(*(volatile u8*)0x4C)
#define TCNT1H		(*(volatile u8*)0x4D)

#define TCCR1		(*(volatile u16*)0x4E)
#define TCCR1A		(*(volatile u8*)0x4F)
#define TCCR1B		(*(volatile u8*)0x4E)
#define COM1A1		bit7
#define COM1A0		bit6
#define COM1B1		bit5
#define COM1B0		bit4
#define FOC1A		bit3
#define FOC1B		bit2
#define WGM11		bit1
#define WGM10		bit0
#define ICNC1		bit7
#define ICES1		bit6
#define WGM13		bit4
#define WGM12		bit3
#define CS12		bit2
#define	CS11		bit1
#define	CS10		bit0

/********************************_WATCH_DOG_TIMER_REGISTERS_**********************************/
#define WDTCR		(*(volatile u8*)0x41)
#define WDTOE		bit4 
#define WDE			bit3
#define WDP2		bit2
#define WDP1		bit1
#define WDP0		bit0


/********************************_I2C_REGISTERS_**********************************/
#define TWAR 		(*(volatile u8*)0x22)
#define TWA6		bit7
#define TWA5		bit6
#define TWA4		bit5
#define TWA3		bit4
#define TWA2		bit3
#define TWA1		bit2
#define TWA0		bit1
#define TWGCE		bit0



#define TWDR		(*(volatile u8*)0x23)
#define TWD7		bit7
#define TWD6		bit6
#define TWD5		bit5
#define TWD4		bit4
#define TWD3		bit3
#define TWD2		bit2
#define TWD1		bit1
#define TWD0		bit0


#define TWSR		(*(volatile u8*)0x21)
#define TWS7		bit7
#define TWS6		bit6
#define TWS5		bit5
#define TWS4		bit4
#define TWS3		bit3
#define TWPS1		bit1
#define TWPS0		bit0

#define TWCR		(*(volatile u8*)0x56)
#define TWINT		bit7
#define TWEA		bit6
#define TWSTA		bit5
#define TWSTO		bit4
#define TWWC		bit3
#define TWEN		bit2
#define TWIE		bit0

#define TWBR	    (*(volatile u8*)0x20)
#define TWBR7		bit7
#define TWBR6		bit6
#define TWBR5		bit5
#define TWBR4		bit4
#define TWBR3		bit3
#define TWBR2		bit2
#define TWBR1		bit1
#define TWBR0		bit0

/********************************_TIMER1_REGISTERS_**********************************/
#define TCCR2		(*(volatile u8*)0x45)
#define FOC2		bit7
#define WGM20		bit6
#define COM21		bit5
#define	COM20		bit4
#define WGM21		bit3
#define CS22		bit2
#define	CS21		bit1
#define	CS20		bit0

#define TCNT2		(*(volatile u8*)0x44)

#define OCR2		(*(volatile u8*)0x43)
 

/*****************************_UART_REGISTERS_**********************************/
#define UDR              *((volatile u8*)0x2C)
#define UCSRA            *((volatile u8*)0x2B)
#define UCSRB            *((volatile u8*)0x2A)
#define UCSRC            *((volatile u8*)0x40)
#define UBRRL            *((volatile u8*)0x29)
#define UBRRH            *((volatile u8*)0x40)




#endif /* REG_H_ */