//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Cryptic
#include <stdio.h>
#include <math.h>
#define pi 3.14159265359

int main() {
  float x, y, angle, distance;
  printf("Enter the x and y coordinate of the point: ");
  scanf("%f%f", &x, &y);
  angle = atan2(y, x) * 180 / pi;
  distance = sqrt(pow(x, 2) + pow(y, 2));
  printf("The polar coordinates of the point are: (%f, %f)\n", angle, distance);
  return 0;
}