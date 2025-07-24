//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 128
#define HEIGHT 64

int main(void) {
    int pixels[HEIGHT][WIDTH];
    srand(time(NULL));
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[y][x] = rand() % 2;
        }
    }
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (pixels[y][x] == 1) {
                printf("\u2588");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return EXIT_SUCCESS;
}