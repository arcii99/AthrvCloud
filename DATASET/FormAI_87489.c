//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define the full range of ASCII characters that we can use for our pixel art
#define ASCII_MIN 33 // '!' in ASCII
#define ASCII_MAX 126 // '~' in ASCII

char pixelArt[HEIGHT][WIDTH]; // Initialize the 2D array to store the pixel art

// Function to generate random ASCII characters within our range
char generateChar() {
    return (char)(rand() % (ASCII_MAX - ASCII_MIN + 1) + ASCII_MIN);
}

int main() {

    // Generate a seed for the random number generator
    srand(time(NULL));

    // Loop through the height and width of the pixel art array and populate it with random characters
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = generateChar();
        }
    }

    // Print out the generated pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}