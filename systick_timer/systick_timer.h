/*
 * Author: AntiHexCode
 * Macros and Prototypes for SysTick timer
*/

// Macros
// SysTick Timer
#define NVIC_ST_CTRL_R           (*((volatile uint32_t *)0xE000E010))
#define NVIC_ST_RELOAD_R         (*((volatile uint32_t *)0xE000E014))
#define NVIC_ST_CURRENT_R        (*((volatile uint32_t *)0xE000E018))


// Prototypes
// SysTick timer
void init_systick (void);
void delay (uint32_t time);
