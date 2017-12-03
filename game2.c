//COE718 Interim Media Center Project GAME2
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
#include <stdbool.h>
int bucket = 120; 
int buckclearleft = 110;
int buckclearright=140;
int cherryx = 130; 
int cherryclear =0;
int cherryy = 10; 
int bombx= 50;
int bombclear =0;
int bomby=10;
int score1=0; 
int buttons; 
int i=2;
int j=3;
// Bit Band Macros used to calculate the alias address at run time
#define ADDRESS(x)    (*((volatile unsigned long *)(x)))
#define BitBand(x, y) 	ADDRESS(((unsigned long)(x) & 0xF0000000) | 0x02000000 |(((unsigned long)(x) & 0x000FFFFF) << 5) | ((y) << 2))

//volatile unsigned long * bit1;
#define ledp1_28   (*((volatile unsigned long *)0x233806F0))
#define ledp1_29   (*((volatile unsigned long *)0x233806F4))
#define ledp1_31   (*((volatile unsigned long *)0x233806FC))
#define ledp2_2    (*((volatile unsigned long *)0x23380A88))
#define ledp2_3    (*((volatile unsigned long *)0x23380A8C))
#define ledp2_4    (*((volatile unsigned long *)0x23380A90))
#define ledp2_5    (*((volatile unsigned long *)0x23380A94))
#define ledp2_6    (*((volatile unsigned long *)0x23380A98))

extern void menu();
extern unsigned char bomb[];
extern unsigned char Bask[];
extern unsigned char buckpic[];
extern unsigned char cup[];
extern unsigned char cherry[];
extern unsigned char whitebucket[];
bool gamewin= false;
bool gameloss= false;

static void delay(int cnt){
	cnt <<= DELAY_2N;
	while (cnt--);
}



void game2 (){


LED_Init();	

while (1){
bool gamewin= false;
bool gameloss= false;
buttons = get_button();
//bucket movement 
if (buttons == KBD_RIGHT  && bucket!=290){	
		bucket = bucket+10;
		buckclearleft=buckclearleft+10;
	buckclearright=buckclearright+10;
	GLCD_Bitmap (buckclearright, 200, 30,  29, whitebucket);		
		GLCD_Bitmap (buckclearleft, 200, 30,  29, whitebucket);			
		GLCD_Bitmap (bucket, 200, 30,  29, Bask);
}

if (buttons == KBD_LEFT  && bucket!=7){
  	bucket = bucket-10;		
	buckclearleft=buckclearleft-10;
	buckclearright=buckclearright-10;

	GLCD_Bitmap (buckclearright, 200, 30,  29, whitebucket);		
GLCD_Bitmap (buckclearleft, 200, 30,  29, whitebucket);		
		GLCD_Bitmap (bucket, 200, 30,  29, Bask);
}
//cherry movement 
cherryy = cherryy +i; 
cherryclear=cherryclear+i;
delay(5);
GLCD_Bitmap (cherryx, cherryclear, 30,  29, whitebucket);
GLCD_Bitmap (cherryx, cherryy, 20,  30, cherry);

//bomb movement
bomby = bomby +j; 
bombclear=bombclear+j;  
delay(5);
GLCD_Bitmap (bombx, bombclear, 30,  29, whitebucket);
GLCD_Bitmap (bombx, bomby, 20,  30, bomb);


if(bombx==cherryx){
bombx = rand()%320; 
bomby=10;	
bombclear=0;

}

//win 
if (cherryy>=164 &&(cherryx>=(bucket)&&cherryx<=(bucket+290))){
cherryx = rand()%320; 
cherryy=10;
cherryclear=0;
i=i+1;
score1++; 
	
	if (score1==1){
ledp1_28=1;
}
if (score1==2){
ledp1_29=1;
}
	if (score1==3){
ledp1_31=1;
}
if (score1==4){
ledp2_2=1;
}
	if (score1==5){
ledp2_3=1;
}
if (score1==6){
ledp2_4=1;
}
	if (score1==7){
ledp2_5=1;
}
if (score1==8){
ledp2_6=1;
		ledp1_28=0;
	ledp1_29=0;
	ledp1_31=0;
	ledp2_2=0;
	ledp2_3=0;
	ledp2_4=0;
	ledp2_5=0;
	ledp2_6 =0;
	cherryy=10;
	cherryclear=0;
	 bucket = 120; 
 buckclearleft = 110;
 buckclearright=140;
score1=0;
i=2;	
	j=3;
gamewin=true;	
}
GLCD_Clear(White);
game2();
}

//loss

 if(cherryy>=164 &&(cherryx!=(bucket)&&cherryx!=(bucket+290))) {
	ledp1_28=0;
	ledp1_29=0;
	ledp1_31=0;
	ledp2_2=0;
	ledp2_3=0;
	ledp2_4=0;
	ledp2_5=0;
	ledp2_6 =0;
	cherryy=10;
	 cherryclear=0;
	 bucket = 120; 
 buckclearleft = 110;
 buckclearright=140;
score1=0; 
	i=2;
	 j=3;
gameloss=true;	
}
//bomb caught
  if (bomby>164 &&(bombx>(bucket)&&bombx<(bucket+290))){ 
 	ledp1_28=0;
	ledp1_29=0;
	ledp1_31=0;
	ledp2_2=0;
	ledp2_3=0;
	ledp2_4=0;
	ledp2_5=0;
	ledp2_6 =0;
	cherryy=10;
	 cherryclear=0;
	 bucket = 120; 
 buckclearleft = 110;
 buckclearright=140;
score1=0; 
	i=2;
	 j=3;
gameloss=true;
 }
//bomb not caught
 if (bomby>164 &&(bombx!=(bucket)&&bombx!=(bucket+290))){
GLCD_Bitmap (bombx, bombclear+j+10, 30,  29, whitebucket);
bombx = rand()%320; 
bomby=10;	
bombclear=0;
j=j+1; 
	 
}
 

 if (gamewin==true){

GLCD_DisplayString(6, 0, __FI, "    Winner!   ");
	ledp1_28=0;
	ledp1_29=0;
	ledp1_31=0;
	ledp2_2=0;
	ledp2_3=0;
	ledp2_4=0;
	ledp2_5=0;
	ledp2_6 =0;
	delay(100);
menu();

	 break;
}
if (gameloss== true){
	ledp1_28=0;
	ledp1_29=0;
	ledp1_31=0;
	ledp2_2=0;
	ledp2_3=0;
	ledp2_4=0;
	ledp2_5=0;
	ledp2_6 =0;

GLCD_DisplayString(6, 0, __FI, "    GAME  OVER!   ");
	delay(100);
menu();
break;
	
}
}

}

