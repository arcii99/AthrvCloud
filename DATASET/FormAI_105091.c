//FormAI DATASET v1.0 Category: Image Editor ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 50

char image[HEIGHT][WIDTH];

void initializeImage() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i][j] = ' '; // set all pixels to blank space
        }
    }
}

void displayImage() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", image[i][j]);
        }
        printf("\n"); // move to the next row
    }
}

void drawLine(int x1, int y1, int x2, int y2, char shape) {
    // draw a line from (x1,y1) to (x2,y2) with the specified shape
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy;

    if (x1 < x2) sx = 1;
    else sx = -1;
    if (y1 < y2) sy = 1;
    else sy = -1;

    int err = dx - dy;
    int x = x1;
    int y = y1;

    while (1) {
        image[y][x] = shape;
        if (x == x2 && y == y2) break;
        int err2 = 2 * err;
        if (err2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (err2 < dx) {
            err += dx;
            y += sy;
        }
    }
}

void addNoise() {
    // add noise to the image by randomly changing the shape of some pixels
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 10 == 0) {
                image[i][j] = '#'; // randomly change shape of some pixels
            }
        }
    }
}

int main() {
    initializeImage();
    drawLine(5, 5, 95, 45, '*');
    drawLine(5, 45, 95, 5, '*');
    addNoise();
    displayImage();

    return 0;
}