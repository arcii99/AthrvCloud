//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <math.h>

int main()
{
  printf("\n**** WELCOME TO GEOMETRIC ALGORITHMS PROGRAM ****\n");

  // Square Root of a Number //
  float sqrtnum, res1;
  printf("\nEnter a number to find the Square Root: ");
  scanf("%f", &sqrtnum);
  res1 = sqrt(sqrtnum);
  printf("The Square Root of %.2f is %.2f\n", sqrtnum, res1);

  // Triangle Area Calculation //
  float base, height, triarea;
  printf("\nEnter the Base of the Triangle: ");
  scanf("%f", &base);
  printf("Enter the Height of the Triangle: ");
  scanf("%f", &height);
  triarea = 0.5 * base * height;
  printf("The area of the Triangle is %.2f square units\n", triarea);

  // Distance between Two Points //
  float x1, y1, x2, y2, distance;
  printf("\nEnter the x-coordinate of Point 1: ");
  scanf("%f", &x1);
  printf("Enter the y-coordinate of Point 1: ");
  scanf("%f", &y1);
  printf("Enter the x-coordinate of Point 2: ");
  scanf("%f", &x2);
  printf("Enter the y-coordinate of Point 2: ");
  scanf("%f", &y2);
  distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
  printf("The Distance between (%.1f,%.1f) and (%.1f,%.1f) is %.2f units\n", x1, y1, x2, y2, distance);

  // Circle Area Calculation //
  float radius, circarea;
  printf("\nEnter the Radius of the Circle: ");
  scanf("%f", &radius);
  circarea = 3.14 * radius * radius;
  printf("The area of the Circle is %.2f square units\n", circarea);

  printf("\n**** THANK YOU FOR USING GEOMETRIC ALGORITHMS PROGRAM ****\n\n");

  return 0;
}