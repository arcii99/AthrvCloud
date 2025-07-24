//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 64    // Width of the generated pixel art
#define HEIGHT 64   // Height of the generated pixel art
#define PIXEL_SIZE 10   // Size of each individual pixel

// Function to generate a random number within a given range
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the pixel art grid
    int pixels[HEIGHT][WIDTH];

    // Generate each pixel value
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Generate a random number between 0 and 1
            float random_value = (float)rand() / RAND_MAX;

            // Set the pixel value based on the random number
            if (random_value < 0.5) {
                pixels[y][x] = 0; // Black pixel
            } else {
                pixels[y][x] = 1; // White pixel
            }
        }
    }

    // Output the pixel art as ASCII characters
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Determine the character to output based on the pixel value
            char pixel_char;
            if (pixels[y][x] == 0) {
                pixel_char = ' ';   // Output a space for black pixels
            } else {
                pixel_char = '#';   // Output a pound sign for white pixels
            }

            // Output the character multiple times to represent the size of each pixel
            for (int i = 0; i < PIXEL_SIZE; i++) {
                printf("%c", pixel_char);
            }
        }

        // Add a newline character to complete the row
        printf("\n");
    }

    return 0;
}