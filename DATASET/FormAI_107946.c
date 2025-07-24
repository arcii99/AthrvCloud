//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define N 10 //Number of GPS coordinates

struct GPS {
  double latitude;
  double longitude;
};

void generateCoordinates(struct GPS *coordinates) {
  srand(time(0));
  for (int i = 0; i < N; i++) {
    coordinates[i].latitude = (double)rand()/(double)(RAND_MAX/180);
    coordinates[i].longitude = (double)rand()/(double)(RAND_MAX/360);
  }
}

double distance(struct GPS a, struct GPS b) {
  double dLat = (b.latitude - a.latitude) * M_PI / 180;
  double dLon = (b.longitude - a.longitude) * M_PI / 180;
  double lat1 = a.latitude * M_PI / 180;
  double lat2 = b.latitude * M_PI / 180;
  double R = 6371; //Radius of earth in kms
  double a1 = sin(dLat/2) * sin(dLat/2) +
              sin(dLon/2) * sin(dLon/2) * cos(lat1) * cos(lat2);
  double c = 2 * atan2(sqrt(a1), sqrt(1-a1));
  double d = R * c;
  return d;
}

struct GPS findNearestCoordinate(struct GPS current_location, struct GPS *coordinates) {
  double min_distance = INFINITY;
  struct GPS nearest_coordinate;
  for (int i = 0; i < N; i++) {
    double d = distance(current_location, coordinates[i]);
    if (d < min_distance) {
      min_distance = d;
      nearest_coordinate = coordinates[i];
    }
  }
  return nearest_coordinate;
}

int main() {
  struct GPS coordinates[N];
  generateCoordinates(coordinates);

  struct GPS current_location = {32.7157, -117.1611}; //San Diego, CA
  struct GPS nearest_coordinate = findNearestCoordinate(current_location, coordinates);

  printf("Your current location: %.4fN %.4fE\n", current_location.latitude, current_location.longitude);
  printf("The nearest coordinate is: %.4fN %.4fE\n", nearest_coordinate.latitude, nearest_coordinate.longitude);
  printf("The distance to the coordinate is: %.2f km\n", distance(current_location, nearest_coordinate));

  return 0;
}