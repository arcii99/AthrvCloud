//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 16
#define HEIGHT 16

void drawPixel(int pixel) {
    switch (pixel) {
        case 0:
            printf("\u2588\u2588");
            break;
        case 1:
            printf("\u2593\u2593");
            break;
        case 2:
            printf("\u2592\u2592");
            break;
        case 3:
            printf("\u2591\u2591");
            break;
        default:
            break;
    }
}

void drawRow(int row[]) {
    for (int i = 0; i < WIDTH; i++) {
        drawPixel(row[i]);
    }
    printf("\n");
}

void drawPixels(int pixels[][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        drawRow(pixels[i]);
    }
}

void generatePixels(int pixels[][WIDTH]) {
    srand((unsigned) time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int pixel = rand() % 4;
            pixels[i][j] = pixel;
        }
    }
}

int main() {
    int pixels[HEIGHT][WIDTH];
    generatePixels(pixels);
    drawPixels(pixels);
    return 0;
}