//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define RADIUS 6371

typedef struct {
  double lat;
  double lon;
} Coordinate;

double degToRad(double deg) {
  return deg * PI / 180;
}

double distBetween(Coordinate coord1, Coordinate coord2) {
  double lat1 = degToRad(coord1.lat);
  double lat2 = degToRad(coord2.lat);
  double lon1 = degToRad(coord1.lon);
  double lon2 = degToRad(coord2.lon);
  
  double dLat = lat2 - lat1;
  double dLon = lon2 - lon1;
  
  double a = pow(sin(dLat/2), 2) + cos(lat1) * cos(lat2) * pow(sin(dLon/2), 2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  double d = RADIUS * c;
  
  return d;
}

double bearingBetween(Coordinate coord1, Coordinate coord2) {
  double lat1 = degToRad(coord1.lat);
  double lat2 = degToRad(coord2.lat);
  double lon1 = degToRad(coord1.lon);
  double lon2 = degToRad(coord2.lon);
  
  double y = sin(lon2-lon1) * cos(lat2);
  double x = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(lon2-lon1);
  
  double bearing = atan2(y, x) * 180 / PI;
  
  return bearing;
}

int main() {
  Coordinate start = {40.7831, -73.9712}; // Central Park, NY
  Coordinate end = {51.5074, -0.1278}; // London, UK
  
  double distance = distBetween(start, end);
  double bearing = bearingBetween(start, end);
  
  printf("Distance from Central Park to London: %.2f km\n", distance);
  printf("Bearing from Central Park to London: %.2f degrees\n", bearing);
  
  return 0;
}