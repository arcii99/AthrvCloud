//FormAI DATASET v1.0 Category: Fractal Generation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

#define WIDTH 1000
#define HEIGHT 1000
#define MAX_ITER 1000

// Define our colors
#define BLACK       "\033[0;30m"
#define RED         "\033[0;31m"
#define GREEN       "\033[0;32m"
#define YELLOW      "\033[0;33m"
#define BLUE        "\033[0;34m"
#define MAGENTA     "\033[0;35m"
#define CYAN        "\033[0;36m"
#define WHITE       "\033[0;37m"
#define RESET_COLOR "\033[m"

void fractal_gen(int **image, double real_min, double real_max, double imag_min, double imag_max) {
    double complex c, z;
    int i, j, iter;
    double real, imag, real_diff, imag_diff, magnitude;
    double escape_radius = 10.0;
    int color;
    double hue;

    real_diff = (real_max - real_min) / (double)WIDTH;
    imag_diff = (imag_max - imag_min) / (double)HEIGHT;

    // Traverse the image
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            real = real_min + j * real_diff;
            imag = imag_max - i * imag_diff; // Flip y-axis to match math coordinates

            c = real + imag * I;
            z = 0.0 + 0.0 * I;
            iter = 0;

            // Iterate until we reach the maximum iterations or escape radius
            while (iter < MAX_ITER && cabs(z) < escape_radius) {
                z = z * z + c;
                iter++;
            }

            // Set pixel color based on escape time
            if (iter == MAX_ITER) {
                color = 0; // Black
            } else {
                magnitude = cabs(z) * log10(iter); // Logarithmic color interpolation
                hue = fmod((360.0 + log10(magnitude)) * 10.0, 360.0) / 60.0; // Rainbow color cycling
                color = hue;

                // Convert color to ANSI color code
                switch (color) {
                    case 0:
                        printf(BLACK);
                        break;
                    case 1:
                        printf(RED);
                        break;
                    case 2:
                        printf(GREEN);
                        break;
                    case 3:
                        printf(YELLOW);
                        break;
                    case 4:
                        printf(BLUE);
                        break;
                    case 5:
                        printf(MAGENTA);
                        break;
                    default:
                        printf(CYAN);
                        break;
                }
            }

            image[i][j] = color;
        }

        // Reset console color and print progress
        printf(RESET_COLOR);
        printf("Rendering: %d%%\r", (int)(100.0 * i / HEIGHT));
        fflush(stdout);
    }

    // Print final progress
    printf(RESET_COLOR);
    printf("Rendering: 100%%\n");
}

int main() {
    int **image = (int **)malloc(HEIGHT * sizeof(int *));
    int i, j;

    // Allocate memory for the image
    for (i = 0; i < HEIGHT; i++) {
        image[i] = (int *)malloc(WIDTH * sizeof(int));
    }

    // Generate the fractal
    fractal_gen(image, -2.0, 1.0, -1.5, 1.5);

    // Print the image to console
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (image[i][j] == 0) {
                printf(" ");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }

    // Free the memory
    for (i = 0; i < HEIGHT; i++) {
        free(image[i]);
    }

    free(image);

    return 0;
}