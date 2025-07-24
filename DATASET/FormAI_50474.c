//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shape shifting
#include <stdio.h>

#define WIDTH 40  // Width of the console
#define HEIGHT 20 // Height of the console
#define MAX_IT 256 // Maximum number of iterations
#define MIN_C_RE -1.5 // Minimum real coordinate of the complex plane
#define MAX_C_RE 0.5 // Maximum real coordinate of the complex plane
#define MIN_C_IM -1 // Minimum imaginary coordinate of the complex plane
#define MAX_C_IM 1 // Maximum imaginary coordinate of the complex plane

int main()
{
    float c_re, c_im, new_c_re, new_c_im, old_c_re, old_c_im, zoom = 1;
    int i, j, k, it;
    char pixels[HEIGHT][WIDTH + 1]; // 2D array of characters to store the pixels

    // Initialize the pixels array with blank spaces
    for (i = 0; i < HEIGHT; i++)
        for (j = 0; j < WIDTH; j++)
            pixels[i][j] = ' ';

    // Loop through each row and column to generate the fractal
    for (i = 0; i < HEIGHT; i++)
    {
        for (j = 0; j < WIDTH; j++)
        {
            // Calculate the corresponding point in the complex plane
            c_re = MIN_C_RE + j * ((MAX_C_RE - MIN_C_RE) / WIDTH) / zoom;
            c_im = MAX_C_IM - i * ((MAX_C_IM - MIN_C_IM) / HEIGHT) / zoom;

            // Initialize the new and old complex values to the current point
            new_c_re = c_re;
            new_c_im = c_im;
            old_c_re = c_re;
            old_c_im = c_im;

            // Loop through a maximum number of iterations to determine whether the point is in the fractal
            for (it = 0; it < MAX_IT; it++)
            {
                // Calculate the new complex value using the Mandelbrot formula
                new_c_re = old_c_re * old_c_re - old_c_im * old_c_im + c_re;
                new_c_im = 2 * old_c_re * old_c_im + c_im;

                // If the magnitude of the new complex value is greater than 2, the point is not in the fractal
                if (new_c_re * new_c_re + new_c_im * new_c_im > 4)
                    break;

                // Otherwise, the point might be in the fractal, so update the old complex value
                old_c_re = new_c_re;
                old_c_im = new_c_im;
            }

            // Determine the appropriate character to represent the pixel based on the number of iterations
            if (it == MAX_IT)
                pixels[i][j] = '#';
            else if (it >= 128)
                pixels[i][j] = '%';
            else if (it >= 64)
                pixels[i][j] = '@';
            else if (it >= 32)
                pixels[i][j] = '-';
            else if (it >= 16)
                pixels[i][j] = '+';
            else if (it >= 8)
                pixels[i][j] = '=';
            else if (it >= 4)
                pixels[i][j] = ':';
            else if (it >= 2)
                pixels[i][j] = ',';
        }

        printf("%.*s\n", WIDTH, pixels[i]); // Print the row of pixels
    }

    return 0;
}