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
#define GPIO_PORTF_LOCK_R        (*((volatile uint32_t *)0x40025520))
#define GPIO_PORTF_CR_R          (*((volatile char *)0x40025524))
#define GPIO_PORTF_AMSEL_R       (*((volatile char *)0x40025528))
#define GPIO_PORTF_PCTL_R        (*((volatile uint32_t *)0x4002552C))


// Prototypes
// PORTF Intializations
void init_portf (void);
void init_portf_leds (void);
void init_portf_switches (void);

// LEDs
void red_on (void);
void yellow_on (void);
void green_on (void);
void turn_leds_off (void);
