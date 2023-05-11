/*
 * Author: AntiHexCode
 * Code for PF4 Switch Interrupt
*/

#include "tm4c123gh6pm.h"

void init_pf4_switch_interrupt(void)
{
  init_portf();
  init_portf_switches();

  GPIO_PORTF_IS_R &= ~0x10; // Edge sensetive
  GPIO_PORTF_IBE_R &= ~0x10; // One edge
  GPIO_PORTF_IEV_R &= ~0x10; // Falling edge
  GPIO_PORTF_ICR_R = 0x10; // Acknowledge
  GPIO_PORTF_IM_R |= 0x10; // arm bit is set to 1

  NVIC_PRI7_R = (NVIC_PRI7_R & 0xFF00FFFF) | 0x00200000; // priority 1
  NVIC_EN0_R = 0x40000000; // bit 30 is set to 1 (enable portF)

  EnableInterrupts(); // Interrupts is enabled
}

// Override the handler
void GPIOPortF_Handler(void)
{
  GPIO_PORTF_ICR_R = 0x10; // Acknowledge
  // The code to be excuted when an interrupt happens
}
