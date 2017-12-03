//COE718 Interim Media Center Project 
//Harrence Mathialagan 500559356
#include <LPC17xx.H>   
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "string.h"
#include "GLCD.h"
#include "KBD.h"
#include "LED.h"
#include <stdbool.h>

#define DELAY_2N    18
#define __FI        1                      /* Font index 16x24               */
#define __USE_LCD   0

void menu();
void photogallery();
void game1main();
void game2main();
extern void game1();
extern void game2();
int joystick = 0; 	/*Joystick*/
int option = 1; /*Current Menu Option*/
extern int music();
/*photo gallery pics */
extern unsigned char BMW[];
extern unsigned char GTR[];
/* image clearing pic*/
extern unsigned char whitebucket[];

bool start=true;
bool start1=true;
bool start2=true;
bool start3=true;

static void delay(int cnt){
	cnt <<= DELAY_2N;
	while (cnt--);
}
  
void musicmenu (){
	GLCD_Clear(White);
	start3=true;
while (start3==true){
	joystick = get_button();
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(0, 0, __FI, "    MUSIC PLAYER            ");
			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Black);
				
			GLCD_DisplayString(3, 4, __FI, "INSTRUCTIONS:");	
			GLCD_DisplayString(5, 2, __FI, "ADJUST POTENTTIO");	
			GLCD_DisplayString(6, 4, __FI, "FOR VOLUME ");
	
	if (joystick == KBD_SELECT)
	{
 
		start3=false;
music();
  start3=true;
	
	}
	if(joystick == KBD_LEFT){
	GLCD_Clear(White);  
		start3=false;
	menu();
  
	}
}





}
void photogallery(){
	 GLCD_Clear(White);  
	while(1){
				joystick = get_button();
		
		if (joystick==KBD_RIGHT && option != 3){
			option++; 
		}
		if (joystick==KBD_LEFT && option != 0){
			option--;
		}
		
		if (option==1){
	
			GLCD_Bitmap(60, 20, 200, 150,BMW);
		}
	if (option==2){		

GLCD_Bitmap(60, 20, 200, 150,GTR);
		
		}
	if (joystick==KBD_SELECT ){
		delay (10);
			menu();
		
		}
			
		
		}
}
void game1main() {
while (start1==true){
joystick = get_button();
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(0, 0, __FI, "    Cup Game            ");
			GLCD_SetTextColor(White);
				
			GLCD_DisplayString(3, 4, __FI, "INSTRUCTIONS:");	
			GLCD_DisplayString(4, 4, __FI, "Guess which cup ");	
			GLCD_DisplayString(5, 4, __FI, "Has the ball ");
			GLCD_DisplayString(8, 2, __FI, "Press select to");
		GLCD_DisplayString(9, 4, __FI,   "Start! ");
	if (joystick == KBD_SELECT)
	{
GLCD_Clear(White);  
		start1==false;
game1();
		start1==true;
	}
}
}
void game2main() {
while(start2==true){
joystick = get_button();
			GLCD_SetBackColor(Black);
			GLCD_SetTextColor(White);
			GLCD_DisplayString(0, 0, __FI, "    Fruit Game    							");
			GLCD_SetTextColor(White);
			GLCD_SetBackColor(Black);	
			GLCD_DisplayString(3, 4, __FI, "INSTRUCTIONS:");	
			GLCD_DisplayString(4, 4, __FI, "Catch fruits  ");	
			GLCD_DisplayString(5, 4, __FI, "with basket ");
			GLCD_DisplayString(8, 2, __FI, "Press select to");
		GLCD_DisplayString(9, 4, __FI,   "Start! ");
	if (joystick == KBD_SELECT)
	{
GLCD_Clear(White);
	start2= false;
		game2();
		start2==true;
}
	}

}

void menu(){
	start=true;
		GLCD_Clear(White);        
  	GLCD_SetBackColor(Blue);
  	GLCD_SetTextColor(Red);
  	GLCD_DisplayString(0, 0, 1, "    Harrence Mathi       ");
		GLCD_SetTextColor(White);
  	GLCD_DisplayString(1, 0, 1, "    Media Center       ");
  	GLCD_SetBackColor(White);
		GLCD_SetTextColor(Blue);
		GLCD_DisplayString(4, 3, 1, "   Photo Gallery");
		GLCD_DisplayString(5, 3, 1, "   Music Player");
		GLCD_DisplayString(6, 3, 1, "   Game1");
		GLCD_DisplayString(7, 3, 1, "   Game2");
		
	while(start==true){
	joystick = get_button();
		
		if (joystick==KBD_DOWN && option != 4){
			option++; 
		}
		if (joystick==KBD_UP && option != 1){
			option--;
		}
		
		if (option==1){
		
			GLCD_SetBackColor(Blue);
			GLCD_SetTextColor(Red);
			GLCD_DisplayString(4, 3, 1, "-> Photo Gallery");
			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(5, 3, 1, "   Music Player");
			GLCD_DisplayString(6, 3, 1, "   Game1");
		GLCD_DisplayString(7, 3, 1, 	"   Game2");
			if(joystick == KBD_SELECT){
				photogallery();
			}
		}
		if (option==2){

			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(4, 3, 1, "   Photo Gallery");
			GLCD_SetBackColor(Blue);
			GLCD_SetTextColor(Red);
			GLCD_DisplayString(5, 3, 1, "-> Music Player");
			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(6, 3, 1, "   Game1");
			GLCD_DisplayString(7, 3, 1, "   Game2");
			if(joystick == KBD_SELECT){
				musicmenu();
			}
			
		}
		if (option==3){

			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(4, 3, 1, "   Photo Gallery");
			GLCD_DisplayString(5, 3, 1, "   Music Player");
			GLCD_SetBackColor(Blue);
			GLCD_SetTextColor(Red);
			GLCD_DisplayString(6, 3, 1, "-> Game1");
		GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(7, 3, 1, "   Game2");
		
		if(joystick == KBD_SELECT){
			start=false;
			GLCD_Clear(White);  
				start2=true;
				game1main();
			
			}
	}
				if (option==4){

			GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(4, 3, 1, "   Photo Gallery");
			GLCD_DisplayString(5, 3, 1, "   Music Player");
					GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
			GLCD_DisplayString(6, 3, 1, " 		Game1");
					GLCD_SetBackColor(Blue);
			GLCD_SetTextColor(Red);
			GLCD_DisplayString(7, 3, 1, "-> Game2");
		GLCD_SetBackColor(White);
			GLCD_SetTextColor(Blue);
		if(joystick == KBD_SELECT){
			start=false;
			GLCD_Clear(White); 
			start2=true;
				game2main();
			}
	}


}
	}

/*Main Program*/
int main (void) { 
	GLCD_Init();
	GLCD_Clear(White);      
	KBD_Init();
	
	 menu();		
}