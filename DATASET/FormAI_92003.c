//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows = 8; // number of rows in the pixel art
    int cols = 8; // number of columns in the pixel art
    int pixels[rows][cols]; // array to hold the pixel values

    // loop through each pixel and randomly assign a value
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            pixels[i][j] = rand() % 2; // either 0 or 1
        }
    }

    // loop through each pixel again and print the corresponding ASCII art
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (pixels[i][j] == 0) {
                printf(" "); // empty space for 0 value
            } else {
                printf("█"); // full block for 1 value
            }
        }
        printf("\n"); // move to next row
    }

    return 0;
}