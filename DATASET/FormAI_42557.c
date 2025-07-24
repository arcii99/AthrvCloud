//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate pixel art
void generatePixelArt(int width, int height, int pixelSize) {
    srand(time(NULL)); // Seed random number generator

    // Loop through rows and columns
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // Generate random RGB values
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;

            // Draw pixels using ASCII characters
            for (int i = 0; i < pixelSize; i++) {
                for (int j = 0; j < pixelSize; j++) {
                    // Print colored character
                    printf("\033[48;2;%d;%d;%dm ", r, g, b);
                }
                printf("\033[0m");
            }
        }
        printf("\n");
    }
}

int main() {
    int width = 50;
    int height = 20;
    int pixelSize = 2;

    generatePixelArt(width, height, pixelSize);

    return 0;
}