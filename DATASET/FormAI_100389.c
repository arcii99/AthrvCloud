//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

int main(void) {
    // Define constants
    const int WIDTH = 80;
    const int HEIGHT = 30;
    const int MAX_ITERATIONS = 50;
    const double MIN_RE = -2.0;
    const double MAX_RE = 1.0;
    const double MIN_IM = -1.0;
    const double MAX_IM = 1.0;
    const double REAL_INCREMENT = (MAX_RE - MIN_RE) / WIDTH;
    const double IMAG_INCREMENT = (MAX_IM - MIN_IM) / HEIGHT;

    // Declare complex number and iteration variables
    double complex z, c;
    int i;
    int j;
    int n;

    // Loop over every pixel
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            // Set initial complex number
            z = 0.0;
            c = MIN_RE + i * REAL_INCREMENT + (MIN_IM + j * IMAG_INCREMENT) * I;

            // Iterate
            for (n = 0; n < MAX_ITERATIONS; n++) {
                z = z * z + c;
                if (creal(z) * creal(z) + cimag(z) * cimag(z) > 4.0) {
                    // Escaped, set color based on number of iterations
                    int color = n % 7; // There are 7 possible colors
                    switch (color) {
                        case 0:
                            printf("#");
                            break;
                        case 1:
                            printf("A");
                            break;
                        case 2:
                            printf("B");
                            break;
                        case 3:
                            printf("C");
                            break;
                        case 4:
                            printf("D");
                            break;
                        case 5:
                            printf("E");
                            break;
                        case 6:
                            printf("F");
                            break;
                    }
                    break;
                }
            }

            if (n == MAX_ITERATIONS) {
                // Did not escape, set color as blank space
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}