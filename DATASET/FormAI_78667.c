//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // initialize the random number generator with current time
    srand(time(NULL));

    // define the dimensions of the pixel art
    int rows = 10;
    int cols = 10;

    // create an empty 2D array to hold the pixel art
    char pixelArt[rows][cols];

    // fill the array with random 1s and 0s
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            pixelArt[i][j] = rand() % 2 ? '#' : '.';
        }
    }

    // print the pixel art
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}