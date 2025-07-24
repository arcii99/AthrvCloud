//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

typedef struct {
  double latitude;
  double longitude;
} Coordinate;

Coordinate getRandomCoordinate() {
  Coordinate c;
  c.latitude = (double)rand()/(double)(RAND_MAX/180) - 90;
  c.longitude = (double)rand()/(double)(RAND_MAX/360) - 180;
  return c;
}

double distance(Coordinate c1, Coordinate c2) {
  double x = (c2.longitude - c1.longitude) * cos((c1.latitude + c2.latitude) / 2);
  double y = (c2.latitude - c1.latitude);
  return sqrt(x*x + y*y) * 6371;
}

int main() {
  Coordinate current_location = getRandomCoordinate();
  Coordinate destination = getRandomCoordinate();
  double distance_to_dest = distance(current_location, destination);

  printf("Your current location is at (%.4f, %.4f)\n", current_location.latitude, current_location.longitude);
  printf("Your destination is at (%.4f, %.4f), %.2f km away\n", destination.latitude, destination.longitude, distance_to_dest);

  while (distance_to_dest > 0.1) {
    double heading = atan2(destination.longitude - current_location.longitude, destination.latitude - current_location.latitude) * 180 / PI;
    printf("Head %.2f degrees, distance to dest: %.2f km\n", heading, distance_to_dest);

    double step_distance = 0.01;
    current_location.latitude += step_distance * sin(heading * PI / 180);
    current_location.longitude += step_distance * cos(heading * PI / 180);
    distance_to_dest = distance(current_location, destination);
  }
  printf("You have arrived at your destination!\n");

  return 0;
}