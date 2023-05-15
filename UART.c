/*
* Code for the UART2 intialization and receving data in case port A is not working
*/
//////////////////////////////////////////////////
///// PD7 = UART2 TX /////// PD6 = UART2  RX//////
////////////////////////////////////////////////

#include "tm4c123gh6pm.h"

//  UART PORT D INIT
void uart_init(void){
  SYSCTL_RCGCUART_R |= 0x04;
  SYSCTL_RCGCGPIO_R |= 0x08;

  UART2_CTL_R &= ~0x01;
  UART2_IBRD_R = 520; // also try 104, and check the CLOCK in the header file
  UART2_FBRD_R = 53; // also try 11, and check the CLOCK in the header file
  UART2_LCRH_R = 0x0060; // 8 bit, fifo disabled
  UART2_CTL_R |= 0x0301;

  GPIO_PORTD_LOCK_R = UNLOCK_KEY;
  GPIO_PORTD_CR_R |= 0xFF;
  GPIO_PORTD_AFSEL_R |= 0xC0;
  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & ~0xFF000000) | 0x11000000;
  GPIO_PORTD_AMSEL_R &= ~0xC0;
  GPIO_PORTD_DEN_R |= 0xC0;
}

// UART2 recieve from Rx fifo
char uart_recieve(void){
    while ((UART2_FR_R & 0X10) != 0); // while fifo empty, wait
    return (char)(UART2_DR_R & 0xFF);
}
