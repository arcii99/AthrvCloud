//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
  printf("Let's find the intersection point of two lines in 2D space! \n");

  // First line parameters
  int x1 = 2, y1 = 3, x2 = 5, y2 = 1;
  float m1 = (float)(y2 - y1)/(x2 - x1);
  float b1 = y1 - (m1*x1);

  // Second line parameters
  int x3 = -1, y3 = 2, x4 = 4, y4 = 4;
  float m2 = (float)(y4 - y3)/(x4 - x3);
  float b2 = y3 - (m2*x3);

  // Calculate intersection point coordinates
  float x_intersect = (b2 - b1)/(m1 - m2);
  float y_intersect = m1 * x_intersect + b1;

  printf("The intersection point of the lines is: (%.2f, %.2f) \n", x_intersect, y_intersect);

  // Distance between intersection point and origin
  float distance = sqrt(pow(x_intersect, 2) + pow(y_intersect, 2));

  printf("The distance between the intersection point and the origin is: %.2f \n", distance);

  return 0;
}