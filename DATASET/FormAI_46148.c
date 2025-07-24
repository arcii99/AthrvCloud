//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 16
#define WIDTH 16

int main () {
    int pixels[HEIGHT][WIDTH];
    int i, j;

    // Seed the random number generator
    srand(time(NULL));

    // Generate random pixels
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    // Draw the pixel art
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}