//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000
#define NUM_ITERS 1000

int main(void) {
  srand(time(NULL));
  int image[WIDTH][HEIGHT] = {0};
  
  double reMin = -2.0, reMax = 2.0, imMin = -2.0, imMax = 2.0;
  
  int x, y, i;
  double cReal, cImag, zReal, zImag, newReal, newImag;
  
  /* Generate random complex number values */
  cReal = (double) (rand() / (double)RAND_MAX) * (reMax - reMin) + reMin;
  cImag = (double) (rand() / (double)RAND_MAX) * (imMax - imMin) + imMin;
  
  /* Iterate through each pixel and calculate fractal */
  for (x = 0; x < WIDTH; x++) {
    for (y = 0; y < HEIGHT; y++) {
      
      /* Initialize values for each pixel */
      zReal = (double)x / WIDTH * (reMax - reMin) + reMin;
      zImag = (double)y / HEIGHT * (imMax - imMin) + imMin;
      
      /* Iterate to calculate fractal */
      for (i = 0; i < NUM_ITERS; i++) {
        newReal = zReal * zReal - zImag * zImag + cReal;
        newImag = 2 * zReal * zImag + cImag;
        
        /* Check if point is outside the Mandelbrot set */
        if (newReal * newReal + newImag * newImag > 4.0) {
          image[x][y] = i;
          break;
        }
        
        /* Update values for next iteration */
        zReal = newReal;
        zImag = newImag;
      }
    }
  }
  
  printf("P2\n%d %d\n%d\n", WIDTH, HEIGHT, NUM_ITERS);
  
  /* Output image */
  for (y = 0; y < HEIGHT; y++) {
    for (x = 0; x < WIDTH; x++) {
      printf("%d ", image[x][y]);
    }
    printf("\n");
  }
  
  return 0;
}