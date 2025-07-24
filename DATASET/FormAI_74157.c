//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Set the size of the canvas
    const int WIDTH = 8;
    const int HEIGHT = 8;

    // Set the characters to be used for pixel art
    const char PIXEL_ON = 'X';
    const char PIXEL_OFF = '-';

    // Seed the random number generator
    srand(time(NULL));

    // Generate random pixel art
    char pixelArt[WIDTH][HEIGHT];

    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            // Randomly turn pixels on or off
            if (rand() % 2 == 0) {
                pixelArt[i][j] = PIXEL_ON;
            } else {
                pixelArt[i][j] = PIXEL_OFF;
            }
        }
    }

    // Print the pixel art
    printf("Pixel Art:\n");
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}