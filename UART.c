/*
* Author: OmarGabr0
* Code for the UART2 intialization and receving data in case port A is not working
*/
//////////////////////////////////////////////////
///// PD7 = UART2 TX /////// PD6 = UART2  RX//////
////////////////////////////////////////////////

#include "tm4c123gh6pm.h"

//  UART PORT D INIT
void uart_init(void){
 
    SYSCTL_RCGCUART_R |=0x0004; 
    SYSCTL_RCGCGPIO_R |=0x0008; 

   UART2_CTL_R &= ~0x0001; 
   UART2_IBRD_R = 104; 
   UART2_FBRD_R = 11; 
   UART2_LCRH_R = 0x0070; 
   UART2_CTL_R |= 0x0301; 

    GPIO_PORTD_LOCK_R = 0x4C4F434B;
    GPIO_PORTD_CR_R |= 0xC0;
    GPIO_PORTD_AMSEL_R &= ~0xC0;
    GPIO_PORTD_PCTL_R &= ~0x0FF000000;
    GPIO_PORTD_DIR_R |= 0x80; 
    GPIO_PORTD_DIR_R &= ~0x40;
    GPIO_PORTD_AFSEL_R |= 0xC0;
    GPIO_PORTD_DEN_R |= 0xC0;
}

// UART2 recieve from Rx fifo
char uart_recieve(){
    while ((UART2_FR_R & 0X010) !=0); // while fifo embty
    return (char)(UART2_DR_R & 0xFF);
}
