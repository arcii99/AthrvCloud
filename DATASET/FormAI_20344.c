//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 8
#define HEIGHT 8

// A function to print the pixel art
void printPixels(int pixels[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 0) {
                printf("  ");
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Create the empty pixel art
    int pixels[HEIGHT][WIDTH] = {0};
    
    // Loop through and randomly set pixels to 1 or 0
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
    
    // Print the pixel art
    printPixels(pixels);
    
    return 0;
}