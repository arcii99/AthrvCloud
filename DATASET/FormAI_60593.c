//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: grateful
#include<stdio.h>
int main() {
  printf("Thank you for running this program! \n");
  printf("Now let's calculate the area of a triangle: \n");

  // Input the dimensions of the triangle
  float base, height;
  printf("Enter the base of the triangle: ");
  scanf("%f", &base);
  printf("Enter the height of the triangle: ");
  scanf("%f", &height);

  // Calculate the area of the triangle using the formula: (1/2)*base*height
  float area = (0.5 * base * height);

  // Print out the area of the triangle
  printf("The area of the triangle is: %f \n", area);

  // Thank the user again for running the program
  printf("Thank you for using this program to calculate the area of a triangle in C! \n");

  return 0;
}