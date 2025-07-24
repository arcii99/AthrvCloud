//FormAI DATASET v1.0 Category: Fractal Generation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>

#define MAX_ITERATIONS 100
#define IMAGE_WIDTH 100
#define IMAGE_HEIGHT 50
#define X_MIN -2
#define X_MAX 1
#define Y_MIN -1
#define Y_MAX 1

// Function to create a 2D array of complex numbers
complex double** create_complex_array(int m, int n) {
    complex double** arr = (complex double**)malloc(m * sizeof(complex double*));
    for (int i = 0; i < m; i++) {
        arr[i] = (complex double*)malloc(n * sizeof(complex double));
    }
    return arr;
}

// Function to free memory allocated to a 2D array
void free_complex_array(complex double** arr, int m) {
    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
}

// Function to generate the Mandelbrot set fractal
void generate_mandelbrot_set(int** image, complex double** c_values) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            complex double c = c_values[i][j];
            complex double z = 0;
            int k = 0;
            while (cabs(z) <= 2 && k < MAX_ITERATIONS) {
                z = z * z + c;
                k++;
            }
            image[i][j] = k;
        }
    }
}

// Function to print the Mandelbrot set fractal in ASCII art
void print_mandelbrot_set(int** image) {
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            int k = image[i][j];
            if (k < MAX_ITERATIONS) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    complex double** c_values = create_complex_array(IMAGE_HEIGHT, IMAGE_WIDTH);
    int** image = (int**)malloc(IMAGE_HEIGHT * sizeof(int*));
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        image[i] = (int*)malloc(IMAGE_WIDTH * sizeof(int));
    }

    // Generate complex values for each pixel in the image
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        for (int j = 0; j < IMAGE_WIDTH; j++) {
            double x = X_MIN + (X_MAX - X_MIN) / IMAGE_WIDTH * j;
            double y = Y_MIN + (Y_MAX - Y_MIN) / IMAGE_HEIGHT * i;
            c_values[i][j] = x + y * I;
        }
    }

    // Generate the Mandelbrot set fractal
    generate_mandelbrot_set(image, c_values);

    // Print the Mandelbrot set fractal in ASCII art
    print_mandelbrot_set(image);

    // Free memory allocated to arrays
    free_complex_array(c_values, IMAGE_HEIGHT);
    for (int i = 0; i < IMAGE_HEIGHT; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}