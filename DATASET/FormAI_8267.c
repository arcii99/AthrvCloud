//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point {
  double x, y;
} Point;

typedef struct Line {
  Point p1, p2;
} Line;

// A function to calculate the distance between two points
double distance(Point p1, Point p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// A function to calculate the slope of a line
double slope(Line l) {
  return (l.p2.y - l.p1.y) / (l.p2.x - l.p1.x);
}

// A function to calculate the midpoint of a line
Point midpoint(Line l) {
  Point p;
  p.x = (l.p1.x + l.p2.x) / 2;
  p.y = (l.p1.y + l.p2.y) / 2;
  return p;
}

int main() {
  Point p1, p2, pm;
  Line l;
  double dist, slp;

  // Prompt the user to enter the coordinates of two points
  printf("Enter the x coordinate of Point 1: ");
  scanf("%lf", &p1.x);

  printf("Enter the y coordinate of Point 1: ");
  scanf("%lf", &p1.y);

  printf("Enter the x coordinate of Point 2: ");
  scanf("%lf", &p2.x);

  printf("Enter the y coordinate of Point 2: ");
  scanf("%lf", &p2.y);

  // Create a line from the two points
  l.p1 = p1;
  l.p2 = p2;

  // Calculate the distance between the two points
  dist = distance(p1, p2);

  // Calculate the slope of the line
  slp = slope(l);

  // Calculate the midpoint of the line
  pm = midpoint(l);

  // Print the results
  printf("Distance between Point 1 (%.2lf, %.2lf) and Point 2 (%.2lf, %.2lf) is %.2lf\n", p1.x, p1.y, p2.x, p2.y, dist);
  printf("Slope of the line is %.2lf\n", slp);
  printf("Midpoint of the line is (%.2lf, %.2lf)\n", pm.x, pm.y);

  return 0;
}