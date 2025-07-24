//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: imaginative
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Define the dimension of the pixel art
#define WIDTH 10
#define HEIGHT 10

// Define the color codes
#define BLACK 0
#define WHITE 1

// Function to generate a random binary number
int randBinary() {
    return rand() % 2;
}

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));

    // Create a 2D array for the pixel art
    int pixels[WIDTH][HEIGHT];

    // Generate random binary numbers for each pixel
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            pixels[x][y] = randBinary();
        }
    }

    // Print the pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (pixels[x][y] == BLACK) {
                printf("██");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}