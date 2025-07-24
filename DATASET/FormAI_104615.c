//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define MAX_ITER 1000

typedef struct Complex_t {
    double real;
    double imag;
} Complex;
 
Complex square(Complex z) {
    Complex res;
    res.real = (z.real * z.real) - (z.imag * z.imag);
    res.imag = 2 * z.real * z.imag;
    return res;
}
 
int isMandelbrot(Complex c) {
    Complex z = {0, 0};
    int iter = 0;
    while (iter < MAX_ITER) {
        z = square(z);
        z.real += c.real;
        z.imag += c.imag;
        if (sqrt((z.real * z.real) + (z.imag * z.imag)) > 2) {
            return 0;
        }
        iter++;
    }
    return 1;
}
 
int main() {
    int rx = 80; // Screen resolution x
    int ry = 24; // Screen resolution y
    double px = 3.0 / rx; // Pixel width
    double py = 2.4 / ry; // Pixel height
    int pxSize = ceil(px / 0.1); // Make pixel big enough to be seen
 
    Complex c;
    c.imag = -1.2;
 
    for (int y = 0; y < ry; y++) {
        c.real = -2.0;
        for (int x = 0; x < rx; x++) {
            if (isMandelbrot(c)) {
                printf(" ");
            } else {
                for (int i = 0; i < pxSize; i++) {
                    printf("*");
                }
                x += pxSize - 1;
            }
            c.real += px;
        }
        c.imag += py;
        printf("\n");
    }
 
    return 0;
}