/////////////////////////////////// General ////////////////////////////////////
/*
* Author: AntiHexCode
* General Macros
*/

// Macros
// System Control Registers (SYSCTL)
#define SYSCTL_RCGCGPIO_R        (*((volatile char *)0x400FE608))
#define SYSCTL_PRGPIO_R          (*((volatile char *)0x400FEA08))

// Constants
#define UNLOCK_KEY                         0x4C4F434B
#define CLOCK                               16000000
////////////////////////////////////////////////////////////////////////////////



/////////////////////////// Distance Calculations //////////////////////////////
/*
* Author: AntiHexCode
* Libraries, Macros and Prototypes for Calculating the distance between two coordinates
*/

// Libraries
#include <math.h>

// Macros
#define EARTH_RADIUS    6371000 // in meters
#define PI              3.14159

// Prototypes
double distance_between_coordinates(double lat_1, double lon_1, double lat_2, double lon_2);
////////////////////////////////////////////////////////////////////////////////



////////////////////////// Latitude and Longitude //////////////////////////////
/*
* Author: AntiHexCode
* Libraries and Prototypes for Extracting the latitude and longitude from NMEA
*/

// Libraries
#include <stdio.h>

// Prototypes
void latitude_and_longitude (double *latitude, double *longitude);
////////////////////////////////////////////////////////////////////////////////



////////////////////////////// LEDs and Switches ///////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////
/*
 * Author: OmarGabr0
 * Macros for Port D ****"used in UART 2"***
*/
// Macros for portD
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTD_PDR_R        (*((volatile unsigned long *)0x40007514))

#define UART2_DR_R              (*((volatile unsigned long *)0x4000E000))
#define UART2_FR_R              (*((volatile unsigned long *)0x4000E018))
#define UART2_IBRD_R            (*((volatile unsigned long *)0x4000E024))
#define UART2_FBRD_R            (*((volatile unsigned long *)0x4000E028))
#define UART2_LCRH_R            (*((volatile unsigned long *)0x4000E02C))
#define UART2_CTL_R             (*((volatile unsigned long *)0x4000E030))
////////////////////////////////////////////////////////////////////////////////



/////////////////////////// PF4 Switch Interrupt ///////////////////////////////
/*
 * Author: AntiHexCode
 * Macros and Prototypes for PF4 Switch Interrupt
*/

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
////////////////////////////////////////////////////////////////////////////////



////////////////////////////// Speed Calculations //////////////////////////////
/*
* Author: OmarGabr0
* Prototypes for calculating inistance velocity every 0.5 secon
*/

double get_instantaneous_speed (double walked_distance);
double average_speed (double counter, double comulative_speed);
////////////////////////////////////////////////////////////////////////////////



/////////////////////////////// SysTick Timer //////////////////////////////////
/*
 * Author: AntiHexCode
 * Macros and Prototypes for SysTick timer
*/

// Macros
// SysTick Timer
#define NVIC_ST_CTRL_R           (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R         (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R        (*((volatile unsigned long *)0xE000E018))


// Prototypes
// SysTick timer
void init_systick (void);
void delay (double time);
////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////// UART0 //////////////////////////////////////
/*
* Author: OmarGabr0
* UART0 Macros and Prototypes
*/

// Macros
// UART0 //
#define UART0_DR_R              (*((volatile unsigned long *)0x4000C000))
#define UART0_FR_R              (*((volatile unsigned long *)0x4000C018))
#define UART0_IBRD_R            (*((volatile unsigned long *)0x4000C024))
#define UART0_FBRD_R            (*((volatile unsigned long *)0x4000C028))
#define UART0_LCRH_R            (*((volatile unsigned long *)0x4000C02C))
#define UART0_CTL_R             (*((volatile unsigned long *)0x4000C030))

// SYSCTL //
#define SYSCTL_RCGCUART_R       (*((volatile unsigned long *)0x400FE618))

// GPIO A //
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))

// Prototypes
void uart_init();
char uart_recieve();
////////////////////////////////////////////////////////////////////////////////



///////////////////////////////// Bit Help /////////////////////////////////////
/*
* Author: Mohamed Mostafa Mahmoud
* Macros to help with some Bit operations
*/

// set specific bit of register to one
#define SET_BIT(reg, bit_no) reg |= (1<<bit_no)

// toogle  specific bit of register
#define TOGGLE_BIT(reg, bit_no) reg ^= (1<<bit_no)

// clear specific bit of register
#define CLEAR_BIT(reg, bit_no) reg &= ~(1<<bit_no)

// set value for more than one bit
#define SET_VALUE(reg, value) reg |= value

// clear value for more than one bit
#define CLEAR_VALUE(reg, value) reg &= ~value

// clear value for more than one bit
#define TOGGLE_VALUE(reg, value) reg ^= value
////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////// LCD ///////////////////////////////////////
/*
 * Author: AntiHexCode, Mohamed Mostafa Mahmoud
 * Macros and Prototypes for LCD
*/

// Macros for PortA
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
#define GPIO_PORTA_PDR_R        (*((volatile unsigned long *)0x40004514))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_LOCK_R       (*((volatile unsigned long *)0x40004520))
#define GPIO_PORTA_CR_R         (*((volatile unsigned long *)0x40004524))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))

// Macros for PortB
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_CR_R         (*((volatile unsigned long *)0x40005524))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_LOCK_R       (*((volatile unsigned long *)0x40005520))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))
#define GPIO_PORTB_PDR_R        (*((volatile unsigned long *)0x40005514))

// Prototypes
void lcd_cmd(unsigned char data);
void BINS_DATA(unsigned char data);
void PORTS_INIT(void);
void lcd_init(void);
void lcd_data(unsigned char data);
void lcd_string(unsigned char *str, unsigned char length);
////////////////////////////////////////////////////////////////////////////////
