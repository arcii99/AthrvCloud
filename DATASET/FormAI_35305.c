//FormAI DATASET v1.0 Category: Fractal Generation ; Style: accurate
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_ITERATIONS 400
#define WIDTH 70
#define HEIGHT 40

int main()
{
    int iterations;
    int i, j, k;
    double x, y, zx, zy, zx_squared, zy_squared;
    double c_real = -0.7, c_imaginary = 0.27015;
    double pixel_width = 4.0 / WIDTH;
    double pixel_height = 4.0 / HEIGHT;
    char output[HEIGHT][WIDTH + 1];

    // Initialize output array
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            output[i][j] = ' ';
        }
        output[i][WIDTH] = '\0';
    }

    // Generate fractal and store result in output array
    for (i = 0; i < HEIGHT; i++)
    {
        y = (2 - i * pixel_height) - 2.0;
        for (j = 0; j < WIDTH; j++)
        {
            x = -2.0 + j * pixel_width;
            zx = x;
            zy = y;
            zx_squared = zx * zx;
            zy_squared = zy * zy;
            for (k = 0; k < MAX_ITERATIONS && zx_squared + zy_squared < 4; k++)
            {
                zy = 2 * zx * zy + c_imaginary;
                zx = zx_squared - zy_squared + c_real;
                zx_squared = zx * zx;
                zy_squared = zy * zy;
            }
            output[i][j] = k == MAX_ITERATIONS ? '#' : '.';
        }
    }

    // Print output array
    for (i = 0; i < HEIGHT; i++)
    {
        printf("%s\n", output[i]);
    }

    return 0;
}