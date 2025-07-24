//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define earthRadiusKm 6371.0

double deg2rad(double deg) {
  return (deg * M_PI / 180);
}

double rad2deg(double rad) {
  return (rad * 180 / M_PI);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r-lat1r)/2);
  v = sin((lon2r-lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u*u + cos(lat1r)*cos(lat2r)*v*v));
}

int main() {
  double lat1 = 37.7749, lon1 = -122.4194;  // San Francisco
  double lat2 = 40.7128, lon2 = -74.0059;   // New York
  printf("Distance between San Francisco and New York is: %.2f km", distanceEarth(lat1, lon1, lat2, lon2));
  return 0;
}