#include "tm4c123gh6pm.h"
#include "leds_&_switches_portf.h"
#include "systick_timer.h"
#include "latitude_and_longitude.h"
#include "distance_between_coordinates.h"
#include <stdint.h>


int main (void)
{
  // First location coordinates
  double latitude_1;
  double longitude_1;

  // Second location coordinates
  double latitude_2;
  double longitude_2;

  // Distance that has been walked in meters
  double walked_distance = 0;

  // Getting the latitude and longitude for the first location
  latitude_and_longitude (&latitude_1, &longitude_1);

  // Wait for half a second (500 msec)
  delay(500);

  // Welcome to the main loop
  while (1){

    // Getting the latitude and longitude for the first location
    latitude_and_longitude (&latitude_2, &longitude_2);

    // Adding the distance we just walked moving between the two coordinates
    distance += distance_between_coordinates(latitude_1, longitude_1, latitude_2, longitude_2);

    /* setting the final point of the "first walked distance" as the first point
       for the "second distance" that will be walked */
    latitude_1 = latitude_2;
    longitude_1 = longitude_2;

    /*the code above may be rearranged after adding the other codes for the project
      in the main function but the main logic will probably stay the same.
      -The Leds code MUST be added.
      -The LCD code MUST be added.
      -The GPS interfacing code MUST be written and that might need a small
      modification on the coordinates extracting function.
      ~~ With pleasure, AntiHexCode :)
    */



  }



}
