//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main() {
  // GPS Navigation Simulation Program
  
  // Initializing variables
  float current_lat = 41.8781; // Starting latitude
  float current_long = -87.6298; // Starting longitude
  float next_lat, next_long, distance;
  char direction[10];
  
  // Starting message
  printf("Welcome to our GPS Navigation Simulation Program!\n");
  
  // Prompting user for the next location
  printf("Please enter the next location's latitude: ");
  scanf("%f", &next_lat);
  printf("Please enter the next location's longitude: ");
  scanf("%f", &next_long);
  
  // Calculating the distance and direction
  distance = sqrt(pow((next_lat - current_lat), 2) + pow((next_long - current_long), 2));
  if (next_long > current_long) {
    strcpy(direction, "East");
  } else {
    strcpy(direction, "West");
  }
  
  // Outputting the results
  printf("The distance to the next location is %.2f miles.\n", distance);
  printf("The direction to the next location is %s.\n", direction);
  
  // Ending message
  printf("Thank you for using our GPS Navigation Simulation Program! Have a great day!");
  
  return 0;
}