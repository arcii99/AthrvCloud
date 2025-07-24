//FormAI DATASET v1.0 Category: Fractal Generation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 100
#define HEIGHT 50

typedef struct {
    float real, imag;
} Complex;

bool isInside(Complex c, float bailout) {
    Complex z = {0, 0};
    for (int i = 0; i < 100; i++) {
        Complex temp = {(z.real * z.real) - (z.imag * z.imag) + c.real,
                        (2 * z.real * z.imag) + c.imag};
        z = temp;
        if (sqrt((z.real * z.real) + (z.imag * z.imag)) > bailout) {
            return false;
        }
    }
    return true;
}

int main() {
    char fractal[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            Complex c = {((float) j / WIDTH) * 4 - 2,
                         ((float) i / HEIGHT) * 4 - 2};
            if (isInside(c, 2)) {
                fractal[i][j] = '-';
            } else {
                fractal[i][j] = 'x';
            }
        }
    }

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", fractal[i][j]);
        }
        printf("\n");
    }

    return 0;
}