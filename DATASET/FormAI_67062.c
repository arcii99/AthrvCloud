//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include<stdio.h>

/*This program takes the coordinates of three points in a 2D plane and computes
the area of the triangle formed by the points using the Shoelace formula*/

int main() {

  //declaring variables for coordinates
  float x1, y1, x2, y2, x3, y3;

  //taking user input for coordinates
  printf("Enter the coordinates of point 1: ");
  scanf("%f %f", &x1, &y1);
  printf("Enter the coordinates of point 2: ");
  scanf("%f %f", &x2, &y2);
  printf("Enter the coordinates of point 3: ");
  scanf("%f %f", &x3, &y3);

  //computing area of triangle using Shoelace formula
  float area = (0.5)*((x1*y2 + x2*y3 + x3*y1) - (x2*y1 + x3*y2 + x1*y3));

  //displaying calculated area
  printf("The area of the triangle formed by the given points is: %f", area);

  return 0;

}