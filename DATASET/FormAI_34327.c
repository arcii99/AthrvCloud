//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: synchronous
#include <stdio.h>

struct Point {
  double x;
  double y;
};

int main() {
  int n;
  printf("Enter the number of points: ");
  scanf("%d", &n);

  struct Point points[n];
  printf("Enter the coordinates of each point:\n");
  for (int i = 0; i < n; i++) {
    printf("Point %d: ", i+1);
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  double area = 0;
  for (int i = 0; i < n; i++) {
    if (i == n-1) {
      area += (points[i].x * points[0].y) - (points[i].y * points[0].x);
    } else {
      area += (points[i].x * points[i+1].y) - (points[i].y * points[i+1].x);
    }
  }
  area /= 2;
  area = area < 0 ? -area : area;

  printf("The area of the polygon is: %lf\n", area);
  return 0;
}