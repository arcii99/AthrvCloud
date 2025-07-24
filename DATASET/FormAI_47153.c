//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Linus Torvalds
#include <stdio.h>
#include <math.h>

// Structure to represent a point (x, y)
typedef struct
{
  double x;
  double y;
} Point;

// A function to find the distance between two points
double distance(Point p1, Point p2)
{
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// A function to find the area of a triangle given three points
double triangle_area(Point p1, Point p2, Point p3)
{
  double a = distance(p1, p2);
  double b = distance(p2, p3);
  double c = distance(p3, p1);
  double s = (a + b + c) / 2;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

// A function to determine if three points are collinear or not
int collinear(Point p1, Point p2, Point p3)
{
  return ((p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y)) == 0;
}

// A function to find the centroid of a triangle given three points
Point centroid(Point p1, Point p2, Point p3)
{
  Point c;
  c.x = (p1.x + p2.x + p3.x) / 3;
  c.y = (p1.y + p2.y + p3.y) / 3;
  return c;
}

int main()
{
  // Define three points
  Point p1 = {0, 0};
  Point p2 = {10, 0};
  Point p3 = {10, 10};

  // Calculate the area of the triangle
  double area = triangle_area(p1, p2, p3);
  printf("Area of the triangle = %f\n", area);

  // Check if the points are collinear
  if (collinear(p1, p2, p3))
  {
    printf("Points are collinear\n");
  }
  else
  {
    printf("Points are not collinear\n");
  }

  // Calculate the centroid of the triangle
  Point c = centroid(p1, p2, p3);
  printf("Centroid of the triangle = (%f, %f)\n", c.x, c.y);

  return 0;
}