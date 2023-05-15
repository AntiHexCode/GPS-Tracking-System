/*
* Code for converting the NMEA GPRMC from GPS to Coordinates
*/

#include "tm4c123gh6pm.h"


/*Extracting latitude and longitude from NMEA GPRMC*/
void latitude_and_longitude (double *latitude, double *longitude)
{
  char GPRMC[75];
  char latitude_array[12];
  char longitude_array[13];
  int i = 0; // counter for all the for loops
  char *p1, *p2; // end pointers for the strtod function

  // Loop till you find the valid GPRMC and extract the latitude and longitude
  while (1)
  {
    // Waiting until it is the start of a GPRMC line
    while (uart_recieve() != 'R');

    // Getting the whole NMEA line of characters
    for (i = 0; i < 75; i++)
      GPRMC[i] = uart_recieve();

    // Checking if its GPRMC or not, and if it's valid or not
    if (!(GPRMC[13] == 'A'))
      continue;

    // Extracting the latitude and longitude
    for (i = 15; i < 27; i++)
      latitude_array[i-15] = GPRMC [i];

    for (i = 30; i < 43; i++)
      longitude_array[i-30] = GPRMC [i];

    char latitude_direction = GPRMC [28];
    char longitude_direction = GPRMC [44];

    // Converting types from char array to double
    *latitude = (strtod(latitude_array, &p1)) / 100;
    *longitude = (strtod(longitude_array, &p2)) / 100;

    // Getting the effect of the directions (south/west has -ve sign latitude and longitude)
    if (latitude_direction == 'S')
      *latitude = (*latitude) * -1;

    if (longitude_direction == 'W')
      *longitude = (*longitude) * -1;

    break;
  }

}
