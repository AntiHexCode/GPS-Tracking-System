/*
* Author: rye141200
* Code for the UART0 intialization and receving data
*/

#include "tm4c123gh6pm.h"

// UART0 Intialization
void uart0_init(){
  SYSCTL_RCGCUART_R |= 0x01;
  SYSCTL_RCGCGPIO_R |= 0x01;
  while(!(SYSCTL_PRGPIO_R &= 0x01));
  UART0_CTL_R &= ~0x01;
  UART0_IBRD_R = 104;
  UART0_FBRD_R = 11 ;
  UART0_LCRH_R = 0x70 ; // parity diabled, word lenght = 8 bits, FEN = 1
  UART0_CTL_R |= 0x301; // enble UART0 ,TXE, RXE
  // PORT A UART0 Initializations //
  GPIO_PORTA_AFSEL_R |= 0x03; // enable alternative function in A0 and A1
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) + 0x11; // PA0 = U0RX, PA1 = U0TX
  GPIO_PORTA_AMSEL_R &= ~0x03; // diable digital function in PA0 and PA1
  GPIO_PORTA_DEN_R |= 0X03 ; // enable digital in PA0 and PA1
}

// Receving data from Rx FIFO
char uart_recieve(){
  while(UART0_FR_R & 0x0010 != 0); // while FIFO empty, wait
  return (char)(UART0_DR_R & 0xFF);
}
