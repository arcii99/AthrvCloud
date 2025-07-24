//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

typedef struct {
    int x, y, color;
} Pixel;

void drawPixel(Pixel *pixel) {
    printf("\033[48;5;%dm", pixel->color);
    printf("\033[%d;%dH ", pixel->y, pixel->x);
    printf("\033[0m");
}

int main() {
    srand(time(NULL));
    Pixel pixels[WIDTH * HEIGHT];

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int color = rand() % 256;
            Pixel *pixel = &pixels[x + y * WIDTH];
            pixel->x = x + 1;
            pixel->y = y + 1;
            pixel->color = color;
            drawPixel(pixel);
        }
    }

    return 0;
}