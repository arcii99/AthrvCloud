//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 15 // Change to set the width of the pixel art
#define HEIGHT 15 // Change to set the height of the pixel art

// CODE TO GENERATE PIXEL ART
void generatePixelArt(char art[HEIGHT][WIDTH], int paletteSize, char palette[]) {
    srand(time(NULL)); // Set random number generator seed

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int index = rand() % paletteSize; // Generate random index in the palette
            art[i][j] = palette[index]; // Set the pixel in the art array to the character in the palette at the generated index
        }
    }
}

int main() {
    char palette[] = {'*', '#', '$', '%', '&', '@'}; // Define palette characters
    int paletteSize = 6; // Set size of palette
    char pixelArt[HEIGHT][WIDTH]; // Define 2D array to hold pixel art

    generatePixelArt(pixelArt, paletteSize, palette); // Call function to fill pixel art array with randomly generated characters from the palette

    // CODE TO PRINT PIXEL ART
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]); // Print out the characters in the array without spaces
        }
        printf("\n"); // Print out a new line character after each row
    }

    return 0;
}