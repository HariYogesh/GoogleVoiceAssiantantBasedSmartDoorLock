
#ifndef _servo_H_
#define _servo_H_

servo_init()
{
	
	TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
   TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM) extremeele

   ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

   DDRD|=(1<<PD4)|(1<<PD5);   //PWM Pins as Out
}
set_0()
{
	OCR1A = 130;	/* Set servo shaft at -90° position */
}

set_90()
{
	OCR1A = 350;	/* Set servo shaft at 0° position */
}

set_180()
{
	OCR1A = 533;	/* Set servo at +90° position */
}

#endif 