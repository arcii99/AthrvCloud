//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 43
#define ITERATIONS 1000000

typedef struct {
  double a, b;
} complex;

int main() {

  int x,y;
  int iterations;
  double scalex = 3.5/WIDTH;
  double scaley = 2.0/HEIGHT;

  complex c,z,t;

  for(y=0; y<HEIGHT; y++) {
    for(x=0; x<WIDTH; x++) {

      c.a = (x - (WIDTH/2)) * scalex;
      c.b = (y - (HEIGHT/2)) * scaley;

      z.a = 0;
      z.b = 0;

      iterations = 0;

      while(z.a*z.a + z.b*z.b < 4 && iterations < ITERATIONS) {
        t.a = z.a*z.a - z.b*z.b + c.a;
        t.b = 2 * z.a * z.b + c.b;
        z = t;
        iterations++;
      }

      if(iterations == ITERATIONS) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}