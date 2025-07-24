//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define the number of colors available
#define NUM_COLORS 4

// Define the characters to use for each color
#define COLOR_CHARS "RGBA"

int main() {
    // Set the random seed for generating the pixel art
    srand(time(NULL));

    // Create the array to store the pixel art
    char pixelArt[HEIGHT][WIDTH];

    // Fill the array with random colors
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            // Get a random color index
            int colorIndex = rand() % NUM_COLORS;
            // Get the character for the color and store it in the pixel art array
            pixelArt[i][j] = COLOR_CHARS[colorIndex];
        }
    }

    // Print the pixel art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}