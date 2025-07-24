//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int main()
{
    srand(time(NULL));

    // Create the pixel art
    char pixelArt [HEIGHT][WIDTH];
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2 == 0 ? '0' : '1';
        }
    }

    // Print the pixel art
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            printf("%c ", pixelArt[i][j]);
        }
        printf("\n");
    }

    return 0;
}