//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* This program will find the area of a circle inscribed in a square.
   The circle is inscribed in the square so that the circle passes through
   each vertice of the square. */

int main() {
  double square_area, circle_radius, circle_diameter, circle_area;

  printf("Enter the area of the square: ");
  scanf("%lf", &square_area);

  circle_diameter = sqrt(2 * square_area);
  circle_radius = circle_diameter / 2;
  circle_area = M_PI * pow(circle_radius, 2);

  printf("\nCircle Diameter: %.2lf", circle_diameter);
  printf("\nCircle Radius: %.2lf", circle_radius);
  printf("\nCircle Area: %.2lf\n", circle_area);

  return 0;
}