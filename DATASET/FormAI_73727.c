//FormAI DATASET v1.0 Category: Fractal Generation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define WIDTH 800 // Screen width
#define HEIGHT 800 // Screen height
#define MAX_ITER 100 // Max iterations for fractal generation

struct Complex {
    double real;
    double imag;
};

// Addition of two complex numbers
struct Complex add(struct Complex a, struct Complex b) {
    return (struct Complex) {a.real + b.real, a.imag + b.imag};
}

// Squaring of a complex number
struct Complex square(struct Complex a) {
    return (struct Complex) {a.real * a.real - a.imag * a.imag, 2.0 * a.real * a.imag};
}

// Absolute value of a complex number
double abs_value(struct Complex a) {
    return sqrt(a.real * a.real + a.imag * a.imag);
}

// Generate the fractal image
void generate_fractal(bool* pixels) {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int i = 0;
            struct Complex c = {2.0 * x / WIDTH - 1.5, 2.0 * y / HEIGHT - 1.0}; // Map pixels to complex plane
            struct Complex z = {0.0, 0.0};
            while (i < MAX_ITER && abs_value(z) < 2.0) {
                z = add(square(z), c);
                i++;
            }
            pixels[x + y * WIDTH] = i == MAX_ITER; // Set pixel color based on number of iterations
        }
    }
}

// Display the fractal image in console
void display_fractal(bool* pixels) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", pixels[x + y * WIDTH] ? ' ' : '*'); // Print pixel as blank space or asterisk
        }
        printf("\n");
    }
}

int main() {
    // Allocate memory for pixels
    bool* pixels = malloc(sizeof(bool) * WIDTH * HEIGHT);
    if (!pixels) {
        printf("Error: Failed to allocate memory for pixels\n");
        return 1;
    }

    // Generate fractal and display it in console
    generate_fractal(pixels);
    display_fractal(pixels);

    // Free allocated memory
    free(pixels);

    return 0;
}