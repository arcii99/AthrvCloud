//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 128
#define HEIGHT 64

void fill_pixels(char pixels[HEIGHT][WIDTH], char color) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            pixels[i][j] = color;
        }
    }
}

void draw_pixel(char pixels[HEIGHT][WIDTH], int x, int y, char color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        pixels[y][x] = color;
    }
}

void draw_line(char pixels[HEIGHT][WIDTH], int x1, int y1, int x2, int y2, char color) {
    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;
    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;
    while (1) {
        draw_pixel(pixels, x1, y1, color);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 >= dy) { err += dy; x1 += sx; }
        if (e2 <= dx) { err += dx; y1 += sy; }
    }
}

int main() {
    char pixels[HEIGHT][WIDTH];
    fill_pixels(pixels, ' ');

    // draw a square
    draw_line(pixels, 20, 20, 40, 20, '#');
    draw_line(pixels, 40, 20, 40, 40, '#');
    draw_line(pixels, 40, 40, 20, 40, '#');
    draw_line(pixels, 20, 40, 20, 20, '#');

    // draw a circle
    for (double theta = 0; theta < 2 * 3.141592653589793; theta += 0.1) {
        int x = 50 + (int)(20 * cos(theta));
        int y = 30 + (int)(20 * sin(theta));
        draw_pixel(pixels, x, y, '#');
    }

    // print the pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            putchar(pixels[i][j]);
        }
        putchar('\n');
    }

    return 0;
}