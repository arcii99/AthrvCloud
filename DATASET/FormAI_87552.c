//FormAI DATASET v1.0 Category: Fractal Generation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

void generate_fractal(double complex c, int width, int height, int max_iterations) {
    int x, y, i;
    double complex z, z_next;

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            z = ((double)x - width/2) / ((double)width / 4) + 
                ((double)y - height/2) / ((double)height / 4) * I;
            i = 0;

            do {
                z_next = z * z + c;
                z = z_next;
                i++;
            } while (i < max_iterations && cabs(z) < 4);

            if (i < max_iterations) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    double complex c = -0.8 + 0.156 * I;
    int width = 80;
    int height = 40;
    int max_iterations = 100;

    generate_fractal(c, width, height, max_iterations);

    return 0;
}