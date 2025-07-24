//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 60
#define MAX_ITERATIONS 1000
#define THRESHOLD 2

bool is_in_mandelbrot_set(double complex c)
{
    double complex z = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++)
    {
        z = z*z + c;
        if (cabs(z) > THRESHOLD)
            return false;
    }
    return true;
}

void generate_fractal(char image[HEIGHT][WIDTH])
{
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            double complex c = ((double) j - WIDTH/2) / (double) WIDTH + ((double) i - HEIGHT/2) / (double) HEIGHT * I;
            if (is_in_mandelbrot_set(c))
                image[i][j] = '#';
            else
                image[i][j] = ' ';
        }
    }
}

int main()
{
    char image[HEIGHT][WIDTH];
    generate_fractal(image);
    int i, j;
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            printf("%c", image[i][j]);
        }
        printf("\n");
    }
    return 0;
}