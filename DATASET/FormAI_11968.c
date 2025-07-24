//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ITERATIONS 1000
#define RE_START -2.0
#define RE_END 2.0
#define IM_START -2.0
#define IM_END 2.0
#define WIDTH 80
#define HEIGHT 40

int main() {
  int row, col, iter;
  double c_real, c_imag, z_real, z_imag, tmp_real;
  
  for (row = 0; row < HEIGHT; row++) {
    for (col = 0; col < WIDTH; col++) {
      c_real = ((double) col / WIDTH) * (RE_END - RE_START) + RE_START;
      c_imag = ((double) row / HEIGHT) * (IM_END - IM_START) + IM_START;
      z_real = c_real;
      z_imag = c_imag;
      iter = 0;
  
      while ((z_real * z_real + z_imag * z_imag) < 4 && iter < MAX_ITERATIONS) {
        tmp_real = z_real * z_real - z_imag * z_imag + c_real;
        z_imag = 2 * z_real * z_imag + c_imag;
        z_real = tmp_real;
        iter++;
      }
  
      if (iter == MAX_ITERATIONS) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  
  return 0;
}