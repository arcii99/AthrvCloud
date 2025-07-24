//FormAI DATASET v1.0 Category: Fractal Generation ; Style: safe
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_ITERATIONS 20

typedef struct {
    double real;
    double imag;
} complex_number;

// Function to create a complex number from two double values (real and imaginary part)
complex_number create_complex_number(double real, double imag) {
    complex_number c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Function to calculate the absolute value of a complex number
double absolute_value(complex_number c) {
    return sqrt(c.real * c.real + c.imag * c.imag);
}

// Function to perform the Mandelbrot iteration on a complex number
int mandelbrot_iteration(complex_number c) {
    int i;
    complex_number z = create_complex_number(0, 0);
    for (i = 0; i < MAX_ITERATIONS; i++) {
        if (absolute_value(z) > 2) {
            return i;
        }
        complex_number z_next = create_complex_number(z.real * z.real - z.imag * z.imag + c.real,
                                                      2 * z.real * z.imag + c.imag);
        z = z_next;
    }
    return MAX_ITERATIONS;
}

int main() {
    // Initializing the ASCII art buffer to all spaces
    char ascii_art_buffer[WIDTH * HEIGHT];
    memset(ascii_art_buffer, ' ', WIDTH * HEIGHT);

    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            // Transforming coordinates from pixel space to complex number space
            double real = (x - WIDTH / 2) * 4.0 / WIDTH;
            double imag = (y - HEIGHT / 2) * 4.0 / WIDTH;
            complex_number c = create_complex_number(real, imag);
            
            // Performing the Mandelbrot iteration on the complex number
            int iteration = mandelbrot_iteration(c);
            
            // Mapping the iteration count to a character in the ASCII art buffer
            char character;
            if (iteration == MAX_ITERATIONS) {
                character = '*';
            } else if (iteration > MAX_ITERATIONS / 2) {
                character = '+';
            } else if (iteration > MAX_ITERATIONS / 4) {
                character = '-';
            } else {
                character = ' ';
            }
            
            // Storing the character in the ASCII art buffer
            ascii_art_buffer[y * WIDTH + x] = character;
        }
    }

    // Printing the ASCII art buffer to the console
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            printf("%c", ascii_art_buffer[y * WIDTH + x]);
        }
        printf("\n");
    }

    return 0;
}