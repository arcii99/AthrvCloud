//FormAI DATASET v1.0 Category: Fractal Generation ; Style: thoughtful
#include <stdio.h>
#define WIDTH 80
#define HEIGHT 80

// Function to calculate the fractal value at each pixel
int calculateFractalValue(double real, double imaginary) {
    // The fractal algorithm goes here
    int value = 0;
    double zx = 0, zy = 0, temp, lengthsq;
    const int max_iterations = 255; // Maximum number of iterations allowed

    for (int i = 0; i < max_iterations && lengthsq < 4; i++) {
        temp = zx * zx - zy * zy + real;    // Calculate the real part of the next iteration
        zy = 2 * zx * zy + imaginary;       // Calculate the imaginary part of the next iteration
        zx = temp;
        lengthsq = zx * zx + zy * zy;        // Calculate the length of the current iteration squared
        value = i;
    }
    return value;
}

// Function to print the fractal to the console
void printFractal(int fractal[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (fractal[y][x] < 128) {
                printf(" ");                  // Use a space for low values
            } else if (fractal[y][x] < 200) {
                printf(".");                  // Use a dot for medium values
            } else {
                printf("#");                  // Use a pound sign for high values
            }
        }
        printf("\n");
    }
}

int main() {
    int fractal[HEIGHT][WIDTH];               // 2D array to store the values of the fractal at each pixel
    double xPos, yPos;
    
    // Iterate over each pixel in the fractal
    for (int y = 0; y < HEIGHT; y++) {
        yPos = 1.25 - y * 2.5 / HEIGHT;
        for (int x = 0; x < WIDTH; x++) {
            xPos = -2.5 + x * 3.5 / WIDTH;
            fractal[y][x] = calculateFractalValue(xPos, yPos);   // Calculate the value of the fractal at this point
        }
    }

    printFractal(fractal);      // Print the fractal to the console
    
    return 0;                   // End of program
}