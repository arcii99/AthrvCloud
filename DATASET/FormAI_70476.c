//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define width and height constants
#define WIDTH 20
#define HEIGHT 20

// Define pixel character constants
#define PIXEL_FULL "\u2588\u2588"
#define PIXEL_HALF "\u258C\u258C"
#define PIXEL_EIGHTH "\u2590\u2590"
#define PIXEL_SIXTEENTH "\u2588 "

// Define pixel color constants
#define COLOR_RED "\033[0;31m"
#define COLOR_BLUE "\033[0;34m"
#define COLOR_RESET "\033[0m"

// Declare function to print pixel art
void printPixelArt(char pixelArt[HEIGHT][WIDTH]);

int main(void) {

    // Seed random number generator
    srand(time(NULL));

    // Initialize pixel art array
    char pixelArt[HEIGHT][WIDTH];

    // Loop through pixel art array and set elements to random values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int randPixel = rand() % 16;
            if (randPixel < 2) {
                // Red full pixel
                pixelArt[i][j] = *COLOR_RED PIXEL_FULL COLOR_RESET;
            } else if (randPixel < 4) {
                // Red half pixel
                pixelArt[i][j] = *COLOR_RED PIXEL_HALF COLOR_RESET;
            } else if (randPixel < 8) {
                // Blue full pixel
                pixelArt[i][j] = *COLOR_BLUE PIXEL_FULL COLOR_RESET;
            } else if (randPixel < 12) {
                // Blue half pixel
                pixelArt[i][j] = *COLOR_BLUE PIXEL_HALF COLOR_RESET;
            } else if (randPixel < 14) {
                // Red eighth pixel
                pixelArt[i][j] = *COLOR_RED PIXEL_EIGHTH COLOR_RESET;
            } else if (randPixel < 15) {
                // Blue eighth pixel
                pixelArt[i][j] = *COLOR_BLUE PIXEL_EIGHTH COLOR_RESET;
            } else {
                // Blue sixteenth pixel
                pixelArt[i][j] = *COLOR_BLUE PIXEL_SIXTEENTH COLOR_RESET;
            }
        }
    }

    // Print pixel art
    printPixelArt(pixelArt);

    return 0;
}

/**
 * This function prints a given pixel art array to the console.
 * 
 * @param pixelArt The pixel art array to print.
 */
void printPixelArt(char pixelArt[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%s", &pixelArt[i][j]);
        }
        printf("\n");
    }
}