//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 8
#define HEIGHT 8

typedef enum {
    PIXEL_OFF,
    PIXEL_ON
} PixelState;

typedef struct {
    PixelState state;
} Pixel;

Pixel canvas[HEIGHT][WIDTH];

void drawPixel(int x, int y) {
    canvas[y][x].state = PIXEL_ON;
}

void erasePixel(int x, int y) {
    canvas[y][x].state = PIXEL_OFF;
}

void clearCanvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            erasePixel(x, y);
        }
    }
}

void displayCanvas() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            printf("%c ", canvas[y][x].state == PIXEL_ON ? '#' : '.');
        }
        printf("\n");
    }
}

void drawCircle(int x0, int y0, int radius) {
    int x = radius;
    int y = 0;
    int err = 0;

    while (x >= y) {
        drawPixel(x0 + x, y0 + y);
        drawPixel(x0 + y, y0 + x);
        drawPixel(x0 - y, y0 + x);
        drawPixel(x0 - x, y0 + y);
        drawPixel(x0 - x, y0 - y);
        drawPixel(x0 - y, y0 - x);
        drawPixel(x0 + y, y0 - x);
        drawPixel(x0 + x, y0 - y);

        if (err <= 0) {
            y += 1;
            err += 2*y + 1;
        }

        if (err > 0) {
            x -= 1;
            err -= 2*x + 1;
        }
    }
}

int main() {
    clearCanvas();

    drawCircle(4, 4, 3);
    drawCircle(4, 4, 2);
    drawCircle(4, 4, 1);

    displayCanvas();

    return EXIT_SUCCESS;
}