//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for width and height of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define constants for colors
#define BLACK ' '
#define WHITE '@'

// Function to randomly generate black or white pixels
char generatePixel() {
    int randomNum = rand() % 2;
    if (randomNum == 0) {
        return BLACK;
    } else {
        return WHITE;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a 2D array to hold the pixel art
    char pixelArt[WIDTH][HEIGHT];

    // Generate the pixel art
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            char pixel = generatePixel();
            pixelArt[row][col] = pixel;
        }
    }

    // Print the pixel art
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            printf("%c ", pixelArt[row][col]);
        }
        printf("\n");
    }

    return 0;
}