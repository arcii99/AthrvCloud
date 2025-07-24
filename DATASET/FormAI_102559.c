//FormAI DATASET v1.0 Category: Fractal Generation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 500
#define MIN_R -2
#define MAX_R 2
#define MIN_I -2
#define MAX_I 2

int main()
{
    int pixels[WIDTH][HEIGHT];
    int i,j,n;
    double x,y,z;

    for(i=0; i<WIDTH; i++)
    {
        for(j=0; j<HEIGHT; j++)
        {
            x = ((double)i / (double)WIDTH) * (MAX_R - MIN_R) + MIN_R;
            y = ((double)j / (double)HEIGHT) * (MAX_I - MIN_I) + MIN_I;

            double real = x;
            double imaginary = y;

            for(n = 0; n < MAX_ITER; ++n)
            {
                z = real * real - imaginary * imaginary + x;
                imaginary = 2 * real * imaginary + y;
                real = z;

                if((real * real + imaginary * imaginary) > 4)
                    break;
            }

            pixels[i][j] = n;

        }
    }

    FILE *f = fopen("image.pgm", "wb");
    fprintf(f, "P5\n%d %d\n255\n", WIDTH, HEIGHT);

    for(j=0; j<HEIGHT; j++)
        for(i=0; i<WIDTH; i++)
            fputc(pixels[i][j], f);

    fclose(f);

    return 0;
}