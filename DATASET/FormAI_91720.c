//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

void generatePixelArt(int pixels[][WIDTH]) {
    int i, j;
    srand(time(NULL));

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
}

void displayPixelArt(int pixels[][WIDTH]) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c ", (pixels[i][j] == 1) ? '#' : '.');
        }
        printf("\n");
    }
}

int main() {
    int pixels[HEIGHT][WIDTH];

    generatePixelArt(pixels);
    displayPixelArt(pixels);

    return 0;
}