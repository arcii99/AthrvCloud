//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

void generatePixelArt(char art[HEIGHT][WIDTH]) {
    // Randomly generate pixel art
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int pixel = rand() % 2;
            art[i][j] = (pixel == 0) ? '.' : '#';
        }
    }
}

void printPixelArt(char art[HEIGHT][WIDTH]) {
    // Print the pixel art
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", art[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH];
    
    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);

    return 0;
}