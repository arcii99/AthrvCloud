//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void printPixelArt(int pixels[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixels[i][j] == 1) {
                printf("* ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void generatePixelArt(int pixels[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) {
                pixels[i][j] = 1;
            } else {
                pixels[i][j] = 0;
            }
        }
    }
}

int main() {
    int pixels[HEIGHT][WIDTH];
    generatePixelArt(pixels);
    printPixelArt(pixels);
    return 0;
}