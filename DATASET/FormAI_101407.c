//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: single-threaded
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

/* This program calculates the area and circumference of a circle
   specified by its radius using geometric algorithms
   and prints the results to the console */

int main() {
  
  // Declare variables
  float radius, area, circumference;
  
  // Prompt user for input
  printf("Enter the radius of the circle: ");
  scanf("%f", &radius);
  
  // Calculate area and circumference
  area = PI * pow(radius, 2);
  circumference = 2 * PI * radius;
  
  // Print results to console
  printf("The area of the circle is: %.2f\n", area);
  printf("The circumference of the circle is: %.2f\n", circumference);
  
  return 0;
}