//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random number generator with seed
    
    int width = 16; // Width of the canvas in pixels
    int height = 16; // Height of the canvas in pixels
    
    char pixels[height][width]; // 2D array to hold pixel data
    
    // Loop through each pixel and randomly assign it a color value
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int color = rand() % 3; // Randomly choose a color (0, 1 or 2)
            switch (color) {
                case 0:
                    pixels[y][x] = 'R';
                    break;
                case 1:
                    pixels[y][x] = 'G';
                    break;
                case 2:
                    pixels[y][x] = 'B';
                    break;
            }
        }
    }
    
    // Print out the pixel data in a grid format
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c ", pixels[y][x]);
        }
        printf("\n"); // Move to the next line after each row
    }
    
    return 0; // Exit program
}