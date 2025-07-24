//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: sophisticated
#include <stdio.h>

typedef struct {
  int x, y;
} point;

// Compute the cross product (p - a) x (q - a)
int cross_product(point a, point p, point q) {
  return (p.x - a.x) * (q.y - a.y) - (q.x - a.x) * (p.y - a.y);
}

// Check if point p is inside the polygon with n vertices
int inside_polygon(point *vertices, int n, point p) {
  // Check if p is on the boundary of the polygon
  for (int i = 0; i < n; i++) {
    if (vertices[i].x == p.x && vertices[i].y == p.y) {
      return 1; // p is on the boundary
    }
    int j = (i + 1) % n;
    if (cross_product(vertices[i], p, vertices[j]) == 0 &&
        p.x >= fmin(vertices[i].x, vertices[j].x) &&
        p.x <= fmax(vertices[i].x, vertices[j].x) &&
        p.y >= fmin(vertices[i].y, vertices[j].y) &&
        p.y <= fmax(vertices[i].y, vertices[j].y)) {
      return 1; // p is on the boundary
    }
  }

  // Count crossings of a horizontal line from p to the right
  int count = 0;
  point r = {800, p.y};
  for (int i = 0; i < n; i++) {
    int j = (i + 1) % n;
    if (vertices[i].y == vertices[j].y) {
      continue; // Skip horizontal edges
    }
    if (vertices[i].y > p.y != vertices[j].y > p.y &&
        cross_product(vertices[i], vertices[j], p) > 0) {
      count++;
    }
  }

  return count % 2 == 1; // Inside if odd number of crossings
}

int main() {
  point vertices[] = {{50, 50}, {150, 50}, {200, 100}, {150, 150}, {50, 150}, {0, 100}};
  int n = sizeof(vertices)/sizeof(vertices[0]);
  point p = {100, 100};

  if (inside_polygon(vertices, n, p)) {
    printf("Point (%d, %d) is inside the polygon\n", p.x, p.y);
  } else {
    printf("Point (%d, %d) is outside the polygon\n", p.x, p.y);
  }

  return 0;
}