
#include "tm4c123gh6pm.h"

  double latitude_1;
  double longitude_1;
  double latitude_2;
  double longitude_2;

int main(void)
{

  while (1) {
    uart_init();
    printf("%c\n", uart_recieve());
    latitude_and_longitude (&latitude_1, &longitude_1);
    latitude_and_longitude (&latitude_2, &longitude_2);
    printf("%lf\n", latitude_1);
    printf("%lf\n", longitude_1);
    printf("%lf\n", latitude_2);
    printf("%lf\n", longitude_2);
  }



}

// Extracting latitude and longitude from NMEA GPRMC
void latitude_and_longitude (double *latitude, double *longitude)
{
  char GPRMC[78];
  char latitude_array[12];
  char longitude_array[13];
  int undefined_location = 1; // undifined till we get the valid GPRMC and extract the latitude and longitude
  int i = 0; // counter for all the for loops

  // Loop till you find the valid GPRMC and extract the latitude and longitude
  while (undefined_location == 1){

    // Waiting until it is the start of a NMEA line
    while (uart_recieve() != '$');

    // Getting the whole NMEA line of characters
    for (i = 0; i < 78; i++)
      GPRMC[i] = uart_recieve();

    // Checking if its GPRMC or not, and if it's valid or not
    if (!((GPRMC[2] == "R") && (GPRMC[16] == "A")))
      continue;

    // Extracting the latitude and longitude
    for (i = 18; i < 30; i++)
      latitude_array[i-18] = GPRMC [i];

    for (i = 33; i < 46; i++)
      longitude_array[i-33] = GPRMC [i];

    char latitude_direction = GPRMC [31];
    char longitude_direction = GPRMC [47];

    // Found the location's latitude and longitude
    undefined_location = 0;

    // Converting types from char array to double
    sscanf(latitude_array, "%lf", &(*latitude));
    sscanf(longitude_array, "%lf", &(*longitude));

    // Getting the effect of the directions (south/west has -ve sign latitude and longitude)
    if (latitude_direction == 'S')
      *latitude = (*latitude) * -1;

    if (longitude_direction == 'W')
      *longitude = (*longitude) * -1;
  }

}

//  UART PORT D INIT
void uart_init(void){
  SYSCTL_RCGCUART_R |=0x04;
  SYSCTL_RCGCGPIO_R |=0x08;
  while(!(SYSCTL_PRGPIO_R &= 0X08)); // wait till port D stable
  UART2_CTL_R &= ~0x0001;
  UART2_IBRD_R  = 104;
  UART2_FBRD_R = 11;
  UART2_LCRH_R = 0x0070;
  UART2_CTL_R |= 0x0301;
  // PORT D UART2 Initializations
  GPIO_PORTD_AFSEL_R |= 0xC0; // enable alternative function on PD7 and PD6
  GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R & 0x00FFFFFF) | 0X11000000 ; //PD6 =U2RX , PD7=U2TX
  GPIO_PORTD_AMSEL_R &= ~0xC0; // disable digital function on PD& andPD6
  GPIO_PORTD_DEN_R |= 0xC0; // enable digital on portD (7 & 6)
}

// UART2 recieve from Rx fifo
char uart_recieve(){
    while (UART2_FR_R & 0X010 !=0); // while fifo embty
    return (char)(UART2_DR_R & 0xFF);
}
