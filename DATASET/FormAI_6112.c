//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <math.h>

int main() {
  // Welcome message
  printf("Welcome to the Geometric Algorithms program!\n");
  printf("------------------------------------------\n\n");

  // User prompt
  printf("Please enter the radius of a circle: ");
  double radius;
  scanf("%lf", &radius);

  // Calculate the area and circumference of the circle
  double area = M_PI * pow(radius, 2);
  double circumference = 2 * M_PI * radius;

  // Output the results
  printf("\nResults:\n");
  printf("The circle's radius is: %.2lf\n", radius);
  printf("The circle's area is: %.2lf\n", area);
  printf("The circle's circumference is: %.2lf\n", circumference);

  // User prompt
  printf("\nPlease enter the height and base of a right triangle: ");
  double height, base;
  scanf("%lf %lf", &height, &base);

  // Calculate the hypotenuse and perimeter of the triangle
  double hypotenuse = sqrt(pow(height, 2) + pow(base, 2));
  double perimeter = height + base + hypotenuse;

  // Output the results
  printf("\nResults:\n");
  printf("The right triangle's height is: %.2lf\n", height);
  printf("The right triangle's base is: %.2lf\n", base);
  printf("The right triangle's hypotenuse is: %.2lf\n", hypotenuse);
  printf("The right triangle's perimeter is: %.2lf\n", perimeter);

  return 0;
}