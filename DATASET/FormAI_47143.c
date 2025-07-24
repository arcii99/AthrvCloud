//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

void drawPixel(char pixels[][WIDTH], int x, int y, char pixelValue) {
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return;

    pixels[y][x] = pixelValue;
}

void drawLine(char pixels[][WIDTH], int x1, int y1, int x2, int y2, char pixelValue) {
    if (x1 == x2) {
        int minY = (y1 < y2) ? y1 : y2;
        int maxY = (y1 > y2) ? y1 : y2;

        for (int i = minY; i <= maxY; i++) {
            drawPixel(pixels, x1, i, pixelValue);
        }
    } else if (y1 == y2) {
        int minX = (x1 < x2) ? x1 : x2;
        int maxX = (x1 > x2) ? x1 : x2;

        for (int i = minX; i <= maxX; i++) {
            drawPixel(pixels, i, y1, pixelValue);
        }
    } else {
        int dx = (x1 < x2) ? 1 : -1;
        int dy = (y1 < y2) ? 1 : -1;
        int err = 0;

        int x = x1, y = y1;

        while (x != x2 && y != y2) {
            drawPixel(pixels, x, y, pixelValue);

            err += abs(dy);

            if (err > abs(dx)) {
                err -= abs(dx);
                y += dy;
            }

            x += dx;
        }
    }
}

void drawTriangle(char pixels[][WIDTH], int x1, int y1, int x2, int y2, int x3, int y3, char pixelValue) {
    drawLine(pixels, x1, y1, x2, y2, pixelValue);
    drawLine(pixels, x1, y1, x3, y3, pixelValue);
    drawLine(pixels, x2, y2, x3, y3, pixelValue);
}

void drawRectangle(char pixels[][WIDTH], int x, int y, int width, int height, char pixelValue) {
    drawLine(pixels, x, y, x + width - 1, y, pixelValue);
    drawLine(pixels, x, y, x, y + height - 1, pixelValue);
    drawLine(pixels, x + width - 1, y, x + width - 1, y + height - 1, pixelValue);
    drawLine(pixels, x, y + height - 1, x + width - 1, y + height - 1, pixelValue);
}

void drawPixelArt(char pixels[][WIDTH], int size) {
    if (size == 1) {
        printf("%c\n", pixels[0][0]);
        return;
    }

    drawPixelArt(pixels, size / 2);

    for (int y = 0; y < size / 2; y++) {
        for (int x = 0; x < size / 2; x++) {
            pixels[y + size / 2][x + size / 2] = pixels[y][x];
        }
    }

    drawRectangle(pixels, size / 2, size / 2, size / 2, size / 2, ' ');

    drawPixelArt(pixels, size / 2);
}

int main() {
    char pixels[HEIGHT][WIDTH];

    srand(time(NULL));

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixels[y][x] = (rand() < RAND_MAX / 2) ? '#' : ' ';
        }
    }

    drawTriangle(pixels, 0, HEIGHT - 1, WIDTH / 2, HEIGHT / 2, WIDTH - 1, HEIGHT - 1, '#');

    drawPixelArt(pixels, WIDTH);

    return 0;
}