//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: Ada Lovelace
#include<stdio.h>
#include<math.h>

typedef struct {
  float x, y;
} Point;

float distance(Point a, Point b) {
  float dx = a.x - b.x;
  float dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}

int main() {
  Point A = {0, 0};
  Point B = {3, 4};
  float d = distance(A, B);
  printf("Distance between A and B is %.2f\n", d);
  return 0;
}