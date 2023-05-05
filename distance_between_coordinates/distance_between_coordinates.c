/*
* Author: AntiHexCode
* Code for Calculating the distance between two coordinates
*/


#include "distance_between_coordinates.h"

// Calculating the distance between two coordinates using their latitude and longitude
double distance_between_coordinates(double lat_1, double lon_1, double lat_2, double lon_2)
{
  double P1 = lat_1 * PI / 180; // in radians
  double P2 = lat_2 * PI / 180; // in radians
  double D = (lat_2 - lat_1) * PI / 180; // in radians
  double L = (lon_2 - lon_1) * PI / 180; // in radians

  double A = sin(D/2) * sin(D/2) + cos(P1) * cos(P2) * sin(L/2) * sin(L/2);

  double C = 2 * atan2(sqrt(A), sqrt(1-A));

  return EARTH_RADIUS * C; // distance in meters
}
