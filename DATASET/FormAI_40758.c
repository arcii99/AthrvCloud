//FormAI DATASET v1.0 Category: Fractal Generation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

void print_fractal(int *fractal_data, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%c ", fractal_data[i * width + j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main() {
    const int width = 80;
    const int height = 40;
    const double x_center = -0.5;
    const double y_center = 0.0;
    const double zoom = 2.0;
    const int max_iterations = 100;

    int *fractal_data = malloc(width * height * sizeof(int));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double complex c = (j - width / 2.0) / (width / 2.0 / zoom) + (i - height / 2.0) / (height / 2.0 / zoom) * I;
            double complex z = c;

            int iterations;
            for (iterations = 0; iterations < max_iterations && cabs(z) < 2.0; iterations++) {
                z = z * z + c;
            }

            fractal_data[i * width + j] = cabs(z) >= 2.0 ? 1 : 0;
        }
    }

    print_fractal(fractal_data, width, height);

    free(fractal_data);
    return 0;
}