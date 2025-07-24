//FormAI DATASET v1.0 Category: Fractal Generation ; Style: standalone
#include <stdio.h>

int iteration = 0; // Global variable to track iteration

// Main function to generate fractals
void generateFractal(double x, double y, double zoom, int maxIterations) {
    
    double real = 0, imaginary = 0; // Initialize real and imaginary values as 0
    double tempReal; // Temporary real value to keep track of calculation
    
    // Calculation to generate fractal
    while (iteration < maxIterations && real * real + imaginary * imaginary < 4) {
        tempReal = real * real - imaginary * imaginary + x;
        imaginary = 2 * real * imaginary + y;
        real = tempReal;
        iteration++;
    }
    
    // Print fractal character based on iteration value
    if (iteration == maxIterations) {
        printf("*");
    } else if (iteration >= maxIterations * 0.8) {
        printf("#");
    } else if (iteration >= maxIterations * 0.6) {
        printf("o");
    } else if (iteration >= maxIterations * 0.4) {
        printf("+");
    } else if (iteration >= maxIterations * 0.2) {
        printf("-");
    } else {
        printf(" ");
    }
    
    // Reset iteration value
    iteration = 0;
    
    // Recursively call generateFractal function with updated values
    if (zoom > 1) {
        generateFractal(x, y, zoom / 2, maxIterations);
        generateFractal(x, y + zoom / 2, zoom / 2, maxIterations);
        generateFractal(x + zoom / 2, y, zoom / 2, maxIterations);
        generateFractal(x + zoom / 2, y + zoom / 2, zoom / 2, maxIterations);
    }
}

int main() {
    
    int width = 80, height = 40; // Set terminal width and height
    double x, y; // Initialize x and y values
    
    // Loop through each row and column to generate fractal
    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            x = ((double) col - width / 2) * 4.0 / width;
            y = ((double) row - height / 2) * 4.0 / width;
            generateFractal(x, y, 2.0, 50);
        }
        printf("\n"); // Print new line after each row
    }
    
    return 0;
}