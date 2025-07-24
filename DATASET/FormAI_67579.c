//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>

// Energetic Style Geometric Algorithm Program

int main() {
  printf("Hello there, let's do some calculations!\n");
  
  // Determine the area of a circle given the radius
  float radius = 6.0;
  float pi = 3.14159;
  float area = pi * (radius * radius);
  printf("The area of a circle with radius %.2f is %.2f.\n", radius, area);
  
  // Calculate the slope of a line given two points
  float x1 = 2.0, y1 = 4.0, x2 = 8.0, y2 = 6.0;
  float slope = (y2 - y1) / (x2 - x1);
  printf("The slope of the line that passes through (%.2f, %.2f) and (%.2f, %.2f) is %.2f.\n", x1, y1, x2, y2, slope);
  
  // Find the distance between two points
  float x3 = 5.0, y3 = 9.0, x4 = 2.0, y4 = 3.0;
  float distance = sqrt(pow((x4 - x3), 2) + pow((y4 - y3), 2));
  printf("The distance between (%.2f, %.2f) and (%.2f, %.2f) is %.2f.\n", x3, y3, x4, y4, distance);

  // Calculate the area of a triangle given three sides
  float a = 7.0, b = 8.0, c = 9.0;
  float s = (a + b + c) / 2.0;
  float triArea = sqrt(s*(s-a)*(s-b)*(s-c));
  printf("The area of a triangle with sides %.2f, %.2f, and %.2f is %.2f.\n", a, b, c, triArea);
  
  return 0;
}