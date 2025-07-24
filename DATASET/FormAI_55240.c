//FormAI DATASET v1.0 Category: Fractal Generation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_ITERATIONS 500
#define ZOOM 250
#define WIDTH 120
#define HEIGHT 50

typedef struct Complex {
    double real;
    double imag;
} Complex;

int getIterations(Complex c) {
    int i;
    Complex z;
    double temp;

    z.real = z.imag = 0;

    for (i = 0; i < MAX_ITERATIONS; i++) {
        temp = z.real * z.real - z.imag * z.imag + c.real;
        z.imag = 2 * z.real * z.imag + c.imag;
        z.real = temp;

        if (z.real * z.real + z.imag * z.imag > 4) {
            return i;
        }
    }

    return MAX_ITERATIONS;
}

void generateFractal(char *image, double x, double y, double zoom) {
    int i, j, index;
    Complex c;
    int iterations;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            c.real = x - WIDTH / 2.0 * zoom / ZOOM + ((double)j) * zoom / ZOOM;
            c.imag = y - HEIGHT / 2.0 * zoom / ZOOM + ((double)i) * zoom / ZOOM;
            iterations = getIterations(c);

            index = i * WIDTH + j;

            if (iterations == MAX_ITERATIONS) {
                strcat(image, " ");
            }
            else if (iterations > 10) {
                strcat(image, ".");
            }
            else if (iterations > 5) {
                strcat(image, "*");
            }
            else {
                strcat(image, "#");
            }
        }

        strcat(image, "\n");
    }
}

int main() {
    char *image = malloc(WIDTH * (HEIGHT + 1) + 1);

    generateFractal(image, -0.5, 0, 3);
    printf("%s", image);

    free(image);

    return 0;
}