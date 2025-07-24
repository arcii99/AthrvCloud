//FormAI DATASET v1.0 Category: Fractal Generation ; Style: expert-level
#include <stdlib.h>
#include <stdio.h>
#include <complex.h>

#define WIDTH 100
#define HEIGHT 100

typedef double complex cplx;

cplx julia(cplx z, cplx c) {
    return z * z + c;
}

int main() {
    int i, j, k;
    cplx c = -0.85 + 0.25i; // change this to vary the Julia set
    cplx z, temp;
    double x, y, x_range = 3.0, y_range = 2.0, x_start = -1.5, y_start = -1.0, x_step = x_range / WIDTH, y_step = y_range / HEIGHT;

    unsigned char image[HEIGHT][WIDTH];

    // calculate the pixels
    for (i = 0, y = y_start; i < HEIGHT; i++, y += y_step) {
        for (j = 0, x = x_start; j < WIDTH; j++, x += x_step) {
            z = x + y * I;

            // iterate the function
            for (k = 0; k < 100; k++) {
                z = julia(z, c);

                if (cabs(z) > 2.0) {
                    image[i][j] = k; // use the iteration count as the color
                    break;
                }
            }
        }
    }

    // output the image
    printf("P2\n%d %d\n255\n", WIDTH, HEIGHT);
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}