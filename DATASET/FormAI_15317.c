//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Alan Touring
#include <stdio.h>

int main() {
  float current_lat, current_long;
  float target_lat, target_long;
  float distance, bearing;

  printf("Enter Current Latitude: ");
  scanf("%f", &current_lat);

  printf("Enter Current Longitude: ");
  scanf("%f", &current_long);

  printf("Enter Target Latitude: ");
  scanf("%f", &target_lat);

  printf("Enter Target Longitude: ");
  scanf("%f", &target_long);

  // Calculate distance between two points using Haversine formula
  float R = 6371.0;
  float dLat = (target_lat - current_lat) * (3.14159 / 180.0);
  float dLon = (target_long - current_long) * (3.14159 / 180.0);
  float a = pow(sin(dLat / 2), 2) + cos(current_lat * (3.14159 / 180.0)) * cos(target_lat * (3.14159 / 180.0)) * pow(sin(dLon / 2), 2);
  float c = 2 * atan2(sqrt(a), sqrt(1 - a));
  distance = R * c;

  // Calculate bearing between two points using Vincenty's formula
  float B, dPhi;
  current_lat*= (3.14159 / 180.0);
  target_lat*= (3.14159 / 180.0);
  dLon*= (3.14159 / 180.0);
  
  B = atan2(sin(dLon) * cos(target_lat), cos(current_lat) * sin(target_lat) - sin(current_lat) * cos(target_lat) * cos(dLon));
  
  // Convert bearing to degrees
  bearing = (B * 180.0 / 3.14159) + 360.0;
  bearing = fmod(bearing, 360);

  printf("Distance: %f km\n", distance);
  printf("Bearing: %f degrees\n", bearing);
  return 0;
}