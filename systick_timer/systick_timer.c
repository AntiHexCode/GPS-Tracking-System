/*
 * Author: AntiHexCode
 * Code for SysTick timer
*/

#include "systick_timer.h"
#include "tm4c123gh6pm.h"
#include <stdint.h>


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
