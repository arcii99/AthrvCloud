//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
// Program to generate a grateful fractal 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 1600  // Width of the image
#define HEIGHT 900  // Height of the image

// Complex number struct
typedef struct complex_num {
    double real;
    double imag;
} complex_num;

// Function to calculate the squared modulus of complex number
double modulus_squared(complex_num num) {
    return (num.real*num.real) + (num.imag*num.imag);
}

// Function to add two complex numbers
complex_num add_complex(complex_num a, complex_num b) {
    return (complex_num) {a.real + b.real, a.imag + b.imag};
}

// Function to multiply two complex numbers
complex_num multiply_complex(complex_num a, complex_num b) {
    return (complex_num) {a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real};
}

// Function to generate the fractal
void generate_fractal(int max_iter, complex_num c) {

    // Image array to store pixel values
    int image[WIDTH][HEIGHT] = {{0}};

    // Loop through every pixel in the image
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {

            // Convert x and y to the corresponding complex number
            complex_num z = (complex_num) {-2.5 + 4.0*x/WIDTH, -2.5 + 4.0*y/HEIGHT};

            // Iterate until modulus of z becomes greater than 2 or max iterations are done
            int iter = 0;
            while (modulus_squared(z) < 4 && iter < max_iter) {
                z = add_complex(multiply_complex(z, z), c);
                iter++;
            }

            // Set the pixel value based on the number of iterations
            if (iter == max_iter)
                image[x][y] = 0;
            else
                image[x][y] = (int)(iter*(255.0/max_iter));
        }
    }

    // Create PPM file to store the image
    FILE *f = fopen("grateful_fractal.ppm", "wb");
    fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fprintf(f, "%d %d %d ", image[x][y], image[x][y], image[x][y]);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    printf("Fractal generation complete. Check grateful_fractal.ppm file for the output.\n");
}

int main(void) {

    // Use current time as seed for random number generator
    srand(time(NULL));

    // Generate random complex number for the fractal
    double real_part = ((double)rand() / (double)RAND_MAX) * 4 - 2;
    double imag_part = ((double)rand() / (double)RAND_MAX) * 4 - 2;
    complex_num c = (complex_num) {real_part, imag_part};

    printf("Generating grateful fractal with c = %lf + %lfi...\n", c.real, c.imag);

    // Generate the fractal with max iterations set to 200
    generate_fractal(200, c);

    return 0;
}