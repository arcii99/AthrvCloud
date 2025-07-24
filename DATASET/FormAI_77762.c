//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complete
#include <stdio.h>
#include <math.h>

/* This program calculates the distance between two points in a 2D coordinate system
   using the Pythagorean Theorem. It also calculates the angle between the two points*/

int main() {

  float x1, y1, x2, y2, distance, angle;

  // Get the coordinates of the first point
  printf("Enter the coordinate of the first point (x1, y1): ");
  scanf("%f %f", &x1, &y1);

  // Get the coordinates of the second point
  printf("Enter the coordinate of the second point (x2, y2): ");
  scanf("%f %f", &x2, &y2);

  // Calculate the distance between the two points using the Pythagorean Theorem
  distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

  // Calculate the angle between the two points
  angle = atan2((y2 - y1), (x2 - x1)) * 180 / M_PI;

  // Print the distance and angle between the two points
  printf("The distance between (%.2f,%.2f) and (%.2f,%.2f) is %.2f units.\n", x1, y1, x2, y2, distance);
  printf("The angle between (%.2f,%.2f) and (%.2f,%.2f) is %.2f degrees.\n", x1, y1, x2, y2, angle);

  return 0;
}