//FormAI DATASET v1.0 Category: Fractal Generation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Define the fractal's width and height
#define WIDTH 80
#define HEIGHT 60

// Function declarations
void printFractal(int fractal[HEIGHT][WIDTH]);
void drawFractal(int fractal[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int depth);

int main() {
    // Create the fractal array and fill it with zeros
    int fractal[HEIGHT][WIDTH] = {0};

    // Draw the fractal starting from the center
    drawFractal(fractal, WIDTH/2, HEIGHT/2, WIDTH/2, HEIGHT/2, 10);

    // Print the resulting fractal
    printFractal(fractal);

    return 0;
}

// Print the fractal using ASCII characters
void printFractal(int fractal[HEIGHT][WIDTH]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (fractal[y][x] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

// Draw the fractal using recursion
void drawFractal(int fractal[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        return;
    }
    int dx = x2 - x1;
    int dy = y2 - y1;
    int x3 = x2 - dy;
    int y3 = y2 + dx;
    int x4 = x1 - dy;
    int y4 = y1 + dx;
    int x5 = (x1 + x2) / 2 + dy / 2;
    int y5 = (y1 + y2) / 2 - dx / 2;

    fractal[y3][x3] = 1;
    fractal[y4][x4] = 1;
    fractal[y5][x5] = 1;

    drawFractal(fractal, x1, y1, x4, y4, depth - 1);
    drawFractal(fractal, x4, y4, x5, y5, depth - 1);
    drawFractal(fractal, x5, y5, x3, y3, depth - 1);
    drawFractal(fractal, x3, y3, x2, y2, depth - 1);
}