//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

int pixels[MAX_WIDTH][MAX_HEIGHT];

void generatePixelArt() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < MAX_WIDTH; i++) {
        for (j = 0; j < MAX_HEIGHT; j++) {
            pixels[i][j] = rand() % 2;
        }
    }
}

void printPixelArt() {
    int i, j;
    for (i = 0; i < MAX_WIDTH; i++) {
        for (j = 0; j < MAX_HEIGHT; j++) {
            if (pixels[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int main() {
    generatePixelArt();
    printPixelArt();
    return 0;
}