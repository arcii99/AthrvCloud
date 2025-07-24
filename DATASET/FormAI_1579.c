//FormAI DATASET v1.0 Category: Fractal Generation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 20

void printGrayscale(char pixels[WIDTH][HEIGHT], int brightness);

void drawLine(char pixels[WIDTH][HEIGHT], int x1, int y1, int x2, int y2);

void drawFractal(char pixels[WIDTH][HEIGHT], int x1, int y1, int x2, int y2, int depth);

int main() {
    char pixels[WIDTH][HEIGHT];

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            pixels[i][j] = '.';
        }
    }

    drawFractal(pixels, 0, HEIGHT / 2, WIDTH - 1, HEIGHT / 2, 5);

    printGrayscale(pixels, 4);

    return 0;
}

/**
 * Draw a grayscale version of the fractal on the screen.
 * @param pixels The 2D pixel array.
 * @param brightness The brightness level, between 0 and 9.
 */
void printGrayscale(char pixels[WIDTH][HEIGHT], int brightness) {
    printf("\n");

    for (int j = 0; j < HEIGHT; j++) {
        for (int i = 0; i < WIDTH; i++) {
            printf("%c", (pixels[i][j] == '.') ? ' ' : (brightness + '0'));
        }
        printf("\n");
    }
}

/**
 * Draw a line on the screen using the Bresenham algorithm.
 * @param pixels The 2D pixel array.
 * @param x1 The x coordinate of the first point.
 * @param y1 The y coordinate of the first point.
 * @param x2 The x coordinate of the second point.
 * @param y2 The y coordinate of the second point.
 */
void drawLine(char pixels[WIDTH][HEIGHT], int x1, int y1, int x2, int y2) {
    bool steep = abs(y2 - y1) > abs(x2 - x1);

    if (steep) {
        int temp = x1;
        x1 = y1;
        y1 = temp;

        temp = x2;
        x2 = y2;
        y2 = temp;
    }

    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;

        temp = y1;
        y1 = y2;
        y2 = temp;
    }

    int dx = x2 - x1;
    int dy = abs(y2 - y1);
    int error = dx / 2;
    int yStep = (y1 < y2) ? 1 : -1;
    int y = y1;

    for (int x = x1; x <= x2; x++) {
        if (steep) {
            pixels[y][x] = '#';
        } else {
            pixels[x][y] = '#';
        }

        error -= dy;
        if (error < 0) {
            y += yStep;
            error += dx;
        }
    }
}

/**
 * Draw a fractal using the Koch curve algorithm.
 * @param pixels The 2D pixel array.
 * @param x1 The x coordinate of the starting point.
 * @param y1 The y coordinate of the starting point.
 * @param x2 The x coordinate of the ending point.
 * @param y2 The y coordinate of the ending point.
 * @param depth The recursion depth.
 */
void drawFractal(char pixels[WIDTH][HEIGHT], int x1, int y1, int x2, int y2, int depth) {
    if (depth == 0) {
        drawLine(pixels, x1, y1, x2, y2);
    } else {
        int dx = x2 - x1;
        int dy = y2 - y1;

        double dist = sqrt(dx * dx + dy * dy);
        double unitX = dx / dist;
        double unitY = dy / dist;

        double size = dist / 3.0;

        int x3 = x1 + (int) (unitX * size);
        int y3 = y1 + (int) (unitY * size);

        int x4 = x2 - (int) (unitX * size);
        int y4 = y2 - (int) (unitY * size);

        int xm = x3 + (int) (unitX - unitY * sqrt(3)) * size;
        int ym = y3 + (int) (unitY + unitX * sqrt(3)) * size;

        drawFractal(pixels, x1, y1, x3, y3, depth - 1);
        drawFractal(pixels, x3, y3, xm, ym, depth - 1);
        drawFractal(pixels, xm, ym, x4, y4, depth - 1);
        drawFractal(pixels, x4, y4, x2, y2, depth - 1);
    }
}