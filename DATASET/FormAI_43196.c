//FormAI DATASET v1.0 Category: Scientific ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y;
} point;

void draw(point a, point b, int depth) {
  if (depth > 0) {
    point c, d, e;
    c.x = (2*a.x + b.x) / 3;
    c.y = (2*a.y + b.y) / 3;
    d.x = (a.x + 2*b.x) / 3;
    d.y = (a.y + 2*b.y) / 3;
    e.x = (c.x + d.x)/2 - sqrt(3)*(d.y - c.y)/2;
    e.y = (c.y + d.y)/2 - sqrt(3)*(c.x - d.x)/2;
    draw(a, c, depth-1);
    draw(c, e, depth-1);
    draw(e, d, depth-1);
    draw(d, b, depth-1);
  } else {
    printf("(%g, %g) ", a.x, a.y);
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s depth\n", argv[0]);
    return 1;
  }
  int depth = atoi(argv[1]);
  point a = {0, 0};
  point b = {1, 0};
  draw(a, b, depth);
  printf("(%g, %g)\n", b.x, b.y);
  return 0;
}