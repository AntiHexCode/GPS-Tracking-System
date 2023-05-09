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
  double instancevelocity;
  double n=0;   // Author:OmarGabr0.. n is used to count how many time the super loob had been excuted, this can be used to calculate the average velocity
  double comulative_speed=0; // used for comulative speed calculations
  // Distance that has been walked in meters
  double walked_distance = 0;
  //velocity in the current instance 
  // Getting the latitude and longitude for the first location
  latitude_and_longitude (&latitude_1, &longitude_1);

  // Wait for half a second (500 msec)
  delay(500);

  // Welcome to the main loop
  while (1){
   n+=1; // used for " average" functions calculations
    // Getting the latitude and longitude for the first location
    latitude_and_longitude (&latitude_2, &longitude_2);

    // Adding the distance we just walked moving between the two coordinates
    walked_distance += distance_between_coordinates(latitude_1, longitude_1, latitude_2, longitude_2);
    // Author:OmarGabr0..  Adding the instance velocity and average velocity 
     instancevelocity= instance_velocity ( latitude_1,longitude_1,latitude_2,longitude_2);
     comulative_speed+= instancevelocity;
   
  
   
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
