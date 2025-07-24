//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

void drawPixel(int x, int y, char pixelArt[WIDTH][HEIGHT]);

int main() {
    srand(time(NULL)); // Seed the random number generator

    char pixelArt[WIDTH][HEIGHT];

    // Initialize the pixelArt array with random values
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixelArt[i][j] = rand() % 2 == 0 ? ' ' : 'X';
        }
    }

    // Draw the pixel art
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            drawPixel(i, j, pixelArt);
        }
        printf("\n");
    }

    return 0;
}

void drawPixel(int x, int y, char pixelArt[WIDTH][HEIGHT]) {
    printf("%c ", pixelArt[x][y]);
}