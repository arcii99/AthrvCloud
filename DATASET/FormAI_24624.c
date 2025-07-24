//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: immersive
#include <stdio.h>

int main() {

  //initialize variables
  double current_latitude;
  double current_longitude;
  double destination_latitude;
  double destination_longitude;

  //get user input for current location and destination
  printf("Enter your current location (latitude and longitude): ");
  scanf("%lf %lf", &current_latitude, &current_longitude);
  printf("Enter your destination (latitude and longitude): ");
  scanf("%lf %lf", &destination_latitude, &destination_longitude);

  //calculate distance to destination
  double lat_distance = destination_latitude - current_latitude;
  double long_distance = destination_longitude - current_longitude;
  double distance = sqrt(pow(lat_distance, 2) + pow(long_distance, 2));

  //display route and distance
  printf("Route: Start at (%.2lf, %.2lf)\n", current_latitude, current_longitude);
  printf("      End at (%.2lf, %.2lf)\n", destination_latitude, destination_longitude);
  printf("Distance to destination: %.2lf km.\n", distance);

  //simulate travel
  for(int i = 0; i < distance; i++) {
    printf("You have traveled %d km. You have %d km left.\n", i, (int)distance-i);
    sleep(1); //pause for 1 second before next iteration
  }

  //arrive at destination
  printf("You have arrived at your destination. Enjoy your visit!\n");

  return 0;
}