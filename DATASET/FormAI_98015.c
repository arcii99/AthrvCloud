//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Size of the canvas
    int width = 10;
    int height = 10;

    // Initialize the random seed
    srand(time(NULL));

    // Create a random pixel art image
    int pixel_art[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            pixel_art[i][j] = rand() % 2;
        }
    }

    // Print the pixel art image
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (pixel_art[i][j] == 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}