//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>

// A program to find the area of a triangle using the Heron's formula
int main() {

  // Declare variables for the sides of the triangle
  double a, b, c;

  // Prompt the user to enter the sides of the triangle
  printf("Enter the sides of the triangle: ");
  scanf("%lf %lf %lf", &a, &b, &c);

  // Calculate the semi-perimeter of the triangle
  double s = (a + b + c) / 2;

  // Calculate the area of the triangle using Heron's formula
  double area = sqrt(s * (s - a) * (s - b) * (s - c));

  // Print the area of the triangle
  printf("The area of the triangle is %.2lf\n", area);

  // Declare variables for the points of a circle and its radius
  double x, y, r;

  // Prompt the user to enter the points and the radius
  printf("Enter the coordinates of the center of the circle: ");
  scanf("%lf %lf", &x, &y);
  printf("Enter the radius of the circle: ");
  scanf("%lf", &r);

  // Calculate the diameter of the circle
  double diameter = 2 * r;

  // Calculate the circumference of the circle
  double circumference = 2 * 3.14159 * r;

  // Calculate the area of the circle
  double circleArea = 3.14159 * r * r;

  // Print the results
  printf("The diameter of the circle is %.2lf\n", diameter);
  printf("The circumference of the circle is %.2lf\n", circumference);
  printf("The area of the circle is %.2lf\n", circleArea);

  return 0;
}