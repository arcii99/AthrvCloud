//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct Point {
  int x;
  int y;
} Point;

void drawTriangle(Point p1, Point p2, Point p3) {
  printf("drawTriangle (%d,%d)-(%d,%d)-(%d,%d)\n", p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
}

void sierpinski(Point p1, Point p2, Point p3, int level) {
  if (level == 0) { // base case
    drawTriangle(p1, p2, p3);
  } else {
    Point mid1, mid2, mid3;

    mid1.x = (p1.x + p2.x) / 2;
    mid1.y = (p1.y + p2.y) / 2;
    mid2.x = (p2.x + p3.x) / 2;
    mid2.y = (p2.y + p3.y) / 2;
    mid3.x = (p3.x + p1.x) / 2;
    mid3.y = (p3.y + p1.y) / 2;

    sierpinski(p1, mid1, mid3, level - 1);
    sierpinski(mid1, p2, mid2, level - 1);
    sierpinski(mid3, mid2, p3, level - 1);
  }
}

int main() {
  Point p1, p2, p3;
  int level;

  // Use time as a random seed
  srand(time(NULL));

  // Generate a random triangle
  p1.x = rand() % 500;
  p1.y = rand() % 500;
  p2.x = rand() % 500;
  p2.y = rand() % 500;
  p3.x = rand() % 500;
  p3.y = rand() % 500;

  level = rand() % 6 + 3; // Random level between 3 and 8

  sierpinski(p1, p2, p3, level);

  return 0;
}