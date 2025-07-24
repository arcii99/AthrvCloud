//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 64
#define HEIGHT 32
#define PIXEL_SIZE 10

void drawPixel(int pixel) {
    if(pixel == 0) {
        printf(" ");
    } else {
        printf("█");
    }
}

int main(void) {
    int pixels[WIDTH][HEIGHT];

    int i, j;
    srand(time(NULL));
    for(i = 0; i < WIDTH; i++) {
        for(j = 0; j < HEIGHT; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    for(i = 0; i < HEIGHT; i++) {
        for(j = 0; j < WIDTH; j++) {
            drawPixel(pixels[j][i]);
            if(j == WIDTH - 1) {
                printf("\n");
            } else {
                printf(" ");
            }
        }
    }

    return 0;
}