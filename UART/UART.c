#include "UART.h"
unsigned long delay;
void uart_init(){
  SYSCTL_SCGCUART_R |= 0x0001 ;
  SYSCTL_SCGCGPIO_R |= 0x001;
  delay=3;
  UART0_CTL_R &=~0x01;
  UART0_IBRD_R = 104; 
  UART0_FBRD_R = 11 ; 
  UART0_LCRH_R= 0x0070 ; // party diabled , word lenght = 8_bit , FEN = 1 
  UART0_CTL_R= 0x0301; //enble UART0 , TXE,RXE  
  //// GPIO port A initializations //
  GPIO_PORTA_AFSEL_R= 0x03; // enable alternative function in A0 and A1 
  GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R&0xffffff00)+0x00000011; // PA0 = U0RX , PA1 = U0TX 
  GPIO_PORTA_AMSEL_R &= ~0x03; // diable digital function in PA0 and PA1 
  GPIO_PORTA_DEN_R |=0X03 ; // enable digital in PA0 and PA1
}
char uart_recieve(){
  while(UART0_FR_R & 0x0010 != 0); // not equal zero then wait
  return (char)(UART0_DR_R &0xFF);
}
