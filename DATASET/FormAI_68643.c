//FormAI DATASET v1.0 Category: Fractal Generation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int x, y;
int SIZE_X = 800, SIZE_Y = 800;
double scaleFactor = 0.5;

double random_double() {
  return (double)rand() / (double)RAND_MAX;
}

void draw_pixel(int x, int y, int color, char image[SIZE_X][SIZE_Y]) {
  if (x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y) {
    image[x][y] = color;
  }
}

void draw_line(int x1, int y1, int x2, int y2, int color, char image[SIZE_X][SIZE_Y]) {
  int dx = abs(x2 - x1), dy = abs(y2 - y1);
  int xi = x1 < x2 ? 1 : -1, yi = y1 < y2 ? 1 : -1;
  int err = dx > dy ? dx : -dy, e2;

  while (1) {
    draw_pixel(x1, y1, color, image);
    if (x1 == x2 && y1 == y2) break;
    e2 = 2*err;
    if (e2 > -dy) { err -= dy; x1 += xi; }
    if (e2 < dx) { err += dx; y1 += yi; }
  }
}

void generate_fractal(int x1, int y1, int x2, int y2, double scale, char image[SIZE_X][SIZE_Y]) {
  int dx = x2 - x1, dy = y2 - y1;
  int x3 = x2 - dy, y3 = y2 + dx;
  int x4 = x1 - dy, y4 = y1 + dx;
  int xmid = (x1 + x2 + x3 + x4) / 4;
  int ymid = (y1 + y2 + y3 + y4) / 4;
  double displacement = pow(random_double(), 4) * scale;

  if (dx*dx + dy*dy < 20) {
    draw_line(x1, y1, x2, y2, 255, image);
    return;
  }

  x3 = xmid + (x3 - xmid) * scaleFactor + displacement;
  y3 = ymid + (y3 - ymid) * scaleFactor + displacement;
  x4 = xmid + (x4 - xmid) * scaleFactor + displacement;
  y4 = ymid + (y4 - ymid) * scaleFactor + displacement;

  generate_fractal(x1, y1, x4, y4, scale*scaleFactor, image);
  generate_fractal(x4, y4, xmid, ymid, scale*scaleFactor, image);
  generate_fractal(xmid, ymid, x3, y3, scale*scaleFactor, image);
  generate_fractal(x3, y3, x2, y2, scale*scaleFactor, image);
}

void print_image(char image[SIZE_X][SIZE_Y]) {
  for (y = 0; y < SIZE_Y; y++) {
    for (x = 0; x < SIZE_X; x++) {
      putchar(image[x][y] == 255 ? '*' : ' ');
    }
    putchar('\n');
  }
}

int main() {
  srand(time(NULL));
  char image[SIZE_X][SIZE_Y];

  for (x = 0; x < SIZE_X; x++) {
    for (y = 0; y < SIZE_Y; y++) {
      image[x][y] = 0;
    }
  }

  generate_fractal(100, 100, 700, 700, 50, image);
  print_image(image);

  return 0;
}