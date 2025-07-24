//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

struct Location {
  double latitude;
  double longitude;
};

double calculateDistance(struct Location location1, struct Location location2) {
  double lat1 = location1.latitude;
  double lon1 = location1.longitude;
  double lat2 = location2.latitude;
  double lon2 = location2.longitude;

  double dLat = (lat2 - lat1) * PI / 180.0;
  double dLon = (lon2 - lon1) * PI / 180.0;

  lat1 = lat1 * PI / 180.0;
  lat2 = lat2 * PI / 180.0;

  double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
  double c = 2 * atan2(sqrt(a), sqrt(1 - a));
  double d = 6371 * c;

  return d;
}

int main() {
  struct Location home = { 37.7749, -122.4194 };
  struct Location work = { 37.3875, -122.0575 };

  double distance = calculateDistance(home, work);

  printf("The distance between home and work is %.2f km", distance);

  return 0;
}