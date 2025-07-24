//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set pixel art dimensions
    int height = 5;
    int width = 5;

    // Create pixel art array
    int pixels[height][width];

    // Populate pixel art array with random values (0 or 1)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    // Print out pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixels[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }

        printf("\n");
    }

    return 0;
}