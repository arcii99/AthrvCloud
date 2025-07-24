//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Point {
  float latitude;
  float longitude;
};

float calculate_distance(struct Point current_location, struct Point destination);

int main() {
  // simulate GPS signal by generating random points
  srand(time(NULL));
  struct Point current_location = {rand() % 90, rand() % 180};
  
  // set destination point
  struct Point destination = {45, 90};
  
  // check if already at destination
  if (current_location.latitude == destination.latitude && current_location.longitude == destination.longitude) {
    printf("You have already arrived at your destination.\n");
    return 0;
  }
  
  // calculate distance and estimated time of arrival
  float distance = calculate_distance(current_location, destination);
  int speed = 50; // assume speed of 50km/hr
  float time_hours = distance / speed;
  int time_minutes = (int)(time_hours * 60);
  
  // output directions to destination
  printf("Starting from (%.2f, %.2f)\n", current_location.latitude, current_location.longitude);
  printf("Head southeast on Main Street\n");
  printf("Turn left onto 1st Avenue\n");
  printf("Turn right onto 2nd Street\n");
  printf("Turn left onto 3rd Avenue\n");
  printf("Turn right onto 4th Street\n");
  printf("Turn left onto 5th Avenue\n");
  printf("Turn right onto 6th Street\n");
  printf("Turn left onto 7th Avenue\n");
  printf("Turn right onto 8th Street\n");
  printf("Continue straight onto Highway 10\n");
  printf("Turn left onto Highway 5\n");
  printf("Turn right onto County Road 22\n");
  printf("Turn left onto County Road 23\n");
  printf("Continue straight onto County Road 24\n");
  printf("Turn right onto County Road 25\n");
  printf("Destination will be on the right.\n");
  printf("Total distance: %.2f km\n", distance);
  printf("Estimated time of arrival: %d minutes\n", time_minutes);
  
  return 0;
}

float calculate_distance(struct Point current_location, struct Point destination) {
  // calculate distance between two points using Haversine formula
  float lat1 = current_location.latitude;
  float lon1 = current_location.longitude;
  float lat2 = destination.latitude;
  float lon2 = destination.longitude;
  float R = 6371; // radius of the Earth in km
  float dLat = (lat2 - lat1) * 3.14159 / 180;
  float dLon = (lon2 - lon1) * 3.14159 / 180;
  float a = sin(dLat/2) * sin(dLat/2) + cos(lat1 * 3.14159 / 180) * cos(lat2 * 3.14159 / 180) * sin(dLon/2) * sin(dLon/2);
  float c = 2 * atan2(sqrt(a), sqrt(1-a));
  float d = R * c;
  return d;
}