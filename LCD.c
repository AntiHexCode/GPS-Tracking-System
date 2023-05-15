/**
 * authour : mohamed mostafa mahmoud 
 * 
*/


/*
*LCD interfacing with tiva c
*/

/*
some info about lcd 16*2:
* we will work in 8 bit mode using 8 bits of port B
* we will make control BITS in A7, A6, A5
* PIN 1 --> ground
* PIN 2 --> VCC
* PIN 4 (R/S): toogle between command and data , 0--->command mode  , 1 -----> DATA mode
* PIN 5 (RW): toogle between READ and write , 0--->WRITW operation  , 1------> READ operation
* PIN 6 (enable) : Must be held high to perform Read/Write Operation
* datasheet_link : https://circuitdigest.com/article/16x2-lcd-display-module-pinout-datasheet
*/

#include "tm4c123gh6pm.h"

// B0  D0
// B1  D1
// B2  D2
// B3  D3
// B4  D4
// B5  D5
// B6  D6
// B7  D7

void BINS_DATA (unsigned char data)  // 8 bit data
{
	if ((data & 0x01)==0x01) // B0 has 1 on it
		GPIO_PORTB_DATA_R |= 0x01;
	else
		GPIO_PORTB_DATA_R &= ~(0x01);

	if ((data & 0x02)==0x02) // B1 has 1 on it
		GPIO_PORTB_DATA_R |= 0x02;
	else
		GPIO_PORTB_DATA_R &= ~(0x02);

	if ((data & 0x04)==0x04) // B2 has 1 on it
		GPIO_PORTB_DATA_R |= 0x04;
	else
		GPIO_PORTB_DATA_R &= ~(0x04);

	if ((data & 0x08)==0x08) // B3 has 1 on it
		GPIO_PORTB_DATA_R |= 0x08;
	else
		GPIO_PORTB_DATA_R &= ~(0x08);

	if ((data & 0x10)==0x10) // B4 has 1 on it
		GPIO_PORTB_DATA_R |= 0x10;
	else
		GPIO_PORTB_DATA_R &= ~(0x10);

	if ((data & 0x20)==0x20) // B5 has 1 on it
		GPIO_PORTB_DATA_R |= 0x20;
	else
		GPIO_PORTB_DATA_R &= ~(0x20);

	if ((data & 0x40)==0x40) // B6 has 1 on it
		GPIO_PORTB_DATA_R |= 0x40;
	else
		GPIO_PORTB_DATA_R &= ~(0x40);

	if ((data & 0x80)==0x80) // B7 has 1 on it
		GPIO_PORTB_DATA_R |= 0x80;
	else
		GPIO_PORTB_DATA_R &= ~(0x80);

}

void PORTS_INIT(void)
{
	SYSCTL_RCGCGPIO_R |= 0x03;
  while(!(SYSCTL_PRGPIO_R &= 0x03));
  GPIO_PORTB_CR_R = 0xFF;
  GPIO_PORTB_AFSEL_R &= ~0x11;
  GPIO_PORTB_PCTL_R &= ~0xFFFFFFF;
  GPIO_PORTB_AMSEL_R &= ~0xFF;
  GPIO_PORTB_DEN_R |= 0xFF;
  GPIO_PORTB_DIR_R |= 0xFF;

	GPIO_PORTA_AMSEL_R |= 0x0;
	GPIO_PORTA_DEN_R |= 0xE0; // RS, EN, RW BITS AS Output: A7, A6, A5 respectivly
	GPIO_PORTA_DIR_R |= 0xE0;
	GPIO_PORTA_AFSEL_R |= 0X01;
}

void lcd_init (void)
{
	// intialize some feature : bit mode and cursor , position of it
	lcd_cmd(0x38); // 8 bit mode
	lcd_cmd (0x80); // cursor at first coloum
	lcd_cmd(0x06); // incrementing cursour
	lcd_cmd (0x0c); //cursor off and display on
	lcd_cmd(0x01); //clear screen
}

void lcd_data (unsigned char data) // this data stored in char register in lcd
{
// enable clock of lcd
// enable write mode operation
BINS_DATA(data);
GPIO_PORTA_DATA_R |=(1<<5); // R/W OFF
GPIO_PORTA_DATA_R |=(1<<7); // RS ON
GPIO_PORTA_DATA_R |=(1<<6); // EN ON
delay(1000);
GPIO_PORTA_DATA_R &= ~(1<<6); // EN OFF
}

void lcd_numberdata (double data) // this data stored in char register in lcd
{
// enable clock of lcd
// enable write mode operation
BINS_DATA(data);
GPIO_PORTA_DATA_R |=(1<<5); // R/W OFF
GPIO_PORTA_DATA_R |=(1<<7); // RS ON
GPIO_PORTA_DATA_R |=(1<<6); // EN ON
delay(1000);
GPIO_PORTA_DATA_R &= ~(1<<6); // EN OFF
}


void lcd_cmd(unsigned char command)  // stored as byte instruction in lcd register
{
// enable clock of lcd
// enable write mode operation
BINS_DATA(command);
GPIO_PORTA_DATA_R |= (1<<5); // R/W OFF
GPIO_PORTA_DATA_R &= ~(1<<7); // RS OFF
delay(1000);
GPIO_PORTA_DATA_R &= ~(1<<6); // EN OFF
}

void lcd_string (unsigned char *str, unsigned char length) //e.g ("distance" , 8)
{
char index;
	for (index = 0; index<length; index++)
		{
		lcd_data(str[index]);
		}
}
