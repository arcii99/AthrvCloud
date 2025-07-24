//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main() {
    srand(time(NULL)); // Seed the random number generator with the current time

    // Initialize pixel art array with random values between 0 and 1
    int pixelArt[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }

    // Print the pixel art
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j] == 1 ? '#' : ' '); // Print '#' if pixel is 1, ' ' if pixel is 0
        }
        printf("\n"); // Newline after each row
    }

    return 0;
}