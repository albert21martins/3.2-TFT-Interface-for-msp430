/***********************************************************
 * ads7843.c
 *
 *  Created on: 24/04/2015
 *      Author: albert
 ***********************************************************/


/*****************************************************
 * Includes
 *****************************************************/
#include <msp430.h>
#include "ads7843.h"
#include <stdint.h>

/**********************Variables**********************/
touch touchscr;
touch tch_CB;


/*****************************************************
 * Set_ports function
 * set the input/output pins, interrupts...
 *****************************************************/
void set_ports(void)
{
	WDTCTL = WDTPW + WDTHOLD;	// Stop watchdog timer

	setupDCO();

	P1DIR |= BIT6+BIT3+BIT5+BIT4+BIT0;
	P3DIR |= BIT5+BIT6+BIT7;
	P4DIR |= BIT0+BIT3;
	P6DIR|=BIT0+BIT1+BIT2+BIT4+BIT6;
	P7DIR|=BIT4+BIT0;
	P8DIR|=BIT2;

	//end stops & touch
	P1REN |= BIT2;                            	// Enable P1.4 internal resistance
	P1OUT |= BIT2;                            	// Set P1.4 as pull-Up resistance
	P1IES &= ~BIT2;                             // P1.4 Hi/Lo edge
	P1IFG &= ~BIT2;                           	// P1.4 IFG cleared
	P1IE |= BIT2;                             	// P1.4 interrupt enabled

	P2REN |= BIT2+BIT0+BIT6;                    // Enable P1.4 internal resistance
	P2OUT |= BIT2+BIT0+BIT6;                    // Set P1.4 as pull-Up resistance
	P2IES &= ~BIT2;         	       			// P1.4 Hi/Lo edge
	P2IES &= ~BIT0;         	       			// P1.4 Hi/Lo edge
	P2IES &= ~BIT6;                             // P1.4 Hi/Lo edge
	P2IFG &= ~BIT0;                      		// P1.4 IFG cleared
	P2IFG &= ~BIT2;                      		// P1.4 IFG cleared
	P2IFG &= ~BIT6;                           	// P1.4 IFG cleared
	P2IE |= BIT2+BIT0+BIT6;                     // P1.4 interrupt enabled

}




/*****************************************************
 * Initializate touch screen pins
 *****************************************************/
void init (void)
{

	clock_high();
	CS_high();
	DIN_high();
	DOUT_high();
}

/*****************************************************
 * write command register into IC via simulated SPI
 *****************************************************/
void write (uint16_t data)
{
	uint16_t i,a;
	clock_low();
	for (i=0; i<8;i++)
	{
		a = data<<i;
		a & 0x80? DIN_high() : DIN_low();

		clock_low(); __delay_cycles(1);
		clock_high();
	}
}

/*****************************************************
 * buffers the data received
 *****************************************************/
uint16_t touch_read(void)
{
	uint16_t data=0,i;
	for(i=0;i<12;i++)
	{
		data<<=1;
		clock_high(); __delay_cycles(1);
		clock_low();
		if(P6IN & BIT3)
		{
			data++;
		}
	}
	return (data);
}

/*****************************************************
 * read parameters from the touch controller
 *****************************************************/
touch read (void)
{
	uint16_t x=0,y=0,i;

	CS_low();

	for(i=0; i<10;i++)
	{
		write(0x90);	//send command to receive Y position
		clock_low(); __delay_cycles(1);
		clock_high();
		y+= touch_read();

		write(0xD0);    //send command to receive X position
		clock_low(); __delay_cycles(1);
		clock_high();
		x+=touch_read();
	}
	CS_low();
	X=x/10;
	Y=y/10;
	touchscr.tx = getX();
	touchscr.ty = getY();
	return(touchscr);
}

/*****************************************************
 * Set the X received parameter to real ones.
 *****************************************************/
int getX(void)
{
	int value;
	value = (Y-300)/11;
	if (value<0) value=0;
	return (value);
}
/*****************************************************
 * Set the Y received parameter to real ones.
 *****************************************************/
int getY(void)
{
	int value;

	value = ((X-180)/15);
	if (value<0) value=0;
	return (value);

}



/*****************************************************
 * config_int function
 * set callbacks functions
 *****************************************************/
void config_int(touchCBack_t t_CB)
{
	tch_CB.callBackFunc=t_CB;
}



/*****************************************************
 * Interrupt on pin 2.0, 2.2, 2.6
 * Y,Z interrupt and touch screen interrupt
 *****************************************************/
#pragma vector=PORT2_VECTOR
__interrupt void Port_2(void)

{
	switch(P2IV)
		{
		case(P2IV_P2IFG6):
				tch_CB.callBackFunc();						//touch screen  interrupt
			break;
		}
}



