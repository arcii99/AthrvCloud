//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Cyberpunk
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 160
#define HEIGHT 45

typedef struct {
    float real;
    float imag;
} complex;

int main() {
    bool fractal[WIDTH * HEIGHT] = {false}; // initialize all values to false
    complex c;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            c.real = (i - WIDTH / 2.0) * 4.0 / WIDTH; // map pixel to complex number
            c.imag = (j - HEIGHT / 2.0) * 4.0 / WIDTH;

            int iterations = 0;
            complex z = c;
            while (iterations < 100) { // escape time algorithm
                z = (complex) {pow(z.real, 2) - pow(z.imag, 2) + c.real, 2 * z.real * z.imag + c.imag};
                if (sqrt(pow(z.real, 2) + pow(z.imag, 2)) > 2) break;
                iterations++;
            }

            fractal[j * WIDTH + i] = (iterations == 100) ? true : false; // determine if pixel is part of fractal
        }
    }

    for (int j = 0; j < HEIGHT; j++) { // render fractal to screen
        for (int i = 0; i < WIDTH; i++) {
            printf(fractal[j * WIDTH + i] ? "•" : " "); // use cyberpunk-style bullet points to represent fractal
        }
        printf("\n");
    }

    return 0;
}