//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct { double r, i; } complex;
static complex add(complex a, complex b) { return (complex) { a.r + b.r, a.i + b.i }; }
static complex square(complex a) { return (complex) { a.r * a.r - a.i * a.i, 2 * a.r * a.i }; }

int main(void)
{
  int space[WIDTH][HEIGHT];
  for(int y = 0; y < HEIGHT; y++) {
    for(int x = 0; x < WIDTH; x++) {
      complex c = (complex) { 2.0 * x / WIDTH - 1.0, 2.0 * y / HEIGHT - 1.0 };
      complex z = (complex) { 0, 0 };
      int i;
      for(i = 0; i < 100; i++) {
        if(z.r * z.r + z.i * z.i > 4.0) break;
        z = add(square(z), c);
      }
      space[x][y] = i;
    }
  }
  for(int y = 0; y < HEIGHT; y++) {
    for(int x = 0; x < WIDTH; x++) {
      putchar(space[x][y] < 100 ? ' ' + space[x][y] / 10 : '#');
    }
    putchar('\n');
  }
}