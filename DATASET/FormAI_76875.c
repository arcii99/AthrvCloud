//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 25

// Define pixel art pattern
const char PIXEL_PATTERN[4][4] = {
    {'*', '-', 'o', '-'},
    {'|', ',', '^', '`'},
    {'`', '-', '#', '_'},
    {'\\', '_', '>', '\''}
};

int main() {
    // Initialize pixel array with default pattern
    char pixels[WIDTH][HEIGHT];
    for(int x = 0; x < WIDTH; x++) {
        for(int y = 0; y < HEIGHT; y++) {
            pixels[x][y] = PIXEL_PATTERN[x % 4][y % 4];
        }
    }

    // Print pixel array
    for(int y = 0; y < HEIGHT; y++) {
        for(int x = 0; x < WIDTH; x++) {
            printf("%c", pixels[x][y]);
        }
        printf("\n");
    }

    return 0;
}