//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

// Define the dimensions of the pixel art
#define ROWS 10
#define COLUMNS 10

// Define color codes for the pixel art
#define CLEAR ' '
#define BLACK '*'
#define WHITE '_'

// Function to generate a random pixel art pattern
void generatePixelArt(char art[][COLUMNS], int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            // Generate random number between 0 and 2
            int color = rand() % 3;
            if (color == 0) {
                art[i][j] = CLEAR;
            } else if (color == 1) {
                art[i][j] = BLACK;
            } else {
                art[i][j] = WHITE;
            }
        }
    }
}

// Function to print the pixel art pattern to the console
void printPixelArt(char art[][COLUMNS], int rows, int columns) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Allocate memory for the pixel art
    char pixelArt[ROWS][COLUMNS];

    // Generate a random pixel art pattern
    generatePixelArt(pixelArt, ROWS, COLUMNS);

    // Print the pixel art pattern to the console
    printPixelArt(pixelArt, ROWS, COLUMNS);

    return 0;
}