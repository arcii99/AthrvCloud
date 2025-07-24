//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40

void generateFractal(double cx, double cy, double scale);

int main() {
    generateFractal(-0.5, 0, 4);
    return 0;
}

void generateFractal(double cx, double cy, double scale) {
    int x, y, i, iterations;
    double zx, zy, temp, magn;

    // loop over all the pixels in the screen
    for (y=0; y<HEIGHT; y++) {
        for (x=0; x<WIDTH; x++) {

            // convert pixel coordinates to complex plane coordinates
            zx = (x - WIDTH/2.0) / (0.5 * scale * WIDTH) + cx;
            zy = (y - HEIGHT/2.0) / (0.5 * scale * HEIGHT) + cy;
            
            // calculate the number of iterations needed to escape the mandelbrot set
            iterations = 0;
            magn = 0;
            while (iterations < 50 && magn < 4) {
                temp = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = temp;
                magn = zx * zx + zy * zy;
                iterations++;
            }

            // print out the appropriate character based on the number of iterations
            if (iterations == 50) {
                printf("*");
            } else if (iterations > 35) {
                printf("#");
            } else if (iterations > 20) {
                printf("=");
            } else if (iterations > 10) {
                printf("+");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}