/*
 * Adc.c
 *
 * Created: 6/16/2022 2:12:32 PM
 *  Author: Ahmed Hesham
 */ 
#include "Adc.h"

void (* Adc_void_CallBack) (void);

void M_Adc_Init (void)
{
	
	M_Dio_PinMode(PA1, INPUT);
	/* Step 1	->		Set Voltage Reference  */
	#if			VOLTAGE_REFERENCE		==		AREF
	ClrBit(ADMUX,REF0);
	ClrBit(ADMUX,REF1);
	#elif		VOLTAGE_REFERENCE		==		AVCC
	SetBit(ADMUX,REF0);
	ClrBit(ADMUX,REF1);
	#elif		VOLTAGE_REFERENCE		==		VREF
	SetBit(ADMUX,REF0);
	SetBit(ADMUX,REF1);
	#endif
	
	/* Step 2	->		Set Left Adjust Result  */
	#if			LEFT_ADJUST_RESULT		==		RIGHT_ADJUST
	ClrBit(ADMUX,ADLAR);
	#elif		LEFT_ADJUST_RESULT		==		LEFT_ADJUST
	SetBit(ADMUX,ADLAR);
	#endif				
	
	/* Step 3	->		Set Pin Used  */
	ClrBit(ADMUX,MUX4); ClrBit(ADMUX,MUX3); ClrBit(ADMUX,MUX2); ClrBit(ADMUX,MUX1); ClrBit(ADMUX,MUX0);
	
	/* Step 4	->		Set ADC Prescaler Selection */
	#if			PRESCALER_SELECTION		==		DIVISION_FACTOR_1
	ClrBit(ADCSRA,ADPS2); ClrBit(ADCSRA,ADPS1);	ClrBit(ADCSRA,ADPS0);
	
	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_2
	ClrBit(ADCSRA,ADPS2); ClrBit(ADCSRA,ADPS1);	SetBit(ADCSRA,ADPS0);
	
	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_4
	ClrBit(ADCSRA,ADPS2); SetBit(ADCSRA,ADPS1);	ClrBit(ADCSRA,ADPS0);
	
	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_8
	ClrBit(ADCSRA,ADPS2); SetBit(ADCSRA,ADPS1);	SetBit(ADCSRA,ADPS0);

	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_16
	SetBit(ADCSRA,ADPS2); ClrBit(ADCSRA,ADPS1);	ClrBit(ADCSRA,ADPS0);
	
	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_32
	SetBit(ADCSRA,ADPS2); ClrBit(ADCSRA,ADPS1);	SetBit(ADCSRA,ADPS0);
	
	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_64	
	SetBit(ADCSRA,ADPS2); SetBit(ADCSRA,ADPS1);	ClrBit(ADCSRA,ADPS0);

	#elif		PRESCALER_SELECTION		==		DIVISION_FACTOR_128
	SetBit(ADCSRA,ADPS2); SetBit(ADCSRA,ADPS1);	SetBit(ADCSRA,ADPS0);
	#endif



	/* Step 5	->		set ADC Enable */
	SetBit(ADCSRA,ADEN);
	
	SetBit(ADCSRA,ADATE);
	/* Step 6	->		Set ADC Interrupt Selection */
// 	#if			ADC_INTERRUPT			==		ADC_INT_ENABLE 
// 	SetBit(SREG,Ibit);
// 	SetBit(ADCSRA,ADIE);
// 	#elif		ADC_INTERRUPT			==		ADC_INT_DISABLE
// 	#endif
	
}

u16 M_Adc_Read(void)
{
	u16 Local_u16_Data = 0;
	SetBit(ADCSRA,ADSC);
	while(GetBit(ADCSRA,ADIF) == 0);
	
	Local_u16_Data = (ADCL + (ADCH<<8));
	
	//Local_u16_Data = ADCH;
	//ClrBit(ADCSRA,ADIF);
		
	return Local_u16_Data;
}

void M_Adc_SetCallBackAdc (void (*Local_void_ptr) (void))
{
	Adc_void_CallBack = Local_void_ptr;
}
// 
// ISR (ADC_vect)
// {
// 	Adc_void_CallBack();
// }