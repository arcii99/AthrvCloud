//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: calm
#include <stdio.h>

int main() {
  float x1, x2, y1, y2, distance;
  
  // Taking coordinates as input
  printf("Enter the coordinates of your current location x1, y1: \n");
  scanf("%f %f", &x1, &y1);
  
  printf("Enter the coordinates of your destination x2, y2: \n");
  scanf("%f %f", &x2, &y2);
  
  // Calculating the distance between the two coordinates using the distance formula
  distance = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
  
  // Printing the distance to the user
  printf("The distance from your current location to your destination is: %f km\n", distance);
  
  // Generating directions for the user based on the coordinates and distance
  if (x1 > x2) {
    printf("Travel west for %f km.\n", x1 - x2);
  } else {
    printf("Travel east for %f km.\n", x2 - x1);
  }
  
  if (y1 > y2) {
    printf("Travel south for %f km.\n", y1 - y2);
  } else {
    printf("Travel north for %f km.\n", y2 - y1);
  }
  
  return 0;
}