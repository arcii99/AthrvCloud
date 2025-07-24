//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: inquisitive
#include <stdio.h>
#include <math.h>

int main() {
  int x1, y1, x2, y2, x3, y3;
  float a, b, c, s, area;

  printf("Enter the first coordinate (x,y): ");
  scanf("%d%d", &x1, &y1);

  printf("Enter the second coordinate (x,y): ");
  scanf("%d%d", &x2, &y2);

  printf("Enter the third coordinate (x,y): ");
  scanf("%d%d", &x3, &y3);

  a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
  c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));

  printf("The length of side a is: %0.2f\n", a);
  printf("The length of side b is: %0.2f\n", b);
  printf("The length of side c is: %0.2f\n", c);

  // calculate the perimeter and semi-perimeter of the triangle
  float perimeter = a + b + c;
  s = perimeter / 2;

  // calculate the area of the triangle using Heron's formula
  area = sqrt(s * (s - a) * (s - b) * (s - c));

  printf("The perimeter of the triangle is: %0.2f\n", perimeter);
  printf("The area of the triangle is: %0.2f\n", area);

  return 0;
}