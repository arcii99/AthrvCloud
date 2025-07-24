//FormAI DATASET v1.0 Category: Fractal Generation ; Style: all-encompassing
#include <stdio.h>
#include <math.h>
#include <complex.h>

int WIDTH = 800;
int HEIGHT = 800;

// Function to calculate the color of a point based on its escape time
int color(int escape_time) {
    int MAX_ITERATIONS = 255;
    return (int)((double)escape_time / MAX_ITERATIONS * 255);
}

// Function to generate a Mandelbrot set
void mandelbrot(double complex c, int max_iterations, int *escape_time) {
    double complex z = 0;
    *escape_time = 0;

    while (*escape_time < max_iterations && cabs(z) < 2) {
        z = z * z + c;
        *escape_time += 1;
    }
}

// Function to generate the fractal
void generateFractal(int (*pixel_array)[WIDTH]) {
    double complex c;
    int escape_time;

    int MAX_ITERATIONS = 255;

    double zoom = 1;
    int shift_x = 0;
    int shift_y = 0;

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {

            // Calculate the complex number that corresponds to the current pixel
            c = ((double) j - WIDTH / 2) / WIDTH * 4.0 / zoom + shift_x / (double) WIDTH
                + (((double) i - HEIGHT / 2) / HEIGHT * 4.0 / zoom + shift_y / (double) HEIGHT) * I;

            // Generate the Mandelbrot set for the current pixel
            mandelbrot(c, MAX_ITERATIONS, &escape_time);

            // Assign the color to the current pixel based on the escape time of the Mandelbrot set
            pixel_array[i][j] = color(escape_time);
        }
    }
}

int main() {

    // Allocate memory for the pixel array
    int (*pixel_array)[WIDTH] = calloc(HEIGHT, WIDTH * sizeof(int));

    // Generate the fractal
    generateFractal(pixel_array);

    // Print the pixel array in PPM format for visualization
    printf("P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d %d %d ", pixel_array[i][j], pixel_array[i][j], pixel_array[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the pixel array
    free(pixel_array);

    return 0;
}