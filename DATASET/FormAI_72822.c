//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configure the size of the canvas here
#define WIDTH 20
#define HEIGHT 10

// Define the characters used for pixel art
#define PIXEL_FULL '█'
#define PIXEL_HALF '▀'
#define PIXEL_EMPTY ' '

int main() {
    char canvas[HEIGHT][WIDTH];

    // Set seed for random number generator
    srand(time(NULL));

    // Fill canvas with random pixels
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            int rand_num = rand() % 100;

            if(rand_num < 33) {
                canvas[i][j] = PIXEL_EMPTY;
            } else if(rand_num < 66) {
                canvas[i][j] = PIXEL_HALF;
            } else {
                canvas[i][j] = PIXEL_FULL;
            }
        }
    }

    // Print canvas
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }

    return 0;
}