#include "tm4c123gh6pm.h"


int main (void)
{

  init_pf4_switch_interrupt();
  lcd_init();
   char* str1="Distance(m)";
    char* str2="Speed(m/s)";
  lcd_cmd(0x80);
    lcd_string(str1,12);
  lcd_cmd(0xC0);
    lcd_string(str2,11);


  ///////////////////////// TOTAL DISTANCE CALCULATIONS ////////////////////////
  // Author: AntiHexCode
  // First location coordinates
  double latitude_1;
  double longitude_1;
  // Second location coordinates
  double latitude_2;
  double longitude_2;
  // Final Location coordinates
  double final_latitude;
  double final_longitude;
  // Distance that has been walked in meters between the sub locations
  double walked_distance;
  // Distance that has been walked in meters between the first and final locations
  double total_walked_distance = 0;
  // Getting the latitude and longitude for the first location
  latitude_and_longitude (&latitude_1, &longitude_1);
  //////////////////////////////////////////////////////////////////////////////




  ///////////////////////// SPEED CALCULATIONS /////////////////////////////////
  // Author: OmarGabr0
  double instantaneous_speed;
  // counter that counts how many times the super loob had been excuted
  // this can be used to calculate the average speed
  int counter = 0;
  // used for comulative speed calculations
  double comulative_speed = 0;
  //////////////////////////////////////////////////////////////////////////////



  // Wait for half a second (500 milisecond)
  delay(500);


  // Welcome to the main loop
  while (1){


    ///////////////////////// TOTAL DISTANCE CALCULATIONS //////////////////////
    // Author: AntiHexCode
    // Getting the latitude and longitude for the first location
    latitude_and_longitude (&latitude_2, &longitude_2);
    // Adding the distance we just walked moving between the two coordinates
    walked_distance = distance_between_coordinates(latitude_1, longitude_1, latitude_2, longitude_2);
    total_walked_distance += walked_distance;
    ////////////////////////////////////////////////////////////////////////////



    ////////////////////////////////// LEDs ////////////////////////////////////
    // Author: KarimWalidFawzy
    // displacement between the current location and the final location
    double displacement = distance_between_coordinates(latitude_2, longitude_2, final_latitude, final_longitude);
    init_portf ();
    init_portf_leds ();
    // Arrived (approx 0.5 meter or less near final location)
    if(displacement <= 0.5)
    {
      only_green_on();
    }
    // five meters or less near the final location but didn't arrive yet
    else if((displacement <= 5) && (displacement > 0.5))
    {
      only_yellow_on();
    }
    // far away
    else
    {
      only_red_on();
    }
    ////////////////////////////////////////////////////////////////////////////



    /////////////////////////// SPEED CALCULATIONS /////////////////////////////
    // Author: OmarGabr0
    counter += 1; // used for average speed calculations
    // Adding the instantaneous speed and average speed
    instantaneous_speed = instantaneous_speed(walked_distance);
    comulative_speed += instantaneous_speed;
    ////////////////////////////////////////////////////////////////////////////



    ////////////////////// TOTAL DISTANCE CALCULATIONS /////////////////////////
    // Author: AntiHexCode
    /* setting the final point of the "first walked distance" as the first point
       for the "second distance" that will be walked */
    latitude_1 = latitude_2;
    longitude_1 = longitude_2;
    ////////////////////////////////////////////////////////////////////////////
    
    ////////////////////// LCD DISPLAY /////////////////////////
    // Author: KarimWalidFawzy 
    /** displaying the distance and speed on the lcd screen*/
    lcd_cmd(0x8D);
    lcd_data(walked_distance);
    lcd_cmd(0xCB);
    lcd_data(instantaneous_speed);
    lcd_cmd(0x8D);
      ////////////////////////////////////////////////////////////////////////////



  }

}
