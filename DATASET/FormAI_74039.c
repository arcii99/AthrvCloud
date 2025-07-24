//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: energetic
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct Point {
  double x;
  double y;
} Point;

double distance(Point a, Point b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

double triangle_area(Point a, Point b, Point c) {
  double s = (distance(a, b) + distance(b, c) + distance(c, a))/2;
  double area = sqrt(s*(s-distance(a,b))*(s-distance(b,c))*(s-distance(c,a)));
  return area;
}

double chord_length(double radius, double angle) {
  return 2*radius*sin(angle/2);
}

double segment_area(double radius, double angle) {
  double chord = chord_length(radius, angle);
  return (radius*radius/2) * (angle - sin(angle)) + (chord*chord/8) * (PI - angle*2);
}

int main() {
  Point a = {0, 0};
  Point b = {0, 5};
  Point c = {3, 0};

  double ab = distance(a, b);
  double bc = distance(b, c);
  double ac = distance(a, c);

  printf("Area of triangle ABC: %f\n", triangle_area(a, b, c));
  printf("Length of AB: %f\n", ab);
  printf("Length of BC: %f\n", bc);
  printf("Length of AC: %f\n", ac);

  double angle = PI/3;
  double radius = 5;

  printf("Chord length: %f\n", chord_length(radius, angle));
  printf("Segment area: %f\n", segment_area(radius, angle));

  return 0;
}