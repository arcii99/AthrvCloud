//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: imaginative
#include <stdio.h>
#include <math.h>

// Define a point on the plane
typedef struct {
  double x;
  double y;
} Point;

// Define a line segment
typedef struct {
  Point start;
  Point end;
} Line;

// Define a rectangle
typedef struct {
  Point bottomLeft;
  Point topRight;
} Rectangle;

// Calculate the length of a line
double length(Line l) {
  double dx = l.end.x - l.start.x;
  double dy = l.end.y - l.start.y;
  return sqrt(dx*dx + dy*dy);
}

// Calculate the midpoint of a line
Point midpoint(Line l) {
  Point mid;
  mid.x = (l.start.x + l.end.x) / 2.0;
  mid.y = (l.start.y + l.end.y) / 2.0;
  return mid;
}

// Check if a point is inside a rectangle
int pointInsideRect(Point p, Rectangle r) {
  if (p.x < r.bottomLeft.x || p.x > r.topRight.x) {
    return 0;
  }
  if (p.y < r.bottomLeft.y || p.y > r.topRight.y) {
    return 0;
  }
  return 1;
}

// Find the intersection point of two lines (assuming they are not parallel)
Point intersect(Line l1, Line l2) {
  double x1 = l1.start.x;
  double y1 = l1.start.y;
  double x2 = l1.end.x;
  double y2 = l1.end.y;
  double x3 = l2.start.x;
  double y3 = l2.start.y;
  double x4 = l2.end.x;
  double y4 = l2.end.y;

  double denom = (x1-x2)*(y3-y4) - (y1-y2)*(x3-x4);
  double px = ((x1*y2-y1*x2)*(x3-x4) - (x1-x2)*(x3*y4-y3*x4)) / denom;
  double py = ((x1*y2-y1*x2)*(y3-y4) - (y1-y2)*(x3*y4-y3*x4)) / denom;

  Point p;
  p.x = px;
  p.y = py;
  return p;
}

int main() {
  Line l1, l2;
  l1.start.x = 1.0;
  l1.start.y = 1.0;
  l1.end.x = 4.0;
  l1.end.y = 5.0;
  l2.start.x = 2.0;
  l2.start.y = 4.0;
  l2.end.x = 5.0;
  l2.end.y = 1.0;

  Point p = intersect(l1, l2);
  printf("Intersection point: (%.2f, %.2f)\n", p.x, p.y);

  double len = length(l1);
  printf("Length of line l1: %.2f\n", len);

  Point mid = midpoint(l2);
  printf("Midpoint of line l2: (%.2f, %.2f)\n", mid.x, mid.y);

  Rectangle r;
  r.bottomLeft.x = 0;
  r.bottomLeft.y = 0;
  r.topRight.x = 5;
  r.topRight.y = 5;
  int inside = pointInsideRect(p, r);
  printf("Is intersection point inside rectangle? %s\n", (inside ? "Yes" : "No"));

  return 0;
}