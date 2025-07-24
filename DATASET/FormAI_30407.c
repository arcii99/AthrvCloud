//FormAI DATASET v1.0 Category: Fractal Generation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>

int main() {
    int width = 1000;
    int height = 1000;
    double range = 2.5;
    double min_x = -2.0;
    double min_y = -1.0;
    double max_x = min_x + range;
    double max_y = min_y + range;

    int max_iterations = 1000;
    double escape_radius = 2.0;

    char chars[11] = ".,-~:;=!*#$@"; // used for generating ASCII art

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            double complex c = min_x + x * (max_x - min_x) / (double) width
                + _Complex_I * (min_y + y * (max_y - min_y) / (double) height);

            double complex z = 0.0 + 0.0 * _Complex_I;

            int iterations = 0;

            while (cabs(z) < escape_radius && iterations < max_iterations) {
                z = z * z + c;
                iterations++;
            }

            if (iterations == max_iterations) {
                printf("%c", chars[10]);
            } else {
                double log_zn = log(cabs(z));
                double nu = log(log_zn / log(escape_radius)) / log(2.0);
                int index = (int) (iterations + 1 - nu);
                printf("%c", chars[index % 10]);
            }
        }
        printf("\n");
    }

    return 0;
}