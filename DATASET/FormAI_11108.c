//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));  // Initializing random seed based on time

    int pixelArray[8][8];  // Two-dimensional array to store pixel values
    int i, j;  // Loop variables

    // Setting all pixel values to 0
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            pixelArray[i][j] = 0;
        }
    }

    // Generating random pixel values
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (rand() % 2 == 0) {
                pixelArray[i][j] = 1;
            }
        }
    }

    // Printing the pixel art
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (pixelArray[i][j] == 1) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}