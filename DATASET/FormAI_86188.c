//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Point {
  float x, y;
};

// Compute the distance between two points
float distance(struct Point p1, struct Point p2) {
  float dx = p2.x - p1.x;
  float dy = p2.y - p1.y;
  return sqrt(dx*dx + dy*dy);
}

// Compute the area of a triangle given its vertices
float area(struct Point p1, struct Point p2, struct Point p3) {
  float a = distance(p1, p2);
  float b = distance(p2, p3);
  float c = distance(p3, p1);
  float s = (a + b + c) / 2.0;
  return sqrt(s * (s-a) * (s-b) * (s-c));
}

// Find the convex hull of a set of points using the gift wrapping algorithm
int cmp(const void *p1, const void *p2) {
  struct Point *a = (struct Point *)p1;
  struct Point *b = (struct Point *)p2;
  if(a->x != b->x)
    return (a->x < b->x) ? -1 : 1;
  else
    return (a->y < b->y) ? -1 : 1;
}

int ccw(struct Point p1, struct Point p2, struct Point p3) {
  float area2 = (p2.x-p1.x)*(p3.y-p1.y) - (p2.y-p1.y)*(p3.x-p1.x);
  if (area2 < 0) return -1; // clockwise
  else if (area2 > 0) return 1; // counter-clockwise
  else return 0; // collinear
}

void convexHull(struct Point *points, int n) {
  // Find the leftmost point and store its index
  int l = 0;
  for (int i = 1; i < n; i++) {
    if (points[i].x < points[l].x) l = i;
  }
 
  // Add the leftmost point to the hull and initialize the hull with this point
  int p = l, q;
  do {
    q = (p + 1) % n;
    for (int i = 0; i < n; i++) {
      // Find the point that turns the smallest angle
      if (ccw(points[p], points[i], points[q]) == -1) q = i;
    }
    // Add the next point to the hull
    printf("(%f, %f)\n", points[q].x, points[q].y);
    p = q;
  } while (p != l);
}

int main() {
  // Define some arbitrary points
  struct Point points[] = {{0,0}, {1,0}, {1,1}, {0,1}, {0.5, 0.5}, {0.25, 0.25}, {0.75, 0.25}, {0.75, 0.75}, {0.25, 0.75}};
  int n = sizeof(points)/sizeof(points[0]);

  // Sort the points based on their x-coordinate (and then by their y-coordinate if x's match)
  qsort(points, n, sizeof(points[0]), cmp);

  // Compute the convex hull of the points and print out the vertices
  convexHull(points, n);

  // Compute the area of the convex hull
  float hull_area = 0;
  for (int i = 0; i < n; i++) {
    hull_area += area(points[i], points[(i+1)%n], points[(i+2)%n]);
  }
  printf("The area of the convex hull is %f\n", hull_area);

  return 0;
}