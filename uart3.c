/*
* Author: OmarGabr0
* Code for the UART2 intialization and receving data in case port A is not working
*/
//////////////////////////////////////////////////
///// PD7 = UART2 TX /////// PD6 = UART2  RX//////
////////////////////////////////////////////////

//  UART PORT D INIT
#include "tm4c123gh6pm.h"
void uart_init(void){ 
    SYSCTL_RCGCUART_R |=0x04; 
    SYSCTL_RCGCGPIO_R |=0x08; 
while(!(SYSCTL_PRGPIO_R &= 0X08)); // wait till port D stable
   UART2_CTL_R &= ~0x0001; 
   UART2_IBRD_R  = 104; 
   UART2_FBRD_R = 11; 
   UART2_LCRH_R = 0x0070; 
   UART2_CTL_R |= 0x0301; 
   // PORT D UART2 Initializations // 
   GPIO_PORTD_AMSEL_R &= ~0xC0; // disable digital function on PD& andPD6
   GPIO_PORTD_LOCK_R = 0x4C4F434B; //unlock port D
   GPIO_PORTD_CR_R |= 0xC0; // allow changes to PD7 and PD6
   GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF) + 0X11000000 ; //PD6 =U2RX , PD7=U2TX
   GPIO_PORTD_DIR_R |= 0x80; //PD7 = OUTPUT
   GPIO_PORTD_DIR_R &= ~0x40; // PD6 = INPUT
   GPIO_PORTD_AFSEL_R |= 0xC0; // enable alternative function on PD& and PD6
   GPIO_PORTD_DEN_R |= 0xC0; // enable digital on portD (7 & 6)
}

// UART2 recieve from Rx fifo
char uart_recieve(){
    while (UART2_FR_R & 0X008 !=0); // while fifo embty 
    return(char)(UART2_DR_R & 0xFF);
}

