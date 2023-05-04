#include "leds_&_switches_portf.h"
#include "systick_timer.c"
#include "tm4c123gh6pm.h"
#include <stdint.h>
#include "UART.c"
#include "UART.h"
int main (void)
{ 
  int counter =0;
  char GPRMC[79];
  char gprmc_mini[5];
  //LAT
  int lat_flag = 0;
  char lat[24];
  int lat_counter =0;

  //LAT-DIR
  char lat_dir[2];
  int lat_dir_flag;
  int lat_dir_counter;
  //LON
  int lon_flag = 0;
  char lon[24];
  int lon_counter=0;
  //LON-FLAG
  int lon_dir_flag = 0;
  char lon_dir[2];
  int lon_dir_counter = 0;
  //INSERT BIG WHILE
  //LAT COUNTER INCREMENT AFTER DELAY
  //LAT DIRECTION COUNTER INCREMENT AFTER DELAY
  while(1){
    if(counter == 5)
    {
      counter = 0;
    }
    if(lat_counter == 24 && lon_counter == 24 && lat_dir_counter%2==0
    &&lon_dir_counter %2==0)
    {
      lat_counter = 0;
      lon_counter = 0;
      lat_dir_counter = 0;
      lon_dir_counter = 0;
    }
  while(1){
    char gpsdata = uart_recieve(); //read gps data from uart
    if(counter == 0 && gpsdata == 'G')
    {
      counter++;
      gprmc_mini[0] = gpsdata;
    }
    if(counter == 1 && gpsdata == 'P')
    { 
      counter++;
      gprmc_mini[1] = gpsdata;
    }
    if(counter == 2 && gpsdata == 'R')
    {
      counter++;
      gprmc_mini[2] = gpsdata;
    }
    if(counter == 3 && gpsdata == 'M')
    {
      counter++;
      gprmc_mini[3] = gpsdata;
    }
    if(counter == 4 && gpsdata == 'C')
    {
      counter++;
      gprmc_mini[4] = gpsdata;
    }
    if(counter == 5) // meaning we are in GPRMC LINE
    { 
      if(gpsdata == 'V')
      break;//invalid data

      //LATITUDE EXCTRACTION
      if(gpsdata == 'A')
      lat_flag = 1;
      if(lat_flag == 1 && gpsdata!=','){
        lat[lat_counter] = gpsdata;
        lat_counter++;
        if(lat_counter ==11)
        {lat_flag =0;}
        lat_dir_flag = 1;
      }
      //LATITUDE DIRECTION EXTRACTION
      if(lat_dir_flag == 1 && gpsdata !=',')
      {
        lat_dir[lat_dir_counter] = gpsdata;
        lat_dir_counter++;
        lat_dir_flag = 0;
        lon_flag = 1;
      }
      //LONGITUDE EXTRACTION
      if(lon_flag == 1 && gpsdata != ",")
      {
        lon[lon_counter] = gpsdata;
        lon_counter++;
        if(lon_counter == 11)
        lon_flag = 0;
        lon_dir_flag = 1;
      }
      //LONGITUDE DIRECTION EXTRACTION
      if(lon_dir_flag == 1 && gpsdata !=",")
      {
        lon_dir[lon_dir_counter] = gpsdata;
        lon_dir_counter++;
        lon_dir_flag=0;
      }
    //TERMINATION
    if(gpsdata == '*')
    break;
    }
    }
    }
}