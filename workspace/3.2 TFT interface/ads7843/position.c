/******************************************************
 * position.c
 *
 *  Created on: 25/04/2015
 *      Author: albert
 ******************************************************/


/*****************************************************
 * Includes
 *****************************************************/
#include <msp430.h>
#include <stdint.h>
#include "position.h"
#include "ads7843.h"
#include "../ssd1289/ssd1289.h"
#include "../ssd1289/screns.h"


/*****************************************************
 * Position function
 * defines which display is being shown
 *****************************************************/
screens position(screens s, touch tp)
{
	switch(s)
	{
	case(screen1):

		s = Screen_intro( s, tp);
		break;
	}
	return s;
}
/*********************************************************************
 * 	Screen 1
 * 	if selected, go to screen 1 or 2 (Jog control or SD card)
**********************************************************************/
screens Screen_intro(screens s, touch tp)
{
	if((tp.tx>30)&&(tp.tx<70) &&(tp.ty>10) && (tp.ty<50) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'1', 90, 245);
		ssd1289_cs_high();
	}

	else if((tp.tx>80)&&(tp.tx<120) &&(tp.ty>10) && (tp.ty<50) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'2', 90, 245);
		ssd1289_cs_high();
	}

	else if((tp.tx>130)&&(tp.tx<170) &&(tp.ty>10) && (tp.ty<50) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'3', 90, 245);
		ssd1289_cs_high();
	}


	else if((tp.tx>180)&&(tp.tx<220) &&(tp.ty>10) && (tp.ty<50) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'4', 90, 245);
		ssd1289_cs_high();
	}


	else if((tp.tx>230)&&(tp.tx<270) &&(tp.ty>10) && (tp.ty<50) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'5', 90, 245);
		ssd1289_cs_high();
	}


	else if((tp.tx>30)&&(tp.tx<70) &&(tp.ty>70) && (tp.ty<120) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'6', 90, 245);
		ssd1289_cs_high();
	}


	else if((tp.tx>80)&&(tp.tx<120)  &&(tp.ty>70) && (tp.ty<120) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'7', 90, 245);
		ssd1289_cs_high();
	}

	else if((tp.tx>130)&&(tp.tx<170) &&(tp.ty>70) && (tp.ty<120) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'8', 90, 245);
		ssd1289_cs_high();
	}

	else if((tp.tx>180)&&(tp.tx<220) &&(tp.ty>70) && (tp.ty<120) )
	{
		ssd1289_cs_low();
		ssd1289_fill_rectangle(0xF000,70,230,50,40);
		ssd1289_char(0x0000,'9', 90, 245);
		ssd1289_cs_high();
	}


//	//Jog control
//	if((tp.tx>70)&&(tp.tx<120) &&(tp.ty>100) && (tp.ty<156) )
//	{
//		Screen2();
//		s=screen2;
//	}
//	//SD Card
//	if((tp.tx>180)&&(tp.tx<230) &&(tp.ty>100) && (tp.ty<156) )
//	{
//		listas = Screen3();
//		s=screen3;
//	}
	return s;
}
