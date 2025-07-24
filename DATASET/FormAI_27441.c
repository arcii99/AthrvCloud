//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 32
#define HEIGHT 32

int main() {
    srand(time(NULL)); // Seed random number generator

    // Define color palette
    const char *palette[] = {
        "  ",
        "██",
        "░░",
        "▒▒",
        "▓▓",
        "██" 
    };

    // Create blank canvas
    int canvas[WIDTH][HEIGHT];

    // Fill canvas with random colors
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            canvas[x][y] = rand() % 6;
        }
    }

    // Print canvas as pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%s", palette[canvas[x][y]]);
        }
        printf("\n");
    }

    return 0;
}