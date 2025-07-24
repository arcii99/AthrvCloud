//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: enthusiastic
#include <stdio.h>
#include <math.h>

struct Point {
  double x;
  double y;
};

double distance(struct Point p1, struct Point p2) {
  return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
}

double area(struct Point p1, struct Point p2, struct Point p3) {
  double s = (distance(p1, p2) + distance(p2, p3) + distance(p3, p1)) / 2;
  return sqrt(s * (s - distance(p1, p2)) * (s - distance(p2, p3)) * (s - distance(p3, p1)));
}

double perimeter(struct Point p1, struct Point p2, struct Point p3) {
  return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}

int main() {
  struct Point p1 = {0, 0};
  struct Point p2 = {4, 0};
  struct Point p3 = {4, 4};
  
  printf("The distance between p1 and p2 is: %lf\n", distance(p1, p2));
  printf("The area of the triangle with points p1, p2 and p3 is: %lf\n", area(p1, p2, p3));
  printf("The perimeter of the triangle with points p1, p2 and p3 is: %lf\n", perimeter(p1, p2, p3));
  
  return 0;
}