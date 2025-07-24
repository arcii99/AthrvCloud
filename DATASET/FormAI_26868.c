//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define MAX_ITER 1000
#define WIDTH 1000
#define HEIGHT 1000
#define SCALE 0.005

int main() {
  //allocate memory for the image array
  unsigned char* image = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));

  //set the initial parameters for the fractal
  double complex c = -0.75 + 0.25 * I;
  double x_min = -2.0, y_min = -2.0, x_max = 2.0, y_max = 2.0;
  double x_range = x_max - x_min, y_range = y_max - y_min;

  //generate the fractal image
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      double complex z = x_range * ((double)x / WIDTH) + x_min
                       + y_range * ((double)y / HEIGHT) * I + y_min * I;

      int iteration = 0;
      while (iteration < MAX_ITER && cabs(z) < 2.0) {
        z = cpow(z, 2) + c;
        iteration++;
      }
      image[y * WIDTH + x] = iteration * (255 / MAX_ITER);
    }
  }

  //print the image to stdout as grayscale ASCII art
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      char pixel = image[y * WIDTH + x] > 128 ? '@' : '.';
      printf("%c%c", pixel, pixel);
    }
    printf("\n");
  }

  //free the allocated memory
  free(image);

  return 0;
}