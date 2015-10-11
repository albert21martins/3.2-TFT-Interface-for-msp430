/**********************************************************************************************************
 * screens.c
 *
 *  Created on: 24/06/2015
 *      Author: albert
 *
 *  						    ************	*****		***		************
 *     							************	******		***		************
 *      						***				***  *** 	***		***
 *      						***				***	   ***  ***		***
 *      						***				***     *** ***		***
 *      						************	***		 ******		************
 *      						************	***		  *****		************
 *
 **********************************************************************************************************/
#include <msp430.h>
#include <stdint.h>
#include "ssd1289.h"
#include "logos.h"
#include "screns.h"



/************************************************************************
 *  First Screen
 *  shows menus: Jog control and SD card files
 ************************************************************************/

void Screen1(void)
{
	ssd1289_rest_high();
	ssd1289_cs_low();
	init_TFT();
	ssd1289_fill(0xFFFF);
	ssd1289_rectangle(0x0000,0,0,239,319);

	ssd1289_rectangle(0x0000,10,30,50,40);
	ssd1289_rectangle(0x0000,10,80,50,40);
	ssd1289_rectangle(0x0000,10,130,50,40);
	ssd1289_rectangle(0x0000,10,180,50,40);
	ssd1289_rectangle(0x0000,10,230,50,40);
	ssd1289_fill_rectangle(0x0000,10,30,50,40);
	ssd1289_fill_rectangle(0x0000,10,80,50,40);
	ssd1289_fill_rectangle(0x0000,10,130,50,40);
	ssd1289_fill_rectangle(0x0000,10,180,50,40);
	ssd1289_fill_rectangle(0x0000,10,230,50,40);
	ssd1289_char(0xFFFF,'1', 30, 45);
	ssd1289_char(0xFFFF,'2', 30, 95);
	ssd1289_char(0xFFFF,'3', 30, 145);
	ssd1289_char(0xFFFF,'4', 30, 195);
	ssd1289_char(0xFFFF,'5', 30, 245);

	ssd1289_rectangle(0x0000,70,30,50,40);
	ssd1289_rectangle(0x0000,70,80,50,40);
	ssd1289_rectangle(0x0000,70,130,50,40);
	ssd1289_rectangle(0x0000,70,180,50,40);
	ssd1289_rectangle(0x0000,70,230,50,40);
	ssd1289_fill_rectangle(0x0000,70,30,50,40);
	ssd1289_fill_rectangle(0x0000,70,80,50,40);
	ssd1289_fill_rectangle(0x0000,70,130,50,40);
	ssd1289_fill_rectangle(0x0000,70,180,50,40);
	ssd1289_fill_rectangle(0xF000,70,230,50,40);
	ssd1289_char(0xFFFF,'6', 90, 45);
	ssd1289_char(0xFFFF,'7', 90, 95);
	ssd1289_char(0xFFFF,'8', 90, 145);
	ssd1289_char(0xFFFF,'9', 90, 195);



	ssd1289_string(0x0000,"Draw bit map", 135, 120);
	ssd1289_hline(0x0000,150,0,320);

	drawbitmap(30,170,80,220,laugh);
	drawbitmap(100,170,150,220,sleep);
	drawbitmap(170,170,220,220,indiferent);
	drawbitmap(240,170,290,220,furious);

	ssd1289_cs_high();
	ssd1289_rest_high();__delay_cycles(50);
	ssd1289_rest_low();	__delay_cycles(50);
	ssd1289_rest_high();__delay_cycles(50);
}

