//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <complex.h>

#define WIDTH 100
#define HEIGHT 50

bool is_point_in_set(double complex c);

int main() {
    int x, y;
    double complex c;
    char result[WIDTH * HEIGHT + HEIGHT + 1];

    for (y = 0; y < HEIGHT; ++y) {
        for (x = 0; x < WIDTH; ++x) {
            c = (2.0 * x - WIDTH) / WIDTH + (2.0 * y - HEIGHT) / HEIGHT * I;
            result[y * WIDTH + x] = is_point_in_set(c) ? '#' : ' ';
        }
        result[y * WIDTH + x] = '\n';
    }
    result[y * WIDTH + x] = '\0';

    printf("%s", result);

    return EXIT_SUCCESS;
}

bool is_point_in_set(double complex c) {
    double complex z = c;
    int i;

    for (i = 0; i < 1000; ++i) {
        z = z * z + c;
        if (cabs(z) > 2.0) {
            return false;
        }
    }

    return true;
}