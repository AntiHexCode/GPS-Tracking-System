// Prototypes for main.c file

// PORTF Intializations
void init_portf (void);
void init_portf_leds (void);
void init_portf_switches (void);

// LEDs
void red_on (void);
void yellow_on (void);
void green_on (void);
void turn_leds_off (void);

// SysTick timer
void init_systick (void);
void delay (uint32_t time);
