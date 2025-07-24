//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

/* This program calculates the area and perimeter of a circle based on the user input radius */

int main() {
  int radius;
  double area, perimeter;
  
  printf("Please enter the radius of the circle: ");
  scanf("%d", &radius);

  /* Calculate the area and perimeter of the circle */
  area = M_PI * pow(radius, 2);
  perimeter = 2 * M_PI * radius;

  printf("The area of the circle is: %f\n", area);
  printf("The perimeter of the circle is: %f\n", perimeter);

  return 0;
}