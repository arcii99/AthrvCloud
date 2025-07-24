//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 10
#define HEIGHT 10

int canvas[WIDTH][HEIGHT];

void setPixel(int x, int y, int color) {
    canvas[x][y] = color;
}

void drawPixelArt() {
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            printf("%d", canvas[x][y]);
        }
        printf("\n");
    }
}

void main() {
    /* Initialize the canvas with default color */
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            canvas[x][y] = 0;
        }
    }

    /* Draw a smiley face */
    setPixel(2, 4, 1);
    setPixel(7, 4, 1);
    setPixel(4, 6, 1);
    setPixel(5, 6, 1);
    setPixel(3, 7, 1);
    setPixel(6, 7, 1);
    setPixel(2, 8, 1);
    setPixel(7, 8, 1);

    drawPixelArt();
}