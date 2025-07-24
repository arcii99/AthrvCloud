//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    // Set up the complex plane coordinates
    const int WIDTH = 640;
    const int HEIGHT = 480;
    const double cx_min = -1.5;
    const double cx_max = 1.5;
    const double cy_min = -1.0;
    const double cy_max = 1.0;

    // Set up the escape time and pixel array
    const int ESCAPE_TIME = 100;
    char pixels[WIDTH][HEIGHT];

    // Iterate over each pixel
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // Translate pixel coordinates to complex plane coordinates
            double cx = cx_min + i * (cx_max - cx_min) / WIDTH;
            double cy = cy_min + j * (cy_max - cy_min) / HEIGHT;

            // Calculate the Mandelbrot Set value for the pixel
            double x = 0, y = 0;
            int t = 0;
            while (x*x + y*y <= 2*2 && t < ESCAPE_TIME) {
                double x_temp = x*x - y*y + cx;
                y = 2*x*y + cy;
                x = x_temp;
                t++;
            }

            // Set the pixel value based on the escape time
            if (t == ESCAPE_TIME) {
                pixels[i][j] = ' ';
            } else if (t >= 10) {
                pixels[i][j] = '.';
            } else if (t >= 6) {
                pixels[i][j] = ':';
            } else if (t >= 4) {
                pixels[i][j] = '-';
            } else if (t >= 2) {
                pixels[i][j] = '=';
            } else {
                pixels[i][j] = '#';
            }
        }
    }

    // Print the pixel array to the console
    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            putchar(pixels[i][j]);
        }
        putchar('\n');
    }

    return 0;
}