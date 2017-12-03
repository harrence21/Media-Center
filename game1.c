//COE718 Interim Media Center Project GAME1
//Harrence Mathialagan 500559356
#include <LPC17xx.H>                    /* NXP LPC17xx definitions            */
#include <stdio.h>
#include "string.h"
#include "GLCD.h"
#include "KBD.h"
#include "LED.h"
#define DELAY_2N    18
#include "stdlib.h"
#define __FI        1   
extern void menu();
extern unsigned char  BASKETBALL_pixel_data[];
extern unsigned char cup[];
extern unsigned char arrow[];
extern unsigned char whitebucket[];
int score=0; 
int button;
int t=0;
char* text;
//////USE BIT BAND FOR LED 
int option1=1;
static void d(int cnt){
	cnt <<= DELAY_2N;
	while (cnt--);
}
// Bit Band Macros used to calculate the alias address at run time
#define ADDRESS(x)    (*((volatile unsigned long *)(x)))
#define BitBand(x, y) 	ADDRESS(((unsigned long)(x) & 0xF0000000) | 0x02000000 |(((unsigned long)(x) & 0x000FFFFF) << 5) | ((y) << 2))

volatile unsigned long * bit;
#define LEDP1_28   (*((volatile unsigned long *)0x233806F0))
#define LEDP1_29   (*((volatile unsigned long *)0x233806F4))

 void cups(){
	 	 int i=0;

	 while(1){
		 
		 button = get_button();
	 //Round one 

	if(i==0){

GLCD_SetBackColor(White);	
	GLCD_SetTextColor(Black);	
		
GLCD_DisplayString(0, 0, __FI, "    			Round 1   						");
		

GLCD_DisplayString(1, 0, __FI, "    			Pick A Cup   					");
GLCD_Bitmap (30, 200, 30,  29, cup);	
GLCD_Bitmap (140, 200, 30,  29, cup);
GLCD_Bitmap (240, 200, 30,  29, cup);


				button = get_button();
		
		if (button==KBD_RIGHT && option1 != 3){
 
			option1++; 
		}
		if (button==KBD_LEFT && option1 != 1){
			option1--;
		}
	///option 1	
		if (option1==1){
			
		GLCD_Bitmap (140, 100, 30,  29, whitebucket);	
			GLCD_Bitmap (30, 100, 30,  29, arrow);	
			
			if (button==KBD_SELECT ){
				GLCD_Bitmap (30, 200, 30,  29, whitebucket);	
		GLCD_Bitmap (30, 100, 30,  29, cup);	
		d(50);
	GLCD_DisplayString(6, 0, __FI, "    Loser   ");
				LEDP1_28 =0;
			d(100);
			GLCD_SetBackColor(White);
			GLCD_ClearLn  (6,__FI);	
		GLCD_SetBackColor(Black);	
				i++;
		
		}
		}
		//option 2
	if (option1==2){
			GLCD_Bitmap (30, 100, 30,  29, whitebucket);	
			GLCD_Bitmap (240, 100, 30,  29, whitebucket);	
			GLCD_Bitmap (140, 100, 30,  29, arrow);	
if (button==KBD_SELECT ){
		GLCD_Bitmap (140, 200, 30,  29, whitebucket);
		GLCD_Bitmap (140, 100, 30,  29, cup);
			d(50);
		GLCD_DisplayString(6, 0, __FI, "    Loser   ");
	LEDP1_28 =0;
			d(100);
		GLCD_SetBackColor(White);
			GLCD_ClearLn  (6,__FI);	
		GLCD_SetBackColor(Black);	
				i++;
			
			
		}
		}
	//option 3
		if (option1==3){
			GLCD_Bitmap (140, 100, 30,  29, whitebucket);	
			GLCD_Bitmap (240, 100, 30,  29, arrow);	
			 
		
		if (button==KBD_SELECT ){
		GLCD_Bitmap (240, 200, 30,  29, whitebucket);
		GLCD_Bitmap (240, 200, 30,  29,BASKETBALL_pixel_data);			
		GLCD_Bitmap (240, 100, 30,  29, cup);			 		
		d(50);
		GLCD_Clear(White);
		
		GLCD_DisplayString(6, 0, __FI, "    Winner!   ");
		score++;
		 	LEDP1_28=1;
		d(100);
		GLCD_SetBackColor(White);
			GLCD_ClearLn  (6,__FI);	
		GLCD_SetBackColor(Black);	
		i++;
		}
		}		
		}
//Round two
if(i==1){
GLCD_SetBackColor(White);
	GLCD_SetTextColor(Black);
GLCD_DisplayString(0, 0, __FI, "    Round 2   					");


//GLCD_Clear(White);
GLCD_DisplayString(1, 0, __FI, "    Pick A Cup   								");
GLCD_Bitmap (30, 200, 30,  29, cup);	
GLCD_Bitmap (140, 200, 30,  29, cup);
GLCD_Bitmap (240, 200, 30,  29, cup);


				button = get_button();
		
		if (button==KBD_RIGHT && option1 != 3){
 
			option1++; 
		}
		if (button==KBD_LEFT && option1 != 1){
			option1--;
		}
	///option 1	
if (option1==1){
			GLCD_Bitmap (140, 100, 30,  29, whitebucket);
			GLCD_Bitmap (30, 100, 30,  29, arrow);	
			
if (button==KBD_SELECT ){
			GLCD_Bitmap (30, 200, 30,  29, whitebucket);	
			GLCD_Bitmap (30, 200, 30,  29,BASKETBALL_pixel_data);
			GLCD_Bitmap (30, 100, 30,  29, cup);	
			d(50);
			GLCD_Clear(White);
	LEDP1_29 =1;
			GLCD_DisplayString(6, 0, __FI, "    Winner!   ");
			score++;
			LEDP1_29 =1;
			d(100);
			GLCD_SetBackColor(White);
			GLCD_ClearLn  (6,__FI);	
		GLCD_SetBackColor(Black);	
			i++;
		}
		}
		//option 2
if (option1==2){
		GLCD_Bitmap (30, 100, 30,  29, whitebucket);	
		GLCD_Bitmap (240, 100, 30,  29, whitebucket);	
		GLCD_Bitmap (140, 100, 30,  29, arrow);		
if (button==KBD_SELECT ){
		GLCD_Bitmap (140, 200, 30,  29, whitebucket);
		GLCD_Bitmap (140, 100, 30,  29, cup);
		d(50);
		GLCD_DisplayString(6, 0, __FI, "    Loser   ");
		d(50);
		i++;	
	GLCD_SetBackColor(Black);	
GLCD_SetTextColor(White);	
		}
		}
	//option 3
		if (option1==3){
			GLCD_Bitmap (140, 100, 30,  29, whitebucket);
			GLCD_Bitmap (240, 100, 30,  29, arrow);	
		if (button==KBD_SELECT ){
			GLCD_Bitmap (240, 200, 30,  29, whitebucket);		
			GLCD_Bitmap (240, 100, 30,  29, cup);			 		
			d(50);
			GLCD_DisplayString(6, 0, __FI, "    Loser   ");
			d(50);
			i++;
			GLCD_SetBackColor(Black);	
			GLCD_SetTextColor(White);
		}
		}
		
		}
	{

}
		if(i==2){
		 
				GLCD_Clear(White);  
				GLCD_SetTextColor(White);
				GLCD_DisplayString(4, 1, __FI, " GAME OVER ");	
			LEDP1_28 =0;
			LEDP1_29 =0;
			d(50);
	
			
			if (button==KBD_SELECT ){

	 menu();	
		}
		}
		}
		}
 
		void game1 (){
		
LED_Init();	
			LEDP1_28 =0;
			LEDP1_29 =0;
cups();

}
	


