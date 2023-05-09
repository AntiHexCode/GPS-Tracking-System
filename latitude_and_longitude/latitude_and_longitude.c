/*
* Author: AntiHexCode
* Code for converting the NMEA GPRMC from GPS to Coordinates
*/

# include "latitude_and_longitude.h"


// Extracting latitude and longitude from NMEA GPRMC
void latitude_and_longitude (double *latitude, double *longitude)
{
  char GPRMC[78];
  char latitude_array[12];
  char longitude_array[13];
  int undifined_location = 1; // undifined till we get the valid GPRMC and extract the latitude and longitude

  // Loop till you find the valid GPRMC and extract the latitude and longitude
  while (undifined_location == 1){

    // Waiting until it is the start of a NMEA line
    while (uart_recieve() != '$');

    // Getting the whole NMEA line of characters
    for (int i = 0; i < 78; i++)
      GPRMC[i] = uart_recieve();

    // Checking if its GPRMC or not, and if it's valid or not
    if (!((GPRMC[2] == "R") && (GPRMC[16] == "A")))
      continue;

    // Extracting the latitude and longitude
    for (int i = 18; i < 30; i++)
      latitude_array[i-18] = GPRMC [i];

    for (int i = 33; i < 46; i++)
      longitude_array[i-33] = GPRMC [i];

    char latitude_direction = GPRMC [31];
    char longitude_direction = GPRMC [47];

    // Found the location's latitude and longitude
    undifined_location = 0;

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
