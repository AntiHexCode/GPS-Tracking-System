#include "tm4c123gh6pm.h"

double distance_between_coordinates(double lat_1, double lon_1, double lat_2, double lon_2)
void RGB_Init(void){
	SYSCTL_RCGCGPIO_R|=0x20; //INTIALIZE THE CLOCK OF PORTF
	while((SYSCTL_PRGPIO_R & 0x20)==0); //delay
	GPIO_PORTF_LOCK_R = 0x4C4F434B; //unlocking the ports have the same value
	GPIO_PORTF_CR_R |= 0x0E; //Allow changing pin 3,2,1 in portF
	GPIO_PORTF_AMSEL_R &=~0x0E; //disable the analog function
	GPIO_PORTF_PCTL_R &=~0x0000FFF0;
	GPIO_PORTF_AFSEL_R &=~0x0E; //disable the alternate function
	GPIO_PORTF_DIR_R |= 0x0E; //Pin1,2,3 is output
	GPIO_PORTF_DEN_R |=0x0E;
	GPIO_PORTF_DATA_R &=~0x0E; //intialize pins 1,2,3 to be off
}

void RGBLED_Init(void){
	volatile unsigned long	delay;
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0);
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R |= 0x0E;
	GPIO_PORTF_AMSEL_R &= ~0x0E;
	GPIO_PORTF_PCTL_R &= ~0x0000FFF0;
	GPIO_PORTF_AFSEL_R &= ~0x0E;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_DATA_R |= 0x08;
}

void SW1_Init(void){
	volatile unsigned long	delay;
	SYSCTL_RCGCGPIO_R |= 0x20;
	while((SYSCTL_PRGPIO_R & 0x20) == 0);
	GPIO_PORTF_LOCK_R = 0x4C4F434B;
	GPIO_PORTF_CR_R |= 0x10;
	GPIO_PORTF_AMSEL_R &= ~0x10;
	GPIO_PORTF_PCTL_R &= ~0x000F0000;
	GPIO_PORTF_AFSEL_R &= ~0x10;
	GPIO_PORTF_DIR_R &= 0x10;
	GPIO_PORTF_DEN_R |= 0x10;
	GPIO_PORTF_DATA_R |= ~0x10;
}

void PortF_Init (void) {
		SYSCTL_RCGCGPIO_R|=0x20; //INTIALIZE THE CLOCK OF PORTF
		while((SYSCTL_PRGPIO_R & 0x20)==0); //delay
		GPIO_PORTF_LOCK_R = 0x4C4F434B; //Constant value
		GPIO_PORTF_AMSEL_R &=~0x11; //disable analog function
		GPIO_PORTF_CR_R |= 0x11; //setting pin p4 &p1 to change
		GPIO_PORTF_PCTL_R &=~0x000F0000; //enable digital function
		GPIO_PORTF_AFSEL_R &=~0x11; //disable alterante function
		GPIO_PORTF_DIR_R &=~0x11; //DIR--> 0->input & 1->output
		GPIO_PORTF_PUR_R |=0x11; //active low
		GPIO_PORTF_DEN_R |= 0x11; //Enable digital for sw1
}

int main(){
	float distance = distance_between_coordinates();
	RGB_Init();
	RGBLED_Init();
    while(1){
    	if( distance == 0){
    		GPIO_PORTF_DATA_R = 0x04;/* for green colour*/
    	}
    	else if(distance <5 && distance !=0){
    		GPIO_PORTF_DATA_R = 0x02; /*for yellow colour */
    	}
    	else{
    		GPIO_PORTF_DATA_R = 0x0E;
    	}
    	delay(1000);
    }
}
