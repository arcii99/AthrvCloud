//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the grid parameters
    int width = 8;
    int height = 8;

    // Seed the random number generator
    srand(time(NULL));

    // Setting up the color options
    char colors[] = {'R', 'G', 'B', 'Y', 'O', 'P'};

    // Generating the pixel art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char color = colors[rand() % 6];
            printf("%c ", color);
        }
        printf("\n");
    }

    return 0;
}