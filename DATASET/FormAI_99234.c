//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24
#define MAX_ITERATIONS 1000

// Function to check if a complex number is in the main cardioid
bool inCardioid(double complex c) {
    double q = (creal(c) - 0.25) * (creal(c) - 0.25) + cimag(c) * cimag(c);
    return q * (q + (creal(c) - 0.25)) < 0.25 * cimag(c) * cimag(c);
}

// Function to check if a complex number is in a period-2 bulb
bool inBulb(double complex c) {
    double complex z0 = c;
    for (int i = 0; i < 3; i++) {
        z0 = z0 * z0 + c;
    }
    return cabs(z0 - 0.5 - 0.8660254 * I) < 0.01;
}

// Function to calculate the color of a pixel
int calculateColor(double complex c) {
    double complex z = 0;
    int i;
    for (i = 0; i < MAX_ITERATIONS; i++) {
        z = z * z + c;
        if (cabs(z) > 2) {
            break;
        }
    }

    if (i == MAX_ITERATIONS) {
        return 232;
    }
    else {
        double smoothColor = i - log(log(cabs(z))) / log(2);
        return 16 + (int)(smoothColor * 36 / MAX_ITERATIONS);
    }
}

int main() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            double complex c = ((double)x - WIDTH / 2) / (WIDTH / 4.0) +
                ((double)y - HEIGHT / 2) / (HEIGHT / 4.0) * I;

            if (inCardioid(c) || inBulb(c)) {
                printf("\033[38;5;232m ");
            }
            else {
                int color = calculateColor(c);
                printf("\033[38;5;%dm█", color);
            }

        }
        printf("\033[0m\n");
    }
    return 0;
}