//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: calm
#include <stdio.h>
#include <math.h>

/* This program calculates the area of a triangle using the Heron's formula. */

int main() {
  double a, b, c, s, area;
  
  printf("Enter the length of side a: ");
  scanf("%lf", &a);

  printf("Enter the length of side b: ");
  scanf("%lf", &b);

  printf("Enter the length of side c: ");
  scanf("%lf", &c);

  s = (a + b + c) / 2;  // Calculate the semiperimeter.

  // Use Heron's formula to calculate the area of the triangle.
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  printf("The area of the triangle is %lf\n", area);

  return 0;
}