//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the pixel art (width and height)
#define WIDTH 20
#define HEIGHT 10

// Define the proportion of black pixels (from 0 to 1)
#define BLACK_PROPORTION 0.3

// Define the character to print for black and white pixels
#define BLACK_CHAR 'X'
#define WHITE_CHAR ' '

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Create the pixel art array
    char pixels[WIDTH][HEIGHT];

    // Fill the array with white pixels
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            pixels[x][y] = WHITE_CHAR;
        }
    }

    // Add black pixels randomly
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            if ((double)rand()/(double)RAND_MAX < BLACK_PROPORTION) {
                pixels[x][y] = BLACK_CHAR;
            }
        }
    }

    // Display the pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c", pixels[x][y]);
        }
        printf("\n");
    }

    return 0;
}