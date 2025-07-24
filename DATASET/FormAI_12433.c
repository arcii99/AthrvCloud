//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>

#define WIDTH 10 // Width of the pixel art canvas
#define HEIGHT 10 // Height of the pixel art canvas

// Function to print the pixel art
void printPixelArt(int pixels[HEIGHT][WIDTH]) {
    // Loop through the rows and columns of the pixels array
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            // Print out the value of the pixel
            printf("%d ", pixels[row][col]);
        }
        printf("\n"); // Move to the next row
    }
}

int main() {
    // Create an array of pixels and set some initial color values
    int pixels[HEIGHT][WIDTH] = {{1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1},
                                 {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                 {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}};
    
    // Print out the initial pixel art
    printPixelArt(pixels);

    return 0;
}