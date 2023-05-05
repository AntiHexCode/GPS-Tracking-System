/*
* Author: AntiHexCode
* Libraries, Macros and Prototypes for Calculating the distance between two coordinates
*/

// Libraries
#include <math.h>
#include <stdint.h>

// Macros
#define EARTH_RADIUS    6371000 // in meters
#define PI              3.14159

// Prototypes
double distance_between_coordinates(double lat_1, double lon_1, double lat_2, double lon_2);
