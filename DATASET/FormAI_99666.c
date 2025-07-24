//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 20
#define HEIGHT 10

int pixel[WIDTH][HEIGHT];

void generatePixelArt() {
    srand(time(NULL)); // seed the random number generator
    int i, j;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            pixel[i][j] = rand() % 2; // generate either 0 or 1
        }
    }
}

void printPixelArt() {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (pixel[j][i] == 1) {
                printf("*");
            } else {
                printf(" ");
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