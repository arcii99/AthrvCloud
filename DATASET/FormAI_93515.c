//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: peaceful
#include <stdio.h>
#include <math.h>

int main() {
  float a, b, c, s, area;

  printf("Enter the length of the first side of the triangle: ");
  scanf("%f", &a);

  printf("Enter the length of the second side of the triangle: ");
  scanf("%f", &b);

  printf("Enter the length of the third side of the triangle: ");
  scanf("%f", &c);

  // Calculating s, which is half of the perimeter
  s = (a + b + c) / 2;

  // Calculating the area using Heron's formula: Area = sqrt(s * (s-a) * (s - b) * (s - c))
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  printf("The area of the triangle is: %.2f\n", area);

  return 0;
}