//FormAI DATASET v1.0 Category: Fractal Generation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<complex.h>

#define WIDTH 800
#define HEIGHT 800

int max_iterations = 100;

bool isInMandelbrotSet(double complex c) {
  double complex z = 0;

  for(int i = 0; i < max_iterations; i++) {
    z = z * z + c;
    if (cabs(z) > 2) {
      return false;
    }
  }
  return true;
}

void generateFractal(double **output) {
  for(int i = 0; i < WIDTH; i++) {
    for(int j = 0; j < HEIGHT; j++) {
      double x = (double)i/WIDTH*4.0 - 2.5;
      double y = (double)j/HEIGHT*4.0 - 2.0;
      double complex c = x + y*I;
      if(isInMandelbrotSet(c)) {
        output[j][i] = 0;
      } else {
        output[j][i] = 255;
      }
    }
  }
}

void render(double **output) {
  FILE *fp = fopen("mandelbrot.ppm", "wb");

  fprintf(fp, "P6\n# Creater: George Foot\n%d %d\n255\n", WIDTH, HEIGHT);

  for(int i = 0; i < WIDTH; i++) {
    for(int j = 0; j < HEIGHT; j++) {
      unsigned char pixel[3];
      pixel[0] = output[i][j];
      pixel[1] = output[i][j];
      pixel[2] = output[i][j];
      fwrite(pixel, 1, 3, fp);
    }
  }
  fclose(fp);
}

int main() {
  double **output = (double **)malloc(sizeof(double *)*HEIGHT);
  for(int i = 0; i < HEIGHT; i++) {
    output[i] = (double *)malloc(sizeof(double)*WIDTH);
  }

  generateFractal(output);
  render(output);

  return 0;
}