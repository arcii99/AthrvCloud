//FormAI DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define MAX_ITER 50
#define SCALE_FACTOR 0.0075

int sign(double num) {
  return num < 0 ? -1 : num > 0 ? 1 : 0;
}

typedef struct complex_num {
  double real;
  double imag;
} ComplexNum;

void compute_pixel(int x, int y, unsigned char (*pixels)[WINDOW_WIDTH][3]) {
  double cx = (x - WINDOW_WIDTH / 2) * SCALE_FACTOR;
  double cy = (y - WINDOW_HEIGHT / 2) * SCALE_FACTOR;

  ComplexNum c = { .real = cx, .imag = cy };
  ComplexNum z = { .real = 0, .imag = 0 };
  int n;

  for (n = 0; n < MAX_ITER; n++) {
    z = (ComplexNum) {
      .real = z.real * z.real - z.imag * z.imag + c.real,
      .imag = 2 * z.real * z.imag + c.imag
    };

    if (sign(z.real) * sign(z.real + z.imag) == -1) {
      break;
    }
  }

  unsigned char brightness = (unsigned char) (255 * n / (MAX_ITER - 1));
  (*pixels)[x][y] = brightness;
}

void generate_fractal(unsigned char (*pixels)[WINDOW_WIDTH][3]) {
  int x, y;
  for (x = 0; x < WINDOW_WIDTH; x++) {
    for (y = 0; y < WINDOW_HEIGHT; y++) {
      compute_pixel(x, y, pixels);
    }
  }
}

int main() {
  unsigned char pixels[WINDOW_WIDTH][WINDOW_HEIGHT][3];

  generate_fractal(&pixels);

  FILE *fp = fopen("fractal.ppm", "wb");

  fprintf(fp, "P6\n%d %d\n%d\n", WINDOW_WIDTH, WINDOW_HEIGHT, 255);
  fwrite(pixels, sizeof(pixels), 1, fp);
  fclose(fp);

  return 0;
}