//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 20

char pixels[MAX_HEIGHT][MAX_WIDTH];

void printPixels() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            printf("%c", pixels[i][j]);
        }
        printf("\n");
    }
}

void clearPixels() {
    for (int i = 0; i < MAX_HEIGHT; i++) {
        for (int j = 0; j < MAX_WIDTH; j++) {
            pixels[i][j] = ' ';
        }
    }
}

void drawLine(int x0, int y0, int x1, int y1, char color) {
    int dx = abs(x1-x0);
    int sx = x0<x1 ? 1 : -1;
    int dy = abs(y1-y0);
    int sy = y0<y1 ? 1 : -1;
    int err = (dx>dy ? dx : -dy)/2;
    int e2;
 
    while(1) {
        pixels[y0][x0] = color;
        if (x0==x1 && y0==y1) break;
        e2 = err;
        if (e2 >-dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

void drawPixel(int x, int y, char color) {
    pixels[y][x] = color;
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, char color) {
    drawLine(x0, y0, x1, y1, color);
    drawLine(x1, y1, x2, y2, color);
    drawLine(x2, y2, x0, y0, color);
}

void drawRectangle(int x0, int y0, int width, int height, char color) {
    for (int y = y0; y < y0+height; y++) {
        for (int x = x0; x < x0+width; x++) {
            drawPixel(x, y, color);
        }
    }
}

int main() {
    srand(time(NULL));

    int shape = 0; // 0 = triangle, 1 = rectangle
    int x0, y0, x1, y1, x2, y2, width, height;
    char color;

    while (1) {
        clearPixels();

        // randomly generate a shape, color, and coordinates
        shape = rand() % 2;
        color = (rand() % 2 == 0) ? 'X' : '*';

        if (shape == 0) {
            x0 = rand() % MAX_WIDTH;
            y0 = rand() % MAX_HEIGHT;
            x1 = rand() % MAX_WIDTH;
            y1 = rand() % MAX_HEIGHT;
            x2 = rand() % MAX_WIDTH;
            y2 = rand() % MAX_HEIGHT;
            drawTriangle(x0, y0, x1, y1, x2, y2, color);
        }
        else {
            width = rand() % (MAX_WIDTH / 2);
            height = rand() % (MAX_HEIGHT / 2);
            x0 = rand() % (MAX_WIDTH - width);
            y0 = rand() % (MAX_HEIGHT - height);
            drawRectangle(x0, y0, width, height, color);
        }

        printPixels();
        getchar(); // wait for user input before generating a new shape
    }

    return 0;
}