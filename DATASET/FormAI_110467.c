//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the canvas
#define WIDTH 50
#define HEIGHT 30

// Function to recursively generate pixel art
void generatePixelArt(char canvas[HEIGHT][WIDTH], int startX, int startY, int endX, int endY) {
    // Base case: if the section is too small to draw, return
    if (endX - startX < 2 || endY - startY < 2) {
        return;
    }

    // Choose a random color for the section
    char color = rand() % 26 + 'A';

    // Draw the borders of the section with the color
    for (int i = startX; i <= endX; i++) {
        canvas[startY][i] = color;
        canvas[endY][i] = color;
    }
    for (int i = startY; i <= endY; i++) {
        canvas[i][startX] = color;
        canvas[i][endX] = color;
    }

    // Recursively call the function with the four smaller sections
    int midX = startX + (endX - startX) / 2;
    int midY = startY + (endY - startY) / 2;
    generatePixelArt(canvas, startX, startY, midX, midY);
    generatePixelArt(canvas, midX, startY, endX, midY);
    generatePixelArt(canvas, startX, midY, midX, endY);
    generatePixelArt(canvas, midX, midY, endX, endY);
}

// Function to print the canvas
void printCanvas(char canvas[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", canvas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the canvas with blank spaces
    char canvas[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            canvas[i][j] = ' ';
        }
    }

    // Generate the pixel art recursively
    generatePixelArt(canvas, 0, 0, WIDTH - 1, HEIGHT - 1);

    // Print the canvas
    printCanvas(canvas);

    return 0;
}