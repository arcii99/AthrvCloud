//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void draw_pixel(int pixel) {
    if (pixel == 0) {
        printf(" ");
    } else {
        printf("#");
    }
}

int main() {
    int pixels[WIDTH][HEIGHT];

    // set up random seed for pixel generator
    srand(time(NULL));

    // generate pixels randomly
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixels[i][j] = rand() % 2;
        }
    }

    // draw the pixel art
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            draw_pixel(pixels[i][j]);
        }
        printf("\n");
    }

    return 0;
}