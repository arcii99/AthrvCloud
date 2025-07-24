//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

int main() {
    int pixels[WIDTH][HEIGHT];

    // Generate random pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[x][y] = rand() % 2;
        }
    }

    // Print pixel art to console
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (pixels[x][y] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }

    return 0;
}