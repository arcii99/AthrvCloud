//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 20
#define WIDTH 20

int main() {
    // Set seed for random number generation
    srand(time(NULL));

    // Initialize array for pixel art
    char pixelArt[HEIGHT][WIDTH];

    // Fill array with random characters to represent pixels
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            // Generate a random number between 0-9
            int randNum = rand() % 10;

            // Assign random character based on number
            if(randNum < 2) {
                pixelArt[row][col] = '0';
            }
            else {
                pixelArt[row][col] = '1';
            }
        }
    }

    // Print out pixel art
    for(int row = 0; row < HEIGHT; row++) {
        for(int col = 0; col < WIDTH; col++) {
            printf("%c", pixelArt[row][col]);
        }
        printf("\n");
    }

    return 0;
}