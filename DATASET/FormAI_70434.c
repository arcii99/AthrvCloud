//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: complex
#include <stdio.h>

struct coordinate {
  double latitude;
  double longitude;
};

double degree_to_radian(double degree) {
  return degree * 3.141592653589 / 180.0;
}

double radian_to_degree(double radian) {
  return radian * 180.0 / 3.141592653589;
}

double calculate_distance(struct coordinate source, struct coordinate destination) {
  double R = 6371; // Earth's radius in km
  double d_latitude = degree_to_radian(destination.latitude - source.latitude);
  double d_longitude = degree_to_radian(destination.longitude - source.longitude);
  double a = sin(d_latitude/2) * sin(d_latitude/2) + cos(degree_to_radian(source.latitude)) * cos(degree_to_radian(destination.latitude)) * sin(d_longitude/2) * sin(d_longitude/2);
  double c = 2 * atan2(sqrt(a), sqrt(1-a));
  return R * c;
}

int main() {
  struct coordinate start = {48.858222, 2.2945};
  struct coordinate end = {51.509865, -0.118092};
  double distance = calculate_distance(start, end);
  printf("The distance between start and end is %.2f km\n", distance);
}