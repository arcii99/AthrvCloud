//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: peaceful
#include <stdio.h>

int main() {
  // Declare necessary variables
  int latitude, longitude;
  int speed, acceleration, time, distance;
  int destinationLat, destinationLong;

  // Get user input for current location
  printf("Enter your current latitude: ");
  scanf("%d", &latitude);
  printf("Enter your current longitude: ");
  scanf("%d", &longitude);

  // Get user input for destination location
  printf("Enter the destination latitude: ");
  scanf("%d", &destinationLat);
  printf("Enter the destination longitude: ");
  scanf("%d", &destinationLong);

  // Calculate initial distance
  distance = (destinationLat - latitude) + (destinationLong - longitude);

  // Get user input for current speed and acceleration
  printf("Enter your current speed (in km/hr): ");
  scanf("%d", &speed);
  printf("Enter your current acceleration (in m/s^2): ");
  scanf("%d", &acceleration);

  // Get user input for time elapsed
  printf("Enter the time elapsed (in minutes): ");
  scanf("%d", &time);

  // Calculate new distance and current location
  distance = distance - (speed * (time / 60)) - (0.5 * acceleration * (time / 60) * (time / 60));
  latitude = latitude + (distance / 2);
  longitude = longitude + (distance / 2);

  // Output current location
  printf("Your current latitude is: %d\n", latitude);
  printf("Your current longitude is: %d\n", longitude);

  return 0;
}