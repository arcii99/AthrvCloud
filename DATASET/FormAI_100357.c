//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ART_SIZE 10 // Size of the art canvas
#define PIXELS 3    // Number of pixels in each cell (R, G, B)

// Function declaration
void generate_pixel_art(int canvas[ART_SIZE][ART_SIZE][PIXELS]);

int main() {
    // Seed random number generator 
    srand(time(NULL));

    // Declare art canvas
    int pixel_art[ART_SIZE][ART_SIZE][PIXELS];

    // Fill the canvas with random colors
    generate_pixel_art(pixel_art);

    // Print the pixel art
    printf("\nYour generated pixel art:\n");

    for (int row = 0; row < ART_SIZE; row++) {
        for (int col = 0; col < ART_SIZE; col++) {
            printf("[%d,%d]:", row, col);
            for (int i = 0; i < PIXELS; i++) {
                printf(" %d", pixel_art[row][col][i]);
            }
            printf("\n");
        }
    }

    return 0;
}

// Function definition
void generate_pixel_art(int canvas[ART_SIZE][ART_SIZE][PIXELS]) {
    for (int row = 0; row < ART_SIZE; row++) {
        for (int col = 0; col < ART_SIZE; col++) {
            for (int i = 0; i < PIXELS; i++) {
                canvas[row][col][i] = rand() % 256; // Random color value between 0 and 255 
            }
        }
    }
}