/*
 * Author: AntiHexCode
 * Macros and Prototypes for SysTick timer
*/

// Header files
#include "tm4c123gh6pm.h"

// Macros
// SysTick Timer
#define NVIC_ST_CTRL_R           (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R         (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R        (*((volatile unsigned long *)0xE000E018))


// Prototypes
// SysTick timer
void init_systick (void);
void delay (double time);
