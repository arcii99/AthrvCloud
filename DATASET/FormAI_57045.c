//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64

// Function to generate and return random color
int generateColor() {
    return rand() % 256;
}

// Function to generate and return random pixel
char generatePixel() {
    if (rand() % 2 == 0) {
        return 'X';
    } else {
        return 'O';
    }
}

// Main function
int main() {
    srand(time(NULL)); // Seed random number generator with the current time

    // Create 2D array to store pixels
    char pixels[HEIGHT][WIDTH];

    // Fill array with random pixels
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[y][x] = generatePixel();
        }
    }

    // Output array as pixel art
    printf("\n");

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (pixels[y][x] == 'X') {
                printf("\033[38;2;%d;%d;%dm", generateColor(), generateColor(), generateColor()); // Set color to random RGB value
                printf("%c", pixels[y][x]);
                printf("\033[0m"); // Reset color
            } else {
                printf("%c", pixels[y][x]);
            }
        }
        printf("\n");
    }

    return 0;
}