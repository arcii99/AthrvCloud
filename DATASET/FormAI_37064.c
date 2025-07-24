//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: excited
#include <stdio.h>

int main() {

  printf("We're about to embark on a journey into the exciting world of geometric algorithms!\n\n");

  // Let's start by finding the area of a rectangle
  float length = 6.5;
  float width = 4.2;
  float area = length * width;
  printf("The area of a rectangle with length %.2f and width %.2f is %.2f.\n\n", length, width, area);

  // Now, let's find the circumference of a circle
  float radius = 3.7;
  float circumference = 2 * 3.14159 * radius;
  printf("The circumference of a circle with radius %.2f is %.2f.\n\n", radius, circumference);

  // Next, let's find the distance between two points in 2D space
  float x1 = 2.0;
  float y1 = 3.0;
  float x2 = 8.0;
  float y2 = 4.5;
  float dx = x2 - x1;
  float dy = y2 - y1;
  float distance = sqrt((dx * dx) + (dy * dy));
  printf("The distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f.\n\n", x1, y1, x2, y2, distance);

  printf("Wow, geometric algorithms are so cool! Let's keep exploring!\n");

  return 0;
}