//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: sophisticated
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
  int angle, distance, x, y;

  printf("Enter the angle (in degrees): ");
  scanf("%d", &angle);

  printf("Enter the distance (in meters): ");
  scanf("%d", &distance);

  // Convert angle to radians
  double radAngle = angle * PI / 180.0;

  // Calculate the x and y distance
  x = distance * cos(radAngle);
  y = distance * sin(radAngle);

  printf("The vehicle moved %d meters to the %s and %d meters to the %s\n", 
         abs(x), x >= 0 ? "right" : "left", 
         abs(y), y >= 0 ? "front" : "back");

  return 0;
}