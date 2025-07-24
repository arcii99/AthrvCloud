//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PIXEL_SIZE 8 // each pixel is an 8x8 square
#define WIDTH 128 // number of pixels across the grid
#define HEIGHT 64 // number of pixels down the grid

// function to draw a pixel at specified xy coordinates
void drawPixel(int x, int y) {
    // calculate starting x and y position of pixel
    int startX = x * PIXEL_SIZE;
    int startY = y * PIXEL_SIZE;
    
    // loop through each row of the pixel
    for (int i = 0; i < PIXEL_SIZE; i++) {
        // loop through each column of the pixel
        for (int j = 0; j < PIXEL_SIZE; j++) {
            // check if we're drawing the border of the pixel
            if (i == 0 || j == 0 || i == PIXEL_SIZE - 1 || j == PIXEL_SIZE - 1) {
                printf("*");
            }
            else {
                printf(".");
            }
        }
        
        // move down to the next row
        printf("\n");
    }
}

int main() {
    // seed random number generator
    srand(time(NULL));
    
    // loop through all pixels in the grid
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // randomly decide if we should draw a pixel
            if (rand() % 2 == 0) {
                // draw a pixel at the current position
                drawPixel(x, y);
            }
            else {
                // output a blank space to skip this pixel
                printf("        ");
            }
        }
        
        // move down to the next row
        printf("\n");
    }
    
    return 0;
}