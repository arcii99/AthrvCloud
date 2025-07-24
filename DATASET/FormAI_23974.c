//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main()
{
  float lat1, lon1, lat2, lon2;
  float lat1_rad, lon1_rad, lat2_rad, lon2_rad;
  float distance, bearing;

  printf("Enter the first point's latitude and longitude separated by a space: ");
  scanf("%f %f",&lat1,&lon1);

  printf("Enter the second point's latitude and longitude separated by a space: ");
  scanf("%f %f",&lat2,&lon2);

  // Convert degrees to radians
  lat1_rad = lat1 * PI / 180;
  lon1_rad = lon1 * PI / 180;
  lat2_rad = lat2 * PI / 180;
  lon2_rad = lon2 * PI / 180;

  // Calculate distance using Haversine formula
  float a = pow( sin( (lat2_rad - lat1_rad)/2 ), 2 ) + cos(lat1_rad) * cos(lat2_rad) * pow(sin( (lon2_rad - lon1_rad)/2 ), 2 );
  float c = 2 * atan2( sqrt(a), sqrt(1-a) );
  distance = 6371 * c;

  // Calculate bearing using Vincenty formula
  float y = sin(lon2_rad-lon1_rad) * cos(lat2_rad);
  float x = cos(lat1_rad) * sin(lat2_rad) - sin(lat1_rad) * cos(lat2_rad) * cos(lon2_rad-lon1_rad);
  bearing = atan2(y, x) * 180 / PI;

  // Output results
  printf("Distance between the two points: %f km\n", distance);
  printf("Bearing from the first point to the second point: %f degrees\n", bearing);

  return 0;
}