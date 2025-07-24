//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITERATIONS 100

char pixels[HEIGHT][WIDTH];

int mandelbrot_set(double real, double imaginary)
{
    double z_real = 0.0;
    double z_imaginary = 0.0;
    int n;

    for(n = 0; n < MAX_ITERATIONS; n++)
    {
        double zr_squared = z_real * z_real;
        double zi_squared = z_imaginary * z_imaginary;

        if(zr_squared + zi_squared > 4.0)
        {
            return 0;
        }

        z_imaginary = 2.0 * z_real * z_imaginary + imaginary;
        z_real = zr_squared - zi_squared + real;
    }

    return 1;
}

int main()
{
    int x, y;

    for(y = 0; y < HEIGHT; y++)
    {
        for(x = 0; x < WIDTH; x++)
        {
            double real = ((double) x - WIDTH/2) * 4.0 / WIDTH;
            double imaginary = ((double) y - HEIGHT/2) * 4.0 / WIDTH;

            int in_set = mandelbrot_set(real, imaginary);

            if(in_set)
            {
                pixels[y][x] = ' ';
            }
            else
            {
                pixels[y][x] = '*';
            }
        }

        pixels[y][WIDTH] = '\0';
    }

    for(y = 0; y < HEIGHT; y++)
    {
        printf("%s\n", pixels[y]);
    }

    return 0;
}