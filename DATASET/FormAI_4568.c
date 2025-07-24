//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

// Calculate the area of a triangle given the length of its three sides
double calculateTriangleArea(double side1, double side2, double side3) {
  double s = (side1 + side2 + side3) / 2; // Half of perimeter
  double area = sqrt(s * (s - side1) * (s - side2) * (s - side3)); // Heron's formula
  return area;
}

// Check if a point is inside a circle given the coordinates of the point and the center of the circle
int isPointInsideCircle(double pointX, double pointY, double centerX, double centerY, double radius) {
  double distance = sqrt(pow(pointX - centerX, 2) + pow(pointY - centerY, 2)); // Distance formula
  if (distance < radius) {
    return 1; // Point is inside circle
  } else {
    return 0; // Point is outside circle
  }
}

// Calculate the distance between two points given their coordinates
double calculateDistanceBetweenPoints(double x1, double y1, double x2, double y2) {
  double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // Distance formula
  return distance;
}

int main() {
  // Calculate the area of a triangle with sides of length 3, 4, and 5
  double triangleArea = calculateTriangleArea(3, 4, 5);
  printf("The area of the triangle is %lf\n", triangleArea);

  // Check if the point (2, 2) is inside the circle with center (0, 0) and a radius of 3
  int isInsideCircle = isPointInsideCircle(2, 2, 0, 0, 3);
  if (isInsideCircle) {
    printf("The point is inside the circle\n");
  } else {
    printf("The point is outside the circle\n");
  }

  // Calculate the distance between the points (0, 0) and (3, 4)
  double distance = calculateDistanceBetweenPoints(0, 0, 3, 4);
  printf("The distance between the points is %lf\n", distance);

  return 0;
}