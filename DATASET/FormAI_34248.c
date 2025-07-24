//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define pixel dimensions
#define PIXEL_ROWS 16
#define PIXEL_COLS 16

// Define pixel colors
#define BLACK 0
#define WHITE 1

// Function to generate random pixels
int generatePixel() {
    return rand() % 2; // Returns either 0 or 1
}

// Function to print the pixel art
void printPixelArt(int pixelArt[][PIXEL_COLS]) {
    for (int i=0; i<PIXEL_ROWS; i++) {
        for (int j=0; j<PIXEL_COLS; j++) {
            if (pixelArt[i][j] == BLACK) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n"); // Move to next row
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Create array to hold pixel art
    int pixelArt[PIXEL_ROWS][PIXEL_COLS];

    // Generate random pixel art
    for (int i=0; i<PIXEL_ROWS; i++) {
        for (int j=0; j<PIXEL_COLS; j++) {
            pixelArt[i][j] = generatePixel();
        }
    }

    // Print the pixel art
    printPixelArt(pixelArt);

    return 0;
}