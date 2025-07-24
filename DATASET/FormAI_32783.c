//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the array to all zeroes
    int pixels[WIDTH][HEIGHT] = {0};

    // Choose a random color
    int color = rand() % 256;

    // Set a random pixel to the chosen color
    int x = rand() % WIDTH;
    int y = rand() % HEIGHT;
    pixels[x][y] = color;

    // Loop through each pixel and randomly change its color
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            if (pixels[i][j] == 0) {
                // Choose a random probability of changing the color
                int chance = rand() % 100;
                if (chance < 50) {
                    // Choose a random new color
                    pixels[i][j] = rand() % 256;
                }
            }
        }
    }

    // Print out the pixel art
    printf("P3 %d %d 255\n", WIDTH, HEIGHT);
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d %d %d ", pixels[i][j], pixels[i][j], pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}