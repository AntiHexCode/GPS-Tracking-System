/*
 * Author: AntiHexCode
 * Header files, Macros and Prototypes for PF4 Switch Interrupt
*/

//Header files
#include "leds_&_switches_portf.h"


// Macros
// GPIO Registers (Port F)
#define GPIO_PORTF_IS_R         (*((volatile unsigned long *)0x40025404))
#define GPIO_PORTF_IBE_R        (*((volatile unsigned long *)0x40025408))
#define GPIO_PORTF_IEV_R        (*((volatile unsigned long *)0x4002540C))
#define GPIO_PORTF_IM_R         (*((volatile unsigned long *)0x40025410))
#define GPIO_PORTF_RIS_R        (*((volatile unsigned long *)0x40025414))
#define GPIO_PORTF_ICR_R        (*((volatile unsigned long *)0x4002541C))

// NVIC
#define NVIC_PRI7_R             (*((volatile unsigned long *)0xE000E41C))
#define NVIC_EN0_R              (*((volatile unsigned long *)0xE000E100))


// Prototypes
void init_pf4_switch_interrupt(void);
void GPIOPortF_Handler(void);
