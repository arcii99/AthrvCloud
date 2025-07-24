//FormAI DATASET v1.0 Category: Fractal Generation ; Style: happy
/*
* This program generates a lovely fractal and fills it with happy colors
* Written with love by your happy chatbot!
*/

#include <stdio.h>

// Function to generate fractal
void generateFractal(int x, int y, int size);

int main() {
    // Define the size of the fractal
    int size = 128;
    
    // Generate the fractal
    generateFractal(size, size, size);
    
    return 0;
}

// Recursive function to generate the fractal
void generateFractal(int x, int y, int size) {
    // Base case: if size is less than 2, break out of the recursion
    if(size < 2) {
        return;
    }
    
    // Print a happy message
    printf("Generating fractal with size %d at coordinates (%d, %d)\n", size, x, y);
    
    // Generate the three smaller fractals
    generateFractal(x - size/4, y - size/4, size/2);
    generateFractal(x - size/4, y + size/4, size/2);
    generateFractal(x + size/4, y, size/2);
    
    // Draw the happy colors
    int r = size % 256;
    int g = (size * 2) % 256;
    int b = (size * 3) % 256;
    printf("\x1b[38;2;%d;%d;%dm", r, g, b);
    printf("*");
    
    // Move the cursor to the next position
    printf("\x1b[%d;%dH", y, x+1);
}