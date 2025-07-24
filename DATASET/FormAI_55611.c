//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 50

int main() {
  int x, y, i;
  double sm, s;
  char image[WIDTH][HEIGHT];

  // initialize image
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      image[x][y] = ' ';
    }
  }

  // calculate fractal
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      sm = 0;
      s = 0;

      for (i = 0; i < MAX_ITERATIONS; i++) {
        double r = (double)x / WIDTH * 3.5 - 2.5;
        double c = (double)y / HEIGHT * 2 - 1;
        double a = r * r - c * c + sm;
        double b = 2 * r * c + s;

        if (a * a + b * b > 4) {
          break;
        }

        sm += a;
        s += b;
      }

      if (i == MAX_ITERATIONS) {
        image[x][y] = '.';
      }
    }
  }

  // print image
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      putchar(image[x][y]);
    }
    putchar('\n');
  }

  return 0;
}