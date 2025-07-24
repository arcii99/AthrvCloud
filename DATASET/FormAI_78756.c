//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 32

void generatePixelArt(char pixelArt[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            // generate random pixel
            int random = rand() % 10;
            pixelArt[i][j] = (random < 5) ? '1' : '0'; // 50% chance of being black or white
        }
    }
}

void printPixelArt(char pixelArt[HEIGHT][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char pixelArt[HEIGHT][WIDTH];

    srand(time(NULL));

    generatePixelArt(pixelArt);
    printPixelArt(pixelArt);

    return 0;
}