#include "tm4c123gh6pm.h"


int main (void)
{
  // Intializations
  init_portf();
  init_portf_leds();
  init_systick();
  init_uart();


  ///////////////////////// TOTAL DISTANCE CALCULATIONS ////////////////////////
  // First location coordinates
  double latitude_1;
  double longitude_1;
  // Second location coordinates
  double latitude_2;
  double longitude_2;
  // Final Location coordinates, put test cooardinates
  double final_latitude;
  double final_longitude;
  // Distance that has been walked in meters between the sub locations
  double walked_distance;
  // Distance that has been walked in meters between the first and final locations
  double total_walked_distance = 0;
  // Getting the latitude and longitude for the first location
  latitude_and_longitude (&latitude_1, &longitude_1);
  //////////////////////////////////////////////////////////////////////////////


  // Wait for half a second (500 milisecond)
  delay(500);


  // Welcome to the main loop
  while (1){


    ///////////////////////// TOTAL DISTANCE CALCULATIONS //////////////////////
    // Getting the latitude and longitude for the first location
    latitude_and_longitude (&latitude_2, &longitude_2);
    // Adding the distance we just walked moving between the two coordinates
    walked_distance = distance_between_coordinates(latitude_1, longitude_1, latitude_2, longitude_2);
    total_walked_distance += walked_distance;
    ////////////////////////////////////////////////////////////////////////////



    ////////////////////////////////// LEDs ////////////////////////////////////
    // displacement between the current location and the final location
    double displacement = distance_between_coordinates(latitude_2, longitude_2, final_latitude, final_longitude);

    // Arrived (approx 0.5 meter or less near final location)
    if(displacement <= 0.5)
      only_green_on();

    // five meters or less near the final location but didn't arrive yet
    else if((displacement <= 5) && (displacement > 0.5))
      only_yellow_on();

    // far away
    else
      only_red_on();
    ////////////////////////////////////////////////////////////////////////////



    ////////////////////// TOTAL DISTANCE CALCULATIONS /////////////////////////
    /* setting the final point of the "first walked distance" as the first point
       for the "second distance" that will be walked */
    latitude_1 = latitude_2;
    longitude_1 = longitude_2;
    ////////////////////////////////////////////////////////////////////////////

  }

}
