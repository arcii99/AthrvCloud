//FormAI DATASET v1.0 Category: Fractal Generation ; Style: multivariable
#include <stdio.h>
#include <math.h>

// Recursive function to generate fractals
void generateFractal(int x, int y, int depth, int size, int color) {
    if (depth == 0) {
        // Base case: draw a square
        printf("Draw square at (%d, %d) with size %d and color %d\n", x, y, size, color);
    } else {
        // Recursive case: split into four smaller squares
        int newSize = size / 2;
        int newColor = (color + 1) % 4;
        generateFractal(x - newSize, y - newSize, depth - 1, newSize, newColor);
        generateFractal(x + newSize, y - newSize, depth - 1, newSize, newColor);
        generateFractal(x - newSize, y + newSize, depth - 1, newSize, newColor);
        generateFractal(x + newSize, y + newSize, depth - 1, newSize, newColor);
    }
}

int main() {
    // Initialize variables
    int x = 0;
    int y = 0;
    int depth = 4;
    int size = 32;
    int color = 0;
    
    // Call recursive function to generate fractal
    generateFractal(x, y, depth, size, color);
    
    return 0;
}