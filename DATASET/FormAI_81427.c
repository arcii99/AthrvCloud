//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_ITERATIONS 1000

int main()
{
  unsigned char buffer[WIDTH * HEIGHT * 3];
  double complex c, z, dz;
  int x, y, i;

  for (y = 0; y < HEIGHT; y++)
  {
    for (x = 0; x < WIDTH; x++)
    {
      c = ((4.0 * x / WIDTH - 2.0) - (4.0 * y / HEIGHT - 2.0) * I);
      z = 0.0 + 0.0 * I;

      for (i = 0; i < MAX_ITERATIONS; i++)
      {
        dz = 2.0 * z * dz + 1.0;
        z = z * z + c;

        if (cabs(z) > 2.0)
        {
          break;
        }
      }

      buffer[(x + y * WIDTH) * 3 + 0] = i % 16 * 16 * 16;
      buffer[(x + y * WIDTH) * 3 + 1] = i % 256;
      buffer[(x + y * WIDTH) * 3 + 2] = i % 16 * 16;
    }
  }

  FILE *f = fopen("fractal.ppm", "wb");

  fprintf(f, "P6 %d %d 255\n", WIDTH, HEIGHT);
  fwrite(buffer, 1, WIDTH * HEIGHT * 3, f);

  fclose(f);
  return 0;
}