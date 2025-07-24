//FormAI DATASET v1.0 Category: Math exercise ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main() {
  int a, b, c;
  double area, s;

  printf("Enter values for a, b, and c: ");
  scanf("%d %d %d", &a, &b, &c);

  // calculate the perimeter
  int perimeter = a + b + c;

  // calculate the semi-perimeter
  s = (double)perimeter / 2;

  // calculate the area using Heron's formula
  area = sqrt(s * (s-a) * (s-b) * (s-c));

  printf("\nPerimeter of triangle = %d units", perimeter);
  printf("\nArea of triangle = %.2lf sq units", area);

  // calculate the volume of sphere using radius = a
  double radius = (double)a;
  double volume = (4.0/3) * M_PI * pow(radius, 3.0);

  printf("\n\nVolume of sphere = %.2lf cubic units", volume);

  // calculate the distance between two points (a,b) and (c,d)
  int d, e;
  printf("\n\nEnter values for d and e: ");
  scanf("%d %d", &d, &e);

  double distance = sqrt(pow(c - a, 2.0) + pow(d - b, 2.0));
  printf("\nDistance between points (%d,%d) and (%d,%d) = %.2lf", a, b, c, d, distance);

  return 0;
}