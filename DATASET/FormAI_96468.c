//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void printPixelArt(bool **pixelArt) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (pixelArt[i][j]) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void generatePixelArt(bool **pixelArt) {
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixelArt[i][j] = rand() % 2;
        }
    }
}

int main() {
    bool **pixelArt = malloc(sizeof(bool *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        pixelArt[i] = malloc(sizeof(bool) * WIDTH);
    }

    generatePixelArt(pixelArt);

    printPixelArt(pixelArt);

    for (int i = 0; i < HEIGHT; i++) {
        free(pixelArt[i]);
    }
    free(pixelArt);

    return 0;
}