#include "tm4c123gh6pm.h"
#include "prototypes.h"
#include <stdint.h>


int main (void)
{
  // The Code Block
}


// Enable PORTF clock
void init_portf (void)
{
  SYSCTL_RCGCGPIO_R |= 0x20;
  while(!(SYSCTL_PRGPIO_R &= 0x20));
}

// Initialize PORTF RGB LEDs (PF1-PF3)
void init_portf_leds (void)
{
  GPIO_PORTF_AFSEL_R &= ~0x0E;
  GPIO_PORTF_PCTL_R &= ~0xFFF0;
  GPIO_PORTF_AMSEL_R &= ~0x0E;
  GPIO_PORTF_DEN_R |= 0x0E;
  GPIO_PORTF_DIR_R |= 0x0E;
  GPIO_PORTF_DATA_R &= ~0x0E;
}

// Initialize PORTF switches (PF0 and PF4)
void init_portf_switches (void)
{
  GPIO_PORTF_LOCK_R = UNLOCK_KEY;
  GPIO_PORTF_CR_R = 0xFF;
  GPIO_PORTF_AFSEL_R &= ~0x11;
  GPIO_PORTF_PCTL_R &= ~0xF000F;
  GPIO_PORTF_AMSEL_R &= ~0x11;
  GPIO_PORTF_DEN_R |= 0x11;
  GPIO_PORTF_DIR_R &= ~0x11;
  GPIO_PORTF_PUR_R |= 0x11;
}

void red_on (void)
{
  GPIO_PORTF_DATA_R |= 0x02;
}

void yellow_on (void)
{
  GPIO_PORTF_DATA_R |= 0x0A;
}

void green_on (void)
{
  GPIO_PORTF_DATA_R |= 0x08;
}

void turn_leds_off (void)
{
  GPIO_PORTF_DATA_R &= ~0x0E;
}

// Intialize SysTick timer to count 1 millisecond
void init_systick (void)
{
  NVIC_ST_CTRL_R = 0;
  NVIC_ST_RELOAD_R = (CLOCK / 1000) - 1;
  NVIC_ST_CURRENT_R = 0;
  NVIC_ST_CTRL_R |= 0x05;
}

// Delay for specified time in milliseconds
void delay (uint32_t time)
{
  uint32_t i;
  for (i = 0; i < time; i++)
    while(!(NVIC_ST_CTRL_R & 0x10000));
}
