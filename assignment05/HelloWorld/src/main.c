/*******************************************************************************
FILE NAME   : main.c
DESCRIPTION : Where all the magic begins.
	      

Copyright   : David Allegre
            : 2015
	    : All Rights Reserved
*******************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "nucleoboard.h"
#include "hw_init.h"
#include "print.h"

/* Global Variables and Externals --------------------------------------------*/
const char* myCstr ="\nThis message is myCstr \n";
const char* mydivCstr ="\nDividing the input by 2 you get: ";

extern int sqrAsm(int val);
extern int div2Asm(int val);
extern void swapCharsAsm(Char* xPtr, Char* yPtr);

char clr_scrn[] = { 27, 91, 50, 74, 0 };              // esc[2J
/* Public variables ----------------------------------------------------------*/
__IO uint32_t timer;
PRINT_DEFINEBUFFER();           /* required for lightweight sprintf */
/* Private prototype ---------------------------------------------------------*/
void delay(uint32_t time);

/*******************************************************************************
Function Name   : main
Description     : 
Parameters      :
Return value    :               */
void main() {
uint8_t foo;

  foo = 10;
  Hw_init();

  PrintString(clr_scrn); /* Clear entire screen */
  // Change [My name] to your name      //
  PrintString("Omar's Nucleo STM32F401 is ... alive!!!\n");
  RETAILMSG(1, ("Programming Assignment #1: Built %s %s.\r\n\r\n",
              __DATE__,
              __TIME__));  

  //Square Assembly function	
  int value = 4;
  int square = sqrAsm(value);
  PrintString("\nThe value I will insert it: ");
  Print_uint32(value);
  PrintString("\nThe square of that value is: ");
  Print_uint32(square);
  PrintString("\n\n");
	
  //Divide by 2 Assembly function
  unsigned int dividend = 50;
  PrintString("\nThe dividend is: ");
  Print_uint32(dividend);
  unsigned int quotient = div2Asm(dividend);
  PrintString("\n\n\n");
	  
  //Swap char assembly function
  char char1 = 'a';
  char char2 = 'b';
  swapCharsAsm(&char1, &char2);
  PrintByte(char1);
  PrintByte(char2);

    
  while (foo) {
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    PrintString("EMBSYS CP100A: University of Washington - UART Test Application \n");
    
    delay(1000);
    GPIO_ToggleBits(GPIO_PORT_LD2, GPIO_PIN_LD2);
    
    delay(1000);
    foo--;
  }
  while (1) {
    // loop forever
    asm("nop");
  }
}


void delay(uint32_t time) {
  
  timer = time;
  while(timer) {}
}
void SystemInit(void) {
  // System init is called from the assembly .s file
  // We will configure the clocks in hw_init
  asm("nop");
}
  
