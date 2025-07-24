//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define WIDTH 10
#define HEIGHT 10

void drawPixel(int pixel) {
    if (pixel == 0) {
        printf(" ");
    } else if (pixel == 1) {
        printf("#");
    } else {
        printf("+");
    }
}

void generatePixelArt(int width, int height) {
    int pixels[width][height];
    
    // Set random seed
    srand(time(NULL));
    
    // Generate random pixels
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = rand() % 3;
        }
    }
    
    // Draw generated pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            drawPixel(pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt(WIDTH, HEIGHT);
    return 0;
}