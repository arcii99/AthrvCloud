//FormAI DATASET v1.0 Category: Fractal Generation ; Style: introspective
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define WIDTH 640
#define HEIGHT 640

typedef struct {
  double x, y;
} Point;

/* A helper function to map the range [a,b] to [c,d]. */
double map(double t, double a, double b, double c, double d) {
  return (t-a)/(b-a)*(d-c) + c;
}

/* A function to plot a single pixel at (x,y). */
void plot(int x, int y) {
  printf("%d %d\n", x, y);
}

/* A function to draw a line from (x1,y1) to (x2,y2). */
void line(int x1, int y1, int x2, int y2) {
  int dx = abs(x2-x1), sx = x1<x2 ? 1 : -1;
  int dy = abs(y2-y1), sy = y1<y2 ? 1 : -1;
  int err = (dx>dy ? dx : -dy)/2, e2;

  for(;;) {
    plot(x1, y1);
    if (x1==x2 && y1==y2) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x1 += sx; }
    if (e2 < dy) { err += dx; y1 += sy; }
  }
}

/* A recursive function to draw a Koch snowflake fractal. */
void koch_snowflake(Point A, Point B, int level) {
  assert(level >= 0 && "Level must be greater than or equal to 0");
  if (level == 0) {
    line((int)A.x, (int)A.y, (int)B.x, (int)B.y);
  } else {
    /* Calculate the coordinates of the four points for the new iteration. */
    Point C, D, E;
    double length = sqrt(pow(B.x-A.x,2)+pow(B.y-A.y,2));
    C.x = A.x + (B.x-A.x)/3;
    C.y = A.y + (B.y-A.y)/3;
    D.x = B.x - (B.x-A.x)/3;
    D.y = B.y - (B.y-A.y)/3;
    E.x = C.x + (D.x-C.x)*cos(M_PI/3) - (D.y-C.y)*sin(M_PI/3);
    E.y = C.y + (D.x-C.x)*sin(M_PI/3) + (D.y-C.y)*cos(M_PI/3);

    /* Recursively call the function on the four smaller segments. */
    koch_snowflake(A, C, level - 1);
    koch_snowflake(C, E, level - 1);
    koch_snowflake(E, D, level - 1);
    koch_snowflake(D, B, level - 1);
  }
}

int main() {
  printf("P2\n%d %d\n255\n", WIDTH, HEIGHT);

  /* Start with an equilateral triangle. */
  Point A, B, C;
  A.x = WIDTH/2 - WIDTH/4;
  A.y = HEIGHT/2 - sqrt(3)*WIDTH/4;
  B.x = WIDTH/2 + WIDTH/4;
  B.y = A.y;
  C.x = WIDTH/2;
  C.y = HEIGHT/2 + sqrt(3)*WIDTH/4;

  /* Draw the three segments of the triangle. */
  line((int)A.x, (int)A.y, (int)B.x, (int)B.y);
  line((int)B.x, (int)B.y, (int)C.x, (int)C.y);
  line((int)C.x, (int)C.y, (int)A.x, (int)A.y);

  /* Recursively draw the fractal. */
  koch_snowflake(A, B, 4);
  koch_snowflake(B, C, 4);
  koch_snowflake(C, A, 4);

  return 0;
}