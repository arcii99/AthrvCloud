//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: optimized
#include <stdio.h>
#include <math.h>

struct point {
  double x;
  double y;
};

double distance(struct point a, struct point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt((dx * dx) + (dy * dy));
}

int main() {
  struct point p1 = {3.0, 7.0};
  struct point p2 = {9.0, 12.0};

  double d = distance(p1, p2);
  printf("Distance between (%g, %g) and (%g, %g) is %g\n", p1.x, p1.y, p2.x, p2.y, d);

  return 0;
}