//FormAI DATASET v1.0 Category: Fractal Generation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

typedef struct {
  double x;
  double y;
} Point;

void drawPixel(Point p, FILE *fp) {
  int xp = (int) p.x;
  int yp = (int) p.y;
  fprintf(fp, "PX %d %d 0 0 0\n", xp, yp);
}

void drawLine(Point p1, Point p2, FILE *fp) {
  double dx = fabs(p2.x - p1.x);
  double dy = fabs(p2.y - p1.y);
  double sx = (p1.x < p2.x) ? 1 : -1;
  double sy = (p1.y < p2.y) ? 1 : -1;
  double err = dx - dy;
  
  while(1) {
    drawPixel(p1, fp);
    if (p1.x == p2.x && p1.y == p2.y) break;
    double e2 = 2 * err;
    if (e2 > -dy) { err -= dy; p1.x += sx; }
    if (e2 < dx) { err += dx; p1.y += sy; }
  }
}

void drawFractal(Point a, Point b, Point c, FILE *fp) {
  if (fabs(a.x - b.x) < 2 && fabs(a.y - b.y) < 2 &&
      fabs(b.x - c.x) < 2 && fabs(b.y - c.y) < 2 &&
      fabs(c.x - a.x) < 2 && fabs(c.y - a.y) < 2) {
    drawLine(a, b, fp);
    drawLine(b, c, fp);
    drawLine(c, a, fp);
    return;
  }

  Point ab, bc, ca;

  ab.x = (a.x + b.x) / 2.0;
  ab.y = (a.y + b.y) / 2.0;

  bc.x = (b.x + c.x) / 2.0;
  bc.y = (b.y + c.y) / 2.0;

  ca.x = (c.x + a.x) / 2.0;
  ca.y = (c.y + a.y) / 2.0;

  drawFractal(a, ab, ca, fp);
  drawFractal(ab, b, bc, fp);
  drawFractal(ca, bc, c, fp);
}

int main() {
  srand(time(NULL));

  FILE *fp = fopen("fractal.ppm", "w");
  fprintf(fp, "P3\n%d %d\n255\n", WINDOW_WIDTH, WINDOW_HEIGHT);

  Point a, b, c;

  a.x = WINDOW_WIDTH * 0.5;
  a.y = WINDOW_HEIGHT * 0.1 + rand() % 50;

  b.x = WINDOW_WIDTH * 0.05 + rand() % 50;
  b.y = WINDOW_HEIGHT * 0.9;

  c.x = WINDOW_WIDTH * 0.95 - rand() % 50;
  c.y = WINDOW_HEIGHT * 0.9;

  drawFractal(a, b, c, fp);

  fclose(fp);

  return 0;
}