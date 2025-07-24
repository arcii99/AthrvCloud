//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// define constants
#define ROWS 20
#define COLS 20

// function to generate random pixel art
void generatePixelArt(int rows, int cols) {
    int pixels[rows][cols];
    int i, j;

    // seed the random number generator
    srand(time(NULL));

    // generate random pixels
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    // print out the pixels
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", pixels[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // generate a 10x10 pixel art
    generatePixelArt(ROWS, COLS);
    return 0;
}