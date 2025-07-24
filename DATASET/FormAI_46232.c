//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Configurable variables
#define WIDTH 50
#define HEIGHT 50
#define PIXEL_SIZE 2
#define PIXEL_CHARACTER '*'

// Function to generate a random integer between min and max (inclusive)
int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random boolean value
int random_bool() {
    return rand() % 2;
}

int main() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Create a 2D array of integers to represent the pixels
    int pixels[HEIGHT][WIDTH];

    // Initialize the pixels to 0 (off)
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = 0;
        }
    }

    // Loop over the pixels and randomly turn some on
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (random_bool()) {
                pixels[i][j] = 1;
            }
        }
    }

    // Print the pixels as ASCII art
    for (int i = 0; i < HEIGHT * PIXEL_SIZE; i++) {
        for (int j = 0; j < WIDTH * PIXEL_SIZE; j++) {
            if (pixels[i / PIXEL_SIZE][j / PIXEL_SIZE]) {
                putchar(PIXEL_CHARACTER);
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }

    return 0;
}