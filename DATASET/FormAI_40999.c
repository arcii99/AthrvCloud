//FormAI DATASET v1.0 Category: Fractal Generation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// Define the maximum number of iterations
#define MAX_ITERATIONS 500

// Define the size of the buffer used for file names
#define FILE_NAME_BUFFER_SIZE 50

// Define the size of the fractal image
#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT 600

// Define the range of the fractal
#define MIN_X -2
#define MAX_X 2
#define MIN_Y -1.5
#define MAX_Y 1.5

// Define the maximum length of the sequence
#define MAX_SEQUENCE_LENGTH 100

// Define the color of the fractal
#define RED 255
#define GREEN 255
#define BLUE 255

// Define the type of the color
typedef struct {
    int red;
    int green;
    int blue;
} Color;

// Define the type of the sequence
typedef struct {
    int length;
    int sequence[MAX_SEQUENCE_LENGTH];
} Sequence;

// Define the function to generate the next complex number in the sequence
void next_complex_number(double *x, double *y, double real, double imaginary) {
    double xtemp = *x;
    *x = xtemp * xtemp - imaginary * imaginary + real;
    *y = 2 * xtemp * imaginary + imaginary;
}

// Define the function to calculate the color of a point in the fractal
Color calculate_color(int sequence_length, Sequence sequence) {
    Color color;
    if (sequence_length == MAX_ITERATIONS) {
        color.red = 0;
        color.green = 0;
        color.blue = 0;
    } else {
        color.red = RED;
        color.green = GREEN;
        color.blue = BLUE;
    }
    return color;
}

// Define the function to generate the fractal
void generate_fractal(char *file_name) {
    // Declare variables
    double x, y, real, imaginary;
    int i, j, sequence_length;
    Sequence sequence;
    Color color;
    FILE *file_ptr;

    // Open the file for writing
    file_ptr = fopen(file_name, "wb");

    // Calculate the real and imaginary values for each pixel in the image
    for (i = 0; i < IMAGE_HEIGHT; i++) {
        for (j = 0; j < IMAGE_WIDTH; j++) {
            real = (double) j / IMAGE_WIDTH * (MAX_X - MIN_X) + MIN_X;
            imaginary = (double) i / IMAGE_HEIGHT * (MAX_Y - MIN_Y) + MIN_Y;

            // Initialize the sequence to the first complex number
            x = 0;
            y = 0;
            sequence.length = 0;

            // Generate the sequence
            for (sequence_length = 0; sequence_length < MAX_ITERATIONS; sequence_length++) {
                sequence.sequence[sequence_length] = (int) trunc(x * 10);
                if (sequence_length >= 1 && sequence.sequence[sequence_length] == sequence.sequence[sequence_length - 1]) {
                    break;
                }
                next_complex_number(&x, &y, real, imaginary);
            }

            // Calculate the color
            color = calculate_color(sequence_length, sequence);

            // Write the color to the file
            fwrite(&color.red, sizeof(unsigned char), 1, file_ptr);
            fwrite(&color.green, sizeof(unsigned char), 1, file_ptr);
            fwrite(&color.blue, sizeof(unsigned char), 1, file_ptr);
        }
    }

    // Close the file
    fclose(file_ptr);
}

int main() {
    // Declare variable
    char file_name[FILE_NAME_BUFFER_SIZE];

    // Seed the random number generator
    srand(time(NULL));

    // Generate the fractal
    sprintf(file_name, "fractal_%d.bmp", rand());
    generate_fractal(file_name);

    // Display the file name
    printf("%s\n", file_name);

    return 0;
}