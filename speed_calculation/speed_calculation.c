 /*
 * Author: OmarGabr0
 * Code for calculating inistance velocity every 0.5 secon
 */

 /*                                             *****VERY IMPORTAN*****
  -only use this funtion within the super loob 
  -this function dependes on where you use it and the delay ised in rhe main 
  -if you changed the delay this function can't be used untill you fix it here
 
 */

 // destance samples evry 0.5 second 

 double instance_velocity ( double lat_1,double lon_1,double lat_2,double lon_2){
    double distance = distance_between_coordinates( lat_1,  lon_1,  lat_2,  lon_2);  // calculating distance every 0.5 second *OR THE DELAY USED IN (main)*
    return (distance/0.5);  }                                                // 0.5 for the delay time used in main //
double average_velocity(double n,double comulative_speed){
    return(comulative_speed/n);
}
