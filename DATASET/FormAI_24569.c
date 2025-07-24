//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371.0 // Earth's radius in kilometers

double degreesToRad(double degrees) {
   return degrees * M_PI / 180.0;
}

double distance(double lat1, double lon1, double lat2, double lon2) {
   double lat1_rad = degreesToRad(lat1);
   double lon1_rad = degreesToRad(lon1);
   double lat2_rad = degreesToRad(lat2);
   double lon2_rad = degreesToRad(lon2);

   double deltaLat = lat2_rad - lat1_rad;
   double deltaLon = lon2_rad - lon1_rad;

   double a = pow(sin(deltaLat / 2.0), 2.0) +
              cos(lat1_rad) * cos(lat2_rad) *
              pow(sin(deltaLon / 2.0), 2.0);
   double c = 2.0 * atan2(sqrt(a), sqrt(1.0 - a));
   return EARTH_RADIUS * c;
}

int main() {
   double lat1, lat2, lon1, lon2;
   printf("Enter latitude and longitude of start point:\n");
   scanf("%lf %lf", &lat1, &lon1);
   printf("Enter latitude and longitude of end point:\n");
   scanf("%lf %lf", &lat2, &lon2);

   double dist = distance(lat1, lon1, lat2, lon2);
   printf("The distance between the two points is %.2lf km.\n", dist);

   return 0;
}