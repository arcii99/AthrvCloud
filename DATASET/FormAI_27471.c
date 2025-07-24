//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Alan Touring
#include <stdio.h>
#include <math.h>

#define MAX_ITERATIONS 1000

typedef struct {
  double x;
  double y;
} complex;

int fractal_escape_time(complex c) {
  complex z = {0, 0};
  int iter = 0;
  while (iter < MAX_ITERATIONS && z.x * z.x + z.y * z.y < 4) {
      // z = z^2 + c
      double z_x = z.x * z.x - z.y * z.y;
      double z_y = 2 * z.x * z.y;
      z.x = z_x + c.x;
      z.y = z_y + c.y;
      iter++;
  }
  return iter;
}

int main() {
  double X_MIN = -2;
  double X_MAX = 1;
  double Y_MIN = -1;
  double Y_MAX = 1;
  int WIDTH = 80;
  int HEIGHT = 40;

  for (int j = 0; j < HEIGHT; j++) {
    for (int i = 0; i < WIDTH; i++) {
      // map pixel coordinates to complex plane
      double x = X_MIN + i * (X_MAX - X_MIN) / WIDTH;
      double y = Y_MAX - j * (Y_MAX - Y_MIN) / HEIGHT;
      complex c = {x, y};
      int iter = fractal_escape_time(c);
      if (iter == MAX_ITERATIONS) {
        printf("*");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  return 0;
}