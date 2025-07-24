//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <time.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITERATIONS 1000

void set_pixel(int x, int y, unsigned char value, unsigned char *pixels)
{
    int i = y * WIDTH + x;
    pixels[i] = value;
}

int mandelbrot_iteration(double complex c)
{
    double complex z = 0;
    int n;

    for (n = 0; n < MAX_ITERATIONS; n++) 
    {
        z = z * z + c;
        if (cabs(z) > 2.0)
            break;
    }

    return n;
}

int main()
{
    unsigned char pixels[WIDTH * HEIGHT];
    clock_t start, end;
    double cpu_time_used;

    start = clock();

    for (int x = 0; x < WIDTH; x++)
    {
        for (int y = 0; y < HEIGHT; y++)
        {
            double complex c = -2.0 + 3.0 * x / WIDTH + I * (-1.5 + 3.0 * y / HEIGHT);
            int n = mandelbrot_iteration(c);
            unsigned char value = (unsigned char)(255 * n / MAX_ITERATIONS);
            set_pixel(x, y, value, pixels);
        }
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Fractal generated in %f seconds.\n", cpu_time_used);

    return 0;
}