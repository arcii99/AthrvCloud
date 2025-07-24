//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: realistic
#include <stdio.h>
#include <math.h>

struct point {
  double x;
  double y;
};

double distance(struct point a, struct point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  struct point p1, p2, p3;
  double side1, side2, side3, perimeter, area;

  printf("Enter coordinates of point 1: ");
  scanf("%lf %lf", &p1.x, &p1.y);
  printf("Enter coordinates of point 2: ");
  scanf("%lf %lf", &p2.x, &p2.y);
  printf("Enter coordinates of point 3: ");
  scanf("%lf %lf", &p3.x, &p3.y);

  side1 = distance(p1, p2);
  side2 = distance(p2, p3);
  side3 = distance(p3, p1);

  perimeter = side1 + side2 + side3;

  printf("Perimeter: %.2f\n", perimeter);

  double s = perimeter/2;
  area = sqrt(s*(s-side1)*(s-side2)*(s-side3));

  printf("Area: %.2f\n", area);

  return 0;
}