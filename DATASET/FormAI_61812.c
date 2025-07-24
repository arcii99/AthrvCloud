//FormAI DATASET v1.0 Category: Fractal Generation ; Style: shocked
#include <stdio.h>
#include <complex.h>

const int WIDTH = 120; // Width of the output image
const int HEIGHT = 40; // Height of the output image

const double CXMIN = -2.5; // Minimum x value
const double CXMAX = 1; // Maximum x value
const double CYMIN = -1; // Minimum y value
const double CYMAX = 1; // Maximum y value

const int MAXITER = 1000; // Maximum number of iterations per pixel

int main() {
    double complex z, c;
    int iter, x, y;
    double zx, zy, cx, cy;

    // Loop through each pixel in the output image
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Calculate the complex number c corresponding to this pixel
            cx = CXMIN + x * (CXMAX - CXMIN) / WIDTH;
            cy = CYMIN + y * (CYMAX - CYMIN) / HEIGHT;

            // Start with z = 0
            z = 0;

            // Iterate until z escapes or we reach the maximum number of iterations
            for (iter = 0; iter < MAXITER; iter++) {
                z = z*z + c;

                // If z escapes, color this pixel black
                if (cabs(z) > 2) {
                    printf(".");
                    break;
                }
            }

            // If we reached the maximum number of iterations without z escaping, color this pixel white
            if (iter == MAXITER) {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}