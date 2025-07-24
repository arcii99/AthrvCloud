//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: cheerful
#include <stdio.h>

// Function to find the area of a triangle
double findArea(double base, double height) {
  return 0.5 * base * height;
}

int main() {
  double base, height;
  
  printf("Welcome to the Triangle Area Calculator!\n");
  printf("Please enter the length of the base: ");
  scanf("%lf", &base);
  printf("Please enter the height: ");
  scanf("%lf", &height);

  double area = findArea(base, height);
  printf("The area of the triangle is: %lf\n", area);

  printf("Thanks for using the Triangle Area Calculator!\n");

  return 0;
}