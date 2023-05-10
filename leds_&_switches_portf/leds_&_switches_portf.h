/*
 * Author: AntiHexCode
 * Macros and Prototypes for Port F
*/

// Macros
// GPIO Registers (Port F)
#define GPIO_PORTF_DATA_R        (*((volatile char *)0x400253FC))
#define GPIO_PORTF_DIR_R         (*((volatile char *)0x40025400))
#define GPIO_PORTF_AFSEL_R       (*((volatile char *)0x40025420))
#define GPIO_PORTF_PUR_R         (*((volatile char *)0x40025510))
#define GPIO_PORTF_DEN_R         (*((volatile char *)0x4002551C))
#define GPIO_PORTF_LOCK_R        (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R          (*((volatile char *)0x40025524))
#define GPIO_PORTF_AMSEL_R       (*((volatile char *)0x40025528))
#define GPIO_PORTF_PCTL_R        (*((volatile unsigned long *)0x4002552C))

//Libraries
#include "tm4c123gh6pm.h"

// Prototypes
// PORTF Intializations
void init_portf (void);
void init_portf_leds (void);
void init_portf_switches (void);

// LEDs
void only_red_on (void);
void only_yellow_on (void);
void only_green_on (void);
void turn_leds_off (void);

// Switches
int switch_1_pressed (void);
int switch_2_pressed (void);
