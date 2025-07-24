//FormAI DATASET v1.0 Category: Fractal Generation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

int main()
{
    printf("Welcome to the world of fractals!\n\n");

    // define the parameters for the fractal function
    const double complex begin = -2.0 + 2.0 * I;
    const double complex end = 2.0 - 2.0 * I;
    const int width = 100;
    const int height = 50;

    // allocate the memory for the fractal array
    double complex *fractal = (double complex*) malloc(width * height * sizeof(double complex));

    // generate the fractal data using the Mandelbrot set formula
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            double complex c = ((double)x / width) * (end - begin) + begin;
            double complex z = c;
            int n = 0;
            while (creal(z) * creal(z) + cimag(z) * cimag(z) < 4.0 && n < 100)
            {
                z = z * z + c;
                n++;
            }
            fractal[y * width + x] = n;
        }
    }

    // print the fractal
    printf("    ");
    for (int x = 0; x < width; x++)
    {
        printf("%c", (char)217);
    }
    printf("\n");
    for (int y = 0; y < height; y++)
    {
        printf("%c%c", (char)179, (char)255);
        for (int x = 1; x < width; x++)
        {
            int n = (int)creal(fractal[y * width + x]);
            printf("%c", n > 0 ? (char)(n % 24 + 176) : ' ');
        }
        printf("%c\n", (char)179);
    }
    printf("    ");
    for (int x = 0; x < width; x++)
    {
        printf("%c", (char)192);
    }
    printf("\n");

    // free the allocated memory
    free(fractal);

    printf("\nThank you for exploring the fascinating world of fractals with me!\n");
    return 0;
}