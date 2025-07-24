//FormAI DATASET v1.0 Category: Fractal Generation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITER 100

int main() {
    // initialize the fractal array
    char fractal[HEIGHT][WIDTH] = {0};

    int x,y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // calculate the complex number associated with this point in the image plane
            double complex c = 2.0 * ((x - (WIDTH / 2.0)) / WIDTH) + 
                                2.0i * ((y - (HEIGHT / 2.0)) / HEIGHT);

            // initialize z to 0
            double complex z = 0;

            // do the iteration
            int i;
            for (i = 0; i < MAX_ITER; i++) {
                z = z * z + c;
                if (cabs(z) > 2) {
                    // if magnitude of z exceeds 2, we know that this point is not in the mandelbrot set
                    fractal[y][x] = '.';
                    break;
                }
            }
            if (i == MAX_ITER) {
                // if we've reached the maximum number of iterations and haven't escaped, we can assume that this point is in the set
                fractal[y][x] = '*';
            }
        }
    }

    // now print out the fractal
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            putchar(fractal[y][x]);
        }
        putchar('\n');
    }

    return 0;
}