//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  // Welcome message for the GPS Navigation Simulation Program
  printf("Welcome to the Wacky GPS Navigation Simulation Program! \n");

  // Let's get the starting point from the user
  char start_point[20];
  printf("What is your starting point? \n");
  scanf("%s", start_point);

  // Let's get the destination from the user
  char destination[20];
  printf("Where would you like to go? \n");
  scanf("%s", destination);

  // Let's calculate the distance between the two points
  int distance = strlen(start_point) + strlen(destination);

  // Let's calculate the estimated time of arrival by dividing the distance by 10
  float eta = distance / 10.0;

  // Let's print out the directions for the user
  printf("Directions: \n");
  printf("1. Turn left out of the parking lot. \n");
  printf("2. Drive straight for %d miles. \n", distance);
  printf("3. Turn right onto Main Street. \n");
  printf("4. Continue for 2 miles. \n");
  printf("5. Turn left onto %s. \n", destination);
  printf("6. Your destination, %s, will be on the right. \n", destination);

  // Let's print out the estimated time of arrival for the user
  printf("Your estimated time of arrival is %0.1f hours. \n", eta);

  // Closing message for the GPS Navigation Simulation Program
  printf("Thank you for using the Wacky GPS Navigation Simulation Program! \n");

  return 0;
}