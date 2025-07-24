//FormAI DATASET v1.0 Category: Fractal Generation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WINDOW_SIZE 800
#define MAX_ITERATIONS 50000
#define ESCAPE_RADIUS 10

typedef struct complex
{
    double real, imag;
} complex;

int mandelbrot(complex c)
{
    complex z = { 0, 0 };
    for (int i = 0; i < MAX_ITERATIONS; i++)
    {
        double mag = z.real * z.real + z.imag * z.imag;
        if (mag > ESCAPE_RADIUS)
            return i;
        z = (complex){
            z.real * z.real - z.imag * z.imag + c.real,
            2 * z.real * z.imag + c.imag
        };
    }
    return MAX_ITERATIONS;
}

int main()
{
    clock_t start = clock();

    double x_min = -2.0, x_max = 1.0;
    double y_min = -1.5, y_max = 1.5;
    double dx = (x_max - x_min) / WINDOW_SIZE;
    double dy = (y_max - y_min) / WINDOW_SIZE;
    double x, y;
    int i, j;

    FILE *fp;
    fp = fopen("fractal.ppm", "w");
    fprintf(fp, "P3\n%d %d\n255\n", WINDOW_SIZE, WINDOW_SIZE);

    for (j = 0, y = y_min; j < WINDOW_SIZE; j++, y += dy)
    {
        for (i = 0, x = x_min; i < WINDOW_SIZE; i++, x += dx)
        {
            int iter = mandelbrot((complex){x, y});
            double hue = iter % 256;
            double saturation = iter < MAX_ITERATIONS ? 255 : 0;
            double value = iter < MAX_ITERATIONS ? 255 : 0;
            fprintf(fp, "%d %d %d ", (int)hue, (int)saturation, (int)value);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    printf("Fractal generation took %f seconds\n",
           ((double)(clock() - start) / CLOCKS_PER_SEC));

    return 0;
}