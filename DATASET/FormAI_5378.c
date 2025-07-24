//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

// Define constants
#define WIDTH 120
#define HEIGHT 60
#define MAX_ITER 50

// Define global variables
char image[HEIGHT][WIDTH];

// Function to check if a point is within the set
bool isInSet(double x, double y) {
    double real = x;
    double imag = y;
    for (int i = 0; i < MAX_ITER; i++) {
        double r2 = real * real;
        double i2 = imag * imag;
        if (r2 + i2 > 4.0) {
            return false;
        }
        imag = 2.0 * real * imag + y;
        real = r2 - i2 + x;
    }
    return true;
}

// Function to generate the fractal
void generateFractal() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            double x = col * 4.0 / WIDTH - 2.0;
            double y = row * 4.0 / HEIGHT - 2.0;
            if (isInSet(x, y)) {
                image[row][col] = '.';
            } else {
                image[row][col] = '#';
            }
        }
    }
}

// Function to print the image
void printImage() {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c", image[row][col]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    generateFractal();
    printImage();
    return 0;
}