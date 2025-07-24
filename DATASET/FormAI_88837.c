//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: genious
#include <stdio.h>
#include <math.h>

typedef struct {
  double x, y;
} point;

double dist(point a, point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;

  return sqrt(dx*dx + dy*dy);
}

double area(point a, point b, point c) {
  double ab = dist(a, b);
  double bc = dist(b, c);
  double ac = dist(a, c);

  double s = (ab + bc + ac) / 2;
  return sqrt(s * (s - ab) * (s - bc) * (s - ac));
}

int intersect(point a1, point a2, point b1, point b2) {
  double d = (a1.x - a2.x)*(b1.y - b2.y) - (a1.y - a2.y)*(b1.x - b2.x);
  if (d == 0) return 0;

  double t = ((a1.x - b1.x)*(b1.y - b2.y) - (a1.y - b1.y)*(b1.x - b2.x)) / d;
  double u = -((a1.x - a2.x)*(a1.y - b1.y) - (a1.y - a2.y)*(a1.x - b1.x)) / d;

  if (t >= 0 && t <= 1 && u >= 0 && u <= 1) {
    return 1;
  } else {
    return 0;
  }
}

int main() {
  point a = {0, 0};
  point b = {3, 0};
  point c = {3, 4};

  double a1 = area(a, b, c);
  printf("Area of triangle ABC: %lf\n", a1);

  point d = {2, 2};
  point e = {4, 2};

  if (intersect(a, b, d, e)) {
    printf("Line segments AB and DE intersect\n");
  } else {
    printf("Line segments AB and DE do not intersect\n");
  }

  point f = {1, 1};
  point g = {2, 2};
  point h = {3, 3};

  double a2 = area(f, g, h);
  printf("Area of triangle FGH: %lf\n", a2);

  return 0;
}