//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Claude Shannon
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle given three points
float calculate_triangle_area(float x1, float y1, float x2, float y2, float x3, float y3) {
  float a = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  float b = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
  float c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
  float s = (a + b + c) / 2;

  return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main() {
  // Define three points for the triangle
  float x1 = 0, y1 = 0;
  float x2 = 3, y2 = 3;
  float x3 = 6, y3 = 0;

  // Calculate and display the area of the triangle
  float area = calculate_triangle_area(x1, y1, x2, y2, x3, y3);
  printf("The area of the triangle is: %f\n", area);

  return 0;
}