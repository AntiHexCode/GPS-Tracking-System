 /*
 * Author: OmarGabr0
 * Code for calculating inistance velocity every 0.5 secon
 */

 /*                                             *****VERY IMPORTANT*****
  -only use this funtion within the super loob
  -this function dependes on where you use it and the delay ised in rhe main
  -if you changed the delay this function can't be used untill you fix it here

 */

 // distance samples evry 0.5 second

double get_instantaneous_speed (double walked_distance)
{
  // calculating instantaneous_speed every 0.5 second *OR THE DELAY USED IN (main)*
  return (walked_distance / 0.5);
}

double average_speed(double counter, double comulative_speed)
{
  return(comulative_speed / counter);
}
