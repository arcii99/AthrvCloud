//FormAI DATASET v1.0 Category: Fractal Generation ; Style: medieval
#include <stdio.h>
#include <math.h>

#define SIZE 256

void generate_fractal(char canvas[SIZE][SIZE], double real_min, double real_max, double imag_min, double imag_max) {
    double real_step = (real_max - real_min) / SIZE;
    double imag_step = (imag_max - imag_min) / SIZE;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            double real = real_min + i * real_step;
            double imag = imag_min + j * imag_step;

            double z_real = real;
            double z_imag = imag;
            int iterations = 0;

            while (z_real * z_real + z_imag * z_imag < 4 && iterations < 100) {
                double new_z_real = z_real * z_real - z_imag * z_imag + real;
                double new_z_imag = 2 * z_real * z_imag + imag;

                z_real = new_z_real;
                z_imag = new_z_imag;

                iterations++;
            }

            if (iterations == 100) {
                canvas[i][j] = '#'; // Color point black if in set
            } else {
                canvas[i][j] = '.'; // Color point white if not in set
            }
        }
    }
}

void print_canvas(char canvas[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char canvas[SIZE][SIZE];

    // Set initial canvas to all white space
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Generate fractal on canvas
    generate_fractal(canvas, -2.0, 1.0, -1.5, 1.5);

    // Print canvas
    print_canvas(canvas);

    return 0;
}