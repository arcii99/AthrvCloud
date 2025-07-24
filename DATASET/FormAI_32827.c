//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: curious
#include <stdio.h>
#include <math.h>

// Function to calculate area of a triangle using Heron's formula
double herons_formula(double a, double b, double c) {
  double s = (a + b + c) / 2; // half of the perimeter
  double area = sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
  return area;
}

int main() {
  printf("Hello, curious programmer!\n");
  printf("Do you want to calculate the area of a triangle by inputting its vertices?\n");

  int x1, y1, x2, y2, x3, y3;
  printf("Please enter the coordinates of the first vertex (x1, y1):\n");
  scanf("%d %d", &x1, &y1);
  printf("Please enter the coordinates of the second vertex (x2, y2):\n");
  scanf("%d %d", &x2, &y2);
  printf("Please enter the coordinates of the third vertex (x3, y3):\n");
  scanf("%d %d", &x3, &y3);

  double a = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1)); // length of side a
  double b = sqrt((x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1)); // length of side b
  double c = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2)); // length of side c

  double area = herons_formula(a, b, c); // calculate area using Heron's formula
  printf("The area of the triangle is: %lf\n", area);

  printf("Thanks for using this program!\n");
  return 0;
}