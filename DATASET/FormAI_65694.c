//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: portable
#include <stdio.h>

struct location {
  float latitude;
  float longitude;
};

struct location getCurrentLocation() {
  // In a real-world scenario, this function would use actual GPS coordinates
  struct location current = {37.7749, -122.4194}; // San Francisco
  return current;
}

void navigateTo(struct location destination) {
  struct location current = getCurrentLocation();
  
  // Calculate distance between current and destination coordinates
  float latDistance = destination.latitude - current.latitude;
  float longDistance = destination.longitude - current.longitude;
  
  // Print out estimated travel time
  float distance = sqrt((latDistance * latDistance) + (longDistance * longDistance));
  float speed = 60; // mph
  float travelTime = distance / speed;
  printf("Estimated travel time: %.2f hours\n", travelTime);
  
  // Print out navigation instructions
  if (latDistance > 0) {
    printf("Go North for %.2f miles.\n", latDistance);
  } else if (latDistance < 0) {
    printf("Go South for %.2f miles.\n", latDistance * -1);
  }
  
  if (longDistance > 0) {
    printf("Go East for %.2f miles.\n", longDistance);
  } else if (longDistance < 0) {
    printf("Go West for %.2f miles.\n", longDistance * -1);
  }
}

int main() {
  printf("Welcome to GPS Navigation Simulation!\n");
  struct location destination = {37.3382, -121.8863}; // San Jose
  navigateTo(destination);
  return 0;
}