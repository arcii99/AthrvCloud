//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: all-encompassing
#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c, s, area;

  printf("Enter the lengths of the three sides of the triangle:\n");
  scanf("%lf %lf %lf", &a, &b, &c);

  // calculate the semi-perimeter
  s = (a + b + c) / 2.0;

  // calculate the area using Heron's formula
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  printf("The area of the triangle is: %lf\n", area);

  return 0;
}