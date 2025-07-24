//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

char pixels[HEIGHT][WIDTH];

void generatePixelArt() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = rand() % 2;
            pixels[i][j] = pixel == 0 ? ' ' : '*';
        }
    }
}

void printPixelArt() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt();
    printPixelArt();

    return 0;
}